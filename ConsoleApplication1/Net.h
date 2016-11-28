#include <iostream>
#include <vector>
#include "Layer.h"
#include "Neuron.h"
#include "Connections.h"

using namespace std;

class Net
{
private:
	int bias = 1;
	const int inputPlusOutputLayer = 2;
	vector<int> topology;
	vector<Layer> layer;
public:
	Net(vector<int> topology);
	void create_Layers();
	void set_Layers(const vector<Layer> tempVectorLayer);
	void create_Connections();
	void set_Connections(const vector<vector<Connections>> &t_connectionVector);
	~Net();
};

