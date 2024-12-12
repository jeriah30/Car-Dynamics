#include "MathVector.h"

using namespace std;

//default contructor
//MathVector();   
//set numElements to 0, then resize the vector "elements" with numElements
MathVector::MathVector() : numElements(0) {
    elements.resize(numElements);
}

//parameterized contructor
//MathVector(int num_entered); 
//set numElements to num_entered, then resize the vector "elements" with numElements
MathVector::MathVector(int num_entered) : numElements(num_entered) {
    elements.resize(numElements > 0 ? numElements : 0);
}