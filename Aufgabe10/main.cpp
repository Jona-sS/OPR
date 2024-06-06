/**
 * OPR-Praktikum SS 2013
 * Aufgabe 8
 * @author Thomas Mahr
 */

#include "audio.h"
#include <chrono>
#include <iostream>
using namespace std;
/*
void tauschePerKopie(Audio& a1, Audio& a2) //alt ohne Operator
{
	Audio::log("tauschePerKopie(Audio& a1, Audio& a2)\n");
	Audio tmp = a1;
	a1.zuweisung(a2);
	a2.zuweisung(tmp);
}
*/
void tauschePerKopie(Audio &a1, Audio &a2)
{
	Audio::log("tauschePerKopie(Audio& a1, Audio& a2)\n");
	Audio tmp = a1; // Aufruf des Überladenen Pointers
	a1 = a2;
	a2 = tmp;
}
void tauschePerVerschiebung(Audio &a1, Audio &a2){
	Audio::log("tauschePerKopie(Audio& a1, Audio& a2)\n");
	Audio tmp;
	tmp << a1; // Aufruf des Überladenen Pointers
	a1 << a2;
	a2 << tmp;
}
void testVerketteteZuweisung()
{
	cout << "---- testVerketteteZuweisung()\n";
	Audio::aktiviereKonsolenausgabe = true;
	const unsigned int N = 10;
	Audio a1;
	Audio a2;
	Audio *a3 = Audio::erzeugeRauschSignal(N);
	cout << "a1 = " << a1.text() << endl;
	cout << "a2 = " << a2.text() << endl;
	cout << "a3 = " << a3->text() << endl;
	a1 = a2 = *a3;
	cout << "a1 = " << a1.text() << endl;
	cout << "a2 = " << a2.text() << endl;
	cout << "a3 = " << a3->text() << endl;
	delete a3;
}

void testFunktionTauschePerKopie()
{
	cout << "---- testFunktionTauschePerKopie()\n";

	Audio::aktiviereKonsolenausgabe = true;

	const unsigned int N = 10;

	Audio *a1 = Audio::erzeugeRauschSignal(N);
	Audio *a2 = Audio::erzeugeRauschSignal(N);

	cout << "a1 = " << a1->text() << endl;
	cout << "a2 = " << a2->text() << endl;
	tauschePerKopie(*a1, *a2);
	cout << "a1 = " << a1->text() << endl;
	cout << "a2 = " << a2->text() << endl;

	delete a1;
	delete a2;
}

void testGeschwindigkeitTauschePerKopie()
{
	cout << "---- testGeschwindigkeitTauschePerKopie()\n";
	Audio::aktiviereKonsolenausgabe = false;

	const unsigned int N = 10000;
	const int ANZAHL_SCHLEIFEN = 10000;

	Audio *a1 = Audio::erzeugeRauschSignal(N);
	Audio *a2 = Audio::erzeugeRauschSignal(N);

	// C++ 11 Zeitmessung (bei Compiler-Problemen durch C-Zeitmessung ersetzen (siehe Skript))
	auto anfang = std::chrono::system_clock::now();
	for (int i = 0; i < ANZAHL_SCHLEIFEN; i++)
	{
		tauschePerKopie(*a1, *a2);
	}
	auto ende = std::chrono::system_clock::now();
	cout << "tauschePerKopie: " << std::chrono::nanoseconds(ende - anfang).count() / ANZAHL_SCHLEIFEN << " ns\n";

	delete a1;
	delete a2;
}
void testFunktionTauschePerVerschiebung()
{
	cout << "---- testFunktionTauschePerVerschiebung()\n";

	Audio::aktiviereKonsolenausgabe = true;

	const unsigned int N = 10;

	Audio *a1 = Audio::erzeugeRauschSignal(N);
	Audio *a2 = Audio::erzeugeRauschSignal(N);

	cout << "a1 = " << a1->text() << endl;
	cout << "a2 = " << a2->text() << endl;
	// tauschePerKopie(*a1, *a2);
	tauschePerVerschiebung(*a1, *a2);
	cout << "a1 = " << a1->text() << endl;
	cout << "a2 = " << a2->text() << endl;

	delete a1;
	delete a2;
}
void testGeschwindigkeitTauschePerVerschiebung()
{
	cout << "---- testGeschwindigkeitTauschePerVerschiebung()\n";
	Audio::aktiviereKonsolenausgabe = false;

	const unsigned int N = 10000;
	const int ANZAHL_SCHLEIFEN = 10000;

	Audio *a1 = Audio::erzeugeRauschSignal(N);
	Audio *a2 = Audio::erzeugeRauschSignal(N);

	// C++ 11 Zeitmessung (bei Compiler-Problemen durch C-Zeitmessung ersetzen (siehe Skript))
	auto anfang = std::chrono::system_clock::now();
	for (int i = 0; i < ANZAHL_SCHLEIFEN; i++)
	{
		// tauschePerKopie(*a1, *a2);
		tauschePerVerschiebung(*a1, *a2);
	}
	auto ende = std::chrono::system_clock::now();
	cout << "tauschePerVerschiebung: " << std::chrono::nanoseconds(ende - anfang).count() / ANZAHL_SCHLEIFEN << " ns\n";

	delete a1;
	delete a2;
}

int main()
{
	testVerketteteZuweisung();
	testFunktionTauschePerKopie();
	testFunktionTauschePerVerschiebung();
	testGeschwindigkeitTauschePerKopie();
	testGeschwindigkeitTauschePerVerschiebung();
}