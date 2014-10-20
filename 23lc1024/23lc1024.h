#ifndef _23LC1024_DRIVER_H_
#define _23LC1024_DRIVER_H_
#include "Arduino.h"
#define _MAX_DATASIZE_ 20
#define _WR_CODE_ 0x02
#define _R_CODE_ 0x03
#define SPI_DATA struct SPI_STR

struct SPI_STR {
	char code;
	uint32_t addr;
	void * wr_data;
	void * rt_data;
	unsigned int size;
};


void _23lc1024_reset();
void _23lc1024_transfer(SPI_DATA *);
void _SPI_init();
#endif

