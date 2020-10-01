#define _USE_MATH_DEFINES

#include <cmath>
#include "main.h"

void update( double **mid_vxy, double **mid_axy, planet *Star )
{
    double xi, yi, vxi, vyi;

    for( int i = 0; i < Num_Star; i++ ){

        vxi = Star[i].vx() + mid_axy[i][0]*Dt;
        vyi = Star[i].vy() + mid_axy[i][1]*Dt;

        xi = Star[i].x() + mid_vxy[i][0]*Dt;
        yi = Star[i].y() + mid_vxy[i][1]*Dt;

        Star[i].set_xy( xi, yi );
        Star[i].set_vxy( vxi, vyi );

    }

}