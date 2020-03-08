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
    string lines[3];
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
    int p = std::stoi (lines[1],&sz);
    if (n < 1 || p < 1 || n > 200 || p > 10101){
        cout << "Argumentos inválidos (1<=n<=200 e 1<=p<=10101)\n";
        return 0;
    }
    int k = 0;
    for (k = 1; k < 110; ++k) {
        if(pow(k,n) == p){
            break;
        }
    }
    if(k == 0 || k >= 110) {
        cout << "Não foi encontrado nenhum número.\n";
        return 0;
    }

    if (file_output.is_open()){
        file_output << k << "\n";
    }
    file_output.close();
    return 0;
}