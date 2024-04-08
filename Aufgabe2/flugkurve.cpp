/**
* $Author: MahrTh $
* $Rev: 118 $
* $Date: 2015-03-21 21:39:51 +0100 (Sa, 21. Mär 2015) $
*/
#include <iostream>
using namespace std;

int main() {
	// Körper:
	float masse = 10; // [kg]
	float xPosition = 0; // [m]
	float yPosition = 0; // [m]
	float xGeschwindigkeit = 10; // [m/s]
	float yGeschwindigkeit = 10; // [m/s]

	// Parametrierung der auf den Körper wirkende Kräfte:
	const float X_BESCHLEUNIGUNG_GRAVITATION = 0; // [m/s^2]
	const float Y_BESCHLEUNIGUNG_GRAVITATION = -9.81; // [m/s^2]
	const float REIBUNGSKOEFFIZIENT = -5; // [kg/s]
	
	// Sorgt dafür, dass 2 Nachkommastellen angezeigt werden:
	cout << fixed;
	cout.precision(2);
	
	// Simulation:
	const float dt = 0.1; // [s]
	for(;;) {
		cout << "(" << xPosition << "," << yPosition << ")" << endl;		

		// Berechnung der Beschleunigung aus der Kraft
		float xBeschleunigung = xGeschwindigkeit * REIBUNGSKOEFFIZIENT / masse + X_BESCHLEUNIGUNG_GRAVITATION;
		float yBeschleunigung = yGeschwindigkeit * REIBUNGSKOEFFIZIENT / masse + Y_BESCHLEUNIGUNG_GRAVITATION;
		
		// Ermittlung der neuen Geschwindigkeit
		xGeschwindigkeit += dt * xBeschleunigung;
		yGeschwindigkeit += dt * yBeschleunigung;

		// Ermittlung der neuen Position
		xPosition += dt * xGeschwindigkeit;
		yPosition += dt * yGeschwindigkeit;
		
		if(yPosition<=0) {
			break;
		}
	}
}
