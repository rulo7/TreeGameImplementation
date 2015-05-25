#include "JugadorAutoT2.h"

class JugadorMinimaxT2 : public JugadorAutoT2 { 
protected: 
	int nivel; 
	virtual float Heuristica(const JuegoLogT2& EJ, Turno T) const=0; 
	float valoraMin(const JuegoLogT2& EJ, Turno T, int n, float A, float B) const throw(EJugador);
	float valoraMax(const JuegoLogT2& EJ, Turno T, int n, float A, float B) const throw(EJugador);
public: 
	JugadorMinimaxT2(int n=4) : nivel(n) {}; 
	virtual ~JugadorMinimaxT2(){};
	// implementa el m�todo juega de JugadorAutoT2 explorando un �rbol de juegos con ra�z EJ 
	virtual Casilla juega(const JuegoLogT2& EJ) const throw(EJugador);
};
