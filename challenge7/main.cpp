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

double findMedian(int a[], int n){
    sort(a, a+n);

    if(n%2 != 0)
        return (double) a[n/2];
    return (double)(a[(n-1)/2] + a[n/2])/2.0;
}

int main(int argc, char *argv[]) {
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


    ofstream file_output ("result.txt");

    int* num_array = &nums[0];

    double result = findMedian(num_array, nums.size());

    if (file_output.is_open()){
        file_output << result << "\n";
    }
    file_output.close();

    return 0;
}