#include "Arduino.h"
#include "stdbool.h"


/* Blue pill pinout:
 * GND
 * GND
 * 3v3
 * NRST
 * PB11
 * PB10
 * PB1
 * PB0
 * PA7
 * PA6
 */

const int nbrOfLamps = 6;
const int nbrOfPhases = 6;
const int Ra_index = 0;
const int Oa_index = 1;
const int Ga_index = 2;
const int Rb_index = 3;
const int Ob_index = 4;
const int Gb_index = 5;

const int lampPin[nbrOfLamps] = {PB11, PB10 , PB1 , PB0 , PA7 , PA6};
const bool phases[nbrOfPhases][nbrOfLamps] = 
{
    /* Ra Oa Ga Rb Ob Gb */
    {  1, 0, 0, 1, 0, 0  },
    {  0, 0, 1, 1, 0, 0  },
    {  0, 1, 0, 1, 0, 0  },
    {  1, 0, 0, 1, 0, 0  },
    {  1, 0, 0, 0, 0, 1  },
    {  1, 0, 0, 0, 1, 0  }
};

static int currentPhase =0;

void setup(void)
{
    int i;
    for (i=0; i < nbrOfLamps; i++)
    {
        digitalWrite(lampPin[i], HIGH);
        pinMode(lampPin[i], OUTPUT);
    }
}

void loop(void)
{
    int i;

    for (i=0; i < nbrOfLamps; i++)
    {
        digitalWrite(lampPin[i], phases[currentPhase][i]);
    }

    if (phases[currentPhase][Ra_index] == true && phases[currentPhase][Rb_index] == true)
    {
        delay(2000);
    } 
    else if (phases[currentPhase][Oa_index] == true || phases[currentPhase][Ob_index] == true)
    {
        delay(2000);
    }
    else
    {
        delay(5000);
    }

    currentPhase = (currentPhase +1) % nbrOfPhases;
}
