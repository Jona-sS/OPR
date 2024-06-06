#pragma once
#include "Musikinstrument.h"
#include <string>
#include <iostream>
class Musiker
{
private:
    std::string _name;
    Musikinstrument const *_musikinstrument;
    int besitztInstrument = 0;

public:
    Musiker()
    {
        std::cout << "Konstruktor: Musiker(): " << _name << std::endl;
    }
    Musiker(std::string name) : _name{name}
    {
        std::cout << "Konstruktor: Musiker(string name): " << _name << std::endl;
    }
    virtual ~Musiker()
    {
        std::cout << "Destruktor: ~Musiker(): " << _name << std::endl;
        if (besitztInstrument)
        {
            delete _musikinstrument;
        }
    }
    void weiseInstrumentZu(Musikinstrument const *instrument)
    {
        if (besitztInstrument)
        {//nicht umbedingt nötig delete handelt das 
            delete _musikinstrument;
        }
        _musikinstrument = instrument;
        std::cout << _name << " erhaelt " << _musikinstrument->liefereName() << std::endl;
        besitztInstrument = 1;
    }
    void spielen() const
    {
        // if (_musikinstrument !=nullptr ) -> muss dann auch als nullptr initailiert werden, sonst steht iwas drinen
        if (besitztInstrument)
        {
            std::cout << _name << " spielt " << _musikinstrument->liefereName() << std::endl;
            _musikinstrument->spielen();
        }
    }
    std::string liefereName()
    {
        return _name;
    }
};