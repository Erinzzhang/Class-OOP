// Name: 張雅涵
// Date: March 14, 2017
// Last Update: March 14, 2017
// Problem statement: Sort and output the input number with occurrences.

#include <iostream>
#include <vector>       //std::vector
#include <fstream>      //std::fstream
#include <algorithm>    //sort

using namespace std;

int main(int argc, const char * argv[]) {
    //initial
    vector<int> array;
    fstream file,file2;
    int data,j = 0;
    int count = 1;
    int temp = 0;

    file.open("intArray.txt", ios::in);    //將檔案開啟為輸入狀態
    file2.open("output.txt", ios::out); //將檔案開啟為輸出狀態
    
    if(!file)   //檢查檔案是否成功開啟
    {
        cerr << "Can't open file!\n";
        exit(1);     //在不正常情形下，中斷程式的執行
    }
    
    // read input.txt data,and write data into output.txt
    while(file >> data ){
        array.push_back(data);
    }
    
    //sort array
    sort(array.begin(),array.end(),greater<int>());
    
    //output data into file2
    file2 << "N\t" << "count" << endl;
    for (int i = 0; i < array.size(); i++)
    {
        temp = array[i];
        j = i + 1;       //jump to next data
        
        while (temp == array[j] && j < array.size())
        {
            count++;
            j++;
        }
        
        count = j - i;  //count
        file2 << temp << "\t" << count << endl; //output answer into file2
        i = j - 1;      //jump to next number
        temp = 0;       //initial temp
    }
    
    //close file
    file.close();
    file2.close();
    
    return 0;
}

