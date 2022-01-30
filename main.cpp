// sample program for raspberry pi Si5351A library
// I2C port on raspberry pi fixed at 1
// see Si5351::init() function in si5351.cpp

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <sys/ioctl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <linux/i2c-dev.h>
#include "si5351.h"

int main(){
	
	Si5351 si5351;
	int iOption = -1;
	unsigned long long ullFreqHz = 0;
	
	printf("Let the chip stabilize ...\n");
	sleep(2);

	si5351.init(SI5351_CRYSTAL_LOAD_8PF, 0, 0);
	printf("init() function called\n");
	
	si5351.set_freq(1200000000ULL, SI5351_CLK0);		// format: (desired_freq_hz*100, OUTPUT_PIN)
	printf("set_freq() function called\n");		// there should be an output clock at the selected pin
	
	
    do{
		printf("0: exit; 1: enter new frequency >> ");
		scanf("%d", &iOption);
		switch(iOption){
			case 0:
				break;
			case 1:
				printf("Enter new frequency (reg: 12M = 12000000) >> ");
				scanf("%d", &ullFreqHz);
				ullFreqHz = ullFreqHz * 100;
				si5351.set_freq(ullFreqHz, SI5351_CLK0);
				printf("set_freq() function called\n");
				break;
		}

	}while(iOption != 0);
	
	return 0;
}