#ifndef INTERFAZGRAFCONECTA4_H_
#define INTERFAZGRAFCONECTA4_H_
using namespace System::Drawing;

#include "InterfazGrafT2.h"
#include "JuegoConecta4.h"
#pragma unmanaged

class InterfazGrafConecta4 : public InterfazGrafT2 {
private:
    int ladoCasilla;
    virtual void muestraEst(Graphics^ canvas, const JuegoConecta4& EJ) const throw();
public:
    InterfazGrafConecta4(int w, int h);
    virtual ~InterfazGrafConecta4();

    virtual unsigned int dameColumna(unsigned int X) const throw(EInterfaz) { return X/ladoCasilla - 1;};

    virtual unsigned int dameFila(unsigned int Y) const throw(EInterfaz) { return Y/ladoCasilla - 1;};

    virtual void muestraEstado(Graphics^ canvas, const JuegoLogT2& EJ) const throw(EInterfaz);
};

#pragma managed
#endif /* INTERFAZGRAFCONECTA4_H_ */
