
Game1.out: main.o conctrl.o input.o output.o strutil.o
	gcc -Ilib main.o conctrl.o input.o output.o strutil.o -o Game1.out -no-pie -lpthread
	rm *.o

main.o:
	gcc -Ilib -c main.c -o main.o

conctrl.o:
	gcc -Ilib -c conctrl.c -o conctrl.o

input.o:
	gcc -Ilib -c input.c -o input.o

strutil.o:
	gcc -Ilib -c strutil.c -o strutil.o

output.o:
	gcc -Ilib -c output.c -o output.o