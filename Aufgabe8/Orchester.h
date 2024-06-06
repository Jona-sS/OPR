#pragma once
#include "Musiker.h"
#include <vector>
#include <iostream>
class Orchester{
    private:
        std::vector<Musiker const*> _musiker;//
    public:
        Orchester(){
            std::cout << "Konstruktor: ~Orchester()"<<std::endl;
        }
        virtual~Orchester(){//muss nicht virtuel
            std::cout << "Destruktor: ~Orchester()"<<std::endl;
            for(Musiker const* musiker : _musiker){//auto Datentyp verwenden
                delete musiker;
            }
        }
        void spielen() {
            for(Musiker const* musiker : _musiker){
                musiker->spielen();
            }
        }
        void hinzufuegen(Musiker *const musiker){
            _musiker.push_back(musiker);
        }
};