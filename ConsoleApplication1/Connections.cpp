#include "Connections.h"
#include <stdio.h>
#include <tchar.h>


Connections::Connections(double randomWeight)
{
	this->weight = randomWeight;
}

double Connections::get_weight() const
{
	return weight;
}

void Connections::set_weight(double weight)
{
	Connections::weight = weight;
}


Connections::~Connections() {}
