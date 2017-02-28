#include "Layer.h"
#include <stdio.h>
#include <tchar.h>

vector<Neuron> &Layer::get_neurons_layer() 
{
	return layer_of_neurons;
}

void Layer::set_neurons_layer(const vector<Neuron> &layerOfNeurons) 
{
	Layer::layer_of_neurons = layerOfNeurons;
}

Layer::Layer(int NumberOfNeurons) 
{
	vector<Neuron> tempLayerOfNeurons;
	for (int i = 0; i < NumberOfNeurons; i++){
		Neuron newNeuron;
		tempLayerOfNeurons.push_back(newNeuron);
	}
	set_neurons_layer(tempLayerOfNeurons);
}

Layer::~Layer()
{
}
