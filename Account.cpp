// Includes

#include "Account.h"
#include <iostream>
#include <fstream>

// Constructors

Account::Account()
{
    this->firstName = "";
    this->lastName = "";
    this->PIN = "9999";
    this->accountNumber = "9999999999";
}

Account::Account(const string firstName, const string lastName, const string PIN, const string accountNumber)
{
    this->firstName = firstName;
    this->lastName = lastName;
    this->PIN = PIN;
    this->accountNumber = accountNumber;
}

Account::Account(const Account & copy)
{
    this->firstName = copy.firstName;
    this->lastName = copy.lastName;
    this->PIN = copy.PIN;
    this->accountNumber = copy.accountNumber;
}

Account::~Account()
{

}

// Utility methods

void Account::print()
{
    cout << this->firstName << "\t" << this->lastName << "\t" << this->PIN << "\t" << this->accountNumber << endl;
}

// Getters

const string Account::getFirstName()
{
    return this->firstName;
}

const string Account::getLastName()
{
    return this->lastName;
}

const string Account::getPIN()
{
    return this->PIN;
}

const string Account::getAccountNumber()
{
    return this->accountNumber;
}

// Setters
void Account::setFirstName(const string firstName)
{
    this->firstName = firstName;
}

void Account::setLastName(const string lastName)
{
    this->lastName = lastName;
}

void Account::setPIN(const string PIN)
{
    this->PIN = PIN;
}

void Account::setAccountNumber(const string accountNumber)
{
    this->accountNumber = accountNumber;
}

