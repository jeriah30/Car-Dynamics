//
//  Input.cpp
//  Created by Jonathan Sprinkle on 9/25/19.
//  

// You can use this code as it is

#include "Input.h"

Input::Input(): MathVector(2){
}

Input::Input(double v, double deltaDot): MathVector(2){
    this->elements.at(0) = v;
    this->elements.at(1) = deltaDot;
}


double Input::getDeltaDot() const { return elements.at(1); }

double Input::getV() const { return elements.at(0); }