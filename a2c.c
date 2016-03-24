#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdint.h>
#include <string.h>
#include <errno.h>
#include <wiringPi.h>
#include <wiringPiSPI.h>


void loadSpiDriver()
{
    if (system("gpio load spi") == -1)
    {
        fprintf (stderr, "Can't load the SPI driver: %s\n", strerror (errno)) ;
        exit (EXIT_FAILURE) ;
    }
}

void spiSetup (int spiChannel, double speed)
{
    if ((wiringPiSPISetup (spiChannel, speed )) < 0)
    {
        fprintf (stderr, "Can't open the SPI bus: %s\n", strerror (errno)) ;
        exit (EXIT_FAILURE) ;
    }
}

int analogGet (int spiChannel,int analogChannel)
{
    if(analogChannel<0 || analogChannel>7)
    {
        return -1;
    }
    unsigned char buffer[3] = {1}; // start bit
    buffer[1] = (8+analogChannel) << 4;
    wiringPiSPIDataRW(spiChannel, buffer, 3);
    int result =( (buffer[1] & 3 ) << 8 ) + buffer[2];// get last 10 bits
    return  result;
}
