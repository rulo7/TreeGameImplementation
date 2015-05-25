#include <stdlib.h>
#include<limits>
#include "JugadorMinimaxC4.h"
#include "JuegoConecta4.h"
#pragma unmanaged


Casilla JugadorMinimaxC4::juega(const JuegoLogT2& EJ) const throw(EJugador) {
	if (typeid(EJ) != typeid(JuegoConecta4)) throw EJugador();

	else {

		if (EJ.final()) throw EJugador();

		return JugadorMinimaxT2::juega(EJ);

	}

}

float JugadorMinimaxC4::Heuristica(const JuegoLogT2& EJ, Turno T) const {

	float sumaJug = 0;
	float sumaContr = 0;

	Turno Tcont = Jhum;

	if(T==Jhum)
		Tcont = Jmaq;

	//Recorro todo el tablero para las posibles lineas de 4 posiciones horizontales
	for(unsigned int fil = 0 ; fil < EJ.numFil(); fil ++){
			for(unsigned int col = 0 ; col < (EJ.numCol() - 3); col ++){

				Turno t[4] = {
							EJ.dameCasilla(col,fil),
							EJ.dameCasilla(col + 1,fil),
							EJ.dameCasilla(col + 2,fil),
							EJ.dameCasilla(col + 3,fil)
							};
				

					sumaJug += heuristicaValora(t,T);
					sumaContr += heuristicaValora(t,Tcont);
			}
	}


	//Posiciones Verticales
	for(unsigned int col = 0 ; col < EJ.numCol(); col ++){			
			for(unsigned int fil = 0 ; fil < EJ.numFil() - 3; fil ++){

				Turno t[4] = {
							EJ.dameCasilla(col,fil),
							EJ.dameCasilla(col,fil + 1),
							EJ.dameCasilla(col,fil + 2),
							EJ.dameCasilla(col,fil + 3)
							};
				

					sumaJug += heuristicaValora(t,T);
					sumaContr += heuristicaValora(t,Tcont);
			}
	}

	//Posiciones Diagonales Dr
	for(unsigned int col = 0 ; col < EJ.numCol() - 3; col ++){			
			for(unsigned int fil = 0 ; fil < EJ.numFil() - 3; fil ++){

				Turno t[4] = {
							EJ.dameCasilla(col,fil),
							EJ.dameCasilla(col + 1,fil + 1),
							EJ.dameCasilla(col + 2,fil + 2),
							EJ.dameCasilla(col + 3,fil + 3)
							};
				

					sumaJug += heuristicaValora(t,T);
					sumaContr += heuristicaValora(t,Tcont);
			}
	}

	//Posiciones Diagonales Izq
	for(unsigned int col = EJ.numCol() - 1 ; col > 2; col --){			
			for(unsigned int fil = 0 ; fil < EJ.numFil() - 3; fil ++){

				Turno t[4] = {
							EJ.dameCasilla(col,fil),
							EJ.dameCasilla(col - 1,fil + 1),
							EJ.dameCasilla(col - 2,fil + 2),
							EJ.dameCasilla(col - 3,fil + 3)
							};

					sumaJug += heuristicaValora(t,T);
					sumaContr += heuristicaValora(t,Tcont);
			}
	}

	return (sumaJug - sumaContr);

}

float JugadorMinimaxC4::heuristicaValora(Turno t[4],Turno T) const{
	int k = 0;
	for(unsigned int i = 0; i < 4; i++){

		if(t[i] == T)
			k++;
		else if (t[i] != T && t[i] != Jn)
			return 0;
	}

	return (float)pow(10,k);
}

#pragma managed