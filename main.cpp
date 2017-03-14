// Name: 張雅涵
// Date: March 2, 2017
// Last Update: March 14, 2017
// Problem statement: the spaces are removed from the English text and
// the characters are writen into a squre(or rectangle).
// input: a string without whitespaace.
// output: the message by reading down the columns going left to right.

#include <iostream>
#include <vector>   //std::vector
#include <cmath>    //std::sqrt

using namespace std;

int main(int argc, const char * argv[]) {
    //initial
    char readWord;
    vector<char> dataArray;
    int size = 0;
    
    //get char
    readWord = cin.get();
    while (readWord != '\n')
    {
        dataArray.push_back(readWord);
        readWord = cin.get();
    }
    
    //calculate how many columns in a squre
    size = sqrt(dataArray.size()) + 1;
    
    //print data
    for (int i = 0; i < size; i ++)
    {
        for(int j = i; j < dataArray.size(); j+=size)
        {
            cout << dataArray[j];
        }
        cout << endl;
    }
    return 0;
}
