v0.5_deque.exe : main.o funkcijos.o
	g++ main.o funkcijos.o -o v0.5_deque.exe

main.o : main.cpp funkcijos.cpp funkcijos.h
	g++ -Wall -c main.cpp

funkcijos.o : funkcijos.cpp funkcijos.h
	g++ -Wall -c funkcijos.cpp

clean :
	rm *.o v0.5_deque.exe
