#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <unistd.h>
#include <stdbool.h>

struct date {
    int day,month,year;
};

struct{
    char Name[60];
    int age;
    int CardNumber;
    char Address[60];
    float PhoneNumber;
    float amt;
    int NumberOfAcc;
    struct date Withdraw;
    struct date Deposit;
    struct date Birth;
}add,update,check,remember,transaction;

bool fileExist(const char *filename){
    return access(filename,F_OK) == 0;
}


void new_acc(void){

    int choice;

    system("cls");

    FILE * ptr = fopen("Acc_details.dat","w");
    FILE * AccCheck = fopen("Acc_Check.dat","w");

    printf("\n\n\t\t\t\xB2\xB2\xB2\ ADD RECORD  \xB2\xB2\xB2\xB2");

    printf("\n\n\n\n\t\tWhat is todays month(xx) : ");
    scanf("%d",&add.Deposit.month);

    printf("\t\tWhat is todays day(xx) : ");
    scanf("%d",&add.Deposit.day);

    printf("\t\tWhat is todays year(xxxx) : ");
    scanf("%d",&add.Deposit.year);

    printf("\t\tWhat is your name : ");
    scanf("%s",&add.Name);

    printf("\t\tWhat is your age : ");
    scanf("%d",&add.age);

    printf("\t\tWhat is your card number : ");
    scanf("%d",&add.CardNumber);

    printf("\t\tWhat is your address : ");
    scanf("%s",&add.Address);

    printf("\t\tWhat is your phone number : ");
    scanf("%f",&add.PhoneNumber);

    printf("\t\tEnter the amount to deposit:$");
    scanf("%f",&add.amt);

    fprintf(ptr,"Date of creation :%d/%d/%d\nYour name is :%s\nYour age is :%d\nYour cardnumber is :%d\nYour address is :%s\nYour phonenumber is : %f\nYour amt is : %f\n",add.Deposit.month,add.Deposit.day,add.Deposit.year,add.Name,add.age,add.CardNumber,add.Address,add.PhoneNumber,add.amt);

    printf("\n\n\n\t\t\xB2\xB2\xB2 Account created successfully! \xB2\xB2\xB2");
    fprintf(ptr,"1");


    printf("\n\n\t\t1.Return to Menu");
    printf("\n\n\t\t2.Exit");
    printf("\n\n\n\t\tEnter your choice : ");
    scanf("%d",&choice);

    fclose(ptr);
    fclose(AccCheck);

    if(choice == 1){
        Menu();
    }
    else{
        closeApplication();
    }

}

void edit(void){
    printf("Choice 2");
}

void transact(void){
    printf("Choice 3");
}

void see(void){
    int choice;
    char AccInformation[300];

    FILE * ptr = fopen("Acc_details.dat","r");
    FILE * AccCheck = fopen("Acc_Check.dat","r");


    if (fileExist(AccCheck))
        printf("File %s exists", AccCheck);
    else
        printf("File %s doesn't exist.", AccCheck);

    if(check.NumberOfAcc != 1){
        printf("\n\n\t\t\t\xB2\xB2\xB2\ There is no existing account  \xB2\xB2\xB2\xB2\n\n\n");
        printf("\n\t\t\t 1.Create new account\n");
        printf("\n\t\t\t 2.Exit\n");
        printf("\n\n\n\t\t\t Enter your choice : \n");
        printf("%d",check.NumberOfAcc);
        scanf("%d",&choice);
            if(choice == 1){
                new_acc();
            }
            else closeApplication();
    }

        while(!feof(ptr)){
            fgets(AccInformation,150,ptr);
            puts(AccInformation);
        }

        scanf("%d",&choice);
        if(choice == 1){
            Menu();
        }
        else closeApplication();


    fclose(ptr);
}

void erase(void){
    printf("Choice 5");

}

void view_list(void){
    printf("Choice 6");
}

void closeApplication(void){
    return 0;
}


int main()
{
    Menu();
}

void Menu(){
    int choice;

    system("cls");
    system("color 5");

    printf("\n\n\t\t\tCUSTOMER ACCOUNT BANKING MANAGEMENT SYSTEM");
    printf("\n\n\n\t\t\t \xB2\xB2\xB2\xB2\xB2\xB2\xB2 WELCOME TO THE MAIN MENU \xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    printf("\n\n\t\t1.Create new account\n");
    printf("\t\t2.Update information of existing account\n");
    printf("\t\t3.For transactions\n");
    printf("\t\t4.Check the details of existing account\n");
    printf("\t\t5.Removing existing account\n");
    printf("\t\t6.View customer's list");
    printf("\n\t\t7.Exit\n\n\n\n\n\t\t Enter your choice:");

    scanf("%d",&choice);

    system("cls");

    switch(choice)
    {
        case 1:new_acc();
        break;
        case 2:edit();
        break;
        case 3:transact();
        break;
        case 4:see();
        break;
        case 5:erase();
        break;
        case 6:view_list();
        break;
        case 7:closeApplication();
        break;
    }

    return 0;
}

