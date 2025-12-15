//
// Created by 12999533 on 15/12/2025.
//

#ifndef FERRARIN_VERIFICA_TPSIT_3_OPERATOR_H
#define FERRARIN_VERIFICA_TPSIT_3_OPERATOR_H
#include <string>
using namespace std;

class Operator {
    public:
    Operator();
    virtual string Print() = 0;
    float Calculate();
};


#endif //FERRARIN_VERIFICA_TPSIT_3_OPERATOR_H