#pragma once

#include <iostream>
#include <exception>
using namespace std;

class DivByZero: public exception
{
public:
  virtual const char* what() const throw()
  {
    return "Attempted division by zero!";
  }
};
