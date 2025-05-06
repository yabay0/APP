#include "Student.hpp"
#include <stdexcept>

Student::Student()
  : name(""),
    tuition_fees(0.0),
    library_fines(0.0)
{}

Student::Student(std::string name_, double fines, double fees)
  : name(std::move(name_)),
    tuition_fees(fees),
    library_fines(0.0)
{
    if (fines < 0.0)
        throw std::invalid_argument("Fine must be positive.");
    library_fines = fines;
}

void Student::SetLibraryFines(double amount)
{
    if (amount < 0.0)
        return;
    library_fines = amount;
}

double Student::GetLibraryFines() const
{
    return library_fines;
}

double Student::MoneyOwed() const
{
    return library_fines + tuition_fees;
}