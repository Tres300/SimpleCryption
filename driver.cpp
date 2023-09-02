// Created by Tres300 for SimpleCryption
// Driver for testing and showcasing
// Last Updated 6/30/23

#include "caesar.cpp"
#include "vigenere.cpp"
#include "aes128.cpp"
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdint>
#include <queue>

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

    cout << "\nAES128 Test Encryption:" << endl;
    string plainText = "00112233445566778899aabbccddeeff";
    string key = "000102030405060708090a0b0c0d0e0f";

    AES_128Encrypt x = AES_128Encrypt(plainText, key);
    cout << x.getCypherText() << endl;

    return 0;
}