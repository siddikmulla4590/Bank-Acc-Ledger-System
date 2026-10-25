
#include <stdio.h>
#include <string.h>

#define MAX 100

struct Account {
    int accountNo;
    char name[50];
    char accountType[20];
    float balance;
    float interest;
};

// Display all accounts
void displayAccounts(struct Account acc[], int n) {
    int i;

    printf("\n========== ALL ACCOUNTS ==========\n");

    for (i = 0; i < n; i++) {
        printf("\nAccount Number : %d", acc[i].accountNo);
        printf("\nName           : %s", acc[i].name);
        printf("\nAccount Type   : %s", acc[i].accountType);
        printf("\nBalance        : Rs. %.2f\n", acc[i].balance);
    }
}

// Deposit money
void deposit(struct Account acc[], int n) {
    int accountNo, i;
    float amount;

    printf("\nEnter Account Number: ");
    scanf("%d", &accountNo);

    for (i = 0; i < n; i++) {
        if (acc[i].accountNo == accountNo) {
            printf("Enter deposit amount: Rs. ");
            scanf("%f", &amount);

            if (amount > 0) {
                acc[i].balance += amount;

                printf("\nAmount deposited successfully!");
                printf("\nNew Balance: Rs. %.2f\n",
                       acc[i].balance);
            } else {
                printf("\nInvalid amount!\n");
            }
            return;
        }
    }

    printf("\nAccount not found!\n");
}

// Withdraw money
void withdraw(struct Account acc[], int n) {
    int accountNo, i;
    float amount;

    printf("\nEnter Account Number: ");
    scanf("%d", &accountNo);

    for (i = 0; i < n; i++) {
        if (acc[i].accountNo == accountNo) {
            printf("Enter withdrawal amount: Rs. ");
            scanf("%f", &amount);

            if (amount <= 0) {
                printf("\nInvalid amount!\n");
            } else if (amount > acc[i].balance) {
                printf("\nInsufficient balance!\n");
            } else {
                acc[i].balance -= amount;

                printf("\nAmount withdrawn successfully!");
                printf("\nNew Balance: Rs. %.2f\n",
                       acc[i].balance);
            }
            return;
        }
    }

    printf("\nAccount not found!\n");
}

// Apply annual interest
void applyInterest(struct Account acc[], int n) {
    int i;
    float rate;

    for (i = 0; i < n; i++) {
        if (strcmp(acc[i].accountType, "Savings") == 0 ||
            strcmp(acc[i].accountType, "savings") == 0) {
            rate = 4.0;
        } else if (strcmp(acc[i].accountType, "Current") == 0 ||
                   strcmp(acc[i].accountType, "current") == 0) {
            rate = 2.0;
        } else {
            printf("\nInvalid account type for account %d\n",
                   acc[i].accountNo);
            continue;
        }

        acc[i].interest = acc[i].balance * rate / 100;
        acc[i].balance += acc[i].interest;
    }

    printf("\nAnnual interest applied successfully!\n");
}

// Display interest details
void displayInterest(struct Account acc[], int n) {
    int i;
    float rate;

    printf("\n========== INTEREST DETAILS ==========\n");

    for (i = 0; i < n; i++) {
        if (strcmp(acc[i].accountType, "Savings") == 0 ||
            strcmp(acc[i].accountType, "savings") == 0) {
            rate = 4.0;
        } else if (strcmp(acc[i].accountType, "Current") == 0 ||
                   strcmp(acc[i].accountType, "current") == 0) {
            rate = 2.0;
        } else {
            continue;
        }

        printf("\nAccount Number : %d", acc[i].accountNo);
        printf("\nName           : %s", acc[i].name);
        printf("\nAccount Type   : %s", acc[i].accountType);
        printf("\nInterest Rate  : %.2f%%", rate);
        printf("\nPrevious Balance: Rs. %.2f",
               acc[i].balance - acc[i].interest);
        printf("\nInterest Amount : Rs. %.2f", acc[i].interest);
        printf("\nNew Balance     : Rs. %.2f\n", acc[i].balance);
    }
}

// Find highest and lowest balance
void findHighestLowest(struct Account acc[], int n) {
    int i;
    int highest = 0;
    int lowest = 0;

    for (i = 1; i < n; i++) {
        if (acc[i].balance > acc[highest].balance) {
            highest = i;
        }

        if (acc[i].balance < acc[lowest].balance) {
            lowest = i;
        }
    }

    printf("\n========== HIGHEST BALANCE ==========\n");
    printf("Account Number : %d\n", acc[highest].accountNo);
    printf("Name           : %s\n", acc[highest].name);
    printf("Balance        : Rs. %.2f\n", acc[highest].balance);

    printf("\n========== LOWEST BALANCE ==========\n");
    printf("Account Number : %d\n", acc[lowest].accountNo);
    printf("Name           : %s\n", acc[lowest].name);
    printf("Balance        : Rs. %.2f\n", acc[lowest].balance);
}

// Minimum balance alert
void minimumBalanceAlert(struct Account acc[], int n) {
    int i;
    int count = 0;

    printf("\n========== MINIMUM BALANCE ALERT ==========\n");

    for (i = 0; i < n; i++) {
        if (acc[i].balance < 1000) {
            printf("\nAccount Number : %d", acc[i].accountNo);
            printf("\nName           : %s", acc[i].name);
            printf("\nBalance        : Rs. %.2f\n", acc[i].balance);
            count++;
        }
    }

    if (count == 0) {
        printf("\nNo accounts have balance below Rs.1000.\n");
    }

    printf("\nAccounts with balance below Rs.1000 = %d\n", count);
}

// Main function
int main() {
    struct Account acc[MAX];
    int n, i, choice;

    printf("========== BANKING ACCOUNT LEDGER ==========\n");
    printf("\nEnter number of accounts: ");
    scanf("%d", &n);

    if (n < 1 || n > MAX) {
        printf("Invalid number of accounts!\n");
        return 1;
    }

    // Input account details
    for (i = 0; i < n; i++) {
        printf("\n---------- Account %d ----------\n", i + 1);

        printf("Enter Account Number: ");
        scanf("%d", &acc[i].accountNo);

        printf("Enter Account Holder Name: ");
        scanf(" %[^\n]", acc[i].name);

        printf("Enter Account Type (Savings/Current): ");
        scanf("%19s", acc[i].accountType);

        printf("Enter Balance: Rs. ");
        scanf("%f", &acc[i].balance);

        acc[i].interest = 0;
    }

    // Menu-driven program
    do {
        printf("\n\n========== BANKING ACCOUNT LEDGER ==========\n");
        printf("1. Display All Accounts\n");
        printf("2. Deposit\n");
        printf("3. Withdraw\n");
        printf("4. Apply Annual Interest\n");
        printf("5. Display Interest Details\n");
        printf("6. Find Highest and Lowest Balance\n");
        printf("7. Minimum Balance Alert\n");
        printf("8. Exit\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                displayAccounts(acc, n);
                break;

            case 2:
                deposit(acc, n);
                break;

            case 3:
                withdraw(acc, n);
                break;

            case 4:
                applyInterest(acc, n);
                break;

            case 5:
                displayInterest(acc, n);
                break;

            case 6:
                findHighestLowest(acc, n);
                break;

            case 7:
                minimumBalanceAlert(acc, n);
                break;

            case 8:
                printf("\nThank you for using Banking Account Ledger!\n");
                break;

            default:
                printf("\nInvalid choice! Please try again.\n");
        }

    } while (choice != 8);

    return 0;
}

