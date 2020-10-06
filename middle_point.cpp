#define _USE_MATH_DEFINES

#include <cmath>
#include "main.h"

void middle_point( double **mid_vxy, double **mid_axy, planet *Star )
{
    double mid_xi, mid_yi, mid_xj, mid_yj;
    double mid_ri, mid_rij;
    double mid_ax, mid_ay;

    for( int i = 0; i < Num_Star; i++ ){
        mid_ax = 0.0;
        mid_ay = 0.0;

        mid_vxy[i][0] = Star[i].vx() + Star[i].ax()*Dt/2.0;
        mid_vxy[i][1] = Star[i].vy() + Star[i].ay()*Dt/2.0;

        mid_xi = Star[i].x() + Star[i].vx()*Dt/2.0;
        mid_yi = Star[i].y() + Star[i].vy()*Dt/2.0;

        mid_ri = abs( mid_xi, mid_yi );

        for( int j = i  + 1; j < Num_Star; j++ ){

            mid_xj = Star[j].x() + Star[j].vx()*Dt/2.0;
            mid_yj = Star[j].y() + Star[j].vy()*Dt/2.0;

            mid_rij = abs( mid_xi - mid_xj, mid_yi - mid_yj );

            // a x component //
            mid_ax += -( GM/std::pow( mid_ri, 3.0 ))*mid_xi
                    - ( GM/std::pow( mid_rij, 3.0 ))*( mid_xi - mid_xj );
                
            // a y component //
            mid_ay += -( GM/std::pow( mid_ri, 3.0 ))*mid_yi
                    - ( GM/std::pow( mid_rij, 3.0 ))*( mid_yi - mid_yj );

        }

        mid_axy[i][0] = mid_ax;
        mid_axy[i][1] = mid_ay;

    }
}