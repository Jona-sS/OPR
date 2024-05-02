#pragma once
#include "Radfahrzeug.h"
class Pkw : public Radfahrzeug
{
    private:
    int _anzahlTueren;
public:
    Pkw(std::string const &name, int anzahlTueren):Radfahrzeug(name,4), _anzahlTueren{anzahlTueren}{}
    Pkw(Pkw const &pkw):Radfahrzeug(pkw), _anzahlTueren{pkw._anzahlTueren}{
        std::cout << "Kopiere Pkw"<<std::endl;
    }
    int anzahlTueren() const{
        return _anzahlTueren;
    }
    std::string text() const{
        return Radfahrzeug::text()+ " Türen="+std::to_string(_anzahlTueren);
    }
};