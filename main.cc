// Created by Aidin Attar. 2019

// main.cc

#include <fstream>
#include <iostream>

struct Particle;
struct Event;
float massMin = 0.490;
float massMax = 0.505;

const Event* read ( std::ifstream& file );
void         dump ( const Event& ev );
bool         add  ( const Event& ev,
                    float min, float max,
                    double& sum, double& summqMass );
void         clear( const Event* ev );
void         stat ( int n,
                    double  sum, double  sqr,
                    double& mea, double& rms );

int main( int argc, char* argv[] ) {

    // open input file
    const char* name = argv[1];
    std::ifstream file(name);

    const Event* ev;
    int n = 0;
    double sum, sqr, mea, rms;

    // loop over events
    while( ( ev = read( file ) ) != 0 ){
        if ( add( *ev, massMin, massMax,
                  sum, sqr) ) ++n;
    //    dump( *ev );
        clear( ev );
        }

    stat ( n, sum, sqr, mea, rms);

    std::cout << n << ' ' << mea + massMin << ' ' << rms << std::endl;

    return 0;
}