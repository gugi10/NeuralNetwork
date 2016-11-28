#pragma once
class Neuron
{
private:

	double input;

	double output;

	double squaredError;

public:
	Neuron();

	double get_Input() const;

	void set_Input(double input);

	double get_Output() const;

	void set_Output(double output);

	double get_SquaredError() const;

	void set_SquaredError(double squaredError);

	void increseInput() const;

	virtual ~Neuron();
	

};

