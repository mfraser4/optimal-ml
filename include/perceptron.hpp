/**
 * @file perceptron.hpp
 * @author Mark Fraser (markfraser2015@yahoo.com)
 * @brief
 * @version 0.1
 * @date 2020-09-13
 *
 * @copyright Copyright (c) 2020
 *
 */

#ifndef __PERCEPTRON_HPP__
#define __PERCEPTRON_HPP__

#include <vector>

/**
 * @brief Perceptron
 *
 * Perceptrons are a basic unit of machine learning and artificial
 * intelligence. Given a set of inputs, the perceptron will classify the data
 * using its classification function.
 *
 * NOTE: This class is a base class and does NOT implement a classification fn.
 * Sub-classes should add a classification function appropriate for its return
 * type (e.g. a continuous or discrete value).
 */
class Perceptron
{
protected:
    /**
     * @brief weights
     *
     * For the purposes of this library, using the std::vector type was decided
     * over using a math library in order to conditionally compile for multiple
     * build environments with minimal incompatibilities.
     */
    std::vector<float> weights;

public:
    Perceptron(int degree);
    ~Perceptron();

    virtual void train(std::vector<std::vector<float>>);
};

class BinaryPerceptron : public Perceptron
{
private:
    /* data */
public:
    BinaryPerceptron(int degree);
    ~BinaryPerceptron();

    void train(std::vector<std::vector<float>>);
    int classify(std::vector<float>);
};

#endif /* __PERCEPTRON_HPP__ */