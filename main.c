/*
* Online Banking System *****
* Purpose: Created for BCI1093 - DATA STRUCTURE & ALGORITHMS assessment as mini-project.
* Created by:
*   1. MOHAMED HABIBALLA ABDELMOEZ MOHAMED ALI (CB19143)
*   2. MOHAMAD AMRI FAKHRI BIN MOHD ZAIDI (CB21076)
*   3. NAME (MATRIC)
*   4. NAME (MATRIC)
*   5. NAME (MATRIC)
* Created on: June 15, 2023
* First Release: ---
* Latest Release: ---
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ACCOUNTS 100
#define MAX_USERNAME_LENGTH 50
#define MAX_PASSWORD_LENGTH 50
#define MAX_NAME_LENGTH 50
#define MAX_PHONE_LENGTH 50
#define MAX_ACCOUNTS 100



struct BankAccount {
    int accountNumber;
    float balance;
};

struct BankAccount bankAccounts[MAX_ACCOUNTS];

struct Address{
  char address[50];
};


struct User{
    char name [MAX_NAME_LENGTH];
    char phoneNum[MAX_PHONE_LENGTH];
};

struct Account {
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
    // Additional account information
    struct User detail;
    struct Address info;
};

struct Transaction {
    char date[20];
    int referenceNumber;
    long long int accountNumber;
    char transactionType[20];
    float amount;
    char status[20];
};

// Structure to create instance of a transaction
struct TransactionNode {
    struct Transaction transaction;
    struct TransactionNode* next;
};

// Global variable to track the head of the linked list
struct TransactionNode* head = NULL;

struct Account accounts[MAX_ACCOUNTS];
int numAccounts = 0;

void injectFile();
//void injectLinkedList();
void storeTransaction(char* date, long long int accountNumber, char* transactionType, float amount, char* status);
void retrieveTransactionsAndSort(long long int accountNumber);
void transactionHistory();
void generateAccountStatement(long long int accountNumber);


void updateBalance(int accountNumber, float amount) {
    // Search for the account in the bankAccounts array
    for (int i = 0; i < MAX_ACCOUNTS; i++) {
        if (bankAccounts[i].accountNumber == accountNumber) {
            // Update the balance of the account
            bankAccounts[i].balance += amount;
            break;
        }
    }
}




// Function to create a new account
void createAccount() {
    if (numAccounts >= MAX_ACCOUNTS) {
        printf("Maximum number of accounts reached!\n");
        return;
    }

    struct Account newAccount;
    printf("Enter username: ");
    scanf("%s", newAccount.username);
    printf("Enter password: ");
    scanf("%s", newAccount.password);
    printf("Enter your name: ");
    scanf("%s", newAccount.detail.name);
    printf("Enter your phone number: ");
    scanf("%s", newAccount.detail.phoneNum);
    printf("Enter your address: ");
    scanf("%s", newAccount.info.address);
    // Additional input for account information if needed

    accounts[numAccounts] = newAccount;
    numAccounts++;
    printf("Account created successfully!\n");
}

//startttsadasd
// Function to perform a deposit into a bank account
void deposit() {
    int accountNumber;
    float amount;
    printf("Enter account number: ");
    scanf("%d", &accountNumber);
    printf("Enter deposit amount: ");
    scanf("%f", &amount);

    updateBalance(accountNumber, amount);
}


// Function to perform a withdrawal from a bank account
void withdrawal() {
    int accountNumber;
    float amount;
    printf("Enter account number: ");
    scanf("%d", &accountNumber);
    printf("Enter withdrawal amount: ");
    scanf("%f", &amount);

    int i;
    for (i = 0; i < numAccounts; i++) {
        if (bankAccounts[i].accountNumber == accountNumber) {
            if (bankAccounts[i].balance >= amount) {
                bankAccounts[i].balance -= amount;
                printf("Withdrawal successful.\n");
            } else {
                printf("Insufficient balance.\n");
            }
            return;
        }
    }
    printf("Account not found.\n");
}


// Function to perform fund transfer between bank accounts
void fundTransfer() {
    int senderAccountNumber, recipientAccountNumber;
    float amount;
    printf("Enter sender's account number: ");
    scanf("%d", &senderAccountNumber);
    printf("Enter recipient's account number: ");
    scanf("%d", &recipientAccountNumber);
    printf("Enter transfer amount: ");
    scanf("%f", &amount);

    int senderIndex = -1, recipientIndex = -1;
    int i;
    for (i = 0; i < numAccounts; i++) {
        if (bankAccounts[i].accountNumber == senderAccountNumber) {
            senderIndex = i;
        }
        if (bankAccounts[i].accountNumber == recipientAccountNumber) {
            recipientIndex = i;
        }
    }

    if (senderIndex == -1 || recipientIndex == -1) {
        printf("One or both accounts not found.\n");
        return;
    }

    if (bankAccounts[senderIndex].balance >= amount) {
        bankAccounts[senderIndex].balance -= amount;
        bankAccounts[recipientIndex].balance += amount;
        printf("Transfer successful.\n");
    } else {
        printf("Insufficient balance.\n");
    }
}

// Function to perform bill payment from a bank account
void billPayment() {
    int accountNumber;
    float amount;
    printf("Enter account number: ");
    scanf("%d", &accountNumber);
    printf("Enter bill amount: ");
    scanf("%f", &amount);

    updateBalance(accountNumber, -amount);
    printf("Bill payment successful.\n");
}

//sadasdasdasd




// Function to update an existing account
void updateAccount() {
    char username[MAX_USERNAME_LENGTH];
    printf("Enter username: ");
    scanf("%s", username);

    for (int i = 0; i < numAccounts; i++) {
        if (strcmp(accounts[i].username, username) == 0) {
            printf("Enter new password: ");
            scanf("%s", accounts[i].password);
            printf("Enter new phone number: ");
            scanf("%s", accounts[i].detail.phoneNum);
            printf("Enter new address: ");
            scanf("%s", accounts[i].info.address);
            // Additional updates for account information if needed

            printf("Account updated successfully!\n");
            return;
        }
    }

    printf("Account not found!\n");
}

// Function to delete an existing account
void deleteAccount() {
    char username[MAX_USERNAME_LENGTH];
    printf("Enter username: ");
    scanf("%s", username);

    for (int i = 0; i < numAccounts; i++) {
        if (strcmp(accounts[i].username, username) == 0) {
            // Shift remaining accounts to fill the gap
            for (int j = i; j < numAccounts - 1; j++) {
                accounts[j] = accounts[j + 1];
            }
            numAccounts--;
            printf("Account deleted successfully!\n");
            return;
        }
    }

    printf("Account not found!\n");
}


void displayInfo() {
    char username[MAX_USERNAME_LENGTH];
    printf("Enter username: ");
    scanf("%s", username);

    for (int i = 0; i < numAccounts; i++) {
        if (strcmp(accounts[i].username, username) == 0) {
            printf("\n--------User Information---------------\n");
            printf("\nName = %s",accounts[i].detail.name);
            printf("\nPhone Number = %s",accounts[i].detail.phoneNum);
            printf("\nAddress = %s",accounts[i].info.address);

            return;
        }
    }

    printf("Account not found!\n");
}



// Function to authenticate a user
int authenticate() {
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
    printf("Enter username: ");
    scanf("%s", username);
    printf("Enter password: ");
    scanf("%s", password);

    for (int i = 0; i < numAccounts; i++) {
        if (strcmp(accounts[i].username, username) == 0 && strcmp(accounts[i].password, password) == 0) {
            printf("Authentication successful!\n");
            return 1;
        }
    }

    printf("Authentication failed!\n");
    return 0;
}


void injectFile() {
    char* date = "2023-06-17";
    long long int accountNumber = 123456789012;
    char* transactionType = "Fund";
    float amount = 500.5;
    char* status = "Outgoing";

    storeTransaction(date, accountNumber, transactionType, amount, status);
    //retrieveTransactionsAndSort(accountNumber);

    date = "2023-06-18";
    accountNumber = 123456789018;
    transactionType = "Bill";
    amount = 37.82;
    status = "Outgoing";

    storeTransaction(date, accountNumber, transactionType, amount, status);
    //retrieveTransactionsAndSort(accountNumber);

    date = "2023-06-20";
    accountNumber = 123456789018;
    transactionType = "Bill";
    amount = 50.5;
    status = "Outgoing";

    storeTransaction(date, accountNumber, transactionType, amount, status);
    //retrieveTransactionsAndSort(accountNumber);

    date = "2023-06-18";
    accountNumber = 123456789018;
    transactionType = "Fund";
    amount = 50.5;
    status = "Outgoing";

    storeTransaction(date, accountNumber, transactionType, amount, status);
    //retrieveTransactionsAndSort(accountNumber);
    printf("\033[2J");
}

void storeTransaction(char* date, long long int accountNumber, char* transactionType, float amount, char* status) {
    struct TransactionNode* newNode = (struct TransactionNode*)malloc(sizeof(struct TransactionNode));
    if (newNode == NULL) {
        printf("Failed to allocate memory.\n");
        return;
    }

    int referenceNumber = generateReferenceNumber();

    strcpy(newNode->transaction.date, date);
    newNode->transaction.referenceNumber = referenceNumber;
    newNode->transaction.accountNumber = accountNumber;
    strcpy(newNode->transaction.transactionType, transactionType);
    newNode->transaction.amount = amount;
    strcpy(newNode->transaction.status, status);

    newNode->next = head;
    head = newNode;

    printf("Storing transaction: %s %d %lld %s %.2f %s\n", newNode->transaction.date, newNode->transaction.referenceNumber,
           newNode->transaction.accountNumber, newNode->transaction.transactionType, newNode->transaction.amount, newNode->transaction.status);
    printf("Transaction recorded successfully.\n");

    // Code to store the transaction in a file (append mode)
    FILE* fileptr = fopen("transactions.txt", "a");
    if (fileptr == NULL) {
        printf("Failed to open transactions file.\n");
        return;
    }

    fprintf(fileptr, "%s\t%d\t%lld\t%s\t%.2f\t%s\n", newNode->transaction.date, newNode->transaction.referenceNumber,
            newNode->transaction.accountNumber, newNode->transaction.transactionType, newNode->transaction.amount, newNode->transaction.status);

    fclose(fileptr);
}

void retrieveTransactionsAndSort(long long int accountNumber) {
    // Retrieve the transactions with the same account number and store them in a temporary array
    struct TransactionNode* current = head;
    struct Transaction* transactions = NULL;
    int transactionCount = 0;

    while (current != NULL) {
        if (current->transaction.accountNumber == accountNumber) {
            // Reallocate memory to accommodate the new transaction
            transactionCount++;
            transactions = realloc(transactions, transactionCount * sizeof(struct Transaction));
            if (transactions == NULL) {
                printf("Failed to allocate memory.\n");
                return;
            }

            // Copy the transaction to the temporary array
            memcpy(&transactions[transactionCount - 1], &current->transaction, sizeof(struct Transaction));
        }
        current = current->next;
    }

    // Sort the transactions based on date and amount
    for (int i = 0; i < transactionCount - 1; i++) {
        for (int j = 0; j < transactionCount - i - 1; j++) {
            // Compare dates (assuming the date format is "YYYY-MM-DD")
            int year1, month1, day1, year2, month2, day2;
            sscanf(transactions[j].date, "%d-%d-%d", &year1, &month1, &day1);
            sscanf(transactions[j + 1].date, "%d-%d-%d", &year2, &month2, &day2);

            // Compare amounts
            float amount1 = transactions[j].amount;
            float amount2 = transactions[j + 1].amount;

            // Swap if the dates or amounts are in the wrong order
            if (year1 > year2 || (year1 == year2 && (month1 > month2 || (month1 == month2 && day1 > day2))) ||
                (year1 == year2 && month1 == month2 && day1 == day2 && amount1 > amount2)) {
                struct Transaction temp = transactions[j];
                transactions[j] = transactions[j + 1];
                transactions[j + 1] = temp;
            }
        }
    }

    // Print the sorted transactions
    for (int i = 0; i < transactionCount; i++) {
        printf("%-10s\t%d\t\t%s\t%.2f\t%-19s\n", transactions[i].date, transactions[i].referenceNumber,
               transactions[i].transactionType, transactions[i].amount, transactions[i].status);
    }

    // Free the temporary array
    free(transactions);
}

void searchReceipt() {
    // Implement the functionality to search and display a receipt
    int referenceNumber;
    printf("Enter the reference number: ");
    scanf("%d", &referenceNumber);

    struct TransactionNode* current = head;
    while (current != NULL) {
        if (current->transaction.referenceNumber == referenceNumber) {
            printf("Receipt Found:\n");
            printf("-------------------------\n");
            printf("Date: %s\n", current->transaction.date);
            printf("Account Number: %lld\n", current->transaction.accountNumber);
            printf("Transaction Type: %s\n", current->transaction.transactionType);
            printf("Amount: %.2f\n", current->transaction.amount);
            printf("Status: %s\n", current->transaction.status);
            printf("-------------------------\n");
            return;
        }
        current = current->next;
    }

    printf("Receipt not found.\n");
}

int generateReferenceNumber() {
    srand(time(NULL));
    return rand() % 90000 + 10000;
}



void transactionHistory() {
    // Implement the functionality to display transaction history

    // Temporary code to add a sample transaction **Please don't delete until checking with me - Habib
    char* date = "2023-06-17";
    long long int accountNumber = 123456789012;
    char* transactionType = "Fund";
    float amount = 50.5;
    char* status = "Outgoing";

    storeTransaction(date, accountNumber, transactionType, amount, status);
    //retrieveTransactionsAndSort(accountNumber);

}

// Function 4: Statement Generation Functions

void generateAccountStatement(long long int accountNumber) {
    // Implement the functionality to generate an account statement
    printf("Account Statement for Account Number: %lld\n", accountNumber);
    printf("-----------------------------------------------------\n");
    printf("Date\t\tReference\tType\tAmount\tStatus\n");
    printf("-----------------------------------------------------\n");

    retrieveTransactionsAndSort(accountNumber);
}









int main() {
    int choice;
    injectFile();

    while (1) {
        printf("\n---------------------\n");
        printf("\nMenu");
        printf("\n1. Create account\n");
        printf("2. Update account\n");
        printf("3. Delete account\n");
        printf("4. Authenticate\n");
        printf("5. Display Info\n"); //searching
        printf("6. Display Transaction\n");
        printf("7. Account Statement\n");
        printf("8. Deposit\n");
        printf("9. Withdrawal\n");
        printf("10. Fund Transfer\n");
        printf("11. Bill Payment\n");
        printf("12. Exit\n");
        printf("\n---------------------\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createAccount();
                break;
            case 2:
                updateAccount();
                break;
            case 3:
                deleteAccount();
                break;
            case 4:
                authenticate();
                break;
            case 5:
                displayInfo();
                break;
            case 6:
                transactionHistory();
                break;
             case 7:
              generateAccountStatement(123456789012);
                break;
              case 8:
                deposit();
                break;
            case 9:
                withdrawal();
                break;
            case 10:
                fundTransfer();
                break;
            case 11:
                billPayment();
                break;
            case 12:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
    }

    return 0;
}

