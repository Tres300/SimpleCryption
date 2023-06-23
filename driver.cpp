// Created by Tres300 for SimpleCryption
// Driver for testing and showcasing
// Last Updated 6/23/23

#include "caesar.cpp"
#include <iostream>
using namespace std;

int main() {
    cout << "Test Encryptions:" << endl;
    cout << caesarEncrypt("Hello",1) << endl;
    cout << caesarEncrypt("I am a potato",-3) << endl;
    cout << caesarEncrypt("Gross",200) << endl;
    cout << caesarEncrypt("Gross!",1) << endl; //results in "Error" because it has '!' in it.

    cout << "\nTest Decryptions of the first three messages:" << endl;
    cout << caesarDecrypt("Ifmmp",1) << endl;
    cout << caesarDecrypt("F xj x mlqxql",-3) << endl;
    cout << caesarDecrypt("Yjgkk",200) << endl;
    return 0;
}