all: main bellmanNorm bellmanFord dijkstra
	g++ m.o bn.o dij.o bf.o -o exec

main: src/main.cpp
	g++ -c src/main.cpp -o m.o

bellmanNorm: src/BellmanNormal.cpp include/BellmanNormal.h
	g++ -c src/BellmanNormal.cpp -o bn.o

bellmanFord: src/BellmanFord.cpp include/BellmanFord.h
	g++ -c src/BellmanFord.cpp -o bf.o

dijkstra: src/Dijkstra.cpp include/Dijkstra.h
	g++ -c src/Dijkstra.cpp -o dij.o

run:
	cd "tests";	../exec
clean:
	rm *~ *.o