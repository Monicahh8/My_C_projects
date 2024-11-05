#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ACCOUNTS 100

// Structure to represent a bank account
struct Account {
    char accountNumber[20];
    char holderName[50];
    float balance;
    int isActive; // Flag to track if the account is active or closed
};

// Function to get current timestamp
void getCurrentTime(char timestamp[]);

// Function prototypes
int login();
void createAccount(struct Account accounts[], int *numAccounts);
void deposit(struct Account accounts[], int numAccounts);
void withdraw(struct Account accounts[], int numAccounts);
void balanceEnquiry(struct Account accounts[], int numAccounts);
void listAccounts(struct Account accounts[], int numAccounts);
void updateAccount(struct Account accounts[], int numAccounts);
void closeAccount(struct Account accounts[], int *numAccounts);
void logout();

int main() {
    int authenticated;
    struct Account accounts[MAX_ACCOUNTS];
    int numAccounts = 0;
    int choice;

    authenticated = login();

    if (!authenticated) {
        printf("Authentication failed. Exiting...\n");
        return 1;
    }

    while (1) {
        char timestamp[20];
        getCurrentTime(timestamp);

        printf("\nBANK MANAGEMENT SYSTEM\n");
        printf("Timestamp: %s\n", timestamp);
        printf("1. CREATE ACCOUNT\n");
        printf("2. DEPOSIT TO ACCOUNT\n");
        printf("3. WITHDRAW MONEY\n");
        printf("4. BALANCE ENQUIRY\n");
        printf("5. ACC HOLDERS LIST\n");
        printf("6. UPDATE ACCOUNT\n");
        printf("7. CLOSE AN ACCOUNT\n");
        printf("8. LOG OUT\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createAccount(accounts, &numAccounts);
                break;
            case 2:
                deposit(accounts, numAccounts);
                break;
            case 3:
                withdraw(accounts, numAccounts);
                break;
            case 4:
                balanceEnquiry(accounts, numAccounts);
                break;
            case 5:
                listAccounts(accounts, numAccounts);
                break;
            case 6:
                updateAccount(accounts, numAccounts);
                break;
            case 7:
                closeAccount(accounts, &numAccounts);
                break;
            case 8:
                logout();
                return 0;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    }

    return 0;
}

int login() {
    char username[20];
    char password[20];

    printf("Enter username: ");
    scanf("%s", username);

    printf("Enter password: ");
    scanf("%s", password);

    // Simple hardcoded login credentials
    if (strcmp(username, "admin") == 0 && strcmp(password, "password") == 0) {
        printf("Login successful.\n");
        return 1;
    } else {
        printf("Login failed.\n");
        return 0;
    }
}

void getCurrentTime(char timestamp[]) {
    time_t t;
    struct tm* tmp;

    t = time(NULL);
    tmp = localtime(&t);

    strftime(timestamp, 20, "%Y-%m-%d %H:%M:%S", tmp);
}

void createAccount(struct Account accounts[], int *numAccounts) {
    // Implementation for creating a new account
    char timestamp[20];
    getCurrentTime(timestamp);
    printf("\n%s - Enter account number: ", timestamp);
    scanf("%s", accounts[*numAccounts].accountNumber);
    printf("%s - Enter account holder name: ", timestamp);
    scanf("%s", accounts[*numAccounts].holderName);
    printf("%s - Enter initial balance: ", timestamp);
    scanf("%f", &accounts[*numAccounts].balance);
    accounts[*numAccounts].isActive = 1; // Account is active
    (*numAccounts)++;
    printf("%s - Account created successfully.\n", timestamp);
}

void deposit(struct Account accounts[], int numAccounts) {
    // Implementation for depositing money into an account
    char timestamp[20];
    getCurrentTime(timestamp);
    char accNum[20];
    float amount;
    printf("\n%s - Enter account number: ", timestamp);
    scanf("%s", accNum);

    for (int i = 0; i < numAccounts; i++) {
        if (strcmp(accounts[i].accountNumber, accNum) == 0 && accounts[i].isActive) {
            printf("%s - Enter deposit amount: ", timestamp);
            scanf("%f", &amount);
            accounts[i].balance += amount;
            printf("%s - Deposit successful. Updated balance: %.2f\n", timestamp, accounts[i].balance);
            return;
        }
    }

    printf("%s - Account not found or closed.\n", timestamp);
}

void withdraw(struct Account accounts[], int numAccounts) {
    // Implementation for withdrawing money from an account
    char timestamp[20];
    getCurrentTime(timestamp);
    char accNum[20];
    float amount;
    printf("\n%s - Enter account number: ", timestamp);
    scanf("%s", accNum);

    for (int i = 0; i < numAccounts; i++) {
        if (strcmp(accounts[i].accountNumber, accNum) == 0 && accounts[i].isActive) {
            printf("%s - Enter withdrawal amount: ", timestamp);
            scanf("%f", &amount);
            if (amount <= accounts[i].balance) {
                accounts[i].balance -= amount;
                printf("%s - Withdrawal successful. Updated balance: %.2f\n", timestamp, accounts[i].balance);
            } else {
                printf("%s - Insufficient balance.\n", timestamp);
            }
            return;
        }
    }

    printf("%s - Account not found or closed.\n", timestamp);
}

void balanceEnquiry(struct Account accounts[], int numAccounts) {
    // Implementation for checking the balance of an account
    char timestamp[20];
    getCurrentTime(timestamp);
    char accNum[20];
    printf("\n%s - Enter account number: ", timestamp);
    scanf("%s", accNum);

    for (int i = 0; i < numAccounts; i++) {
        if (strcmp(accounts[i].accountNumber, accNum) == 0 && accounts[i].isActive) {
            printf("%s - Account Holder: %s\n", timestamp, accounts[i].holderName);
            printf("%s - Account Balance: %.2f\n", timestamp, accounts[i].balance);
            return;
        }
    }

    printf("%s - Account not found or closed.\n", timestamp);
}

void listAccounts(struct Account accounts[], int numAccounts) {
    // Implementation for listing all accounts
    char timestamp[20];
    getCurrentTime(timestamp);
    printf("\n%s - ACCOUNT HOLDERS LIST\n", timestamp);
    for (int i = 0; i < numAccounts; i++) {
        if (accounts[i].isActive) {
            printf("%s - Account Number: %s\n", timestamp, accounts[i].accountNumber);
            printf("%s - Account Holder: %s\n", timestamp, accounts[i].holderName);
            printf("%s - Account Balance: %.2f\n", timestamp, accounts[i].balance);
            printf("%s - --------------------------\n", timestamp);
        }
    }
}

void updateAccount(struct Account accounts[], int numAccounts) {
    // Implementation for updating account
    char timestamp[20];
    getCurrentTime(timestamp);
    char accNum[20];
    printf("\n%s - Enter account number: ", timestamp);
    scanf("%s", accNum);

    for (int i = 0; i < numAccounts; i++) {
        if (strcmp(accounts[i].accountNumber, accNum) == 0 && accounts[i].isActive) {
            printf("%s - Enter new account holder name: ", timestamp);
            scanf("%s", accounts[i].holderName);
            printf("%s - Account information updated successfully.\n", timestamp);
            return;
        }
    }

    printf("%s - Account not found or closed.\n", timestamp);
}

void closeAccount(struct Account accounts[], int *numAccounts) {
    // Implementation for closing an account
    char timestamp[20];
    getCurrentTime(timestamp);
    char accNum[20];
    printf("\n%s - Enter account number to close: ", timestamp);
    scanf("%s", accNum);

    for (int i = 0; i < *numAccounts; i++) {
        if (strcmp(accounts[i].accountNumber, accNum) == 0 && accounts[i].isActive) {
            accounts[i].isActive = 0; // Mark account as closed
            printf("%s - Account closed successfully.\n", timestamp);
            return;
        }
    }

    printf("%s - Account not found or already closed.\n", timestamp);
}

void logout() {
    // Implementation for logging out
    printf("Logged out successfully.\n");
}
