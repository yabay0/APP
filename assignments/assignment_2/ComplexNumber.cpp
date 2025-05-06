#include "ComplexNumber.hpp"
#include <cmath>

ComplexNumber::ComplexNumber()
    : mRealPart(0.0), mImaginaryPart(0.0)
{
}

ComplexNumber::ComplexNumber(double x, double y)
    : mRealPart(x), mImaginaryPart(y)
{
}

ComplexNumber::ComplexNumber(double real)
    : mRealPart(real), mImaginaryPart(0.0)
{
}

ComplexNumber::ComplexNumber(const ComplexNumber& z)
    : mRealPart(z.mRealPart), mImaginaryPart(z.mImaginaryPart)
{
}

ComplexNumber& ComplexNumber::operator=(const ComplexNumber& z)
{
    if (this != &z) {
        mRealPart      = z.mRealPart;
        mImaginaryPart = z.mImaginaryPart;
    }
    return *this;
}

double ComplexNumber::GetRealPart() const
{
    return mRealPart;
}

double ComplexNumber::GetImaginaryPart() const
{
    return mImaginaryPart;
}

double RealPart(const ComplexNumber& z)
{
    return z.mRealPart;
}

double ImaginaryPart(const ComplexNumber& z)
{
    return z.mImaginaryPart;
}

double ComplexNumber::CalculateModulus() const
{
    return std::sqrt(mRealPart * mRealPart + mImaginaryPart * mImaginaryPart);
}

double ComplexNumber::CalculateArgument() const
{
    return std::atan2(mImaginaryPart, mRealPart);
}

ComplexNumber ComplexNumber::CalculatePower(double n) const
{
    double r     = CalculateModulus();
    double theta = CalculateArgument();
    double rn    = std::pow(r, n);
    double angle = theta * n;
    return ComplexNumber(rn * std::cos(angle), rn * std::sin(angle));
}

ComplexNumber ComplexNumber::operator-() const
{
    return ComplexNumber(-mRealPart, -mImaginaryPart);
}

ComplexNumber ComplexNumber::operator+(const ComplexNumber& z) const
{
    return ComplexNumber(mRealPart + z.mRealPart,
                         mImaginaryPart + z.mImaginaryPart);
}

ComplexNumber ComplexNumber::operator-(const ComplexNumber& z) const
{
    return ComplexNumber(mRealPart - z.mRealPart,
                         mImaginaryPart - z.mImaginaryPart);
}

ComplexNumber ComplexNumber::operator*(const ComplexNumber& z) const
{
    return ComplexNumber(
        mRealPart * z.mRealPart - mImaginaryPart * z.mImaginaryPart,
        mRealPart * z.mImaginaryPart + mImaginaryPart * z.mRealPart
    );
}

ComplexNumber ComplexNumber::CalculateConjugate() const
{
    return ComplexNumber(mRealPart, -mImaginaryPart);
}

void ComplexNumber::SetConjugate()
{
    mImaginaryPart = -mImaginaryPart;
}

std::ostream& operator<<(std::ostream& output, const ComplexNumber& z)
{
    output << '(' << z.mRealPart;
    if (z.mImaginaryPart >= 0)
        output << '+';
    output << z.mImaginaryPart << 'i' << ')';
    return output;
}