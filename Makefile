all: main

main: main.o monkey_search_knapsack.o
	g++ main.o monkey_search_knapsack.o -o main

main.o: main.cpp monkey_search_knapsack.h
	g++ -c main.cpp

monkey_search_knapsack.o: monkey_search_knapsack.cpp monkey_search_knapsack.h
	g++ -c monkey_search_knapsack.cpp

clean:
	rm -f *.o main
