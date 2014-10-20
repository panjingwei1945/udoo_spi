//#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "23lc1024.h"
#include <unistd.h>
       
#define addr0 0
#define addr1 100
#define addr2 200
#define isi 2000
#define msleep(x) usleep(x*1000)
unsigned char wrcode = 0x02;
unsigned char rdcode = 0x03;

char str0[_MAX_DATASIZE_] = "hellow world!";
char str1[_MAX_DATASIZE_] = "this is a test.";
char str2[_MAX_DATASIZE_] = "I'm 23lc1024.";
char empty_str[_MAX_DATASIZE_] = "";
char rt_str[_MAX_DATASIZE_] = "";
int i = 0;
//SPI_DATA test_data;
//The setup function is called once at startup of the sketch



int main()
{
	int i;



	_SPI_init();
	_23lc1024_reset();

	_23lc1024_write(addr0, str0, _MAX_DATASIZE_);
	_23lc1024_write(addr1, str1, _MAX_DATASIZE_);
	_23lc1024_write(addr2, str2, _MAX_DATASIZE_);

	fprintf(stderr,"*********************\n");

	fprintf(stderr,"str0=");
	fprintf(stderr,str0);
	fprintf(stderr,"\n");

	//_23lc1024_write(0, str0, _MAX_DATASIZE_);

	fprintf(stderr,"rt_str(before)=");
	fprintf(stderr,rt_str);
	fprintf(stderr,"\n");

	memset(str0,0,_MAX_DATASIZE_);
	_23lc1024_read(addr0, rt_str,_MAX_DATASIZE_);

	fprintf(stderr,"rt_str=");
	fprintf(stderr,rt_str);
	fprintf(stderr,"\n");

	msleep(isi);

	fprintf(stderr,"*********************\n");

	fprintf(stderr,"str1=");
	fprintf(stderr,str1);
	fprintf(stderr,"\n");

	//_23lc1024_write(0, str1, _MAX_DATASIZE_);

	fprintf(stderr,"rt_str(before)=");
	fprintf(stderr,rt_str);
	fprintf(stderr,"\n");

	memset(str0,0,_MAX_DATASIZE_);
	_23lc1024_read(addr1, rt_str,_MAX_DATASIZE_);

	fprintf(stderr,"rt_str=");
	fprintf(stderr,rt_str);
	fprintf(stderr,"\n");

	msleep(isi);


	fprintf(stderr,"*********************\n");

	fprintf(stderr,"str2=");
	fprintf(stderr,str2);
	fprintf(stderr,"\n");

	//_23lc1024_write(0, str2, _MAX_DATASIZE_);

	fprintf(stderr,"rt_str(before)=");
	fprintf(stderr,rt_str);
	fprintf(stderr,"\n");

	memset(str0,0,_MAX_DATASIZE_);
	_23lc1024_read(addr2, rt_str,_MAX_DATASIZE_);

	fprintf(stderr,"rt_str=");
	fprintf(stderr,rt_str);
	fprintf(stderr,"\n");

	_SPI_close();
	return 0;
}

