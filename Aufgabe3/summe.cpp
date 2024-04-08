#include "summe.h"

float berechneSumme(const float* const wert, int anzahlWerte)
{
	return (anzahlWerte) ? *wert+berechneSumme(wert+1, anzahlWerte-1) : 0;
}


