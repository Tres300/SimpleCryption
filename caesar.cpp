// Created by Tres300 for SimpleCryption
// Caesar Cypher Encryption and Decryption
// Last Updated 6/30/23

#include <string>
#include <utility>
#include <fstream>

// Does mod 26 mathematically, meaning the remainder is strictly positive
static int mod26(int x) {
    return (x % 26 + 26) % 26;
}

// Encrypts message using a Caesar Cipher by shift places.
// Only upper and lowercase letters are affected. Case is preserved.
static std::string caesarEncrypt(std::string message, int shift) {
    shift = mod26(shift);
    for(int i = 0; i < message.size(); ++i) {
        if(message[i] > 64 && message[i] < 91) {
            message[i] = mod26(((message[i] + shift) - 65)) + 65;
        } else if(message[i] > 96 && message[i] < 123) {
            message[i] = mod26(((message[i] + shift) - 97)) + 97;
        }
    }
    return message;
}

// Decrypts message using a Caesar Cipher, where shift is the shift used when
// encrypting.
// Only upper and lowercase letters are affected. Case is preserved.
static std::string caesarDecrypt(std::string message, int shift) {
    return caesarEncrypt(std::move(message), -shift);
}

// Encrypts a file at filePath using a Caesar Cipher by shift places.
// Only upper and lowercase letters are affected. Case is preserved.
// Encrypted file is placed in the same directory with the same file type,
// but with "CaesarEncrypted" appended to the file's name.
static bool caesarEncryptFile(std::string filePath, int shift) {
    std::ifstream readFile;
    readFile.open(filePath);
    if (!readFile.is_open()) return false;

    int dotIndex;
    for (int i = 0; i < filePath.size(); ++i) {
        if (filePath[i] == '.') {
            dotIndex = i;
        }
    }
    std::string fileType = filePath.substr(dotIndex + 1);
    filePath = filePath.substr(0, dotIndex);
    std::ofstream writeFile(filePath + "CaesarEncrypted." + fileType);
    std::string line;
    while (std::getline(readFile, line)) {
        writeFile << caesarEncrypt(line, shift) << std::endl;
    }
    return true;
}

// Decrypts a file at filePath using a Caesar Cipher by shift places.
// Only upper and lowercase letters are affected. Case is preserved.
// Encrypted file is placed in the same directory with the same file type,
// but with "CaesarEncrypted" appended to the file's name.
static bool caesarDecryptFile(std::string filePath, int shift) {
    std::ifstream readFile;
    readFile.open(filePath);
    if(!readFile.is_open()) return false;

    int dotIndex;
    for(int i = 0; i < filePath.size(); ++i) {
        if(filePath[i] == '.') {
            dotIndex = i;
        }
    }
    std::string fileType = filePath.substr(dotIndex+1);
    filePath = filePath.substr(0, dotIndex);
    std::ofstream writeFile(filePath + "CaesarDecrypted." + fileType);
    std::string line;
    while(std::getline(readFile, line)) {
        writeFile << caesarDecrypt(line, shift) << std::endl;
    }
    return true;
}