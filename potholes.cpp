#include "potholes.h"
#include "math.h"
potholes::potholes()
{
	for (short i = 0; i<5; i++)
	{
		buffer[i] = 0;
	}
	buffer_pointer = 0;
}

void potholes::add(float number)
{
	if (buffer_pointer == 5) buffer_pointer = 0;
	buffer[buffer_pointer++] = number;
}

float potholes::get_avg()
{
	float avg = 0;
	for (short i = 0; i<5; i++)
	{
		avg += buffer[i];
	}
	avg /= 5.0;
	return avg;
}

float potholes::get_stdev()
{
	float avg = 0;
	float stdev = 0;
	for (short i = 0; i<5; i++)
	{
		avg += buffer[i];
	}
	avg /= 5.0;

	for (short i = 0; i<5; i++)
	{
		stdev += (buffer[i] - avg)*(buffer[i] - avg);
	}

	stdev /= 5.0;
	stdev = sqrt(stdev);
	return stdev;
}

