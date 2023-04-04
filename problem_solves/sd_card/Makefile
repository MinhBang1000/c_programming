run: sd_card
	./sd_card

sd_card: sd_card.o
	gcc -o sd_card sd_card.o

sd_card.o: sd_card.c 
	gcc -c sd_card.c -o sd_card.o

clean: 
	rm -r *.o sd_card