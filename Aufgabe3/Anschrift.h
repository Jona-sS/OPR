// #ifndef Anschrift
// #define Anschrift
#pragma once
#include <string>
#include <sstream>
using namespace std;

class Anschrift
{
private:
    string _strasse;
    string _hausnummer;
    int _postleitzahl;
    string _stadt;

public:
    Anschrift() = default;
    Anschrift(const string &strasse, const string &hausnummer, int postleitzahl, const string &stadt)
    { // Überladen
        _strasse = strasse;
        this->_hausnummer = hausnummer;
        this->_postleitzahl = postleitzahl;
        this->_stadt = stadt;
    }
    string text() const
    {
        stringstream ss;
        ss << "--- wohnhaft in " << this->_postleitzahl << " " << this->_stadt << ", " << this->_strasse << " " << this->_hausnummer;
        return ss.str();
    }
};
// #endif