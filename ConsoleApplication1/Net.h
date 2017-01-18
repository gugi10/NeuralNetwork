#include <iostream>
#include <vector>
#include "Connections.h"
#include "Layer.h"
#include "Neuron.h"
#include <cstdlib>
#include <ctime>
#include <random>
#include <cmath>
using namespace std;

class Net
{
private:
	int bias = 1;
	const double BETA = 1;
	const int inputPlusOutputLayer = 2;
	vector<int> topology;
	vector<Layer> layer;
	vector<vector<Connections>> connections;
public:	
	Net(vector<int> topology);
	void create_Layers();
	void set_Layers( vector<Layer> tempVectorLayer);
	void create_Connections();
	void set_Connections( vector<vector<Connections>> &t_connectionVector);

	double ActivationFunction(double NeuronOutput);
	
	

	void feed_Forward();
	void BackPropForLastLayer();
	void BackpropForHiddenLayers();
	vector<vector<Connections>> &get_Connections();
	vector<Layer> &get_Layers();
	~Net();
};

