#define _USE_MATH_DEFINES

#include <cmath>
#include "planet_class.h"

extern const double AU;
extern const double YR;
extern const double G;
extern const double M;
extern const double GM;

extern const double Max_Time;
extern const double Dt;
extern const int ite;
extern const double Dv;

extern const int Num_Star;
extern const int Num_Ring;

double** memory_allocate2d( int, int, double );

void initialize( double Initialize_vx, double Initialize_vy, 
                double *Ring_r, planet *Star );
void calc_acce( planet* Star );
void middle_point( double **Middle_vxy, double **Middle_axy, planet *Star );
void update( double **Middle_vxy, double **Middle_axy, planet *Star );

inline double abs( double x, double y ){ return std::sqrt( x*x + y*y ); }