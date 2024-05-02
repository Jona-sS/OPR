#pragma once
#include "Vektor.h"

class Verkehrsmittel : public Vektor
{
private:
   std::string _name;
   Vektor _position;

public:
   Verkehrsmittel(std::string const &name) : _name{name}{}
   Verkehrsmittel(Verkehrsmittel const &verkehrsmittel) : _name{"Kopie von "+verkehrsmittel._name}, Vektor(verkehrsmittel._position.x,verkehrsmittel._position.y){
      std::cout << "Kopiere Verkehrsmittel ("+_name+")"<<std::endl;
            std::cout<<verkehrsmittel._position.x<<std::endl;
   }
   std::string const &name() const
   {
      return _name;
   }
   Vektor const &position() const
   {
      return _position;
   }
   ~Verkehrsmittel()
   {
      //delete &_position;       //was wie löschen??
      std::cout << _name <<"gelöscht" << std::endl;
   }
   void bewegeZu(Vektor const &bewegung){
      _position.x+=bewegung.x;
      _position.y+=bewegung.y;
   }
   std::string text() const
   {
      return _name + ": " + _position.text();
   }
};