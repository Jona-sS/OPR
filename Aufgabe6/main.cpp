#include "Pkw.h"
#include "Heissluftballon.h"
#include <iostream>
#include <cassert>
using namespace std;

void test01() {
	cout << "test01:\n-------\n";
	const Verkehrsmittel verkehrsmittel("Verkehrsmittel");
	const Radfahrzeug radfahrzeug("Radfahrzeug",3);
	const Pkw pkw("VW Käfer",2);
	const Luftfahrzeug luftfahrzeug("Luftfahrzeug",10000);
	const Heissluftballon heissluftballon("Heissluftballon",500, 7500);
	cout << verkehrsmittel.text() << endl;
	cout << radfahrzeug.text() << endl;
	cout << pkw.text() << endl;
	cout << luftfahrzeug.text() << endl;
	cout << heissluftballon.text() << endl;
	assert(radfahrzeug.anzahlRaeder()==3);
	assert(pkw.name()=="VW Käfer");
	assert(pkw.anzahlRaeder()==4);
	assert(pkw.anzahlTueren()==2);
	assert(heissluftballon.maxFlughoehe()==500);
	assert(heissluftballon.ballonVolumen()==7500);
}

void test02() {
	cout << "test02:\n-------\n";	
	Pkw pkw("Pkw",2);
	cout << pkw.text() << endl;
	pkw.bewegeZu(Vektor(50,60));
	cout << pkw.text() << endl;
	cout << pkw.name() << " befindet sich nach der Bewegung an Position " << pkw.position().text() << endl;
	assert(pkw.position().x==50);
	assert(pkw.position().y==60);
	Heissluftballon heissluftballon("Heissluftballon",1000, 7500);
	cout << heissluftballon.text() << endl;
	heissluftballon.bewegeZu(Vektor(70,80));
	cout << heissluftballon.name() << " befindet sich nach der Bewegung an Position " << heissluftballon.position().text() << endl;
	assert(heissluftballon.position().x==70);
	assert(heissluftballon.position().y==80);
}

void test03() {
	cout << "test03:\n-------\n";	
	Pkw pkw1("Pkw1",5);
	pkw1.bewegeZu(Vektor(77,88));
	cout << pkw1.text() << endl;	
	const Pkw pkw2 = pkw1;		//
	cout << pkw2.text() << endl;
	assert(pkw1.anzahlRaeder()==pkw2.anzahlRaeder());
	assert(pkw1.anzahlTueren()==pkw2.anzahlTueren());
	assert(pkw1.position().x==pkw2.position().x);
	assert(pkw1.position().y==pkw2.position().y);
	assert(pkw1.name()!=pkw2.name());
}

void test04() {
	cout << "test04:\n-------\n";	
	Heissluftballon ballon1("Ballon1",234,5678);
	ballon1.bewegeZu(Vektor(99,111));
	cout << ballon1.text() << endl;	
	const Heissluftballon ballon2{ballon1};
	cout << ballon2.text() << endl;
	assert(ballon1.maxFlughoehe()==ballon2.maxFlughoehe());
	assert(ballon1.ballonVolumen()==ballon2.ballonVolumen());
	assert(ballon1.position().x==ballon2.position().x);
	assert(ballon1.position().y==ballon2.position().y);
	assert(ballon1.name()!=ballon2.name());
}

int main() {
	test01();
	cout << endl;
	test02();
	cout << endl;
	test03();
	cout << endl;
	test04();
}
