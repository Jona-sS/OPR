#pragma once
#include "Luftfahrzeug.h"
class Heissluftballon : public Luftfahrzeug
{
    private:
    int _ballonVolumen;
public:
    Heissluftballon(std::string const &name, int maxFlughoehe, int ballonVolumen):Luftfahrzeug(name,maxFlughoehe), _ballonVolumen{ballonVolumen}{}
    int ballonVolumen() const{
        return _ballonVolumen;
    }
    std::string text() const{
        return Luftfahrzeug::text()+ ", ballonVolumen="+std::to_string(_ballonVolumen)+"m^3";
    }
};