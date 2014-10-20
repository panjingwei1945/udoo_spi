G_BUSY=89
H_BUSY=105
H_REQ=104

from time import sleep

import ctypes
c = ctypes
lib23lc1024 = c.CDLL("lib23lc1024.so")
l=lib23lc1024
l._SPI_init()
l._23lc1024_reset()

import gpio
g=gpio


g.pinMode(G_BUSY,"in")
g.pinMode(H_BUSY,"in")
g.pinMode(H_REQ,"out")
g.digitalWrite(H_REQ,0)

def request():
    g.digitalWrite(H_REQ,1)
    while 1:
        if g.digitalRead(H_BUSY)==1 : break
        sleep(0.001)


def release():
    g.digitalWrite(H_REQ,0)


def write(addr,data,size):
    request()
    l._23lc1024_write(addr,data,size)
    release()


def read(addr,data,size):
    request()
    l._23lc1024_read(addr,data,size)
    release()


def read_str(addr,size):
    temp_str = c.create_string_buffer(size)
    temp_str_p = c.pointer(temp_str)
    read(addr, temp_str_p,size)
    return temp_str.value


def test_write_str(data):
    size_t = len(data)+1
    temp_int_size = c.c_uint(size_t)
    temp_size_t_p = c.pointer(temp_int_size)

    temp_str = c.create_string_buffer(size_t)
    temp_str.value = data
    temp_str_p = c.pointer(temp_str)

    request()
    l._23lc1024_write(0,temp_size_t_p ,4)
    l._23lc1024_write(4,temp_str_p,size_t)
    release()


def test_read_str():
    return



