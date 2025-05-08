#include "monkey_search_knapsack.h"
#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;

MonkeyKnapsack::MonkeyKnapsack(int popSize, int iter, int cap, vector<Item> itemList)
    : populationSize(popSize), maxIterations(iter), capacity(cap), items(itemList) {
    std::srand(std::time(nullptr));
    bestMonkey.totalValue = 0;
}

Monkey MonkeyKnapsack::generateMonkey() {
    Monkey monkey;
    monkey.solution.resize(items.size());
    for (size_t i = 0; i < items.size(); ++i)
        monkey.solution[i] = rand() % 2;

    evaluateMonkey(monkey);
    return monkey;
}

void MonkeyKnapsack::evaluateMonkey(Monkey &monkey) {
    monkey.totalValue = 0;
    monkey.totalWeight = 0;

    for (size_t i = 0; i < items.size(); ++i) {
        if (monkey.solution[i]) {
            monkey.totalWeight += items[i].weight;
            monkey.totalValue += items[i].value;
        }
    }

    // Penalize overweight
    if (monkey.totalWeight > capacity)
        monkey.totalValue = 0;
}

void MonkeyKnapsack::climb(Monkey &monkey) {
    size_t i = rand() % items.size();
    monkey.solution[i] = !monkey.solution[i]; // Flip bit
    evaluateMonkey(monkey);
}

void MonkeyKnapsack::run() {
    std::vector<Monkey> population(populationSize);

    for (int i = 0; i < populationSize; ++i) {
        population[i] = generateMonkey();
        if (population[i].totalValue > bestMonkey.totalValue)
            bestMonkey = population[i];
    }

    for (int iter = 0; iter < maxIterations; ++iter) {
        for (int i = 0; i < populationSize; ++i) {
            Monkey trial = population[i];
            climb(trial);
            if (trial.totalValue > population[i].totalValue)
                population[i] = trial;

            if (population[i].totalValue > bestMonkey.totalValue)
                bestMonkey = population[i];
        }

        std::cout << "Iteration " << iter + 1 << ": Best Value = " << bestMonkey.totalValue << "\n";
    }

    std::cout << "\nFinal Best Total Value: " << bestMonkey.totalValue << "\n";
    std::cout << "Selected Items (0=skip, 1=take): ";
    for (bool b : bestMonkey.solution) std::cout << b << " ";
    std::cout << "\n";
}
