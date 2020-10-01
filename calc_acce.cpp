#define _USE_MATH_DEFINES

#include <cmath>
#include "main.h"

void calc_acce( planet *Star )
{
    double ri;
    double rij;
    double x1, x2, y1, y2;
    double ax, ay;

    for( int i = 0; i < Num_Star; i++ ){
        ax = 0.0, ay = 0.0;
        
        for( int j = 0; j < Num_Star; j++ ){

            if( i != j){
                ri = abs( Star[i].x(), Star[i].y() );
                rij = abs( Star[i].x() - Star[j].x(), Star[i].y() - Star[j].y() );

                // a x component //
                ax += -( GM/std::pow( ri, 3.0 ))*Star[i].x()
                    - ( GM/std::pow( rij, 3.0 ))*( Star[i].x() - Star[j].x() );
                
                // a y component //
                ay += -( GM/std::pow( ri, 3.0))*Star[i].y()
                    - ( GM/std::pow( rij, 3.0 ))*( Star[i].y() - Star[j].y() );
            }

        }

        Star[i].set_axy( ax, ay );
    }
    
}