#include <vector>
#include <fstream>
#include <iostream>
#include "Account.h"
#include "Transaction.h"

// For generating data
#include <time.h>
#include <stdlib.h>

// For shuffling vector
#include <algorithm>

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
  srand(time(0));
  vector<Account> accounts;
  vector<Transaction> transactions;
  accountRead("accounts.txt", accounts);
  transactionRead("shuffledDecryptedTransactions.txt", transactions);

  for (int z = 0; z < transactions.size(); z++)
  {
    string num = transactions[z].getFromAccountNumber();
    string pin = " ";

    for (int y = 0; y < accounts.size(); y++)
    {
        if (num == accounts[y].getAccountNumber())
        {
            pin = accounts[y].getPIN();
            break;
        }
    }

    if (pin == " ")
    {
        cout << "PIN NOT FOUND" << endl;
    }
    else
    {
        //cout << transactions[z].getFromAccountNumber() << "==" << num << "=>" << pin << endl;
    }

    transactions[z].encrypt(num, pin);
  }

  transactionWrite("encryptedTransactions.txt", transactions);
  return 0;
}

