#include <iostream>
#include <vector>
#include <random>
using namespace std;


int partition(vector<int>& a, int l, int h) {
    int pivot = a[h];
    int i = (l - 1);
    for(int j = l; j <= h; j++) {
        if(a[j] < pivot) {
            i++;
            swap(a[i], a[j]);
        }
    }
    swap(a[i+1], a[h]);
    return (i + 1);
}

int partition_r(vector<int>& a, int l, int h) {
    srand(time(NULL));
    int random = l + rand() % (h - l);
    swap(a[random], a[h]);
    return partition(a,l,h);
}


void quick_sort_left_pivot(vector<int>& a, int l, int h) {
    if (l < h) {
        int q = partition(a,l,h);
        quick_sort_left_pivot(a,l,q-1);
        quick_sort_left_pivot(a,q+1,h);
    }
}

void quick_sort_random_pivot(vector<int>& a, int l, int h) {
    if (l < h) {
        int q = partition_r(a,l,h);
        quick_sort_random_pivot(a,l,q-1);
        quick_sort_random_pivot(a,q+1,h);
    }
}
