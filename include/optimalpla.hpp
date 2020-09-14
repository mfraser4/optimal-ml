/**
 * @file optimalpla.hpp
 * @author Mark Fraser (markfraser2015@yahoo.com)
 * @brief TODO
 * @version 0.1
 * @date 2020-09-13
 *
 * @copyright Copyright (c) 2020
 *
 */

#ifndef __OPTIMALPLA_HPP__
#define __OPTIMALPLA_HPP__

#include "perceptron.hpp"

/**
 * @brief Optimal Perceptron Learning Algorithm
 *
 * Provides an API for creating and training a PLA instance.
 */
class OptimalPla
{
private:
    Perceptron perceptron;
public:
    OptimalPla(Perceptron p);
    ~OptimalPla();
};


#endif /* __OPTIMALPLA_HPP__ */