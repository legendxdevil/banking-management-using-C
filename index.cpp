#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DATA_FILE "accounts.dat"

// Structure for bank account
struct Account {
    int accountNumber;
    char name[100];
    double balance;
    char accountType[10]; // "Saving" or "Current"
};

// Function prototypes
void createAccount();
void depositMoney();
void withdrawMoney();
void saveAccountsToFile();
void loadAccountsFromFile();
void checkBalance();
void deleteAccount();
void customizeAccount();
void help();
void showMainMenu();

// Global array to store accounts (simple approach for demo)
struct Account accounts[100];
int accountCount = 0;

int main() {
    loadAccountsFromFile();
    showMainMenu();
    saveAccountsToFile();
    return 0;
}

void showMainMenu() {
    int choice;
    while (1) {
        printf("\n==============================\n");
        printf("  Banking Management System\n");
        printf("==============================\n");
        printf("1. Create Account\n");
        printf("2. Deposit Money\n");
        printf("3. Withdraw Money\n");
        printf("4. Check Balance\n");
        printf("5. Delete Account\n");
        printf("6. Customize Account\n");
        printf("7. Help\n");
        printf("8. Exit\n");
        printf("Enter your choice (1-8): ");
        scanf("%d", &choice);
        getchar(); // consume newline
        if (choice == 1) createAccount();
        else if (choice == 2) depositMoney();
        else if (choice == 3) withdrawMoney();
        else if (choice == 4) checkBalance();
        else if (choice == 5) deleteAccount();
        else if (choice == 6) customizeAccount();
        else if (choice == 7) help();
        else if (choice == 8) break;
        else printf("Invalid choice!\n");
    }
}

