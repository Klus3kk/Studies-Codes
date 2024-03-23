#include <iostream>
#include <vector>
#include <random>
using namespace std;


void selection_sort(vector<int>& a) {
    int min;
    for (int i = 0; i < a.size() - 1; i++) {
        min = i;
        for(int j = i + 1; j < a.size(); j++) {
            if (a[j] < a[min]) {
                min = j;
            }
        }
        swap(a[min],a[i]);
    }
}

void new_table(int n, vector<int>& a) {
    cout << "Creating a random table with elements..." << endl;
    for (int i = 0; i < n; i++) {
        a.push_back(1 + (rand() % 20));
    }
}

