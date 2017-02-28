#pragma once
#include <iostream>


class Neuron
{
private:

	double input;
	double output;
	double propageted_error;


public:
	Neuron();

	double get_input() const;
	void set_input(double input);
	double get_output() const;
	void set_output(double output);
	double get_propagated_error() const;
	void set_propagated_error(double propageted_error);
	void add_propagated_error(double error);
	void add_input(double newValue);
	double calculate_derivative();



	virtual ~Neuron();
	

};

