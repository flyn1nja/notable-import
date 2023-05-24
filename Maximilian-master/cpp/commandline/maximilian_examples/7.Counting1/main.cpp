
#include "maximilian.h"
#include "maxiSynths.h"

maxiOsc mySine; // This is the oscillator we will use to generate the test tone
maxiClock myClock; // This will allow us to generate a clock signal and do things at specific times
double freq; // This is a variable that we will use to hold and set the current frequency of the oscillator

void setup() {
    
    myClock.setTicksPerBeat(1);//This sets the number of ticks per beat
    myClock.setTempo(120);// This sets the tempo in Beats Per Minute
    freq=20; // Here we initialise the variable
}

void play(double *output) {
    
    myClock.ticker(); // This makes the clock object count at the current samplerate
    
    //This is a 'conditional'. It does a test and then does something if the test is true 

    if (myClock.tick) { // If there is an actual tick at this time, this will be true.
        
        freq+=100; // DO SOMETHING
        
    } // The curly braces close the conditional
    
    //output[0] is the left output. output[1] is the right output
    
    output[0]=mySine.sinewave(freq);//simple as that!
    output[1]=output[0];

}

