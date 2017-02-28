#include "Net.h"
#include <stdio.h>
#include <tchar.h>

using namespace std;

Net::Net(vector<int> topology)
{
	this->topology = topology;
	create_connections();
	create_Layers();

}



vector<vector<Connections>> &Net::get_connections() 
{
	return connections;
}

vector<Layer> &Net::get_layers()
{
	return layer;
}
void Net::set_inputs(vector<double> new_inputs)
{
	for (unsigned int i = 0; i < new_inputs.size(); i++)
	{
		this->get_layers()[0].get_neurons_layer()[i].set_output(new_inputs[i]);
	};
}
void Net::set_output_for_bias(double output)
{
	for (unsigned int i = 0; i <= topology.size() - 1; i++)
	{
		this->get_layers()[i].get_neurons_layer().back().set_output(output);
	}
}
void Net::reset_propageted_error()
{
	for (auto &layer : this->get_layers())
	{
		for (auto &neuron : layer.get_neurons_layer())
		{
			neuron.set_propagated_error(0);
		}
	}
}

void Net::reset_inputs() {
	for (auto &layer : this->get_layers())
	{
		for (auto &neuron : layer.get_neurons_layer())
		{
			neuron.set_input(0);
		}
	}
}

void Net::feed_forward()
{
	int connections_counter = 0;
	double single_input = 0;
	double new_neuron_output = 0;
	for (unsigned int used_layer = 0; used_layer < this->get_layers().size() -1; used_layer++)
	{
		connections_counter = 0;
		if (used_layer == this->get_connections().size() - 1)
			bias = 0;
		else
			bias = 1;
		for (unsigned int right_neuron = 0; right_neuron < this->get_layers()[used_layer + 1].get_neurons_layer().size() - bias; right_neuron++)
		{
			for (unsigned int left_neuron = 0; left_neuron < this->get_layers()[used_layer].get_neurons_layer().size(); left_neuron++)
			{
				single_input = this->get_connections()[used_layer][connections_counter].get_weight()*this->get_layers()[used_layer].get_neurons_layer()[left_neuron].get_output();
				this->get_layers()[used_layer + 1].get_neurons_layer()[right_neuron].add_input(single_input);
				connections_counter++;
			}
			new_neuron_output = activation_function(this->get_layers()[used_layer + 1].get_neurons_layer()[right_neuron].get_input());
			
			this->get_layers()[used_layer + 1].get_neurons_layer()[right_neuron].set_output(new_neuron_output);
			
		}
	}
	this->reset_inputs();

}


