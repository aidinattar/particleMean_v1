// Created by Aidin Attar. 2019

// stat.cc

#include <cmath>

void stat ( int n,
            double  sum, double  sqr,
            double& mea, double& rms ){

    double v;

    mea =   sum * 1.0 / n;
    v   = ( sqr * 1.0 / n ) - ( mea * mea );
    rms = ( v > 0 ? sqrt ( v ) : 0.0 );

    return;
}