test: test.cpp
	g++ -O2 test.cpp -fconcepts -o test.out
	./test.out

clean:
	rm *.out
