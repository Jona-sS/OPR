#include "Anschrift.h"
#include "Person.h"
#include <iostream>
#include <cassert>
using namespace std;

void log(const Person& person) {
	cout << "(" << &person << ") " << person.text() << endl; 
}

int main() {
	Person daniel("Daniel Düsentrieb");
	daniel.setzeAnschrift(Anschrift("Raketenweg", "12", 90560, "Entenhausen"));
	log(daniel);
	assert(daniel.anzahlFreunde()==0);	
	
	Person donald("Donald Duck");
	donald.setzeAnschrift("Entengasse", "3a", 90560, "Entenhausen");
	log(donald);
	assert(donald.anzahlFreunde()==0);	
	
	cout << "\nDaniel und Donald werden Freunde:\n";
	daniel.befreunden(donald);
	log(daniel);
	log(donald);
	assert(daniel.anzahlFreunde()==1);	
	assert(donald.anzahlFreunde()==1);	
	assert(daniel.freund(0)==&donald);	
	assert(donald.freund(0)==&daniel);	
	assert(daniel.freund(1)==nullptr);	
	assert(donald.freund(1)==nullptr);	

	Person person;
	cout << "\nEine geheimnisvolle Person befreundet sich mit allen anderen:\n";
	person.befreunden(daniel);
	person.befreunden(donald);
	log(person);
	
	Anschrift anschrift("Erpelhofer Str.", "12", 90560, "Entenhausen");
	cout << "\nDonald zieht um nach " << anschrift.text() << endl;
	donald.setzeAnschrift(anschrift);
	log(donald);
}
