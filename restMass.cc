// Created by Aidin Attar. 2019

// restMass.cc

#include <cmath>

double restMass ( float Px, float Py, float Pz,
                  double en ){
                      
    double Ptot = sqrt ( pow ( Px, 2 ) +
                         pow ( Py, 2 ) +
                         pow ( Pz, 2 ) );

    return sqrt ( pow ( en,   2 ) -
                  pow ( Ptot, 2) );

}