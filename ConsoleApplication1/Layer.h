#include <iostream>
#include <vector>
#include "Neuron.h"
using namespace std;


class Layer {
private:
	vector<Neuron> layer_of_neurons;
public:
	Layer(int);

	vector<Neuron> &get_neurons_layer();

	void set_neurons_layer(const vector<Neuron> &neuronsLayer);

	virtual ~Layer();
};



