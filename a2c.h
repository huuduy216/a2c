#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdint.h>
#include <string.h>
#include <errno.h>
#include <wiringPi.h>
#include <wiringPiSPI.h>


void loadSpiDriver();

void spiSetup (int spiChannel, double speed);

int analogGet (int spiChannel,int analogChannel);

