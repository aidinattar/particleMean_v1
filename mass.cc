// Created by Aidin Attar. 2019

// mass.cc

#include <cmath>

#include "Particle.h"
#include "Event.h"

extern float massMin;

double  energy   ( float Px, float Py, float Pz,
                   double invMass);
double  restMass ( float Px, float Py, float Pz,
                   double en );

const double massPion    = 0.1395706;   // GeV/c^2
const double massProton  = 0.938272;    // GeV/c^2
const double massK0      = 0.497611;    // GeV/c^2
const double massLambda0 = 1.115683;    // GeV/c^2

double mass ( const Event& ev ){

  // retrieve particles in the event
  typedef const Particle* part_ptr;
  const part_ptr* particles = ev.particles;

  // variables to loop over particles
  int i;

  // positive / negative track counters
  int p = 0,
      n = 0;

  // variables for momentum sums
  float sumPx = 0,
        sumPy = 0,
        sumPz = 0;
  // variables for energy sums, for K0 and Lambda0
  float sumEnK0 = 0,
        sumEnL0 = 0;

  // loop over particles - momenta
  for ( i = 0; i < ev.nParticles; ++i ) {
    // get particle pointer
    part_ptr par = new Particle;
    par = particles[ i ];

    // update momentum sums
    sumPx += par->Px;
    sumPy += par->Py;
    sumPz += par->Pz;

    // update energy sums, for K0 and Lambda0 hypotheses:
    // pion mass for K0,
    // proton or pion mass for Lambda0,
    // for positive or negative particles respectively
    // update positive/negative track counters
    sumEnK0 += energy ( par->Px, par->Py, par->Pz,
                        massPion );

    if ( par->q == 1 ){
      sumEnL0 += energy ( par->Px, par->Py, par->Pz,
                          massProton );
      ++p;
      }
    else {
      sumEnL0 += energy ( par->Px, par->Py, par->Pz,
                          massPion );
      ++n;
      }
  }

  // check for exactly one positive and one negative track
  // otherwise return negative (unphysical) invariant mass
  if ( n != p )   return -1;

  // invariant masses for different decay product mass hypotheses
  double K0exp = restMass ( sumPx, sumPy, sumPz,
                            sumEnK0 );
  double L0exp = restMass ( sumPx, sumPy, sumPz,
                            sumEnL0 );

  // compare invariant masses with known values and return the nearest one
  if ( fabs( K0exp - massK0 ) <=
       fabs( L0exp - massLambda0 ) ) return K0exp - massMin;

  return L0exp - massMin;

}
