#include <iostream>
#include <vector>
#include <random>
using namespace std;

void heap(vector<int>& a, int s, int i) {
    int large = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if(l < s && a[l] > a[large]) {
        large = l; 
    }
    if (r < s && a[r] > a[large])
        large = r;

    if (large != i) {
        swap(a[i], a[large]);
        heap(a, s, large);
    }
}

void heap_sort(vector<int>& a) {
    for(int i = a.size() / 2 - 1; i >= 0; i--) {
        heap(a,a.size(),i);
    }

    for(int i = a.size() - 1; i > 0; i--) {
        swap(a[0], a[i]);
        heap(a,i,0);
    }
    
}

