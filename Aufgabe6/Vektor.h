#pragma once
#include <iostream>

class Vektor
{
public:
    Vektor():x{0}, y{0}{}
    Vektor(int x_neu, int y_neu):x(x_neu), y(y_neu){
    }
    std::string text() const
    {
        return "Postition=(" + std::to_string(x) + "," + std::to_string(y) + ")";
    }
    int x=0;
    int y=0;
};