#include "MultiLayerPerceptron.h"

MultiLayerPerceptron::MultiLayerPerceptron(std::vector<int> layers, double bias /*= 1.0*/, double eta /*= 0.5*/)
{
	this->layers = layers;
	this->bias = bias;
	this->eta = eta;
	for (int i = 0; i < layers.size(); i++)
	{
		values.push_back(std::vector<double>(layers[i], 0.0));
		network.push_back(std::vector<Perceptron>());
		if (i > 0)
		{
			for (int j = 0; j < layers[i]; j++)
			{
				network[i].push_back(Perceptron(layers[i - 1], bias));
			}
		}
	}
}

void MultiLayerPerceptron::setWeights(std::vector<std::vector<std::vector<double>>> wInit)
{
	for (int i = 0; i < wInit.size(); i++)
	{
		for (int j = 0; j < wInit[i].size(); j++)
		{
			network[i + 1][j].setWeights(wInit[i][j]);
		}
	}
}

void MultiLayerPerceptron::printWeights()
{
	std::cout << std::endl;
	for (int i = 1; i < network.size(); i++)
	{
		for (int j = 0; j < layers[i]; j++)
		{
			std::cout << "Layer: " << (i + 1) << " Neuron: " << j << ": ";
			for (auto& it : network[i][j].weights)
			{
				std::cout << it << "  ";
			}
			std::cout << std::endl;
		}
	}
	std::cout << std::endl;
}

std::vector<double> MultiLayerPerceptron::run(std::vector<double> x)
{
	values[0] = x;
	for (int i = 1; i < network.size(); i++)
	{
		for (int j = 0; j < layers[i]; j++)
		{
			values[i][j] = network[i][j].run(values[i - 1]);
		}
	}
	return values.back();

}

double MultiLayerPerceptron::bp(std::vector<double> x, std::vector<double> y)
{
	return 0.0;
}