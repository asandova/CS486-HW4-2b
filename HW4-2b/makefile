all:HW4_2B

HW4_2B: main.o IUPAC.o
	g++ main.o IUPAC.o -o HW4_2B

IUPAC.o: IUPAC.h IUPAC.cpp
	g++ -c IUPAC.cpp

main.o: main.cpp IUPAC.h
	g++ -c main.cpp
clean:
	rm -rf *.o

