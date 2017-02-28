#include <iostream>
#include "Net.h"
#include <vector>
#include <stdio.h>
#include <tchar.h>
#include <random>
#include <algorithm>
using namespace std;
int main() {
	vector<int> Topology;
	Topology.push_back(2);
	Topology.push_back(2);
	Topology.push_back(1);

	Net net(Topology);

	vector<double> first = { 0,0 };
	vector<double> second = { 0,1};
	vector<double> third = { 1,0};
	vector<double> fourth = { 1,1};
	vector <vector<double>> data = { first, second, third};
	vector<vector<double>> outputs = { {0}, {1}, {1}};

	double x = 0;
	double error = 100;
	vector<int> indexes;
	double squared_error = 0;
	net.set_output_for_bias(1.0);

	while (error > 0.01) {
		squared_error = 0;

		for (unsigned int i = 0; i < data.size(); i++) {
			net.set_inputs(data[i]);
			net.feed_forward();
			squared_error = squared_error + net.calculate_squared_error(outputs[i]);
			net.backprop_lastlayer(outputs[i]);
			net.backprop_hiddenlayer();
			net.update_weights();
		}
		cout << "sqr error: " << squared_error / data.size() << endl;
		error = squared_error / data.size();
	}
	int last_layer = net.get_layers().size() - 1;
	net.set_inputs(data[0]);
	net.feed_forward();
	cout << net.get_layers()[last_layer].get_neurons_layer()[0].get_output() << endl;
	net.set_inputs(data[1]);
	net.feed_forward();
	cout << net.get_layers()[last_layer].get_neurons_layer()[0].get_output() << endl;
	net.set_inputs(data[2]);
	net.feed_forward();
	cout << net.get_layers()[last_layer].get_neurons_layer()[0].get_output() << endl;
	return 0;
}