#include <vector>
#include <fstream>
#include <iostream>
#include "Account.h"
#include "Transaction.h"

// For generating data
#include <time.h>
#include <stdlib.h>

using namespace std;

void accountRead(string filename, vector<Account> & accounts)
{
    ifstream din;
    // Open provided file
    din.open(filename);

    // Process file into accounts vector
    string firstName, lastName, PIN, accountNumber;

    while(!din.fail() && !din.eof())
    {
        din >> firstName;
        din >> lastName;
        din >> PIN;
        din >> accountNumber;
        Account account(firstName, lastName, PIN, accountNumber);

        if (!din.eof())
            accounts.push_back(account);
    }

    // Close provided file
    din.close();
}

void accountWrite(string filename, vector<Account> accounts)
{
    ofstream dout;
    // Open provided file
    dout.open(filename);

    for (int z = 0; z < accounts.size(); z++)
    {
        dout << accounts[z].getFirstName() << " " << accounts[z].getLastName() << " " << accounts[z].getPIN() << " " << accounts[z].getAccountNumber() << endl;
    }

    // Close provided file
    dout.close();
}

void transactionRead(string filename, vector<Transaction> & transactions)
{
    ifstream din;
    // Open transactions file
    din.open(filename);

    // Process file into transactions vector
    string from, to, amount;

    while(!din.fail() && !din.eof())
    {
        din >> from;
        din >> to;
        din >> amount;
        Transaction transaction(from, to, amount);

        if(!din.eof())
            transactions.push_back(transaction);
    }

    // Close transactions file
    din.close();
}

void transactionWrite(string filename, vector<Transaction> transactions)
{
    ofstream dout;
    // Open provided file
    dout.open(filename);

    for (int z = 0; z < transactions.size(); z++)
    {
        dout << transactions[z].getFromAccountNumber() << " " << transactions[z].getToAccountNumber() << " " << transactions[z].getAmount() << endl;
    }

    // Close provided file
    dout.close();
}

int main()
{
  // Seed srand with current time
  srand(time(0));

  vector<Account> accounts;
  accountRead("accounts.txt", accounts);

  ofstream dout;
  dout.open("decryptedTransactions.txt");

  // Generate random transaction data using account data
  for (unsigned int z = 0; z < accounts.size(); z++)
  {
    int numberOfTransactions = rand() % 100;

    if (numberOfTransactions == 0)
    {
      std::cout << accounts[z].getAccountNumber() << std::endl;
    }

    for (int y = 0; y < numberOfTransactions; y++)
    {
      // Generate random values for transaction data
      int toAccountIndex = rand() % 100;
      int amountDollars = rand() % 1000 + 1;
      int amountCents = rand() % 100 + 1;
      std::string amountDollarsString = std::to_string(amountDollars);
      std::string amountCentsString = std::to_string(amountCents);

      // Add a leading zero if the string is a singular digit.
      if (amountCentsString.size() == 1)
      {
        amountCentsString.insert(0, 1, '0');
      }

      std::string amount = '$' + amountDollarsString + '.' + amountCentsString;

      // Create transaction instance and write to transactions file
      dout << accounts[z].getAccountNumber() << " " << accounts[toAccountIndex].getAccountNumber() << " " << amount << endl;
    }
  }

  return 0;
}

