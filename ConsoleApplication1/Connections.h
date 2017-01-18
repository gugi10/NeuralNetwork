#pragma once
#include <iostream>

using namespace std;

class Connections
{
	private:
		double weight;
		double deltaWeight;
	public:
		Connections(double randomWeight);

		double get_Weight() const;

		void set_Weight(double weight);

		double get_DeltaWeight() const;

		void set_DeltaWeight(double deltaWeight);

		virtual ~Connections();
	};
