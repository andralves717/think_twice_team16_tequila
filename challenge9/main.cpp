//
// Created by andralves on 06/03/20.
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

vector<int> multiple_by(int base_low, int base_high, int k){
    vector<int> result;
    for (double i = pow(2,base_low); i < pow(2, base_high); ++i) {
        if((int)i % k == 0 ) {
            result.push_back(i);
        }
    }
    return result;
}

bool decimal_to_bin_and_freq(int decimal, int size) {
    int bin[size];
    int zero = 0;
    int one = 0;
    for (int i = size - 1; i >= 0; i--) {
        bin[i] = decimal%2;
        decimal /= 2;
        if(bin[i] == 0) zero++;
        else one++;
    }
    return one == zero;
}

int main(int argc, char *argv[]) {
    string input = argv[1];
    ifstream file_input (input);
    string line;
    if(file_input.is_open()){
        while(getline(file_input,line));
        file_input.close();
    }

    vector<string> data = split_by_space(line);
    vector<int> data_decimal;

    for (unsigned int i = 0; i < data.size(); ++i) {
        data_decimal.push_back(stoi(data[i]));
    }

    vector<int> multiples_of_k = multiple_by(data_decimal[0]-1, data_decimal[0], data_decimal[1]);

    int count = 0;

    for (unsigned int i = 0; i < multiples_of_k.size(); ++i) {
        if(decimal_to_bin_and_freq(multiples_of_k[i], data_decimal[0]))
            count++;
    }

    ofstream file_output ("result.txt");
    if (file_output.is_open()){
        file_output << count << endl;
    }
    file_output.close();
    return 0;
}