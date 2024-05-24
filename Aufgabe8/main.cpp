#include "Klavier.h"
#include "Trompete.h"
#include "Orchester.h"
#include "Musikinstrument.h"
#include "Musiker.h"
#include <cstdlib>
#include <ctime>
#include <climits>
#include <iostream>
#include <string>
using namespace std;

Musikinstrument* musikinstrumentErzeugen() {
	Musikinstrument* musikinstrument;
	int r = rand()%3;
	switch(r) {
		case 0:
			musikinstrument = new Klavier();
			break;
		case 1:
			musikinstrument = new Trompete();
			break;
		default: 
			musikinstrument = new Musikinstrument();
			break;
	}			
	return musikinstrument;
}

void test1() {
	cout << "*** test1 ***\n";
	Musiker* musiker = new Musiker("Musiker 1");
	musiker->spielen();
	delete musiker;
	musiker = new Musiker("Musiker 2");
	musiker->weiseInstrumentZu(new Klavier());
	musiker->weiseInstrumentZu(new Trompete());
	musiker->spielen();
	delete musiker;
}

void test2() {
	cout << "*** test2 ***\n";
	srand(time(0));	
	Orchester orchester;	
	int n;
	cout << "Wieviele Musiker sollen im Orchester spielen? ";
	cin >> n;
	cin.ignore(INT_MAX,'\n');
	cout << "+++ Orchester mit " << n << " Musikern besetzen\n";
	for(int i=0; i<n; i++)
	{
		cout << "Wie heißt der " << i+1 << ". Musiker? ";
		string name;
		getline(cin,name);
		Musiker* musiker = new Musiker(name);
		orchester.hinzufuegen(musiker);
		musiker->weiseInstrumentZu(musikinstrumentErzeugen());
	}
	cout << "+++ Das Konzert beginnt\n";
	orchester.spielen();
	cout << "+++ Applaus\n";
}

int main() {
	test1();
	test2();
}
