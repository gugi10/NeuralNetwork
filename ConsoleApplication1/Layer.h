#pragma once
#include <iostream>
#include <vector>
#include "Neuron.h"
using namespace std;

class Layer {
private:
	vector<Neuron> layerOfNeurons;
public:
	Layer(int);

	vector<Neuron> &get_NeuronsLayer();

	void set_NeuronsLayer(const vector<Neuron> &neuronsLayer);

	virtual ~Layer();
};



