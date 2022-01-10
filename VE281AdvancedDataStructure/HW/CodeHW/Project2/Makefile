all:main

main:main.o
	g++ -o main main.o -O2

main.o:main.cpp
	g++ -c main.cpp -O2

clean:
	rm -f main *.o
