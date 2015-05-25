#include <stdlib.h>
#include<limits>
#include "JugadorMinimaxT2.h"
#include "JuegoLogT2.h"
#pragma unmanaged


Casilla JugadorMinimaxT2::juega(const JuegoLogT2& EJ) const throw(EJugador) {

	Casilla mejorC; 
	float mejorV = - (numeric_limits<float>::infinity());
	Casilla c;

	JuegoLogT2* EJObj;

	for(unsigned int fil = 0; fil < EJ.numFil(); fil++){		
		for(unsigned int col = 0; col < EJ.numCol(); col++){
			c.col = col;
			c.fil = fil;

			

			if(EJ.sePuede(c)){
				EJObj = EJ.clona();
				EJObj->aplicaJugada(c);

				if(EJObj->final()){
					delete EJObj;
					return c;
				}

				float v = valoraMin(*EJObj, EJ.dameTurno(), nivel - 1, mejorV, numeric_limits<float>::infinity());

				if(v > mejorV){
					mejorV = v;
					mejorC = c;
				}

				delete EJObj;
			}			
		}
	}


	return mejorC;
}

float JugadorMinimaxT2::valoraMin(const JuegoLogT2& EJ, Turno T, int n, float A, float B) const throw(EJugador){

	JuegoLogT2* EJObj;

	if (EJ.final() || n==0) {
		return Heuristica(EJ,T); 
	}else { 	

		for(unsigned int fil = 0; fil < EJ.numFil(); fil++){
			for (unsigned int col = 0; col < EJ.numCol(); col++){
				Casilla c;

				c.fil = fil;
				c.col = col;


				if(EJ.sePuede(c)){
					EJObj = EJ.clona();
					EJObj->aplicaJugada(c);

					float x = valoraMax(*EJObj, T ,n-1, A, B);

					if(x < B)
						B = x;	

					if (A >= B) {
						delete EJObj;
						return B;
					}
					delete EJObj;
				}		
				
			}
		}
	} 

	return B;
} 

float JugadorMinimaxT2::valoraMax(const JuegoLogT2& EJ, Turno T, int n, float A, float B) const throw(EJugador){

	JuegoLogT2* EJObj;

	if (EJ.final() || n==0) {
		return Heuristica(EJ,T); 
	}else { 
		Casilla c;

		for(unsigned int fil = 0; fil < EJ.numFil(); fil++){
			for (unsigned int col = 0; col < EJ.numCol(); col++){
				c.col = col;
				c.fil = fil;


				if(EJ.sePuede(c)){				
					EJObj = EJ.clona();
					EJObj->aplicaJugada(c);

					float x = valoraMin(*EJObj, T ,n-1, A, B);

					if(x > A)
						A = x;	

					if (A >= B) {
						delete EJObj;
						return A;
					}

					delete EJObj;
				}

			}
		}
	} 

	return A;
} 


#pragma managed