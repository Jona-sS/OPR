#pragma once
#include "Musikinstrument.h"
#include <iostream>
class Klavier : public Musikinstrument{
    private:

    public:
        Klavier():Musikinstrument("Klavier"){
            std::cout<<"Konstruktor: Klavier()"<<std::endl;
        }
        virtual~Klavier(){
            std::cout<<"Destruktor: ~Klavier()"<<std::endl;
        }
        virtual void spielen() const override{
            std::cout<<"Klavier klimpert"<<std::endl;
        }
};