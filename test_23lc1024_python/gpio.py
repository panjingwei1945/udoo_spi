def export(pin_num):
    temp_export = open(r"/sys/class/gpio/export","w",0)#0 means no buffer
    temp_export.write(repr(pin_num))
    temp_export.close

def unexport(pin_num):
    temp_unexport = open(r"/sys/class/gpio/unexport","w",0)#0 means no buffer
    temp_unexport.write(repr(pin_num))
    temp_unexport.close
    return
    
def pinMode(pin,mode):
    temp_pin=open(r"/sys/class/gpio/gpio"+repr(pin)+r"/direction","w",0)#0 means no buffer
    temp_pin.write(mode)
    temp_pin.close


def digitalWrite(pin,value):
    temp_pin=open(r"/sys/class/gpio/gpio"+repr(pin)+r"/value","w",0)#0 means no buffer
    temp_pin.write(repr(value))
    temp_pin.close

def digitalRead(pin):
    temp_pin=open(r"/sys/class/gpio/gpio"+repr(pin)+r"/value","r",0)#0 means no buffer
    temp_value = temp_pin.read(1)
    temp_pin.close
    return int(temp_value)
   
