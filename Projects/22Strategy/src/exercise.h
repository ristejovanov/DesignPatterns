#pragma once

#include <iostream>
#include <vector>
#include <complex>
#include <tuple>
using namespace std;

struct DiscriminantStrategy
{
  virtual double calculate_discriminant(double a, double b, double c) = 0;
};

struct OrdinaryDiscriminantStrategy : DiscriminantStrategy
{
  // todo
};

struct RealDiscriminantStrategy : DiscriminantStrategy
{
  // todo
};

class QuadraticEquationSolver
{
  DiscriminantStrategy& strategy;
public:
  QuadraticEquationSolver(DiscriminantStrategy& strategy) : strategy(strategy) {}

  tuple<complex<double>, complex<double>> solve(double a, double b, double c)
  {
    // todo
  }
};