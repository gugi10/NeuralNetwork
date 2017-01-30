#include <iostream>
#include "Net.h"
#include <vector>
#include <stdio.h>
#include <tchar.h>
using namespace std;
int main() {
	vector<int> Topology;
	Topology.push_back(2);
	Topology.push_back(2);
	Topology.push_back(1);

	Net net(Topology);

	/*cout << "number of connetion 1: " << net.get_Connections()[0].size() << endl;
	cout << "number of connetion 2: " << net.get_Connections()[1].size() << endl;
	cout << "number of neurons 1: " << net.get_Layers()[0].get_NeuronsLayer().size() << endl;
	cout << "number of neurons 1: " << net.get_Layers()[1].get_NeuronsLayer().size() << endl;
	cout << "number of neurons 1: " << net.get_Layers()[2].get_NeuronsLayer().size() << endl;*/


	vector<double> first = { 1,1 };
	vector<double> second = { 0,1,1 };
	vector<double> third = { 1,0,1 };
	vector<double> fourth = { 0,0,1 };

	net.set_inputs(first);
	net.set_output_for_bias(1);
	net.feed_Forward();
	net.BackPropForLastLayer();
	net.BackpropForHiddenLayers();

	return 0;
}