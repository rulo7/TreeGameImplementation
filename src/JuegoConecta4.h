#ifndef JUEGOCONECTA4_H_
#define JUEGOCONECTA4_H_

#include "JuegoLogT2.h"
#pragma unmanaged

class JuegoConecta4 : public JuegoLogT2 {

public:
    static const int numCols = 8;
    static const int numFils = 6;
private:
    unsigned int libres;
    bool conecta4(unsigned int c,unsigned int f);
    bool horizontal(unsigned int c,unsigned int f);
    bool vertical(unsigned int c,unsigned int f);
    bool subeDer(unsigned int c,unsigned int f);
    bool subeIzq(unsigned int c,unsigned int f);
public:
    JuegoConecta4(Turno JI=Jn) : libres(numCols*numFils){
        turno=JI;
        tablero=new Matriz<Ficha>(numCols,numFils,Jn);
    }
    JuegoConecta4(const JuegoConecta4& EJ) : JuegoLogT2(EJ) {
        libres=EJ.libres;
    }
    virtual ~JuegoConecta4(){

    }
    virtual void reinicia(Turno JI){
        JuegoLogT2::reinicia(JI);libres=numCols*numFils;
    }
    virtual bool fin() const {
        return libres==0;
    }
    virtual JuegoLogT2* clona() const {
        return new JuegoConecta4(*this);
    }
    
	virtual void aplicaJugada(unsigned int c,unsigned int f) throw(EJuego);
    
	virtual bool sePuede(unsigned int c,unsigned int f) const throw() {
		
		if(ganador)
			return false;
		
		try {

				if(dameCasilla(c,f) == Jn){
					if(f == 0)
						return true;

					if (dameCasilla(c,f-1) != Jn)					
						return true;

				}

        } catch(EJuego &) { return false; }
		return false;
    }

	virtual bool sePuede(Casilla cf) const throw() {
		try {
			return sePuede(cf.col,cf.fil);
        } catch(EJuego &) { return false; }
        return false;
    }

};

#pragma managed
#endif /* JUEGOCONECTA4_H_ */