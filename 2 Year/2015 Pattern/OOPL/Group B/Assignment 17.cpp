// Write a C++ program using command line arguments to search for a word in a file and replace it with the specified word. The usage of the program is shown below. $  change <old word> <new word> <file name>

// Author: Mohit Khedkar.

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(){
    istream readFile("test.txt");
    string readout,
           search,
           firstname,
           lastname;

    cout << "Enter the id which you want to modify";
    cin >> search;

    while(getline(readFile,readout)){
        if(readout == search){
            
            cout << "Enter new First name";
            cin >> firstname;

            cout << "Enter Last name";
            cin >> lastname;  
        }
    }
}  