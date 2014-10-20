#include "23lc1024.h"

#define _WR_CODE_ 0x02
#define  _R_CODE_ 0x03
//char _temp_data_[_MAX_DATASIZE_+4]="";
void NOP();
/************user defined*************/
#define device  "/dev/spidev0.0"
#define _BITS_ 8
#define  _SPEED_ 5000000
int fd;




/************user defined*************/
static void pabort(const char *s)
{
	perror(s);
	abort();
}

/*-----------user modified------------*/
#define _CS_HIGH_()
#define _CS_LOW_()
#define _SCK_HIGH_()
#define _SCK_LOW_()
#define _MOSI_HIGH_()
#define _MOSI_LOW_() 
#define _MISO_HIGH_()
#define _MISO_LOW_()

 void NOP(){

}

 inline static void _SPI_begin(){
}

 inline static void _SPI_end(){
}


 void _SPI_setDataMode(){
	//SPI mode: CPOL=1,CPHA=1. For arduino it should be SPI_MODE3;
 }


 void _SPI_setClockDivider(){
	//The cycle duration should longer than 100ns.
}


 void _SPI_setBitOrder(){
	//MSBFIRST
 }


 void _SPI_init(){
    int ret = 0;
    uint8_t bits = _BITS_;
    uint8_t mode=0;//SPI_CPHA|SPI_CPOL;
    uint32_t speed = _SPEED_;
	fd = open(device, O_RDWR);
	if (fd < 0) 
		pabort("can't open device");

	_SPI_begin();
	_SPI_setDataMode(); 
	_SPI_setClockDivider();
	_SPI_setBitOrder();

 	/*
	 * spi mode
	 */
	ret = ioctl(fd, SPI_IOC_WR_MODE, &mode);
	if (ret == -1)
		pabort("can't set spi mode");

	ret = ioctl(fd, SPI_IOC_RD_MODE, &mode);
	if (ret == -1)
		pabort("can't get spi mode");

	/*
	 * bits per word
	 */
	ret = ioctl(fd, SPI_IOC_WR_BITS_PER_WORD, &bits);
	if (ret == -1)
		pabort("can't set bits per word");

	ret = ioctl(fd, SPI_IOC_RD_BITS_PER_WORD, &bits);
	if (ret == -1)
		pabort("can't get bits per word");

	/*
	 * max speed hz
	 */
	ret = ioctl(fd, SPI_IOC_WR_MAX_SPEED_HZ, &speed);
	if (ret == -1)
		pabort("can't set max speed hz");

	ret = ioctl(fd, SPI_IOC_RD_MAX_SPEED_HZ, &speed);
	if (ret == -1)
		pabort("can't get max speed hz");

	printf("spi mode: %d\n", mode);
	printf("bits per word: %d\n", bits);
	printf("max speed: %d Hz (%d KHz)\n", speed, speed/1000);

}



 void _SPI_close(){
	close(fd);
}


 inline static void _SPI_transfer_array(uint16_t size , char * data){
    static uint16_t delay;
    int ret = 0;
    uint32_t speed = _SPEED_;
    static uint8_t bits = _BITS_;
	struct spi_ioc_transfer tr = {
		.tx_buf = (unsigned long)data,
		.rx_buf = (unsigned long)data,
		.len =size,
		.delay_usecs = delay,
		.speed_hz = speed,
		.bits_per_word = bits,
	};

	ret = ioctl(fd, SPI_IOC_MESSAGE(1), &tr);
	if (ret < 1)
		pabort("can't send spi message");
}




/*-----------user modified------------*/




/*-----------23LC1024_driver-------------*/
void _23lc1024_reset()
{
	NOP();
	_MOSI_HIGH_();
	_MISO_HIGH_();
	_SCK_LOW_();
	_CS_HIGH_();
	_SCK_HIGH_();
	_SCK_LOW_();
	_SCK_HIGH_();
	_SCK_LOW_();
	_CS_LOW_();
	NOP();
	NOP();
	_CS_HIGH_();
	_SCK_HIGH_();
	_SCK_LOW_();
	_SCK_HIGH_();
	_SCK_LOW_();
	_SCK_HIGH_();
	_SCK_LOW_();
	_SCK_HIGH_();
	_SCK_LOW_();
	_CS_LOW_();
}



void _23lc1024_write(ADDR addr, void * data, SIZE size){
    char * _temp_data_=(char*)calloc(size+4,sizeof(char));
	_temp_data_[0] = _WR_CODE_;
	_temp_data_[1] = (char)(addr>>16);
	_temp_data_[2] = (char)(addr>>8);
	_temp_data_[3] = (char)(addr);
	memcpy(_temp_data_+4, data, size);

	_CS_LOW_();
	_SPI_begin();
	_CS_LOW_();
	_SPI_transfer_array(size+4 , _temp_data_);
	_CS_HIGH_();
	_SPI_end();
	_CS_HIGH_();
    free(_temp_data_);
    _temp_data_ = NULL;
}

void _23lc1024_read(ADDR addr, void * data, SIZE size){
    char * _temp_data_=(char*)calloc(size+4,sizeof(char));
	_temp_data_[0] = _R_CODE_;
	_temp_data_[1] = (char)(addr>>16);
	_temp_data_[2] = (char)(addr>>8);
	_temp_data_[3] = (char)(addr);

	_CS_LOW_();
	_SPI_begin();
	_CS_LOW_();
	_SPI_transfer_array(size+4 , _temp_data_);
	_CS_HIGH_();
	_SPI_end();
	_CS_HIGH_();

	memcpy(data, _temp_data_+4, size);
    free(_temp_data_);
    _temp_data_ = NULL;
}


/*-----------23LC1024_driver-------------*/



