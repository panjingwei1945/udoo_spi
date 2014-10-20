All: test_23lc1024 lib23lc1024.so test_23lc1024.o 23lc1024.o

test_23lc1024:test_23lc1024.o lib23lc1024.so
	gcc -o test_23lc1024  test_23lc1024.o -L/home/ubuntu/udoo_dev/udoo_spi/test_23lc1024_python -l23lc1024

test_23lc1024.o : test_23lc1024.c
	gcc -c test_23lc1024.c 

lib23lc1024.so: 23lc1024.c 23lc1024.h  #copy this file to /lib/
	gcc -fPIC -shared 23lc1024.c 23lc1024.h -o lib23lc1024.so

23lc1024.o:  23lc1024.c  23lc1024.h
	gcc -c 23lc1024.c 23lc1024.h 


clean: 
	rm -f test_23lc1024 23lc1024.o test_23lc1024.o lib23lc1024.so 
