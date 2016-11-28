#include "Connections.h"



Connections::Connections()
{
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
