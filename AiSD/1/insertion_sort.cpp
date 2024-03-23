#include <iostream>
#include <vector>
#include <random>
using namespace std;


void insertion_sort(vector<int>& a) {
    int key, j;
    for (int i = 1; i <= a.size(); i++) {
        key = a[i];
        j = i - 1;
        while ((j >= 0) && (a[j] > key)) {
            a[j + 1] = a[j];
            j = j - 1;
        }
        a[j+1] = key;
    }
}



