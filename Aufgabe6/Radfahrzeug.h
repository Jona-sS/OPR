#pragma once
#include "Verkehrsmittel.h"
class Radfahrzeug : public Verkehrsmittel
{
    private:
    int const _anzahlRaeder;
public:
    Radfahrzeug(std::string const &name, int anzahlRaeder):Verkehrsmittel(name), _anzahlRaeder{anzahlRaeder}{}
    Radfahrzeug(Radfahrzeug const &radfahrzeug):Verkehrsmittel(radfahrzeug), _anzahlRaeder{radfahrzeug._anzahlRaeder}{
        std::cout << "Kopiere Radfahrzeug"<<std::endl;
    }
    int anzahlRaeder() const{
        return _anzahlRaeder;
    }
    std::string text() const{
        return Verkehrsmittel::text()+ " Räder="+ std::to_string(_anzahlRaeder);
    }
};