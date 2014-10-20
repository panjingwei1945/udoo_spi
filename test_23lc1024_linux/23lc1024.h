#ifndef _23LC1024_DRIVER_H_
#define _23LC1024_DRIVER_H_
#include <stdint.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <linux/types.h>
#include <linux/spi/spidev.h>


#define _MAX_DATASIZE_ 20

typedef  unsigned int long ADDR;
typedef unsigned int long SIZE;

void _23lc1024_reset();
void _23lc1024_read(ADDR addr, void * data, SIZE size);
void _23lc1024_write(ADDR addr, void * data, SIZE size);
void _SPI_init();
void _SPI_close();
#endif

