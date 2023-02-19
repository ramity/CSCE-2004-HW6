#include <vector>
#include <fstream>
#include <iostream>
#include "Transaction.h"

// For generating data
#include <time.h>
#include <stdlib.h>

// For shuffling vector
#include <algorithm>

using namespace std;

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
  srand(time(0));
  vector<Transaction> transactions;
  transactionRead("decryptedTransactions.txt", transactions);
  random_shuffle(transactions.begin(), transactions.end());
  transactionWrite("shuffledDecryptedTransactions.txt", transactions);
  return 0;
}

