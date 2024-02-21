src := bench.cpp
target := bench

run:
	mkdir bin -p
	g++-13 $(src) --std=c++23 -lbenchmark  -o bin/bench 
	./bin/$(target)

clean:
	rm -rf bin/*
