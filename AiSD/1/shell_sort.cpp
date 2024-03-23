#include <iostream>
#include <vector>
#include <random>
#include <math.h>
using namespace std;

void generateSedgewickSeries(vector<int>& g, int n) {
    int s = 1;
    int k = 0;
    
    while (s < n) {
        g.push_back(s);
        if (k % 2 == 0) {
            s = 9 * ((pow(4,(k-1))) - (pow(2,(k-1)))) + 1;
        } else {
            s = pow(4,(k+1)) - 6 * (pow(2,k)) + 1; 
        }
        k++;
    }
}



void shell_sort(vector<int>& a) {
    vector<int> g;
    generateSedgewickSeries(g, a.size());
    
    for (int i = g.size() - 1; i >= 0; i--) {
        int h = g[i];
        for (int d = h; d < a.size(); d++) {
            int key = a[d];
            int j = d;
            while (j >= h && a[j - h] > key) {
                a[j] = a[j - h];
                j -= h;
            }
            a[j] = key;
        }
    }
}


