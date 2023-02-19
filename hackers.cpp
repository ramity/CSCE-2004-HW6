#include <vector>
#include <fstream>
#include <iostream>
#include "Account.h"
#include "Transaction.h"


void accountRead(string filename, vector<Account> & accounts)
{
    ifstream din;
    // Open provided file
    din.open(filename);

    // Process file into accounts vector
    string firstName, lastName, PIN, accountNumber;

    while(!din.eof())
    {
        din >> firstName;
        din >> lastName;
        din >> PIN;
        din >> accountNumber;
        Account account(firstName, lastName, PIN, accountNumber);

        if(!din.eof())
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

    while(!din.eof())
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
    // Init required variables
    vector<Account> accounts;
    vector<Transaction> transactions;
    Account donnasAccount;

    // Read in accounts
    accountRead("accounts.txt", accounts);

    // Read in transactions
    transactionRead("encryptedTransactions.txt", transactions);

    // Decrypt all transactions
    for (int y = 0; y < accounts.size(); y++)
    {
        bool found = false;
        for (int z = 0; z < transactions.size(); z++)
        {
            if (transactions[z].decrypt(accounts[y].getAccountNumber(), accounts[y].getPIN()))
            {
                found = true;
                break;
            }
        }
        if (found == false)
        {
            cout << "Hacker found!" << endl;
            accounts[y].print();
        }
    }
}
