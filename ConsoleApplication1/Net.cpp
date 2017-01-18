#include "Net.h"
#include <stdio.h>
#include <tchar.h>

using namespace std;

Net::Net(vector<int> topology)
{
	this->topology = topology;
	create_Connections();
	create_Layers();

}


vector<vector<Connections>> &Net::get_Connections() 
{
	return connections;
}

vector<Layer> &Net::get_Layers()
{
	return layer;
}
void Net::feed_Forward()
{
	int connectionsCounter = 0;
	double singleInput = 0;
	double NewNeuronOutput = 0;
	for (unsigned int used_layer = 0; used_layer <this->get_Connections().size(); used_layer++)
	{
		connectionsCounter = 0;
		if (used_layer == this->get_Connections().size() - 1)
			bias = 0;
		else
			bias = 1;
		for (unsigned int RightLayerNeuron = 0; RightLayerNeuron < this->get_Layers()[used_layer + 1].get_NeuronsLayer().size() - bias; RightLayerNeuron++)
		{
			for (unsigned int LeftLayerNeuron = 0; LeftLayerNeuron < this->get_Layers()[used_layer].get_NeuronsLayer().size(); LeftLayerNeuron++)
			{
				singleInput = this->get_Connections()[used_layer][connectionsCounter].get_Weight()*this->get_Layers()[used_layer].get_NeuronsLayer()[LeftLayerNeuron].get_Output();
				this->get_Layers()[used_layer + 1].get_NeuronsLayer()[RightLayerNeuron].add_ToInput(singleInput);
				connectionsCounter++;
			}
			NewNeuronOutput = ActivationFunction(this->get_Layers()[used_layer + 1].get_NeuronsLayer()[RightLayerNeuron].get_Output());
			this->get_Layers()[used_layer + 1].get_NeuronsLayer()[RightLayerNeuron].set_Output(NewNeuronOutput);
		}
	}
}
void Net::BackPropForLastLayer()
{
	double error = 0;
	int desired_output_iteration = 0;
	int desired_output = 1;
	for (auto &neuron : this->get_Layers().back().get_NeuronsLayer())
	{
		error = (desired_output - neuron.get_Output())*neuron.CalculateDerivative();
		neuron.add_SquaredError(error);
		desired_output_iteration++;
		
	}
}
void Net::BackpropForHiddenLayers()
{

}

void Net::set_Layers( vector<Layer>tempLayerVector)
{
	this->layer = tempLayerVector;
}
void Net::create_Layers()
{
	vector<Layer> tempLayerVector;
	int layerCount = 0;
	Layer inputLayer(topology[layerCount]);
	tempLayerVector.push_back(inputLayer);
	for (unsigned int i = 0; i < (topology.size() - inputPlusOutputLayer); i++) {
		Layer hiddenLayer(topology[layerCount] + bias);
		tempLayerVector.push_back(hiddenLayer);
		layerCount++;
	}
	layerCount++;
	Layer outputLayer(topology[layerCount]);
	tempLayerVector.push_back(outputLayer);
	set_Layers(tempLayerVector);
	
}
void Net::create_Connections()
{
	vector < vector<Connections>> tempConnectionVector;
	for (unsigned int numberOfConnections = 0; numberOfConnections < topology.size(); numberOfConnections++) {
		vector<Connections> connectionVector;
		if (numberOfConnections == 0)
			bias = 0;
		else
			bias = 1;
		for (int i = 0; i < (topology[numberOfConnections] + bias) * topology[numberOfConnections+1]; i++) {
			random_device rd;
			mt19937 eng(rd());
			uniform_int_distribution<int> distr(-10, 10);
			double randomWeight = distr(eng)/10;
			Connections newConnection(randomWeight);
			connectionVector.push_back(newConnection);

		}
		tempConnectionVector.push_back(connectionVector);
	}
	set_Connections(tempConnectionVector);
}
void Net::set_Connections( vector<vector<Connections>> &t_connectionVector) 
{
	Net::connections = t_connectionVector;
}
double Net::ActivationFunction(double NeuronOutput)
{
	return 1 / (1 + exp(-BETA * NeuronOutput));
}


Net::~Net()
{
}
