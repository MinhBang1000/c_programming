# Sample create share and static library .


#AR=ar rc
#RANLIB=ranlib
#CC=gcc
#STRIP=strip

AR=ar rc
RANLIB=ranlib
CC=gcc
STRIP=strip

all:static shared

shared:	hellow.so
	$(CC) main.c -o $@ $?
	$(STRIP) $@

static: hellow.a
	$(CC) main.c -o $@ $?
	$(STRIP) $@	

hellow.a: hellow.o
	$(AR) $@  $?
	-@ ($(RANLIB) $@ || true) >/dev/null 2>&1
	
hellow.so : hellow.o
	$(CC) -shared -o $@  $?

hellow.o: hellow.c
	$(CC) -c $?  

install:
	#Please put hellow.so into /lib and run shared.

clean:
	rm -f *~ static shared *.a *.o *.so