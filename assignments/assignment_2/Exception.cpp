#include "Exception.hpp"
#include <iostream>

Exception::Exception(std::string tagString, std::string probString)
  : mTag(std::move(tagString)),
    mProblem(std::move(probString))
{}

void Exception::PrintDebug() const {
    std::cerr << "** Error (" << mTag << ") **\n"
              << "Problem: " << mProblem << "\n\n";
}