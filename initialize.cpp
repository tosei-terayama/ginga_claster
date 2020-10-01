#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>

#include "main.h"

void initialize( double ini_v1, double ini_v2, double *ring_r, planet *Star )
{
    int Q;
    double th;
    double del_th( 2.0*M_PI/Num_Star );
    double vx( 0.0 ), vy( 0.0 );
    
    for( int i = 0; i < Num_Star; i++ ){

        Q = i%Num_Ring;
        th = i*del_th;

        Star[i].set_xy( ring_r[Q]*std::cos(th), ring_r[Q]*std::sin(th) );
        Star[i].calc_t();

        vx = -ini_v1*Star[i].y();
        vy = ini_v2*Star[i].x();

        Star[i].set_vxy( vx, vy );

        Star[i].set_axy( 0.0, 0.0 );
        Star[i].set_f( 0.0 );
        
    }
}