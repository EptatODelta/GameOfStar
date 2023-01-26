
Proj1.out: main.o libconctrl.a libconinput.a liboutput.a libstrutil.a libthreadproc.a libprogSE.a libmathsutil.a libdatautil.a
	gcc -Wno-format -Ilib main.o  -lpthread -Llib/static -lprogSE -lthreadproc -lconctrl -lconinput   -lmathsutil -ldatautil -loutput -lstrutil -lm -o Proj1.out -no-pie
	rm *.o
	rm lib/static/*.a

main.o:
	gcc -Ilib -c main.c -o main.o

libmathsutil.a: mathsutil.o
	ar rc lib/static/libmathsutil.a mathsutil.o

libdatautil.a: datautil.o
	ar rc lib/static/libdatautil.a datautil.o

libconctrl.a: conctrl.o
	ar rc lib/static/libconctrl.a conctrl.o

libconinput.a: coninput.o
	ar rc lib/static/libconinput.a coninput.o

libstrutil.a: strutil.o
	ar rc lib/static/libstrutil.a strutil.o

libthreadproc.a: threadproc.o
	ar rc lib/static/libthreadproc.a threadproc.o

liboutput.a: output.o
	ar rc lib/static/liboutput.a output.o

libprogSE.a: progSE.o
	ar rc lib/static/libprogSE.a progSE.o

mathsutil.o:
	gcc -Ilib -c mathsutil.c -lm -o mathsutil.o

datautil.o:
	gcc -Ilib -c datautil.c -lm -o datautil.o

conctrl.o:
	gcc -Ilib -c conctrl.c -o conctrl.o

coninput.o:
	gcc -Ilib -c coninput.c -o coninput.o

strutil.o:
	gcc -Ilib -c strutil.c -o strutil.o

output.o:
	gcc -Ilib -c output.c -o output.o

threadproc.o:
	gcc -Ilib -c threadproc.c -o threadproc.o

progSE.o:
	gcc -Ilib -c progSE.c -o progSE.o
