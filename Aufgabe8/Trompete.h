#pragma once
#include "Musikinstrument.h"
#include <iostream>
class Trompete : public Musikinstrument{
    private:

    public:
        Trompete():Musikinstrument("Trompete"){
            std::cout<<"Konstruktor: Trompete()"<<std::endl;
        }
        virtual~Trompete(){
            std::cout<<"Destruktor: ~Trompete()"<<std::endl;
        }
        virtual void spielen() const override{
            std::cout<<"Trompete trötet"<<std::endl;
        }
};