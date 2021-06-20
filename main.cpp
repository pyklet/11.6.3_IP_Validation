#include <iostream>
#include <string>

//get part of a string "str" from index "n" to character "c"
std::string getPartRow(std::string str, int n, char c) {
    std::string partStr;
    for (int i = n; str[i] != '.' && i < str.length(); ++i) {
        partStr += str[i];
    }
    return partStr;
}

int main() {
    std::string row, rowPart;
    int rowPartNum, numCount = 0;
    bool correct = true;

    std::cout << "Input row" << std::endl;
    std::cin >> row;

    for (int i = 0; correct && i <= row.length(); ++i) {
        rowPart = getPartRow(row, i, '.');
        numCount++;

        //check row part length
        if (rowPart.length() < 1 || rowPart.length() > 3) correct = false;

        //check row part first symbol
        if (correct && rowPart[0] == '0' && rowPart.length() > 1) correct = false;

        //check row part char
        rowPartNum = 0;
        for (int j = 0; correct && j < rowPart.length(); ++j) {
            if (rowPart[j] < '0' || rowPart[j] > '9') correct = false;
            rowPartNum = rowPartNum * 10 + (rowPart[j] - '0');
        }

        //check num 0-255;
        if (correct && rowPartNum > 255) correct = false;

        i += rowPart.length();
    }

    //check count numbers
    if (correct && numCount != 4) correct = false;

    std::cout << (correct ? "Yes" : "No");
}
