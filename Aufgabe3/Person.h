//#ifndef Person
//#define Person
#pragma once
//#include "Anschrift.h"
#include <string> 
#include <vector>
#include <sstream>
using namespace std;
class Person{
    private:
    string _name;
    Anschrift _anschrift;
    vector<Person*> _freunde;
    bool istFreund(Person const& person){
        for(int i = 0;i<_freunde.size();i++){
            if(_freunde.at(i)==&person){
                return 1;
            }
        }
        return 0;
    }
    public:
    Person(){
        _name = "Anonymus";
        this->_anschrift=Anschrift("unbekannte Straße", "unbekannte Hausnummer", 0, "unbekannte Stadt");   
    }// = default;
    Person (const string& name){
       _name= name;
    }
    string name(){
        return this->_name;
    }
    void setzeAnschrift(Anschrift neueAnschrift){
        this->_anschrift=neueAnschrift;
    }
    void setzeAnschrift(string const& strasse, string const& hausnummer, int postleitzahl, string const& stadt){
        this->_anschrift=Anschrift(strasse, hausnummer, postleitzahl, stadt);
    }
    Anschrift anschrift(){
        return this->_anschrift;
    }
    int anzahlFreunde(){
        return _freunde.size();
    }
    Person* freund(int nummer){
        if(nummer>=_freunde.size()||nummer<0){
            return nullptr;
        }
        return _freunde.at(nummer);
    }
    void befreunden(Person& neuerFreund){
        _freunde.push_back(&neuerFreund);
        neuerFreund._freunde.push_back(this);
    }
   string text()const{//Konstante Funktion wegen Konstanten Objekt
        stringstream ss;
        ss << this->_name << endl << this->_anschrift.text();
        if(_freunde.size()==0){
            ss << endl <<"--- keine Freunde"; 
        }else{
            for(int i = 0; i<_freunde.size();i++){
                ss << endl <<"--- Freund: " << _freunde.at(i)->_name << " ("<<_freunde.at(i) <<")"; 
            }
        }
        return ss.str();
   }
};
//#endif