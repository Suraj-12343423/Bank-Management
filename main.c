
#include <stdio.h>

float balance = 23000;
int pin = 1234;

void checkBalance() {
    printf("Current Balance: %.2f\n", balance);
}

void depositMoney() {

    float amount;

    printf("Enter Amount to Deposit: ");
    scanf("%f", &amount);

    if(amount <= 0) {
    
        printf("Invalid Amount!\n");
    } else {
        balance += amount;
        printf("Deposit Successful!\n");
    }
}

void withdrawMoney() {

    float amount;

    printf("Enter Amount to Withdraw: ");
    scanf("%f", &amount);

    if(amount > balance) {
        printf("Insufficient Balance!\n");
    }
    else if(amount <= 0) {
        printf("Invalid Amount!\n");
    }
    else {
        balance -= amount;
        printf("Withdrawal Successful!\n");
    }
}

void changePin() {

    int newPin;

    printf("Enter New PIN: ");
    scanf("%d", &newPin);

    pin = newPin;

    printf("PIN Changed Successfully!\n");
}

int login() {

    int enteredPin;

    printf("Enter PIN: ");
    scanf("%d", &enteredPin);

    if(enteredPin == pin) {
        return 1;
    }

    return 0;
}

int main() {

    int choice;

    printf("===== ATM MACHINE =====\n");

    if(!login()) {
        printf("Incorrect PIN!\n");
        return 0;
    }

    printf("Login Successful!\n");

    while(1) {

        printf("\n===== ATM MENU =====\n");

        printf("1. Check Balance\n");
        printf("2. Deposit Money\n");
        printf("3. Withdraw Money\n");
        printf("4. Change PIN\n");
        printf("5. Exit\n");

        printf("Enter Choice: ");
        scanf("%d", &choice);

        switch(choice) {

            case 1:
                checkBalance();
                break;

            case 2:
                depositMoney();
                break;

            case 3:
                withdrawMoney();
                break;

            case 4:
                changePin();
                break;

            case 5:
                printf("Thank You For Using ATM!\n");
                return 0;

            default:
                printf("Invalid Choice!\n");
        }
    }

    return 0;
}