#include <iostream>
#include "Perceptron.h"
#include "MultiLayerPerceptron.h"


Perceptron* createANDGate()
{
    Perceptron* p = new Perceptron(2);
    p->setWeights({ 10, 10, -15 });
    return p;
}

Perceptron* createORGate()
{
	Perceptron* p = new Perceptron(2);
    p->setWeights({ 15, 15, -10 });
	return p;
}

Perceptron* createNANDGate()
{
	Perceptron* p = new Perceptron(2);
    p->setWeights({ -10, -10, 15 });
	return p;
}

Perceptron* createNORGate()
{
	Perceptron* p = new Perceptron(2);
	p->setWeights({ -15, -15, 10 });
	return p;
}

int main()
{
    srand(time(NULL));
    rand();

    /**
    std::cout << "\n\n--------Logic Gate Example----------------\n\n";
    Perceptron* p = new Perceptron(2);
    std::cout << "Gate: " << std::endl;
    std::cout << p->run({ 0,0 }) << std::endl;
    std::cout << p->run({ 0,1 }) << std::endl;
    std::cout << p->run({ 1,0 }) << std::endl;
    std::cout << p->run({ 1,1 }) << std::endl;
    */

    std::cout << "XOR Example" << std::endl;
    MultiLayerPerceptron* XORGate = new MultiLayerPerceptron({ 2,2,1 });
    XORGate->setWeights({ {{-10, -10, 15}, {15, 15, -10}}, {{10, 10, -15}} });
    std::cout << "Weights" << std::endl;
    XORGate->printWeights();

    std::cout << "XOR Tests:" << std::endl;
    std::cout << "0, 0 = " << XORGate->run({ 0,0 })[0] << std::endl;
    std::cout << "0, 1 = " << XORGate->run({ 0,1 })[0] << std::endl;
    std::cout << "1, 0 = " << XORGate->run({ 1,0 })[0] << std::endl;
    std::cout << "1, 1 = " << XORGate->run({ 1,1 })[0] << std::endl;
}
