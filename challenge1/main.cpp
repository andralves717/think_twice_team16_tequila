//
// Created by andralves on 06/03/20.
//

#include <iostream>
#include <string>
#include <fstream>
#include <math.h>
#include <vector>

using namespace std;

int main(int argc, char *argv[]) {
    string input = argv[1];
    ifstream file_input (input);
    vector<string> lines;
    string line;
    if(file_input.is_open()){
        while(getline(file_input,line)){
            lines.push_back(line);
        }
        file_input.close();
    }

    ofstream file_output ("result.txt");

    string::size_type sz;
    int n = stoi (lines[0],&sz);
    int p = stoi (lines[1],&sz);
    if (n < 1 || p < 1 || n > 200 || p > 10101){
        return 0;
    }
    int k = 0;
    for (k = 1; k < 110; ++k) {
        if(pow(k,n) == p){
            break;
        }
    }
    if(k == 0 || k >= 110) {
        return 0;
    }

    if (file_output.is_open()){
        file_output << k << "\n";
    }
    file_output.close();
    return 0;
}