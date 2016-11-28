#include "Net.h"
#include <vector>


using namespace std;
Net::Net(vector<int> topology)
{
	this->topology = topology;
	create_Connections();
	create_Layers();

}
void Net::set_Layers(const vector<Layer>tempLayerVector)
{
	this->layer = tempLayerVector;
}
void Net::create_Layers()
{
	vector<Layer> tempLayerVector;
	int layerCount = 0;
	Layer inputLayer(topology[layerCount]);
	tempLayerVector.push_back(inputLayer);
	for (int i = 0; i < topology.size() - inputPlusOutputLayer; i++) {
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
	for (int numberOfConnections = 0; numberOfConnections < topology.size; numberOfConnections) {
		vector<Connections> connectionVector;
		if (numberOfConnections = 0)
			bias = 0;

		else
			bias = 1;
		for (int i = 0; i < (topology[numberOfConnections] + bias) * topology[numberOfConnections+1]; i++) {
			Connections newConnection();
			connectionVector.push_back(newConnection);

		}
		tempConnectionVector.push_back(connectionVector);
	}
	set_Connections(tempConnectionVector);
}
void Net::set_Connections(const vector<vector<Connections>> &t_connectionVector) 
{
	Net::	
}
Net::~Net()
{
}
