#include <iostream>

#include "Fraction.h"
using namespace std;

int main() {
    Fraction f = Fraction(3, 6);
    cout << f.Print()<<endl;
    Fraction simpl = f.Simplify();
    cout << simpl.Print()<<endl;
    f.Set(2,6);
    cout << f.Print()<<endl;
    cout << (f+simpl).Print()<<endl;
    cout << (f-simpl).Print()<<endl;
    cout << (f*simpl).Print()<<endl;
    cout << (f/simpl).Print()<<endl;
    cout << (f>simpl)<<endl;
    return 0;
}