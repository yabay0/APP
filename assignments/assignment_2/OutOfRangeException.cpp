#include "OutOfRangeException.hpp"

OutOfRangeException::OutOfRangeException(std::string prob)
  : Exception("OutOfRangeException", std::move(prob))
{}