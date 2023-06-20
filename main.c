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

// Structure to store account information
struct Account {
    int accountNumber;
    char name[50];
    char password[20];
    int phoneNum;
    float balance;
    struct address;
};

struct address {
    int houseNum;
    char street1[255];
    char street2[255];
};

// Structure to create instance of a transaction
struct Transaction {
    char date[20];
    int referenceNumber;
    long long int accountNumber;
    char transactionType[20];
    float amount;
    char status[20];
};

// Structure for linked list node
struct TransactionNode {
    struct Transaction transaction;
    struct TransactionNode* next;
};

// Global variable to track the head of the linked list
struct TransactionNode* head = NULL;

// Function prototypes
void createAccount();
void updateAccount();
void deleteAccount();
void userAuthentication();
void deposit();
void withdrawal();
void fundTransfer();
void billPayment();
void checkBalance();
void transactionHistory();
void generateAccountStatement(long long int accountNumber);
void searchReceipt();
int generateReferenceNumber();
void storeTransaction(char* date, long long int accountNumber, char* transactionType, float amount, char* status);
void retrieveTransactionsAndSort(long long int accountNumber);

int main() {
    int choice;

    while (1) {
        printf("\n-------------------------\n");
        printf("1. Create Account\n");
        printf("2. Update Account\n");
        printf("3. Delete Account\n");
        printf("4. Deposit\n");
        printf("5. Withdrawal\n");
        printf("6. Fund Transfer\n");
        printf("7. Bill Payment\n");
        printf("8. Check Balance\n");
        printf("9. Transaction History\n");
        printf("10. Generate Account Statement\n");
        printf("11. Search Receipt\n");
        printf("0. Exit\n");
        printf("-------------------------\n");
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
                deposit();
                break;
            case 5:
                withdrawal();
                break;
            case 6:
                fundTransfer();
                break;
            case 7:
                billPayment();
                break;
            case 8:
                checkBalance();
                break;
            case 9:
                transactionHistory();
                break;
            case 10:
                generateAccountStatement(123456789012);
                break;
            case 11:
                searchReceipt();
                break;
            case 0:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

// Function 1: Account Management Functions

void createAccount() {
    // Implement the functionality to create a new user account
}

void updateAccount() {
    // Implement the functionality to update user account details
}

void deleteAccount() {
    // Implement the functionality to delete a user account
}

void userAuthentication() {
    // Implement the functionality to authenticate a user
}

// Function 2: Transaction Functions

void deposit() {
    // Implement the functionality to deposit funds into an account
}

void withdrawal() {
    // Implement the functionality to withdraw funds from an account
}

void fundTransfer() {
    // Implement the functionality to transfer funds between accounts
}

void billPayment() {
    // Implement the functionality to pay bills from an account
}

// Function 3: Account Inquiry Functions

void checkBalance() {
    int accountNumber;
    printf("Enter your account number: ");
    scanf("%d", &accountNumber);

    //amri
    // Implement the functionality to check the account balance
}

void transactionHistory() {
    //amri
    // Implement the functionality to display transaction history

    // Temporary code to add a sample transaction **Please don't delete until checking with me - Habib
    char* date = "2023-06-17";
    long long int accountNumber = 123456789012;
    char* transactionType = "Fund";
    float amount = 50.5;
    char* status = "Outgoing";

    storeTransaction(date, accountNumber, transactionType, amount, status);
    retrieveTransactionsAndSort(accountNumber);

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

// Function 5: Print Receipt

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
