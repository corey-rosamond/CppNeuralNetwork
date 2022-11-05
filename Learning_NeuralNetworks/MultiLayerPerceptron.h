#pragma once
#include "Perceptron.h"
#include <algorithm>
#include <vector>
#include <iostream>
#include <random>
#include <numeric>
#include <cmath>
#include <time.h>

class MultiLayerPerceptron
{
public:
	std::vector<int> layers;

	double bias;

	double eta;

	std::vector<std::vector<Perceptron>> network;

	std::vector<std::vector<double>> values;

	std::vector<std::vector<double>> d;


	MultiLayerPerceptron(std::vector<int> layers, double bias = 1.0, double eta = 0.5);
	
	void setWeights(std::vector<std::vector<std::vector<double>>> wInit);

	void printWeights();

	std::vector<double> run(std::vector<double> x);

	double bp(std::vector<double> x, std::vector<double> y);

};

