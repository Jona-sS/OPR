// #ifndef Person
// #define Person
#pragma once
// #include "Anschrift.h"
#include <string>
#include <vector>
#include <sstream>
using namespace std;
class Person
{
private:
    string _name;
    Anschrift _anschrift;
    vector<Person *> _freunde;
    bool istFreund(Person const &person) const
    {
        for (int i = 0; i < _freunde.size(); i++)
        {
            if (_freunde.at(i) == &person)
            {
                return true;
            }
        }
        return false;
    }

public:
    Person()
    {
        this->_name = "Anonymus";
        this->_anschrift = Anschrift("unbekannte Straße", "unbekannte Hausnummer", 0, "unbekannte Stadt");
    } // = default;
    Person(const string &name)
    {
        this->_name = name;
    }
    string name() const
    {
        return this->_name;
    }
    void setzeAnschrift(Anschrift neueAnschrift)
    {
        this->_anschrift = neueAnschrift;
    }
    void setzeAnschrift(string const &strasse, string const &hausnummer, int postleitzahl, string const &stadt)
    {
        this->_anschrift = Anschrift(strasse, hausnummer, postleitzahl, stadt);
    }
    Anschrift anschrift()
    {
        return this->_anschrift;
    }
    int anzahlFreunde()
    {
        return this->_freunde.size();
    }
    Person *freund(int nummer)
    {
        if (nummer >= this->_freunde.size() || nummer < 0)
        {
            return nullptr;
        }
        return this->_freunde.at(nummer);
    }
    void befreunden(Person &neuerFreund)
    { // ist Freund verwenden? & nach eigener Reff prüfen
        if (!istFreund(neuerFreund)&& &neuerFreund !=this)
        {
            this->_freunde.push_back(&neuerFreund);
            neuerFreund.befreunden(*this); // befreunden() nutzen
        }
    }
    string text() const
    { // Konstante Funktion wegen Konstanten Objekt
        stringstream ss;
        ss << this->_name << endl
           << this->_anschrift.text();
        if (this->_freunde.size() == 0) // empty nutzen
        {
            ss << endl
               << "--- keine Freunde";
        }
        else
        {
            for (int i = 0; i < this->_freunde.size(); i++)
            {
                ss << endl
                   << "--- Freund: " << this->_freunde.at(i)->_name << " (" << this->_freunde.at(i) << ")";
            }
        }
        return ss.str();
    }
};
// #endif