// Includes

#include "Transaction.h"
#include <iostream>
#include <fstream>
#include <cstdlib>

// Constructors
Transaction::Transaction()
{
  this->fromAccountNumber = "9999999999";
  this->toAccountNumber = "9999999999";
  this->amount = "0";
}

Transaction::Transaction(const string fromAccountNumber, const string toAccountNumber, const string amount)
{
  this->fromAccountNumber = fromAccountNumber;
  this->toAccountNumber = toAccountNumber;
  this->amount = amount;
}

Transaction::Transaction(const Transaction & copy)
{
  this->fromAccountNumber = copy.fromAccountNumber;
  this->toAccountNumber = copy.toAccountNumber;
  this->amount = copy.amount;
}

Transaction::~Transaction()
{

}

// Utility methods
void Transaction::print()
{
  cout << this->fromAccountNumber << "\t" << this->toAccountNumber << "\t" << this->amount << endl;
}

// Encryption methods - THESE ARE PROVIDED TO YOU
string Transaction::shiftCipherEncoder(string message, const string key)
{
    int offset = 33;
    int characters = 93;
    int keyValue = stol(key) % characters;

    for (unsigned int z = 0; z < message.size(); z++)
    {
        char currentCharacter = message[z];
        int currentValue = (int) currentCharacter;
        int normalizedValue = currentValue - offset;
        int encryptedValue = ((normalizedValue + keyValue) % characters) + offset;
        char encryptedCharacter = (char) encryptedValue;
        message[z] = encryptedCharacter;
    }

    return message;
}

string Transaction::shiftCipherDecoder(string message, const string key)
{
    int offset = 33;
    int characters = 93;
    int keyValue = stol(key) % characters;

    for (unsigned int z = 0; z < message.size(); z++)
    {
        char encryptedCharacter = message[z];
        int encryptedValue = (int) encryptedCharacter;
        int normalizedValue = encryptedValue - offset;
        int keyedValue = normalizedValue - keyValue;
        if (keyedValue < 0)
            keyedValue += characters;
        int decryptedValue = keyedValue + offset;
        char decryptedCharacter = (char) decryptedValue;
        message[z] = decryptedCharacter;
    }

    return message;
}

void Transaction::encrypt(const string accountNumber, const string PIN)
{
    // Create key from accountNumber + PIN
    string key = accountNumber + PIN;

    // Update attributes with encoded values
    this->fromAccountNumber = this->shiftCipherEncoder(this->fromAccountNumber, key);
    this->toAccountNumber = this->shiftCipherEncoder(this->toAccountNumber, key);
    this->amount = this->shiftCipherEncoder(this->amount, key);
}

bool Transaction::decrypt(const string accountNumber, const string PIN)
{
    // Create key from accountNumber + PIN
    string key = accountNumber + PIN;

    // Perform decoding and store into temp variables
    string testingFromAccountNumber = this->shiftCipherDecoder(this->fromAccountNumber, key);
    string testingToAccountNumber = this->shiftCipherDecoder(this->toAccountNumber, key);
    string testingAmount = this->shiftCipherDecoder(this->amount, key);

    // Check if decryption failed
    if (testingFromAccountNumber != accountNumber)
    {
        return false;
    }

    // Update attributes with temp variables in case decryption does not fail
    this->fromAccountNumber = testingFromAccountNumber;
    this->toAccountNumber = testingToAccountNumber;
    this->amount = testingAmount;

    return true;
}

// Getters
const string Transaction::getFromAccountNumber()
{
    return this->fromAccountNumber;
}

const string Transaction::getToAccountNumber()
{
    return this->toAccountNumber;
}

const string Transaction::getAmount()
{
    return this->amount;
}

// Setters
void Transaction::setFromAccountNumber(const string fromAccountNumber)
{
    this->fromAccountNumber = fromAccountNumber;
}

void Transaction::setToAccountNumber(const string toAccountNumber)
{
    this->toAccountNumber = toAccountNumber;
}

void Transaction::setAmount(const string amount)
{
    this->amount = amount;
}

