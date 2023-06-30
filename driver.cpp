// Created by Tres300 for SimpleCryption
// Driver for testing and showcasing
// Last Updated 6/30/23

#include "caesar.cpp"
#include "vigenere.cpp"
#include <iostream>
using namespace std;

int main() {
    cout << "Caesar Test Encryptions:" << endl;
    cout << caesarEncrypt("Hello! This is a secret message.",1) << endl;
    cout << caesarEncrypt("I am a potato",-3) << endl;
    cout << caesarEncrypt("Gross!",200) << endl;

    cout << "\nCaesar Test Decryptions:" << endl;
    cout << caesarDecrypt("Ifmmp",1) << endl;
    cout << caesarDecrypt("F xj x mlqxql",-3) << endl;
    cout << caesarDecrypt("Yjgkk!",200) << endl;

    cout << "\nVigenere Test Encryptions:" << endl;
    cout << vigenereEncrypt("Hello! This is a secret message.", "b") << endl;
    cout << vigenereEncrypt("Hello! This is a secret message.", "secret") << endl;
    cout << vigenereEncrypt("Hello! This is a secret message.", "SeCrEt") << endl;

    cout << "\nVigenere Test Decryptions:" << endl;
    cout << vigenereDecrypt("Ifmmp! Uijt jt b tfdsfu nfttbhf.", "b") << endl;
    cout << vigenereDecrypt("Zincs! Mzmu zw t kieiim eiujezw.", "secret") << endl;
    cout << vigenereDecrypt("Zincs! Mzmu zw t kieiim eiujezw.", "SeCrEt") << endl;
    return 0;
}