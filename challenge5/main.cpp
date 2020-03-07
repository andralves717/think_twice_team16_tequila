//
// Created by andralves on 06/03/20.
//

#include <iostream>
#include <string>
#include <fstream>
#include <math.h>

using namespace std;

int main(int argc, char *argv[]) {
    string input = argv[1];
    ifstream file_input (input);
    string lines[4];
    int i = 0;
    if(file_input.is_open()){
        while(getline(file_input,lines[i++]));
        file_input.close();
    }
    else {
        cout << "Esse ficheiro não existe!\n";
        return 0;
    }

    ofstream file_output ("result.txt");

    std::string::size_type sz;
    int n = std::stoi (lines[0],&sz);
    int l = std::stoi (lines[1],&sz);
    int r = std::stoi (lines[2],&sz);
    if (n > 20 || n < r || n < l || l < 1 || r < 1 || (r == l && (r == 1 || r == n))){
        cout << "Argumentos inválidos (r<=n<=20 e l>=1)\n";
        return 0;
    }
    if (l == n || r == n){
        if(file_output.is_open()){
            file_output << 1 << "\n";
        }
    }
    if (l+r == n){
        int result = 1;
        for (int j = 1; j < n; ++j) {
            result *= j;
        }
        result--;
        cout << result;
        if (file_output.is_open()){
            file_output << result << "\n";
        }
        return 0;
    }

    \\

    int a[n];
    a[0] = l;
    a[n-1] = r;
    for (int k = 1; k < n-1; ++k) {
        a[k] = n;
    }
    for (int j = 1; j < n; ++j) {
        a[j] -= j;
    }
    r--;
    if(r == 1){
        a[n-1] = 1;
        for (int j = 0; j < ; ++j) {

        }
    }
    int l_tmp = l;
    for (int j = 0; j < n; ++j) {
        if(l_tmp == 1) break;
        a[j] = n - l_tmp-- + 1;
    }

    if (file_output.is_open()){
        file_output << k << "\n";
    }
    file_output.close();
    return 0;
}