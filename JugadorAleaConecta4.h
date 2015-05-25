#ifndef JUGADORALEACONECTA4_H_
#define JUGADORALEACONECTA4_H_

#include "JugadorAutoT2.h"
#include "JuegoConecta4.h"

#pragma unmanaged


class JugadorAleaConecta4 : public JugadorAutoT2 {
public:
    JugadorAleaConecta4(){
    };
    virtual ~JugadorAleaConecta4(){
    };
    virtual Casilla juega(const JuegoLogT2& EJ) const throw(EJugador);

};

#pragma managed
#endif /* JUGADORALEACONECTA4_H_ */
