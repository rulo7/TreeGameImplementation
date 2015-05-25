#ifndef JUGADORMINIMAXC4_H_
#define JUGADORMINIMAXC4_H_

#include "JugadorMinimaxT2.h"

#pragma unmanaged


class JugadorMinimaxC4 : public JugadorMinimaxT2 {
private:

	virtual float Heuristica(const JuegoLogT2& EJ, Turno T) const;	
	float heuristicaValora(Turno t[4],Turno T) const;
	

public:
    JugadorMinimaxC4(int nivel) : JugadorMinimaxT2(nivel){
    };
    virtual ~JugadorMinimaxC4(){
    };
    virtual Casilla juega(const JuegoLogT2& EJ) const throw(EJugador);

};

#pragma managed
#endif /* JUGADORMINIMAXC4_H_ */
