#include <iostream>
#include <vector>
#include "Connections.h"
#include "Layer.h"
#include "Neuron.h"
#include <cstdlib>
#include <ctime>
#include <random>
#include <cmath>
#include <algorithm>
using namespace std;

class Net
{
private:
	int bias = 1;
	
	const int input_plus_output_layers = 2;
	vector<int> topology;
	vector<Layer> layer;
	vector<vector<Connections>> connections;
	const double learning_rate = 0.5;
public:	
	Net(vector<int> topology);
	void create_Layers();
	void set_layers( vector<Layer> tempVectorLayer);
	void create_connections();
	void reset_inputs();
	void set_connections( vector<vector<Connections>> &t_connectionVector);
	void update_weights();
	void set_inputs(vector<double> new_inputs);
	void set_output_for_bias(double output);
	void reset_propageted_error();
	double activation_function(double neuron_input);
	void feed_forward();
	void backprop_lastlayer(vector<double> desired_output);
	void backprop_hiddenlayer();
	double calculate_squared_error(vector<double> desired_outputs);
	//void calculate_network();
	vector<vector<Connections>> &get_connections();
	vector<Layer> &get_layers();
	~Net();
};

