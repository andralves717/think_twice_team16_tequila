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
    int result;
    if (l == n || r == n) result = 1;
    else if (l+r == n){
        result = 1;
        for (int j = 1; j < n; ++j) {
            result *= j;

1523 Pontos

Último Commit: 6/3 1:27:38



8º Classificado

0x1C0E6AE
1437 Pontos

Último Commit: 6/3 1:27:38



9º Classificado

Coffee Addicts
1128 Pontos

Último Commit: 6/3 1:27:38



10º Classificado

Escolinha
1115 Pontos

Último Commit: 6/3 1:27:38



11º Classificado

void()
1100 Pontos

Último Commit: 6/3 1:27:38



12º Classificado

QUE NERD
1035 Pontos

Último Commit: 6/3 1:27:38



13º Classificado

Dirty Bits
1020 Pontos

Último Commit: 6/3 1:27:38



14º Classificado

!(RuntimeError)
687 Pontos

Último Commit: 6/3 1:27:38



15º Classificado

Think Once
639 Pontos

Último Commit: 6/3 1:27:38



16º Classificado}
        result--;
    } else result = n - l - r + 1;

    if (file_output.is_open()){
        file_output << result << endl;
    }
    file_output.close();
    return 0;
}