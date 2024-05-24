#pragma once
#include <iostream>
#include <string>
class Musikinstrument{
    private:
        std::string _name;
    public:
        Musikinstrument():_name{"Irgendein Instrument"}{
            std::cout<<"Konstruktor: Musikinstrument()"<<std::endl;
        }
        Musikinstrument(std::string name):_name{name}{
            std::cout<<"Konstruktor: Musikinstrument(string name): "<< _name<<std::endl;
        }
        virtual~Musikinstrument(){
            std::cout<<"Destruktor: ~Musikinstrument():"<< _name<<std::endl;
        }
        virtual void spielen() const{//const nötig da Aufruf über const Objekt
            std::cout << "Irgendein Instrument erklingt irgendwie"<<std::endl;
        }
        std::string liefereName() const{
            return _name;
        }
};