//
//  MathVector.h
//

#ifndef MathVector_h
#define MathVector_h

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class MathVector {
public:
    //default contructor
    MathVector();
    MathVector( int num_entered );


protected: //to be used with inhetied classes
    int numElements;
    vector<double> elements;
};

#endif /* MathVector_h */