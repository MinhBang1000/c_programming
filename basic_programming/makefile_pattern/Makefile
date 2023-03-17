# This is make file
$(CC)=gcc
$(RM)=rm
final: main.c lib_add.c lib_sub.c
	$(CC) main.c lib_add.c lib_sub.c -o final -I include
main.o: main.c my_calc.h
	$(CC) -c main.c
lib_add.o: lib_add.c my_calc.h
	$(CC) -c lib_add.c
lib_sub.o: lib_sub.c my_calc.h
	$(CC) -c lib_sub.c
clean:
	$(RM) -r *.o
