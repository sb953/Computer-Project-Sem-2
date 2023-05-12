#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct account 
{
    char name[60];
    int accnum;
    float balance;
};
void create_account(struct account *acc) 
{
    printf("Enter name: ");
    scanf("%s", acc->name);
    printf("Enter account number: ");
    scanf("%d", &acc->accnum);
    printf("Enter initial balance: ");
    scanf("%f", &acc->balance);
    printf("\nAccount has been created successfully!\n\n");
}
void deposit(struct account *acc) 
{
    float amount;
    printf("Enter amount to deposit: ");
    scanf("%f", &amount);
    acc->balance += amount;
    printf("Deposit successful!\n\n");
}
void withdraw(struct account *acc) 
{
    float amount;
    printf("Enter amount to withdraw: ");
    scanf("%f", &amount);
    if (amount > acc->balance) 
    {
        printf("Insufficient balance!\n\n");
    } 
    else 
    {
        acc->balance -= amount;
        printf("Withdrawal successful!\n\n");
    }
}
void view_balance(struct account *acc) 
{
    printf("Name: %s\n", acc->name);
    printf("Account number: %d\n", acc->accnum);
    printf("Balance: %f\n\n", acc->balance);
}
int main() 
{
    int choice;
    struct account acc;
    memset(&acc, 0, sizeof(acc));
    printf("Welcome!\n");
    while (1) 
    {
        printf("1. Create an account\n");
        printf("2. Deposit money\n");
        printf("3. Withdraw money\n");
        printf("4. View bank balance\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) 
        {
            case 1:
                create_account(&acc);
                break;
            case 2:
                deposit(&acc);
                break;
            case 3:
                withdraw(&acc);
                break;
            case 4:
                view_balance(&acc);
                break;
            case 5:
                printf("Thank you!\n");
                exit(0);
            default:
                printf("Invalid choice!\n\n");
                break;
        }
    }
    return 0;
}
