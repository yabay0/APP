#include "GraduateStudent.hpp"

GraduateStudent::GraduateStudent()
  : Student(),
    fullTime(true)
{}

GraduateStudent::GraduateStudent(std::string name,
                                 double fines,
                                 double fees,
                                 bool fullTime_)
  : Student(std::move(name), fines, fees),
    fullTime(fullTime_)
{}

double GraduateStudent::MoneyOwed() const {
    return GetLibraryFines();
}
