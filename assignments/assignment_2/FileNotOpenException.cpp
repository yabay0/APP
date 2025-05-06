#include "FileNotOpenException.hpp"

FileNotOpenException::FileNotOpenException(std::string prob)
  : Exception("FileNotOpenException", std::move(prob))
{}