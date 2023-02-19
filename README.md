# Scripts

1. ./generate.sh - create decrypted transactions (outputs hacker account numbers, if any)
2. ./shuffle.sh - shuffle create decrypted transactions.
3. ./encrypt.sh - encrypt shuffled decrypted transactions.
4. ./test.sh - run main program
5. ./hackers.sh - get hackers not found in transactions

- ./reset.sh - resets created files (minus accounts.txt) and executables

# Data Files

- accounts.txt - provided account values
- decryptedTransactions.txt - generated transactions
- shuffledDecryptedTransactions.txt - shuffled(generated transactions)
- encryptedTransactions.txt - encrypted(shuffled(generated transactions))
- results.txt - decrypted(encrypted(shuffled(generated transactions)))

# Code Files

- Account.h
- Account.cpp
- Transaction.h
- Transaction.cpp
- main.cpp
- hackers.cpp
