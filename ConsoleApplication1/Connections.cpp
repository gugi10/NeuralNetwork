#include "Connections.h"
#include <stdio.h>
#include <tchar.h>


Connections::Connections(double randomWeight)
{
	this->weight = randomWeight;
}

double Connections::get_Weight() const
{
	return weight;
}

void Connections::set_Weight(double weight)
{
	Connections::weight = weight;
}

double Connections::get_DeltaWeight() const
{
	return deltaWeight;
}

void Connections::set_DeltaWeight(double deltaWeight)
{
	Connections::deltaWeight = deltaWeight;
}

Connections::~Connections() {}