void Net::backprop_lastlayer(vector<double> desired_output)
{
	double error = 0;

	int i = 0;
	for (auto &neuron : this->get_layers().back().get_neurons_layer())
	{
		error = (desired_output[i] - neuron.get_output())*neuron.calculate_derivative();
		neuron.add_propagated_error(error);
		i++;
	}

}
void Net::backprop_hiddenlayer()
{
	double epsilon = 0;
	double error = 0;
	int connection_counter = 0;
	int connection_counter_2dim = int(this->get_connections().size())-1;

	for (int current_layer = int(topology.size() - 2); current_layer > 0; current_layer--)
	{
		int next_layer = current_layer + 1;
		for (int current_layer_neuron = 0; current_layer_neuron < topology[current_layer] + bias; current_layer_neuron++)
		{
			connection_counter = current_layer_neuron;
			epsilon = 0;
			for (int right_layer_neuron = 0; right_layer_neuron < topology[next_layer]; right_layer_neuron++)
			{

				epsilon = epsilon + this->get_layers()[next_layer].get_neurons_layer()[right_layer_neuron].get_propagated_error() * this->get_connections()[connection_counter_2dim][connection_counter].get_weight();
				connection_counter = connection_counter + topology[current_layer] + bias;
				
			}
			
			error = epsilon * this->get_layers()[current_layer].get_neurons_layer()[current_layer_neuron].calculate_derivative();
			this->get_layers()[current_layer].get_neurons_layer()[current_layer_neuron].add_propagated_error(error);
		}
		connection_counter_2dim--;
	}
}
void Net::update_weights()
{
	
	double new_weight = 0;
	int connections_counter = 0;
	int connection_counter_2dim = int(this->get_connections().size()-1);
	for (int current_layer = int(this->get_layers().size() - 1); current_layer > 0; current_layer--)
	{
		connections_counter = 0;
		for (int current_layer_neuron = 0; current_layer_neuron < topology[current_layer]; current_layer_neuron++)
		{	
			int previous_layer = current_layer - 1;
			for (int previous_layer_neuron = 0; previous_layer_neuron < topology[previous_layer] + bias; previous_layer_neuron++)
			{
				
				new_weight = this->get_connections()[connection_counter_2dim][connections_counter].get_weight()
					+ 2 * learning_rate*this->get_layers()[current_layer].get_neurons_layer()[current_layer_neuron].get_propagated_error()
					*this->get_layers()[previous_layer].get_neurons_layer()[previous_layer_neuron].get_output();
				
				this->get_connections()[connection_counter_2dim][connections_counter].set_weight(new_weight);
				connections_counter++;
			}

		}
		connection_counter_2dim--;
	
	}
	reset_propageted_error();
}
double Net::calculate_squared_error(vector<double> desired_outputs)
{
	double squared_error = 0;
	int i = 0;
	for (auto &neuron : this->get_layers().back().get_neurons_layer()) 
	{
		squared_error = squared_error + pow((desired_outputs[i] - neuron.get_output()), 2);
		i++;
	}
	return squared_error;
}
//void Net::calculate_network()
//{
//	double error = 100;
//	double squared_error = 0;
//	double previous_error = 100;
//	double desired_output=0;
//	int input1 = 1;
//	int input2 = 1;
//	int epoch = 0;
//	int count = 0;
//	set_inputs(1,1);
//	while (epoch < 20)
//		{
//			/*if (count == 0)
//
//			{
//				set_inputs(0, 0); desired_output = 1;
//			}
//			if(count==0)
//
//			if (count == 1)
//
//			{
//				set_inputs(1, 0); desired_output = 1;
//			}
//			if (count == 2)
//
//			{
//				set_inputs(0, 1); desired_output = 1;
//			}
//			if (count == 3)
//
//			{
//				set_inputs(1, 1); desired_output = 1;
//			}*/
//			
//			set_output_for_bias(1);
//			feed_Forward();
//			//squared_error = squared_error + this->calculate_squared_error(desired_output);
//			BackPropForLastLayer(desired_output);
//			BackpropForHiddenLayers(desired_output);
//			update_weights();
//		 	cout << "Output for set number: " << count << endl;
//			get_Layers()[2].get_NeuronsLayer()[0].cout_output();
//			//error = squared_error;
//			epoch++;
//			count++;
//			if (count == 4)
//				count = 0;
//			
//		}
//	
//
//}
void Net::set_layers( vector<Layer>temp_layer_vector)
{
	this->layer = temp_layer_vector;
}
void Net::create_Layers()
{
	vector<Layer> temp_layer_vector;
	int layer_counter = 0;
	Layer input_layer(topology[layer_counter] + bias);
	temp_layer_vector.push_back(input_layer);
	
	for (unsigned int i = 0; i < (topology.size() - input_plus_output_layers); i++)
	{
		layer_counter++;
		Layer hidden_layer(topology[layer_counter] + bias);
		temp_layer_vector.push_back(hidden_layer);
	}
	layer_counter++;
	Layer output_layer(topology[layer_counter]);
	temp_layer_vector.push_back(output_layer);
	set_layers(temp_layer_vector);
	
}
void Net::create_connections()
{
	
	vector < vector<Connections>> temp_connection_vector;

	
	for (unsigned int number_of_connections = 0; number_of_connections < topology.size()-1; number_of_connections++) {
		vector<Connections> connectionVector;
		for (int i = 0; i < (topology[number_of_connections] + bias) * (topology[number_of_connections+1]); i++) {
		
			random_device rd;
			mt19937 eng(rd());
			uniform_int_distribution<int> distr(-10, 10);
			double random_weight = distr(eng);
			random_weight = random_weight / 10;
			//cout <<"Random weight:"<< randomWeight<<" "<<i+1 << endl;
			Connections newConnection(random_weight);
			connectionVector.push_back(newConnection);

		}
		temp_connection_vector.push_back(connectionVector);
	}
	set_connections(temp_connection_vector);
}
void Net::set_connections( vector<vector<Connections>> &t_connectionVector)
{
	Net::connections = t_connectionVector;
}
double Net::activation_function(double neuron_input)
{
	double new_output =  1 / (1 + exp(-1 * neuron_input));
	return new_output;
}


Net::~Net()
{
}
