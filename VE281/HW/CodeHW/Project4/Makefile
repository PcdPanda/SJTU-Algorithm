all:main

main:main.o
	g++ -std=c++11 -o main main.o -O2

main.o:main.cpp
	g++ -std=c++11 -c main.cpp -O2

clean:
	rm -f main *.o
