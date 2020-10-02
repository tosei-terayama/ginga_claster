#define _USE_MATH_DEFINES

#include <iostream>
#include <fstream>
#include <cmath>

#include "main.h"

const double AU( 1.0 );
const double YR( 1.0 );
const double G( 5.46e-11 );
const double M( 1.99e30 );
const double GM( 4.0*M_PI*M_PI );

const double Max_Time( 10.0 );
const double Dt( 0.0002 );
const int ite( Max_Time/Dt );
const double Dv( 0.01 );

const int Num_Star( 4 );
const int Num_Ring( 2 );

int main( void )
{
    double ini_v1( 0.0 ), ini_v2( 0.0 );
    planet *Star;
    double *Ring_r;
    double **mid_vxy, **mid_axy;
    int count(0);
    
    Star = new planet[ Num_Star ];
    Ring_r = new double[ Num_Ring ];
    mid_vxy = memory_allocate2d( Num_Star, 2, 0.0 );
    mid_axy = memory_allocate2d( Num_Star, 2, 0.0 );
    double max_r( 0.0 );

    for( int i = 0; i < Num_Ring; i++ ) Ring_r[i] = 0.5*( i + 1 );  // 0.5刻み //

    std::ofstream ofs;
    ofs.open("./result/v_data.dat");

    for( ini_v1 = 0.0; ini_v1 <= 4.0; ini_v1 += Dv ){
        for( ini_v2 = 0.0; ini_v2 <= 4.0; ini_v2 += Dv ){

            count++;
            if( count%1000 == 0 )std::cout << count << std::endl;
             
            initialize( ini_v1, ini_v2, Ring_r, Star );

            for( int n = 0; n < ite; n++ ){

                calc_acce( Star );

                middle_point( mid_vxy, mid_axy, Star );

                update( mid_vxy, mid_axy, Star );

            }

            max_r = abs( Star[0].x(), Star[0].y() );

            for( int i = 0; i < Num_Star; i++ ){

                double swap_r = abs( Star[i].x(), Star[i].y() );
                if( max_r <= swap_r ) max_r = swap_r;

            }

            ofs << ini_v1 << " " << ini_v2 << " " << max_r << std::endl;

        }
        ofs << std::endl;
    }

    ofs.close();

    return 0;
}
