#include "Neuron.h"



Neuron::Neuron()
{
	input = 0;
	output = 0;
	squaredError = 0;
}
double Neuron::get_Input() const
{
	return input;
}
void Neuron::set_Input(double input)
{
	Neuron::input = input;
}
double Neuron::get_Output() const
{
	return output;
}
void Neuron::set_Output(double output)
{
	Neuron::output = output;
}
double Neuron::get_SquaredError() const
{
	return squaredError;
}
void Neuron::set_SquaredError(double squaredError)
{
	Neuron::squaredError = squaredError;
}

Neuron::~Neuron()
{
}
