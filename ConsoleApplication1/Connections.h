#pragma once
#include <iostream>

using namespace std;

class Connections
{
	private:
		double weight;
		
	public:
		Connections(double random_weight);

		double get_weight() const;

		void set_weight(double weight);


		virtual ~Connections();
	};
