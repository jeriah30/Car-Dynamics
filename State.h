//
//  State.h
//

#ifndef State_h
#define State_h

#include <iostream>
#include "MathVector.h"

#include <cmath>
#define DELTA_MAX 0.5236
#define DELTA_MIN (-DELTA_MAX)
#define HEADING_MAX (2*M_PI)

class State : public MathVector {
public:
    State( );
    State( double x, double y, double delta, double theta );

    double getX( ) const;
    double getY( ) const;
    double getDelta( ) const;
    double getTheta( ) const;
    void setX( double newX );
    void setY( double newY );
    void setDelta( double newDelta );
    void setTheta( double newTheta );
    void updateState(double v, double deltaDot);
};

#endif /* State_h */
