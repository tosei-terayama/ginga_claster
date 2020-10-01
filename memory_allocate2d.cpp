#include <iostream>
#include "main.h"

double** memory_allocate2d( int m, int n, double ini )
{
    double **array;
    array = new double*[m];

    for( int i = 0; i < m; i++ ){
        array[i] = new double[n];
        for( int j = 0; j < n ; j++ ){
            array[i][j] = ini;
        }
    }

    return array;
}