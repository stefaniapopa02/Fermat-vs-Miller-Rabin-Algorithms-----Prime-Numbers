build: p1 p2 best

run-p1:
	./p1

p1: fermat.cpp
	g++ -g -Wall fermat.cpp -o p1

run-p2:
	./p2

p2: rabin_miller.cpp
	g++ -g -Wall rabin_miller.cpp -o p2

run-best:
	./best

best: rabin_miller.cpp
	g++ -g -Wall rabin_miller.cpp -o best

clean:
	rm p1 p2 best