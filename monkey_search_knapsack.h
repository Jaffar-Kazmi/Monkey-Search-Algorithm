#ifndef MONKEY_KNAPSACK_H
#define MONKEY_KNAPSACK_H

#include <vector>

struct Item {
    int weight;
    int value;
};

struct Monkey {
    std::vector<bool> solution;
    int totalWeight;
    int totalValue;
};

class MonkeyKnapsack {
private:
    int populationSize;
    int maxIterations;
    int capacity;
    std::vector<Item> items;
    Monkey bestMonkey;

    Monkey generateMonkey();
    void evaluateMonkey(Monkey &monkey);
    void climb(Monkey &monkey);

public:
    MonkeyKnapsack(int popSize, int iter, int cap, std::vector<Item> itemList);
    void run();
};

#endif
