#include "23lc1024_driver.h"
//#include "Arduino.h"

void NOP();
#define _BV(bit) (1 << (bit))
/************user defined*************/


/************user defined*************/


/*-----------user modified------------*/
#define ADDR uint32_t
//#define uint16_t uint16_t
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


 void _SPI_setDataMode(unsigned char mode){

 }


 void _SPI_setClockDivider(unsigned char rate)
{
   
 }


 void _SPI_setBitOrder(unsigned char bitOrder)
 {
  
 }


 void _SPI_init(){
	 _SPI_begin();
	_SPI_setDataMode(SPI_MODE3); //equal to SPI.setDataMode(SPI_MODE3);
	_SPI_setClockDivider(SPI_CLOCK_DIV4);//SPI.setClockDivider(SPI_CLOCK_DIV4); //half speed, if the wire is too long may set this to SPI_CLOCK_DIV8
	_SPI_setBitOrder(MSBFIRST);
 }



 inline static char _SPI_read_char(){
		// return _SPI_transfer(0);
}

 inline static void _SPI_write_char(char wr_data){
		 //_SPI_transfer(wr_data);
}



 inline static void _SPI_read_array(uint16_t size , char * rt_data){
	 
}


 inline static void _SPI_write_array(uint16_t size ,char * wr_data){
	
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




void _23lc1024_transfer(SPI_DATA * data){
	char code_addr[4];

	code_addr[0]= data->code;
	code_addr[1]= data->addr>>16;
	code_addr[2]= data->addr>>8;
	code_addr[3]= data->addr;

	_CS_LOW_();
	_SPI_begin();
	_CS_LOW_();

	_SPI_write_array(4,code_addr);
	if(_WR_CODE_ == data->code){
		_SPI_write_array(data->size, (char *)data->wr_data);
	}else if(_R_CODE_ == data->code){
		_SPI_read_array(data->size, (char *)data->rt_data);
	}
	_CS_HIGH_();
	_SPI_end();
	_CS_HIGH_();
}
/*-----------23LC1024_driver-------------*/

