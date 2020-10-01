#define _USE_MATH_DEFINES

#include <cmath>
#include "planet_class.h"

void planet::set_xy( double x, double y )
{
    set_x( x );
    set_y( y );
}

void planet::set_vxy( double vx, double vy )
{
    set_vx( vx );
    set_vy( vy );
}

void planet::set_axy( double ax, double ay )
{
    set_ax( ax );
    set_ay( ay );
}

void planet::calc_t( void )
{
    double r;
    double ratio;
    r = std::sqrt( X*X + Y*Y );
    ratio = ( 2.0*M_PI*std::sqrt(std::pow( r, 3 )) )/( 2.0*M_PI*std::sqrt(std::pow( 1.0,3)) );
    set_t( ratio*YR );
}