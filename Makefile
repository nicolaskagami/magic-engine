magic: clean main.o analysis.o io.o components.o
	g++ -o magic main.o analysis.o io.o components.o
main.o:
	g++ -c main.cpp
analysis.o:
	g++ -c analysis.cpp
io.o:
	g++ -c io.cpp
components.o:
	g++ -c components.cpp
clean:
	rm -rf *.o
