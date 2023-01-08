
Game1.out: main.o libconctrl.a libinput.a liboutput.a libstrutil.a libthreadproc.a libprogSE.a
	gcc -Ilib main.o -lpthread -Llib/static -lprogSE -lthreadproc -lconctrl -linput -loutput -lstrutil -o Game1.out -no-pie
	rm *.o
	rm lib/static/*.a

main.o:
	gcc -Ilib -c main.c -o main.o

libconctrl.a: conctrl.o
	ar rc lib/static/libconctrl.a conctrl.o

libinput.a: input.o
	ar rc lib/static/libinput.a input.o

libstrutil.a: strutil.o
	ar rc lib/static/libstrutil.a strutil.o

libthreadproc.a: threadproc.o
	ar rc lib/static/libthreadproc.a threadproc.o

liboutput.a: output.o
	ar rc lib/static/liboutput.a output.o

libprogSE.a: progSE.o
	ar rc lib/static/libprogSE.a progSE.o

conctrl.o:
	gcc -Ilib -c conctrl.c -o conctrl.o

input.o:
	gcc -Ilib -c input.c -o input.o

strutil.o:
	gcc -Ilib -c strutil.c -o strutil.o

output.o:
	gcc -Ilib -c output.c -o output.o

threadproc.o:
	gcc -Ilib -c threadproc.c -o threadproc.o

progSE.o:
	gcc -Ilib -c progSE.c -o progSE.o