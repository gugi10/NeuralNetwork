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
void Net::set_inputs(vector<double> input)
{
	for (int i = 0; i < input.size(); i++)
	{
		this->get_Layers()[0].get_NeuronsLayer()[i].set_Output(input[i]);
	}
}
void Net::set_output_for_bias(double output)
{
	for (int i = 0; i <= topology.size() - 1; i++)
	{
		this->get_Layers()[i].get_NeuronsLayer().back().set_Output(output);
	}
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
		for (unsigned int RightLayerNeuron = 0; RightLayerNeuron < this->get_Layers()[used_layer + 1].get_NeuronsLayer().size(); RightLayerNeuron++)
		{
			for (unsigned int LeftLayerNeuron = 0; LeftLayerNeuron < this->get_Layers()[used_layer].get_NeuronsLayer().size(); LeftLayerNeuron++)
			{
				singleInput = this->get_Connections()[used_layer][connectionsCounter].get_Weight()*this->get_Layers()[used_layer].get_NeuronsLayer()[LeftLayerNeuron].get_Output();
				cout << "input: " << singleInput << endl;
				this->get_Layers()[used_layer + 1].get_NeuronsLayer()[RightLayerNeuron].add_ToInput(singleInput);
				connectionsCounter++;
			}
			NewNeuronOutput = ActivationFunction(this->get_Layers()[used_layer + 1].get_NeuronsLayer()[RightLayerNeuron].get_Input());
			
			this->get_Layers()[used_layer + 1].get_NeuronsLayer()[RightLayerNeuron].set_Output(NewNeuronOutput);
			cout << "output in neuron: ";
			cout << get_Layers()[used_layer + 1].get_NeuronsLayer()[RightLayerNeuron].get_Output() << endl;
		}
	}
}

void Net::change_outputs_in_input_layer(vector<double> new_outputs)
{

}
void Net::BackPropForLastLayer()
{
	double error = 0;
	double epsilon = 0;
	int desired_output_iteration = 0;
	int desired_output = 0;
	for (auto &neuron : this->get_Layers().back().get_NeuronsLayer())
	{
		error = (desired_output - neuron.get_Output())*neuron.CalculateDerivative();
		cout << "Error" << error << endl;
		neuron.add_SquaredError(error);
		desired_output_iteration;
	}

}
void Net::BackpropForHiddenLayers()
{
	double epsilon = 0;
	const int bias = 1;
	double error = 0;
	int connection_counter = 0;
	int connection_counter_2dim = 0;

		for (int current_layer = int(topology.size() - 2); current_layer > 0; current_layer--)
		{
			for (int current_layer_neuron = 0; current_layer_neuron < topology[current_layer] + bias; current_layer_neuron++)
			{
				connection_counter = current_layer_neuron;
				epsilon = 0;
				for (int right_layer_neuron = 0; right_layer_neuron < topology[current_layer + 1]; right_layer_neuron++)
				{
				
					epsilon = epsilon + this->get_Layers()[current_layer + 1].get_NeuronsLayer()[right_layer_neuron].get_SquaredError() * this->get_Connections()[connection_counter_2dim][connection_counter].get_Weight();
					connection_counter = connection_counter + topology[current_layer] + bias;
				}
				error = epsilon * this->get_Layers()[current_layer].get_NeuronsLayer()[current_layer_neuron].CalculateDerivative();
				cout << "Squared error for back prop: "<<error << endl;
				this->get_Layers()[current_layer].get_NeuronsLayer()[current_layer_neuron].add_SquaredError(error);
			}
			connection_counter_2dim++;
		}


}
/*void Net::update_weights()
{
	const int bias = 1;
	double new_weight = 0;
	int connections_counter = 0;
	int connection_counter_2dim = int(this->get_Connections().size());
	for (int current_layer = int(this->get_Layers().size() - 1); current_layer > 0; current_layer--)
	{
		connections_counter = 0;
		for (int current_layer_neuron = 0; current_layer_neuron < topology[current_layer]; current_layer_neuron++)
		{
			for (int left_layer_neuron = 0; left_layer_neuron < topology[current_layer - 1] + bias; left_layer_neuron++)
			{
				new_weight = this->get_Connections()[connection_counter_2dim][connections_counter] + 2 * learning_rate;
				
			}

		}
	}
}*/

void Net::set_Layers( vector<Layer>tempLayerVector)
{
	this->layer = tempLayerVector;
}
void Net::create_Layers()
{
	vector<Layer> tempLayerVector;
	int layerCount = 0;
	Layer inputLayer(topology[layerCount] + bias);
	tempLayerVector.push_back(inputLayer);
	
	for (unsigned int i = 0; i < (topology.size() - inputPlusOutputLayer); i++)
	{
		layerCount++;
		Layer hiddenLayer(topology[layerCount] + bias);
		tempLayerVector.push_back(hiddenLayer);
	}
	layerCount++;
	Layer outputLayer(topology[layerCount]);
	tempLayerVector.push_back(outputLayer);
	set_Layers(tempLayerVector);
	
}
void Net::create_Connections()
{
	
	vector < vector<Connections>> tempConnectionVector;
	int bias2 = 1;

	
	for (unsigned int numberOfConnections = 0; numberOfConnections < topology.size()-1; numberOfConnections++) {
		vector<Connections> connectionVector;
		if (numberOfConnections == topology.size() - 2)
		{
			bias2 = 0;
		}
		for (int i = 0; i < (topology[numberOfConnections] + bias) * (topology[numberOfConnections+1]+bias2); i++) {
		
			random_device rd;
			mt19937 eng(rd());
			uniform_int_distribution<int> distr(-10, 10);
			double randomWeight = distr(eng);
			randomWeight = randomWeight / 10;
			cout <<"Random weight:"<< randomWeight<<" "<<i+1 << endl;
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
