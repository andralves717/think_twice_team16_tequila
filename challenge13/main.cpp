//
// Created by andralves on 08/03/20.
//

#include <iostream>
#include <string>
#include <fstream>
#include <math.h>
#include <vector>
#include <sstream>
#include <iterator>

using namespace std;

template<char delimiter>
class WordDelimitedBy : public string
{};

vector<string> split_by_space(string text) {
    istringstream iss(text);
    vector<string> results((istream_iterator<WordDelimitedBy<' '>>(iss)),
                                     istream_iterator<WordDelimitedBy<' '>>());
    return results;
}
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

    vector<string> dim = split_by_space(lines[0]);
    int dimension[dim.size()] = {stoi(dim[0]), stoi(dim[1])};
    int **table;
    table = new int *[dimension[0]];

    for (int i = 0; i < dimension[0]; ++i) {
        vector<string> y = split_by_space(lines[i+1]);
        table[i] = new int[dimension[1]];
        for (int j = 0; j < dimension[1]; ++j) {
            table[i][j] = stoi(y[j]);
        }
    }

    int lucro_max = 0;
    int l0, l1, c0, c1 = 0;

    for (int i = 0; i < dimension[0]; ++i) {
        for (int j = 0; j < dimension[1]; ++j) {
            for (int k = 0; k < dimension[0]-i; ++k) {
                for (int l = 0; l < dimension[1]-j; ++l) {
                    int lucro = 0;
                    for (int m = k; m < k+i; ++m) {
                        for (int n = l; n < l+j; ++n) {
                            lucro += table[m][n];
                        }
                    }
                    if(lucro > lucro_max) {
                        lucro_max = lucro;
                        l0 = k;
                        l1 = k+i-1;
                        c0 = l;
                        c1 = l+j-1;
                    }
                }

            }
        }
    }


    ofstream file_output ("result.txt");
    if (file_output.is_open()){
        file_output << lucro_max << endl;
        file_output << l0 << " " << c0 << " " << l1 << " " << c1 << " " << endl;
    }
    file_output.close();
    return 0;
}