#include "Neuron.h"
#include <stdio.h>
#include <tchar.h>


Neuron::Neuron()
{
	input = 0;
	output = 0;
	propageted_error = 0;

}
double Neuron::get_input() const
{
	return input;
}
void Neuron::set_input(double input)
{
	Neuron::input = input;
}
double Neuron::get_output() const
{
	
	return output;
}
void Neuron::set_output(double output)
{
	Neuron::output = output;
}

double Neuron::get_propagated_error() const
{
	return propageted_error;
}
void Neuron::set_propagated_error(double squaredError)
{
	Neuron::propageted_error = squaredError;
}
void Neuron::add_propagated_error(double error)
{
	this->Neuron::propageted_error = this->Neuron::propageted_error + error;
}

void Neuron::add_input(double newValue)
{
	this->input = this->input + newValue;
}
#define fp(x) exp(x)/pow((1+exp(x)),2)
double Neuron::calculate_derivative()
{
	return fp(output);
}

Neuron::~Neuron()
{
}
