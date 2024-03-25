//einfaches Programm mit verschiedenen Fehlerfällen (auskommentiert)
#include <iostream>
using namespace std;

#define zweiteZahl "a"
#define quadriert(z) z*z //fehlende Klammern sorgen bei Ersetzung von mit einer Formel für flasches Ergebnis


int rechnen();
//#include "linkfehler.h"

//#include "mat.h"

int main(){
    int zahl =4;
    int zahlen[3];

    //Präprozessorfehler: (Fehlverhalten nach Textersetzung)
    //zahl=zweiteZahl;    //unpassender Datentyp nach Textersetzung
    //zahl=quadriert(2+1);
    //zahl=pow(4,2);      //alternativ: bib falsch

    //Compilerfehler: (Syntaxfehler, in Programmiersprache nicht definierter Ausdruck)
    //zahl = zahlen.3;

    //Assembler:        mit "g++ -S fehlerfaelle.cpp" Assembler-Code erzeugen

    //Linkerfehler:     mit "g++ linkfehler.o fehlerfaelle.o -o fehlerfaelle.exe" linken -> fehler wenn linkfehler.o nicht gefunden wird
    //zahlen[0]=rechnen();

    //Laufzeitfehler: (Diffison durch 0 oder Zugriff auf nicht existierendes Element->unvorhersebares Ergebnis oder Enlosschleife)
    //zahl=3/0;
    //zahlen[5]=zahl;
    //while (1);
    
    cout << "Hallo " << zahl << endl;
}