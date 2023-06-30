// Created by Tres300 for SimpleCryption
// Vigenère Cypher Encryption and Decryption
// Last Updated 6/30/23

#include <string>
#include <utility>
#include <cctype>

// Encrypts message using a Vigenère Cipher and a key.
// key must be strictly letters with no spaces. key is case insensitive.
// Only upper and lowercase letters are affected. message case is preserved.
static std::string vigenereEncrypt(std::string message, std::string key) {
    // Each letter of the key is turned into the number of shifts
    for(int i = 0; i < key.size(); ++i) {
        if(!isalpha(key[i])) {
            return "ERROR: key must be strictly letters";
        } else {
            key[i] = toupper(key[i]) - 65;
        }
    }

    int j = 0; // key index
    for(int i = 0; i < message.size(); ++i) {
        if(message[i] > 64 && message[i] < 91) {
            message[i] = ((message[i] - 65 + key[j++]) % 26) + 65;
            if(j == key.size()) j = 0;
        } else if(message[i] > 96 && message[i] < 123) {
            message[i] = ((message[i] - 97 + key[j++]) % 26) + 97;
            if(j == key.size()) j = 0;
        }
    }
    return message;
}

// Decrypts message using a Vigenère Cipher and a key.
// key must be strictly letters with no spaces. key is case insensitive.
// Only upper and lowercase letters are affected. message case is preserved.
static std::string vigenereDecrypt(std::string message, std::string key) {
    // Each letter of the key is turned into the number of shifts
    for(int i = 0; i < key.size(); ++i) {
        if(!isalpha(key[i])) {
            return "ERROR: key must be strictly letters";
        } else {
            key[i] = toupper(key[i]) - 65;
        }
    }

    int j = 0; // key index
    for(int i = 0; i < message.size(); ++i) {
        if(message[i] > 64 && message[i] < 91) {
            message[i] = (((message[i] - 65 - key[j++]) % 26) + 26) % 26 + 65; //%26 is done twice so the remainder is always positive
            if(j == key.size()) j = 0;
        } else if(message[i] > 96 && message[i] < 123) {
            message[i] = (((message[i] - 97 - key[j++]) % 26) + 26) % 26 + 97;
            if(j == key.size()) j = 0;
        }
    }
    return message;
}

// Encrypts a file at filePath using a Vigenère Cipher and a key.
// key must be strictly letters with no spaces. key is case insensitive.
// Only upper and lowercase letters are affected. Case is preserved.
// Encrypted file is placed in the same directory with the same file type,
// but with "VigenereEncrypted" appended to the file's name.
static bool vigenereEncryptFile(std::string filePath, std::string key) {
    std::ifstream readFile;
    readFile.open(filePath);
    if(!readFile.is_open()) return false;

    // Each letter of the key is turned into the number of shifts
    for(int i = 0; i < key.size(); ++i) {
        if(!isalpha(key[i])) {
            return false;
        } else {
            key[i] = toupper(key[i]) - 65;
        }
    }

    int dotIndex;
    for(int i = 0; i < filePath.size(); ++i) {
        if(filePath[i] == '.') {
            dotIndex = i;
        }
    }
    std::string fileType = filePath.substr(dotIndex+1);
    filePath = filePath.substr(0, dotIndex);
    std::ofstream writeFile(filePath + "VigenereEncrypted." + fileType);

    int j = 0; // key index
    std::string line;
    while(std::getline(readFile, line)) {
        for(int i = 0; i < line.size(); ++i) {
            if(line[i] > 64 && line[i] < 91) {
                line[i] = ((line[i] - 65 + key[j++]) % 26) + 65;
                if(j == key.size()) j = 0;
            } else if(line[i] > 96 && line[i] < 123) {
                line[i] = ((line[i] - 97 + key[j++]) % 26) + 97;
                if(j == key.size()) j = 0;
            }
        }
        writeFile << line << std::endl;
    }
    return true;
}

// Decrypts a file at filePath using a Vigenère Cipher and a key.
// key must be strictly letters with no spaces. key is case insensitive.
// Only upper and lowercase letters are affected. message case is preserved.
// Decrypted file is placed in the same directory with the same file type,
// but with "VigenereDecrypted" appended to the file's name.
static bool vigenereDecryptFile(std::string filePath, std::string key) {
    std::ifstream readFile;
    readFile.open(filePath);
    if(!readFile.is_open()) return false;

    // Each letter of the key is turned into the number of shifts
    for(int i = 0; i < key.size(); ++i) {
        if(!isalpha(key[i])) {
            return false;
        } else {
            key[i] = toupper(key[i]) - 65;
        }
    }

    int dotIndex;
    for(int i = 0; i < filePath.size(); ++i) {
        if(filePath[i] == '.') {
            dotIndex = i;
        }
    }
    std::string fileType = filePath.substr(dotIndex+1);
    filePath = filePath.substr(0, dotIndex);
    std::ofstream writeFile(filePath + "VigenereDecrypted." + fileType);

    int j = 0; // key index
    std::string line;
    while(std::getline(readFile, line)) {
        for(int i = 0; i < line.size(); ++i) {
            if(line[i] > 64 && line[i] < 91) {
                // % 26 is done twice so the remainder is always positive
                line[i] = (((line[i] - 65 - key[j++]) % 26) + 26) % 26 + 65;
                if(j == key.size()) j = 0;
            } else if(line[i] > 96 && line[i] < 123) {
                line[i] = (((line[i] - 97 - key[j++]) % 26) + 26) % 26 + 97;
                if(j == key.size()) j = 0;
            }
        }
        writeFile << line << std::endl;
    }
    return true;
}