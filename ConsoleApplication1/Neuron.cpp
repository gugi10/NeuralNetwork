#include "Neuron.h"
#include <stdio.h>
#include <tchar.h>


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
void Neuron::add_SquaredError(double error)
{
	this->Neuron::squaredError = this->Neuron::squaredError + error;
}

void Neuron::add_ToInput(double newValue)
{
	this->input = this->input + newValue;
}
double Neuron::CalculateDerivative()
{
	return input*(1 - input);
}

Neuron::~Neuron()
{
}
