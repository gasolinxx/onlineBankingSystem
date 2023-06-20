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
void generateAccountStatement();
void searchReceipt();

int main() {
    int choice;

    while (1) {
        printf("\n-------------------------\n");
        printf("1. Create Account\n");
        printf("2. Update Account\n");
        printf("3. Delete Account\n");
        printf("4. User Authentication\n");
        printf("5. Deposit\n");
        printf("6. Withdrawal\n");
        printf("7. Fund Transfer\n");
        printf("8. Bill Payment\n");
        printf("9. Check Balance\n");
        printf("10. Transaction History\n");
        printf("11. Generate Account Statement\n");
        printf("12. Search Receipt\n");
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
                userAuthentication();
                break;
            case 5:
                deposit();
                break;
            case 6:
                withdrawal();
                break;
            case 7:
                fundTransfer();
                break;
            case 8:
                billPayment();
                break;
            case 9:
                checkBalance();
                break;
            case 10:
                transactionHistory();
                break;
            case 11:
                generateAccountStatement();
                break;
            case 12:
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
}

// Function 4: Statement Generation Functions

void generateAccountStatement() {
    // Implement the functionality to generate an account statement
}

// Function 5: Print Receipt

void searchReceipt() {
    // Implement the functionality to search and display a receipt
}
