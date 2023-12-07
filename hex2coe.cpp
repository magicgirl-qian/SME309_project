#include <iostream>
#include <fstream>
#include <string>
using namespace std;
string remove(string a){
    string a1 = a.substr(0,2);
    string a2 = a.substr(2,2);
    string a3 = a.substr(4,2);
    string a4 = a.substr(6,2);
    string sum = a4 + a3 + a2 + a1;
    return sum;
}
int main() {
    // open input file
    ifstream inputFile("input.hex");
    if (!inputFile.is_open()) {
        cerr << "Error opening input file." << endl;
        return 1;
    }

    // open output file
    ofstream instram("instram.coe");
    if (!instram.is_open()) {
        cerr << "Error opening output file." << endl;
        return 1;
    }
    ofstream dataram("dataram.coe");
    if (!dataram.is_open()) {
        cerr << "Error opening output file." << endl;
        return 1;
    }

    // writing
    string line;
    instram << "memory_initialization_radix = 16;"<<endl;
    instram << "memory_initialization_vector ="<<endl;
    dataram << "memory_initialization_radix = 16;"<<endl;
    dataram << "memory_initialization_vector ="<<endl;
    getline(inputFile, line);
    for(int i=0;i<32;i++){
        getline(inputFile, line);
        string a1 = line.substr(9,8);
        string a2 = line.substr(17,8);
        string a3 = line.substr(25,8);
        string a4 = line.substr(33,8);
        instram << remove(a1) << endl ;
        instram << remove(a2) << endl ;
        instram << remove(a3) << endl ;
        instram << remove(a4) << endl ;
    }
    instram.close();
    while(true){
        getline(inputFile, line);
        string b = line.substr(1,2);
        if(b=="10"){
            string a1 = line.substr(9,8);
            string a2 = line.substr(17,8);
            string a3 = line.substr(25,8);
            string a4 = line.substr(33,8);
            dataram << remove(a1) << endl ;
            dataram << remove(a2) << endl ;
            dataram << remove(a3) << endl ;
            dataram << remove(a4) << endl ;
        } else if(b=="0C"){
            string a1 = line.substr(9,8);
            string a2 = line.substr(17,8);
            string a3 = line.substr(25,8);
            dataram << remove(a1) << endl ;
            dataram << remove(a2) << endl ;
            dataram << remove(a3) << endl ;
            break;
        } else if(b=="08"){
            string a1 = line.substr(9,8);
            string a2 = line.substr(17,8);
            dataram << remove(a1) << endl ;
            dataram << remove(a2) << endl ;
            break;
        } else if(b=="04"){
            string a1 = line.substr(9,8);
            dataram << remove(a1) << endl ;
            break;
        }
    }

    // close file
    inputFile.close();
    dataram.close();

    cout << "File operation successful." << endl;

    return 0;
}