void createAccount() {
    printf("\n--- Create Account ---\n");
    char name[100], accType[10];
    int accNo, typeChoice;
    double initBal;
    printf("Enter Account Number: ");
    scanf("%d", &accNo);
    getchar();
    printf("Enter Name: ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = 0;
    printf("Select Account Type:\n");
    printf("1. Saving\n");
    printf("2. Current\n");
    printf("Enter your choice (1-2): ");
    scanf("%d", &typeChoice);
    getchar();
    if (typeChoice == 1) strcpy(accType, "Saving");
    else if (typeChoice == 2) strcpy(accType, "Current");
    else {
        printf("Invalid account type!\n");
        return;
    }
    printf("Enter Initial Balance: ");
    scanf("%lf", &initBal);
    if (strcmp(accType, "Saving") == 0 && initBal > 500000) {
        printf("Please upgrade your account! (Saving account limit is 5 lakh)\n");
        return;
    }
    if (strcmp(accType, "Current") == 0 && initBal > 5000000) {
        printf("You reach your limit to save money in your account! (Current account limit is 50 lakh)\n");
        return;
    }
    accounts[accountCount].accountNumber = accNo;
    strcpy(accounts[accountCount].name, name);
    accounts[accountCount].balance = initBal;
    strcpy(accounts[accountCount].accountType, accType);
    accountCount++;
    printf("Account created successfully!\n");
}

void depositMoney() {
    printf("\n--- Deposit Money ---\n");
    int accNo, i, found = 0;
    double amt;
    printf("Enter Account Number: ");
    scanf("%d", &accNo);
    for (i = 0; i < accountCount; i++) {
        if (accounts[i].accountNumber == accNo) {
            found = 1;
            printf("Enter Amount to Deposit: ");
            scanf("%lf", &amt);
            double newBal = accounts[i].balance + amt;
            if (strcmp(accounts[i].accountType, "Saving") == 0 && newBal > 500000) {
                printf("Please upgrade your account! (Saving account limit is 5 lakh)\n");
                return;
            }
            if (strcmp(accounts[i].accountType, "Current") == 0 && newBal > 5000000) {
                printf("You reach your limit to save money in your account! (Current account limit is 50 lakh)\n");
                return;
            }
            accounts[i].balance = newBal;
            printf("Deposit successful! New Balance: %.2lf\n", accounts[i].balance);
            break;
        }
    }
    if (!found) {
        printf("Account not found!\n");
    }
}

void withdrawMoney() {
    printf("\n--- Withdraw Money ---\n");
    int accNo, i, found = 0;
    double amt;
    printf("Enter Account Number: ");
    scanf("%d", &accNo);
    for (i = 0; i < accountCount; i++) {
        if (accounts[i].accountNumber == accNo) {
            found = 1;
            printf("Enter Amount to Withdraw: ");
            scanf("%lf", &amt);
            if (accounts[i].balance >= amt) {
                accounts[i].balance -= amt;
                printf("Withdrawal successful! New Balance: %.2lf\n", accounts[i].balance);
            } else {
                printf("Insufficient balance!\n");
            }
            break;
        }
    }
    if (!found) {
        printf("Account not found!\n");
    }
}

void saveAccountsToFile() {
    FILE *fp = fopen(DATA_FILE, "wb");
    if (fp) {
        fwrite(&accountCount, sizeof(int), 1, fp);
        fwrite(accounts, sizeof(struct Account), accountCount, fp);
        fclose(fp);
    }
}

void loadAccountsFromFile() {
    FILE *fp = fopen(DATA_FILE, "rb");
    if (fp) {
        fread(&accountCount, sizeof(int), 1, fp);
        fread(accounts, sizeof(struct Account), accountCount, fp);
        fclose(fp);
    }
}

void checkBalance() {
    printf("\n--- Check Balance ---\n");
    int accNo, i, found = 0;
    printf("Enter Account Number: ");
    scanf("%d", &accNo);
    for (i = 0; i < accountCount; i++) {
        if (accounts[i].accountNumber == accNo) {
            found = 1;
            printf("Account Number: %d\n", accounts[i].accountNumber);
            printf("Name: %s\n", accounts[i].name);
            printf("Current Balance: %.2lf\n", accounts[i].balance);
            break;
        }
    }
    if (!found) {
        printf("Account not found!\n");
    }
}

void deleteAccount() {
    printf("\n--- Delete Account ---\n");
    int accNo, i, j, found = 0;
    printf("Enter Account Number to Delete: ");
    scanf("%d", &accNo);
    for (i = 0; i < accountCount; i++) {
        if (accounts[i].accountNumber == accNo) {
            found = 1;
            // Shift all accounts after i to the left
            for (j = i; j < accountCount - 1; j++) {
                accounts[j] = accounts[j + 1];
            }
            accountCount--;
            printf("Account deleted successfully!\n");
            break;
        }
    }
    if (!found) {
        printf("Account not found!\n");
    }
}

void customizeAccount() {
    printf("\n--- Customize Account ---\n");
    int accNo, i, found = 0, choice;
    printf("Enter Account Number to Customize: ");
    scanf("%d", &accNo);
    for (i = 0; i < accountCount; i++) {
        if (accounts[i].accountNumber == accNo) {
            found = 1;
            printf("Select what you want to customize:\n");
            printf("1. Name\n");
            printf("2. Account Type\n");
            printf("Enter your choice (1-2): ");
            scanf("%d", &choice);
            getchar();
            if (choice == 1) {
                char newName[100];
                printf("Enter new name: ");
                fgets(newName, sizeof(newName), stdin);
                newName[strcspn(newName, "\n")] = 0;
                strcpy(accounts[i].name, newName);
                printf("Name updated successfully!\n");
            } else if (choice == 2) {
                int typeChoice;
                printf("Select new Account Type:\n");
                printf("1. Saving\n");
                printf("2. Current\n");
                printf("Enter your choice (1-2): ");
                scanf("%d", &typeChoice);
                if (typeChoice == 1) strcpy(accounts[i].accountType, "Saving");
                else if (typeChoice == 2) strcpy(accounts[i].accountType, "Current");
                else {
                    printf("Invalid account type!\n");
                    return;
                }
                printf("Account type updated successfully!\n");
            } else {
                printf("Invalid choice!\n");
            }
            break;
        }
    }
    if (!found) {
        printf("Account not found!\n");
    }
}

void help() {
    printf("\n--- Help ---\n");
    printf("For assistance, please contact:\n");
    printf("Mobile: 7982402954\n");
    printf("Email: nandkishorsoni098765@gmail.com\n");
}