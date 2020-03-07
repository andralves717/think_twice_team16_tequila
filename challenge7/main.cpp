//
// Created by andralves on 06/03/20.
//

#include <iostream>
#include <string>
#include <fstream>
#include <math.h>
#include <algorithm>
#include <vector>

using namespace std;

int find_kth(int *v, int n, int k) {
    if (n == 1 && k == 0) return v[0];

    int m = (n + 4)/5;
    int *medians = new int[m];
    for (int i=0; i<m; i++) {
        if (5*i + 4 < n) {
            int *w = v + 5*i;
            for (int j0=0; j0<3; j0++) {
                int jmin = j0;
                for (int j=j0+1; j<5; j++) {
                    if (w[j] < w[jmin]) jmin = j;
                }
                swap(w[j0], w[jmin]);
            }
            medians[i] = w[2];
        } else {
            medians[i] = v[5*i];
        }
    }

    int pivot = find_kth(medians, m, m/2);
    delete [] medians;

    for (int i=0; i<n; i++) {
        if (v[i] == pivot) {
            swap(v[i], v[n-1]);
            break;
        }
    }

    int store = 0;
    for (int i=0; i<n-1; i++) {
        if (v[i] < pivot) {
            swap(v[i], v[store++]);
        }
    }
    swap(v[store], v[n-1]);

    if (store == k) {
        return pivot;
    } else if (store > k) {
        return find_kth(v, store, k);
    } else {
        return find_kth(v+store+1, n-store-1, k-store-1);
    }
}


int main(int argc, char *argv[]) {
    if(argc < 2 || argc > 2){
        cout << "Executar como: ./main <Path to input file>\n";
        return 0;
    }
    string input = argv[1];
    ifstream file_input (input);
    string lines[2];
    int value;
    vector<int> nums;
    if(file_input.is_open()) {
        while (file_input >> value)
            nums.push_back(value);
        file_input.close();
    } else {
        cout << "Esse ficheiro não existe!\n";
        return 0;
    }


    ofstream file_output ("team16_tequila/challenge7/result.txt");

    int* num_array = &nums[0];

    int result = find_kth(num_array, nums.size(), nums.size()/2);

    if (file_output.is_open()){
        file_output << result << "\n";
    }
    file_output.close();

    return 0;
}