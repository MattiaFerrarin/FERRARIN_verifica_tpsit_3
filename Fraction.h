//
// Created by 12999533 on 15/12/2025.
//

#ifndef FERRARIN_VERIFICA_TPSIT_3_FRACTION_H
#define FERRARIN_VERIFICA_TPSIT_3_FRACTION_H
#include "Operator.h"
using namespace std;


class Fraction : Operator {
    private:
    int _numerator;
    int _denominator;
    int compareFractions(int num1, int den1, int num2, int den2);
    int mcd(int num, int den);
public:
    Fraction();
    Fraction(int numerator, int denominator);
    Fraction(Fraction& fraction);
    bool Set(int numerator, int denominator);
    string Print() override;
    float RealValue();
    Fraction Simplify();

    Fraction operator+(Fraction);
    Fraction operator*(Fraction);
    Fraction operator-(Fraction);
    Fraction operator/(Fraction);
    bool operator>(Fraction);
    bool operator<(Fraction);
    bool operator==(Fraction);
    bool operator!=(Fraction);
    bool operator>=(Fraction);
    bool operator<=(Fraction);
};


#endif //FERRARIN_VERIFICA_TPSIT_3_FRACTION_H