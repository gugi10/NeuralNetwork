#include "Layer.h"
#include <stdio.h>
#include <tchar.h>

vector<Neuron> &Layer::get_NeuronsLayer() 
{
	return layerOfNeurons;
}

void Layer::set_NeuronsLayer(const vector<Neuron> &layerOfNeurons) 
{
	Layer::layerOfNeurons = layerOfNeurons;
}

Layer::Layer(int NumberOfNeurons) 
{
	vector<Neuron> tempLayerOfNeurons;
	for (int i = 0; i < NumberOfNeurons; i++){
		Neuron newNeuron;
		tempLayerOfNeurons.push_back(newNeuron);
	}
	set_NeuronsLayer(tempLayerOfNeurons);
}

Layer::~Layer()
{
}
