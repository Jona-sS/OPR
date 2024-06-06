/**
 * OPR-Praktikum SS 2024
 * Aufgabe 10
 * @author Thomas Mahr
 */

#include "audio.h"
#include <cstring>
#include <iostream>
#include <random>
#include <sstream>
using namespace std;

bool Audio::aktiviereKonsolenausgabe = true;

Audio::Audio(unsigned long int laenge) : laenge(laenge)
{
	Audio::log("Audio()\n");
	amplitude = new int[laenge];  
}

Audio::Audio(const Audio& a) : laenge(a.laenge) 
{
	Audio::log("Audio(const Audio&)\n");
	amplitude = new int[laenge]; 
	memcpy(amplitude,a.amplitude,laenge*sizeof(int)); 
}

Audio::~Audio()  
{
	Audio::log("~Audio()\n");
	if(amplitude!=nullptr)   
	{
		delete[] amplitude;
	}
}
/*
void Audio::zuweisung(const Audio& a)  //durch Operator ersetzen
{
	if(this!=&a)
	{
		Audio::log("operator=(Audio&)\n");
		if(amplitude!=nullptr)  
		{
			delete[] amplitude;
		}
		laenge = a.laenge;
		amplitude = new int[laenge]; 
		memcpy(amplitude,a.amplitude,laenge*sizeof(int)); 	
	}
}
*/
Audio& Audio::operator=(const Audio& a){
	if(this!=&a)//This Pointer mit der (refferenzierten) Adresse von a Vergleichen
	{
		Audio::log("operator=(Audio&)\n");
		if(amplitude!=nullptr)  
		{
			delete[] amplitude;
		}
		laenge = a.laenge;
		amplitude = new int[laenge]; 
		memcpy(amplitude,a.amplitude,laenge*sizeof(int)); 	
	}
	return *this;//Derefferenzieren des this Pointers um Ref zurück zu geben
}
Audio& Audio::operator<<(const Audio& a){
	if(this!=&a)//This Pointer mit der (refferenzierten) Adresse von a Vergleichen
	{
		Audio::log("operator<<(Audio&)\n");
		if(amplitude!=nullptr)  
		{
			delete[] amplitude;
		}
		laenge = a.laenge;
		amplitude = new int[laenge]; 
		memcpy(amplitude,a.amplitude,laenge*sizeof(int)); 	
	}
	return *this;//Derefferenzieren des this Pointers um Ref zurück zu geben
}
std::string Audio::text() const 
{
	int i=0;
	std::stringstream s;
	for(unsigned long int x=0; x<laenge; x++) 
	{
		s << amplitude[i++] << " ";
	}
	return s.str();
}

Audio* Audio::erzeugeRauschSignal(unsigned long int laenge)
{
	Audio* audio = new Audio(laenge);
	
	// C++11 Zufallszahlengenerator (bei Compiler-Problemen durch C-Zufallszahlengenerator ersetzen)
	std::random_device seed;
	std::mt19937 engine(seed());
	
	// Erzeugt Zufallswerte zwischen -1000 und +1000
	std::uniform_int_distribution<int> dist(-1000,+1000);
	
	for(unsigned long int i=0; i<laenge; i++)
	{
		audio->amplitude[i] = dist(engine);
	}
	
	return audio;
}
