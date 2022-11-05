#pragma once
#include <algorithm>
#include <vector>
#include <iostream>
#include <random>
#include <numeric>
#include <cmath>
#include <time.h>

class Perceptron {
public:
	std::vector<double> weights;
	double bias;

	Perceptron(int inputs, double bias = 1.0);
	
	double run(std::vector<double> x);
	
	void setWeights(std::vector<double> wInit);
	
	double sigmoid(double x);

	inline static double frand()
	{
		return (2.0 * (double)rand() / RAND_MAX) - 1.0;
	}
};
