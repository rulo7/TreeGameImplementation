#include <stdlib.h>
#include "JugadorAleaConecta4.h"
#pragma unmanaged

Casilla JugadorAleaConecta4::juega(const JuegoLogT2& EJ) const throw(EJugador) {
    if (typeid(EJ) != typeid(JuegoConecta4)) throw EJugador();
    else {
        if (EJ.final()) throw EJugador();
        int col,fil;
        unsigned int Ncol=EJ.numCol();
        unsigned int Nfil=EJ.numFil();
        col=rand() % Ncol;
        fil=rand() % Nfil;
        while (!EJ.sePuede(col,fil)) {
            col=rand() % Ncol;
            fil=rand() % Nfil;
        }
        return Casilla(col,fil);
    }
}

#pragma managed