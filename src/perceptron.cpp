#include "perceptron.hpp"

Perceptron::Perceptron(int degree) : weights { std::vector<float>(degree+1) }
{
    /* TODO: initialize weights with random distribution */
}

Perceptron::~Perceptron()
{
}

BinaryPerceptron::BinaryPerceptron(int degree) : Perceptron(degree)
{
}

BinaryPerceptron::~BinaryPerceptron()
{
}

void BinaryPerceptron::train(std::vector<std::vector<float>>)
{
    /* TODO: implement binary classification */
}