// Created by Aidin Attar. 2019

// add.cc

#include "Particle.h"
#include "Event.h"

double mass ( const Event& ev );

bool add ( const   Event& ev,
           float   min, float   max,
           double& sum, double& sqr ){

    double Mass = mass ( ev );

    if ( Mass > max - min || Mass < 0 ) return false;

    sum += Mass;
    sqr += Mass * Mass;

    return true;
}
