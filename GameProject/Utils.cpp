#include "Utils.h"
#include <cmath>

bool IsEqual(float x, float y)
{
	return fabsf(x - y) < EPSILON;
}

bool IsGreaterThenOrEqual(float x, float y)
{
	return x > y || IsEqual(x, y);
}

bool IsLessThenOrEqual(float x, float y)
{
	return x < y || IsEqual(x, y);
}