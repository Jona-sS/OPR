#ifndef Anschrift
#define Anschrift
#include <iostream>
using namespace std;

class Anschrift
{
//private:
public:
    string _strasse;
    string _hausnummer;
    int _postleitzahl;
    string _stadt;

//public:
    Anschrift(){ // Konstruktor
    }
    Anschrift(string const& strasse, string const& hausnummer, int postleitzahl, string const &stadt)
    { // Überladen
        this->_strasse = _strasse;
        this->_hausnummer = _hausnummer;
        this->_postleitzahl = _postleitzahl;
        this->_stadt = _stadt;
    }
    string text() const
    {
        cout << "--- wohnhaft in " << this->_postleitzahl << " " << this->_stadt << ", " << this->_strasse << " " <<this->_hausnummer<<  endl;
        //return "--- wohnhaft in " << this->_postleitzahl << " " << this->_stadt << ", " << this->_strasse << " " <<this->_hausnummer;
    }
};
#endif