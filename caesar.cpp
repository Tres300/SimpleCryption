// Created by Tres300 for SimpleCryption
// Caesar Cypher Encryption and Decryption Functions
// Last Updated 6/23/23

#include <string>
#include <utility>

// Does mod 26 mathematically, meaning the remainder is strictly positive
static int mod26(int x) {
    return (x % 26 + 26) % 26;
}

// Encrypts message using a Caesar Cipher by shift places.
// Message must only contain upper and lowercase letters, and spaces. Otherwise
// the output will be "Error". Shift may be any integer.
static std::string caesarEncrypt(std::string message, int shift) {
    shift = mod26(shift);
    for(int i = 0; i < message.size(); ++i) {
        if(message[i] != 32) {
            if (message[i] < 65 || message[i] > 122 ||
                (message[i] > 90 && message[i] < 97)) {
                return "Error";
            }

            if (message[i] < 97) {
                message[i] = mod26(((message[i] + shift) - 65)) + 65;
            } else {
                message[i] = mod26(((message[i] + shift) - 97)) + 97;
            }

        }
    }
    return message;
}

static std::string caesarDecrypt(std::string message, int shift) {
    return caesarEncrypt(std::move(message), -shift);
}