#include "calccost.h"

double calcCostByKilpMetre(int kiloMetre)
{
	double result = 0;
	if (kiloMetre > 0) {
		result = 6;
		if (kiloMetre > 2) {
			result += 0.8 * (kiloMetre - 2);
			if (kiloMetre > 8)
				result += 0.8 * 0.5 * (kiloMetre - 8);
		}
	}
	return result;
}

double calcCostByMinutes(int minutes)
{
	double result = 0;
	if (minutes > 0) {
		result = 0.25 * minutes;
	}
	return result;
}

int calcCost(int kiloMetre, int minutes)
{
	return int(calcCostByKilpMetre(kiloMetre) + calcCostByMinutes(minutes) + 0.5);
}
