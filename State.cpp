#include <cmath>
#include "State.h"
using namespace std;
//State();  
//see input.cpp to implement this one BUT with number of elements = 4
//since a state is a 1-D array with 4 values: x, y, delta, theta
State::State() : MathVector(4){}

//State(double x, double y, double delta, double theta); 
State::State(double x, double y, double delta, double theta) : MathVector(4) {
    this->elements.at(0) = x;
    this->elements.at(1) = y;
    this->elements.at(2) = delta;
    this->elements.at(3) = theta;
}

//return a value at index 0 of elements
//double getX();
double State::getX() const{
    return elements.at(0);
}

//return a value at index 1 of elements
//double getY();
double State::getY() const{
    return elements.at(1);
}

//return a value at index 2 of elements
//double getDelta();
double State::getDelta() const{
    return elements.at(2);
}

//return a value at index 3 of elements
//double getTheta();
double State::getTheta() const{
    return elements.at(3);
}


//use newX to set index 0 of elements
//void setX(double newX);
void State::setX(double newX) {
    this->elements.at(0) = newX;
}


//use newY to set index 1 of elements
//void setY(double newY);
void State::setY(double newY) {
    this->elements.at(1) = newY;
}


//if newDelta is between [-0.5236,0.5236], use newDelta to set index 2 of elements
//if newDelta < -0.5236,  set index 2 of elements to -0.5236
//if newDelta > 0.5236,  set index 2 of elements to 0.5236
//void setDelta(double newDelta);
void State::setDelta(double newDelta) {
    if (newDelta >= DELTA_MIN && newDelta <= DELTA_MAX) {
        this->elements.at(2) = newDelta;
    }
    else if (newDelta < DELTA_MIN) {
        this->elements.at(2) = DELTA_MIN;
    }
    else {
        this->elements.at(2) = DELTA_MAX;
    }
}

//First, make sure that newTheta is between [0, 2π)
//then use it to set index 3 of elements
//void setTheta(double newTheta);
void State::setTheta(double newTheta) {
    while (newTheta < 0 || newTheta >= HEADING_MAX) {
        if (newTheta < 0) { 
            newTheta += HEADING_MAX;
        }
        else if (newTheta >= HEADING_MAX) {
            newTheta -= HEADING_MAX;
        }
    }
        this->elements.at(3) = newTheta;
}

void State::updateState(double v, double deltaDot) {
    double x = getX();
    double y = getY();
    double delta = getDelta();
    double theta = getTheta();

    double newX = x + 0.1 * v * cos(delta) * cos(theta);
    double newY = y + 0.1 * v * cos(delta) * sin(theta);
    double newDelta = delta + 0.1 * deltaDot;
    double newTheta = theta + 0.025 * v * sin(delta);

    setX(newX);
    setY(newY);
    setDelta(newDelta);
    setTheta(newTheta);
}