// Created by Aidin Attar. 2019

// energy.cc

#include <cmath>

double energy ( float Px, float Py, float Pz,
                double invMass){

    double Ptot = sqrt ( pow ( Px, 2 ) +
                         pow ( Py, 2 ) +
                         pow ( Pz, 2 ) );

    return sqrt ( pow ( invMass, 2 ) +
                  pow ( Ptot,    2 ) );

}
