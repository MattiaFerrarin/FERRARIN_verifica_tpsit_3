//
// Created by 12999533 on 15/12/2025.
//

#include "Fraction.h"
using namespace std;

Fraction::Fraction() {
    _numerator = 1;
    _denominator = 1;
}

Fraction::Fraction(int numerator, int denominator) {
    if (denominator == 0) {
        return;
    }
    _numerator = numerator;
    _denominator = denominator;
}

Fraction::Fraction(Fraction &fraction) {
    if (fraction._denominator == 0) {
        return;
    }
    _numerator = fraction._numerator;
    _denominator = fraction._denominator;
}

bool Fraction::Set(int numerator, int denominator) {
    if (denominator == 0) {
        return false;
    }
    _numerator = numerator;
    _denominator = denominator;
    return true;
}

string Fraction::Print(){
    return to_string(_numerator) + "/" + to_string(_denominator);
}

float Fraction::RealValue() {
    return _numerator/_denominator;
}

int Fraction::mcd(int den1, int den2) {
    if (den2 > den1) {
        int temp = den1;
        den1 = den2;
        den2 = temp;
    }
    int mcd = 1;
    while (den2 != 0) {
        int temp = den2;
        den2 = den1 % den2;
        den1 = temp;
    }
    mcd = den1;
    return mcd;
}

Fraction Fraction::Simplify() {
    int mcd = Fraction::mcd(_numerator, _denominator);
    return Fraction(_numerator/mcd, _denominator/mcd);
}


Fraction Fraction::operator+(Fraction fraction) {
    return Fraction(_numerator*fraction._denominator + fraction._numerator*_denominator, _denominator*fraction._denominator).Simplify();
}

Fraction Fraction::operator*(Fraction fraction) {
    return Fraction(_numerator*fraction._numerator, _denominator*fraction._denominator).Simplify();
}

Fraction Fraction::operator-(Fraction fraction) {
    return Fraction(_numerator*fraction._denominator - fraction._numerator*_denominator, _denominator*fraction._denominator).Simplify();
}

Fraction Fraction::operator/(Fraction fraction) {
    return Fraction(_numerator*fraction._denominator, _denominator*fraction._numerator).Simplify();
}

int Fraction::compareFractions(int num1, int den1, int num2, int den2) {
    bool isFirstGreater = true;
    if (den2 > den1) {
        isFirstGreater = false;
    }
    if (isFirstGreater) {
        int factor = den1/den2;
        den2 *= factor;
        num2 *= factor;
    }else {
        int factor = den2/den1;
        den1 *= factor;
        num1 *= factor;
    }
    if (num1 > num2) {
        return 1;
    }
    if (num1 == num2) {
        return 0;
    }
    if (num1 < num2) {
        return -1;
    }
}

bool Fraction::operator>(Fraction fraction) {
    return (Fraction::compareFractions(_numerator, _denominator, fraction._numerator, fraction._denominator) == 1);
}

bool Fraction::operator<(Fraction fraction) {
    return (Fraction::compareFractions(_numerator, _denominator, fraction._numerator, fraction._denominator) == -1);
}

bool Fraction::operator==(Fraction fraction) {
    return (Fraction::compareFractions(_numerator, _denominator, fraction._numerator, fraction._denominator) == 0);
}

bool Fraction::operator!=(Fraction fraction) {
    return (Fraction::compareFractions(_numerator, _denominator, fraction._numerator, fraction._denominator) != 0);
}

bool Fraction::operator>=(Fraction fraction) {
    return (Fraction::compareFractions(_numerator, _denominator, fraction._numerator, fraction._denominator) == 1  ||  Fraction::compareFractions(_numerator, _denominator, fraction._numerator, fraction._denominator) == 0);
}

bool Fraction::operator<=(Fraction fraction) {
    return (Fraction::compareFractions(_numerator, _denominator, fraction._numerator, fraction._denominator) == -1  ||  Fraction::compareFractions(_numerator, _denominator, fraction._numerator, fraction._denominator) == 0);
}