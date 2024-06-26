#pragma once
#include "Verkehrsmittel.h"
class Luftfahrzeug : public Verkehrsmittel
{
    private:
    int const _maxFlughöhe;
public:
    Luftfahrzeug(std::string const &name, int maxFlughöhe):Verkehrsmittel(name), _maxFlughöhe{maxFlughöhe}{}
    Luftfahrzeug(Luftfahrzeug const &luftfahrzeug):Verkehrsmittel(luftfahrzeug), _maxFlughöhe{luftfahrzeug._maxFlughöhe}{
        std::cout << "Kopiere Luftfahrzeug"<<std::endl;
    }
    int maxFlughoehe() const{
        return _maxFlughöhe;
    }
    std::string text() const{
        return Verkehrsmittel::text()+ " maxFlughoehe="+ std::to_string(_maxFlughöhe)+"m";
    }

};