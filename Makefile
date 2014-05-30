MagicEngine: clean components.o io.o main.o
	g++ -o MagicEngine components.o io.o main.o
main.o:
	g++ -c main.cpp
components.o:
	g++ -c components.cpp
io.o:
	g++ -c io.cpp
clean:
	rm -rf *.o
