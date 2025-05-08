#include "monkey_search_knapsack.h"
#include <vector>
using namespace std;

int main() {
    vector<Item> items = {
        {weight: 3, value: 25},
        {weight: 2, value: 20},
        {weight: 1, value: 15},
        {weight: 4, value: 40},
        {weight: 5, value: 50}
    };

    int capacity = 7;
    MonkeyKnapsack search(10, 50, capacity, items);
    search.run();

    return 0;
}
