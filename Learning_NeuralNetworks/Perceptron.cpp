#include "Perceptron.h"

// Return a new Perceptron object with the specified number of inputs (+1 for the bias).
Perceptron::Perceptron(int inputs, double bias)
{
	this->bias = bias;
	weights.resize(inputs + 1);
	generate(
		weights.begin(), 
		weights.end(), 
		Perceptron::frand
	);
}

// Run the Perceptron. x is a vector with the input values.
double Perceptron::run(std::vector<double> x)
{
	x.push_back(bias);
	double sum = inner_product(
		x.begin(), 
		x.end(), 
		weights.begin(), 
		(double)0.0
	);
	return sigmoid(sum);
}

// Set the weights. w_init is a vector with the weights.
void Perceptron::setWeights(std::vector<double> wInit)
{
	weights = wInit;
}

// Evaluate the sigmoid function for the floating point input x.
double Perceptron::sigmoid(double x)
{
	return 1.0 / (1.0 + exp(-x));
}