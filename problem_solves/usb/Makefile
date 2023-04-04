run: usb
	sudo ./usb

init: usb
	echo "init successful!"

usb: usb.o
	gcc -o usb usb.o
	
usb.o: usb.c
	gcc -c usb.c -o usb.o

clean:
	rm -r *.o usb
