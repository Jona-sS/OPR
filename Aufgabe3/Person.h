#ifndef Person
//#define Person
#pragma Person
#include "Anschrift.h"
#include <vector>
#include <iostream>
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
    Person (){//Standartkonstruktor

    }
    Person (string const& name){
       this->_name= _name;
    }
    string name(){
        return this->_name;
    }
    void setzeAnschrift(Anschrift anschrift){
        this->_anschrift=anschrift;
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
        //return _freunde[nummer];
        return _freunde.at(nummer);
    }
    void befreunden(Person& neuerFreund){
        _freunde.push_back(&neuerFreund);
    }
   string text()const{//Konstante Funktion wegen Konstanten Objekt
        cout << this->_name << endl; 
        this->_anschrift.text();
        if(_freunde.size()==0){
            cout << "--- keine Freunde" << endl; 
        }else{
            for(int i = 0; i<_freunde.size();i++){
                cout << "--- Freund: " << _freunde.at(i)->text() <<endl; 
            }
        }
        //return ; String returnen und nicht ausgeben!
   }
};
#endif