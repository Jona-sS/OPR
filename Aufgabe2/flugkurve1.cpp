/**
 * $Author: MahrTh $
 * $Rev: 118 $
 * $Date: 2015-03-21 21:39:51 +0100 (Sa, 21. Mär 2015) $
 */
#include <iostream>
using namespace std;

struct Vektor
{
	float x;
	float y;
};
struct Koerper
{
	float masse;
	Vektor position;
	Vektor geschwindigkeit;
};
void ausgabeKoerper(const Koerper &koerper);
void ausgabeVektor(const Vektor &vektor);
Vektor mulVektor(const Vektor &EINGANGS_VEKTOR,const float MULTIPLIKATOR);
Vektor addVektor(const Vektor &vektor1,const Vektor &vektor2);
int bewegeKoerper(Koerper &koerper,const Vektor &gesamtkraft,const float dt);

int main()
{
	// Körper:
	Koerper koerper;
	koerper.masse = 10;
	koerper.position = {0, 0};
	koerper.geschwindigkeit = {10, 10};
	// Parametrierung der auf den Körper wirkende Kräfte:
	const Vektor BESCHLEUNIGUNG_GRAVITATION = {0, -9.81}; // [m/s^2]
	const float REIBUNGSKOEFFIZIENT = -5;				  // [kg/s]
	// Sorgt dafür, dass 2 Nachkommastellen angezeigt werden:
	cout << fixed;
	cout.precision(2);
	// Simulation:
	const float dt = 0.1;
	for (;;)
	{
		cout << "Position des Koerpers: ";
		ausgabeKoerper(koerper);
		cout << endl;
		// Bestimmung der Kraft
		Vektor reibungskraft = mulVektor(koerper.geschwindigkeit,
										 REIBUNGSKOEFFIZIENT);
		Vektor anziehungskraft = mulVektor(BESCHLEUNIGUNG_GRAVITATION,
										   koerper.masse);
		Vektor gesamtkraft = addVektor(reibungskraft, anziehungskraft);
		// Ermittlung der neuen Position und neuen Geschwindigkeit
		bewegeKoerper(koerper, gesamtkraft, dt);//Körper als Reff übergeben //bei Zeiger Übergabe &koerper
		if (koerper.position.y <= 0)
		{
			break;
		}
	}
}
void ausgabeKoerper(const Koerper &koerper){ //übergabe als Refferenz ist bei größeren Datentypen besser, weil weniger auf den Stack kopiert wird
	ausgabeVektor(koerper.position);
	cout << "Geschwindigkeit:"; 
	ausgabeVektor(koerper.geschwindigkeit);
}
void ausgabeVektor(const Vektor &vektor){
	cout << "(" << vektor.x << "," << vektor.y << ")" << endl;
}
Vektor mulVektor(const Vektor &EINGANGS_VEKTOR,const float MULTIPLIKATOR){
	Vektor ausgangsVektor;
	ausgangsVektor.x=EINGANGS_VEKTOR.x*MULTIPLIKATOR;
	ausgangsVektor.y=EINGANGS_VEKTOR.y*MULTIPLIKATOR;
	return ausgangsVektor;
}
Vektor addVektor(const Vektor &vektor1,const Vektor &vektor2){
	Vektor ausgangsVektor;
	ausgangsVektor.x=vektor1.x+vektor2.x;
	ausgangsVektor.y=vektor1.y+vektor2.y;
	return ausgangsVektor;
}
int bewegeKoerper(Koerper &koerper,const Vektor &gesamtkraft,const float dt){//alternativ Call by Reff(*koerper und ->)
		// Ermittlung der neuen Geschwindigkeit v=dt*a -> F=m*a -> v=dt*(F/m)
		koerper.geschwindigkeit.x += dt * (gesamtkraft.x/koerper.masse);
		koerper.geschwindigkeit.y += dt * (gesamtkraft.y/koerper.masse);

		// Ermittlung der neuen Position
		koerper.position.x += dt * koerper.geschwindigkeit.x;
		koerper.position.y += dt * koerper.geschwindigkeit.y;

		return 1;
}