#include "JuegoConecta4.h"

#pragma unmanaged
void JuegoConecta4::aplicaJugada(unsigned int c,unsigned int f) throw(EJuego) {

	if(sePuede(c,f) && !ganador) {
		int i = 0;
		while(dameCasilla(c,i) != Jn)
			i++;				

		tablero->at(c,i)=turno;
		libres--;
		ganador=conecta4(c,i);
		if(!ganador) turno=cambia(turno);

	} else throw EJuego("Jugada incorrecta");
}

bool JuegoConecta4::conecta4(unsigned int c,unsigned int f) {
	return (vertical(c,f) || horizontal(c,f) || subeDer(c,f)|| subeIzq(c,f));
}

bool JuegoConecta4::vertical(unsigned int c,unsigned int f) {

	//Comprobamos si por debajo de la casilla hay 3 conectadas con esta

	//Si hay al menos cuatro fichas por debajo
	if(f >= 3){
		return tablero->at(c,f-1)==turno && tablero->at(c,f-2)==turno && tablero->at(c,f-3)==turno;
	}

	return false;

}

bool JuegoConecta4::horizontal(unsigned int c,unsigned int f) {

	//Recorremos la horizontal en busca de cuatro conectadas

	int conectadas = 0;
	int j = c - 3;

	if(j < 0)
		j = 0;

	while((j < numCols) && (j <= c + 3)){

		if(tablero->at(j,f)==turno)
			conectadas++;
		else{
			conectadas = 0;
		}

		if(conectadas == 4)
			return true;

		j++;
	}

	return false;


}

bool JuegoConecta4::subeDer(unsigned int c,unsigned int f) {

	int cinit, finit;

	if(c < f){
		cinit = c - 3;

		if(cinit < 0)
			cinit = 0;

		finit = f - (c - cinit); 
	}else{

		finit = f - 3;

		if(finit < 0)
			finit = 0;

		cinit = c - (f - finit); 
	}



	//Recorro el bucle en busca de 4 conectadas

	int conectadas = 0;


	while((finit <= (f+3)) && (cinit <= (c+3)) && (finit < numFils) && (cinit < numCols)){

		if(tablero->at(cinit,finit)==turno)
			conectadas++;
		else
			conectadas = 0;

		if(conectadas == 4)
			return true;

		finit++;
		cinit++;
	}



	return false;

}

bool JuegoConecta4::subeIzq(unsigned int c,unsigned int f) {

	//Tener en cuenta que el recorrido de la diagonal es c - 1 , f + 1
	//Inicio de la diagonoal es el c + 3 , f - 3

	int cinit, finit;

	// si la distancia desde f hasta abajo es menor que de c a la derecha
	if(f <= numCols - 1 - c){
		finit = f - 3;

		if(finit < 0)
			finit = 0;

		cinit = c + (f - finit);
	}else{

		cinit = c + 3;

		if(cinit >= numCols)
			cinit = numCols - 1;

		finit = f - (cinit - c);

	}

	//Recorro el bucle en busca de 4 conectadas

	int conectadas = 0;

	while((finit <= (int)(f + 3)) && (cinit >= (int)(c - 3)) && (finit < numFils) && (cinit >= 0)){

		if(tablero->at(cinit,finit)==turno)
			conectadas++;
		else
			conectadas = 0;

		if(conectadas == 4)
			return true;

		finit++;
		cinit--;

	}



	return false;

}

#pragma managed