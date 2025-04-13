#include <stdio.h>

typedef struct Account
{
    char name[50];
    unsigned Id;
    double balance;
} Account;

Account createAccount()
{
    struct Account acc;

    printf("Hi Enter your name \n");
    scanf("%s", acc.name);

    printf("What is your balance\n");
    scanf("%lf", &acc.balance);

    static int nextId = 1;
    acc.Id = nextId++;

    return acc;
}

void printAccount(Account *acc)
{
    printf("----Account INFO----\n");
    printf("Account's ID: %d\n", acc->Id);
    printf("Account's Name: %s\n", acc->name);
    printf("Account's balance: %lf", acc->balance);
}

void deposit(Account *acc)
{
    double depositAmount = 0;
    printf("Please write amount of money\n");
    scanf("%lf", &depositAmount);

    acc->balance += depositAmount;

    printf("Success! Balance now: %lf\n", acc->balance);
}

void withdraw(struct Account *acc)
{
    double withdrawAmount = 0;
    printf("Please write amount of money\n");
    scanf("%lf", &withdrawAmount);

    if (withdrawAmount > acc->balance)
    {
        printf("Not enouth money on your account\n");
    }
    else
    {
        acc->balance -= withdrawAmount;
        printf("Success! Balance now: %lf\n", acc->balance);
    }
}

int main()
{
    struct Account acc = createAccount();
    printAccount(&acc);

    int choice;

    do
    {
        printf("\n");
        printf("\n====== 'Maximiliano Tech' Bank Menu ====== \n");
        printf("1 -> Deposit\n");
        printf("2 -> Withdraw\n");
        printf("3 -> Show Account Info\n");
        printf("0 -> Exit\n");
        printf("\n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            deposit(&acc);
            break;
        case 2:
            withdraw(&acc);
            break;
        case 3:
            printAccount(&acc);
            break;
        case 0:
            printf("Bye\n");
            break;
        default:
            printf("Invalid option\n");
        }
    } while (choice != 0);

    return 0;
}