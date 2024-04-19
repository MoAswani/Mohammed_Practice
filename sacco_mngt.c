#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ADMINS 3

struct user {
    char name[50];
    char phone[20];
    char acc[30];
    char password[20];
    float balance, loanAmount, loanInterest;
    char loanDueDate[11];
};

struct admin{
    char name[50];
    char phone[20];
    char password[20];
}admins[MAX_ADMINS];
int numAdmins = 0; // Counter for the number of created admin accounts

struct transaction {
    char date[20];
    char description[100];
    float amount;
};

void saveAdminsToFile() {
    FILE *adminFile = fopen("admins.dat", "wb");
    if (adminFile == NULL) {
        printf("\nError opening admin file for writing.");
        return;
    }

    fwrite(&numAdmins, sizeof(int), 1, adminFile);
    fwrite(admins, sizeof(struct admin), numAdmins, adminFile);

    fclose(adminFile);
}

void loadAdminsFromFile() {
    FILE *adminFile = fopen("admins.dat", "rb");
    if (adminFile == NULL) {
        printf("\nAdmin file not found. Creating a new one.");
        return;
    }

    fread(&numAdmins, sizeof(int), 1, adminFile);
    fread(admins, sizeof(struct admin), numAdmins, adminFile);

    fclose(adminFile);
}




char* calculateDueDate(int repaymentPeriod) {
    time_t currentTime;
    struct tm *dueDateInfo;
    time(&currentTime);
    dueDateInfo = localtime(&currentTime);

    // Calculate the due date by adding the repayment period in months
    dueDateInfo->tm_mon += repaymentPeriod;
    mktime(dueDateInfo);

    // Format the due date as a string (e.g., "YYYY-MM-DD")
    static char dueDate[11];  // "YYYY-MM-DD\0"
    strftime(dueDate, sizeof(dueDate), "%Y-%m-%d", dueDateInfo);

    return dueDate;
}


int main(){
    loadAdminsFromFile();

    struct user usr,usr1;
    FILE *fp;
    char filename[50],phone[50],pword[50], acc[50], name[50], adminPword[50];
    int opt,choice, repaymentPeriod;
    char cont = 'y';
    float amount, loanAmount, interest;

    printf("\nWhat do you want to do?");
    printf("\n");
    printf("\n\n1. Member registration");
    printf("\n2. Member Login");
    /*
    printf("\n");
    printf("\n\n3. Manager/Admin registration");
    printf("\n4. Manager/Admin Login");
*/
    printf("\n\nYour choice:\t");
    scanf("%d",&opt);

    if(opt == 1){
        system("clear");
        printf("Enter your name:\t");
        scanf("%s",usr.name);
        printf("Enter your phone number:\t");
        scanf("%s",usr.phone);
        printf("Enter your account number:\t");
        scanf("%s",usr.acc);
        printf("Enter your new password:\t");
        scanf("%s",usr.password);
        usr.balance = 0;
        strcpy(filename,usr.name);
        fp = fopen(strcat(filename,".dat"),"w");
        fwrite(&usr,sizeof(struct user),1,fp);
        if(fwrite != 0){
            printf("\n\nAccount succesfully registered");
        }else {
            printf("\n\nSomething went wrong please try again");
        }
        fclose(fp);
    }
    if(opt == 2){
        system("clear");
        printf("\nAccount Name:\t");
        scanf("%s",name);
        printf("Password:\t");
        scanf("%s",pword);
        strcpy(filename,name);
        fp = fopen(strcat(filename,".dat"),"r");
        if(fp == NULL){
            printf("\nAccount number not registered");
        }
        else {
        fread(&usr,sizeof(struct user),1,fp);
        fclose(fp);
        if(!strcmp(pword,usr.password)){
            printf("\n\t\tWelcome %s",usr.name);;
            while(cont == 'y'){
                system("clear");
                printf("\n\nPress 1 for balance inquiry");
                printf("\nPress 2 for depositing cash");
                printf("\nPress 3 for cash withdrawl");
                printf("\nPress 4 for online transfer");
                printf("\nPress 5 for loan applcation");
                printf("\nPress 6 for loan balance and due date");
                printf("\nPress 7 for password change");
                printf("\nPress 8 for Logout");
                printf("\n\nYour choice:\t");
                scanf("%d",&choice);

                switch(choice){
                    case 1:
                        printf("\nYour current balance is KSh.%.2f",usr.balance);
                        break;
                    case 2:
                        printf("\nEnter the amount:\t");
                        scanf("%f",&amount);
                        usr.balance += amount;
                        fp = fopen(filename,"w");
                        fwrite(&usr,sizeof(struct user),1,fp);
                        if(fwrite != NULL) printf("\nSuccesfully deposited.");
                        fclose(fp);
                        break;
                    case 3:
                        printf("\nEnter the amount:\t");
                        scanf("%f",&amount);
                        usr.balance -= amount;
                        fp = fopen(filename,"w");
                        fwrite(&usr,sizeof(struct user),1,fp);
                        if(fwrite != NULL) printf("\nYou have withdrawn KSh.%.2f",amount);
                        fclose(fp);
                        break;

                    case 4:
                        printf("\nPlease enter the name of the receiver to transfer the balance:\t");
                        scanf("%s",name);
                        printf("\nPlease enter the amount to transfer:\t");
                        scanf("%f",&amount);
                        strcpy(filename,name);
                        fp = fopen(strcat(filename,".dat"),"r");
                        if(fp == NULL) printf("\nAccount number not registered");
                        else {
                            fread(&usr1,sizeof(struct user),1,fp);
                        
                        fclose(fp);
                        if(amount > usr.balance) printf("\nInsufficient balance");
                        else {
                            
                            
                            fp = fopen(filename,"w");
                            usr1.balance += amount;
                            fwrite(&usr1,sizeof(struct user),1,fp);
        
                            fclose(fp);
                            if(fwrite != NULL){
                                printf("\nYou have succesfully transfered KSh.%.2f to %s",amount,name);
                                strcpy(filename,usr.name);
                                fp = fopen(strcat(filename,".dat"),"w");
                                usr.balance -= amount;
                                fwrite(&usr,sizeof(struct user),1,fp);
                                fclose(fp);
                            }

                            
                        }
                        break;
                    case 5:
                            printf("\nEnter the loan amount:\t");
                            scanf("%f", &loanAmount);
                            printf("\nEnter the repayment period in months:\t");
                            scanf("%d", &repaymentPeriod);
                            // Calculate the interest based on the repayment period (modify this calculation as needed)
                            interest = loanAmount * 0.05 * repaymentPeriod;
                            usr.balance += loanAmount; // Assuming the loan amount is added to the user's balance
                            usr.loanAmount = loanAmount;
                            usr.loanInterest = interest;strcpy(usr.loanDueDate, calculateDueDate(repaymentPeriod));
                            //usr.loanDueDate = calculateDueDate(repaymentPeriod); // You need to implement this function
                            fp = fopen(filename, "w");
                            fwrite(&usr, sizeof(struct user), 1, fp);
                            if (fwrite != NULL) printf("\nLoan application approved.");
                            fclose(fp);
                            break;
                    case 6:
                            // Add a case for checking the loan balance and due date
                            if (usr.loanAmount > 0) {
                                printf("\nYour loan balance is KSh.%.2f", usr.loanAmount);
                                printf("\nYour loan is due on %s", usr.loanDueDate);
                            } else {
                                printf("\nYou don't have an active loan.");
                            }
                            break;
                    case 7:
                        printf("\nPlease enter your new password:\t");
                        scanf("%s",pword);
                        fp = fopen(filename,"w");
                        strcpy(usr.password,pword);
                        fwrite(&usr,sizeof(struct user),1,fp);
                        if(fwrite != NULL)
                        printf("\nPassword succesfully changed");
                        }
                    break;
                    case 8:
                        printf("\nUser logged out.");
                        break;
                default:
                    printf("\nInvalid option");
                }
                        

                printf("\nDo you want to continue the transaction [y/n]\t");
                scanf("%s",&cont);

            }
        }
        else {
            printf("\nInvalid password");
        }
        }

    }
    if(opt == 3){
        if (numAdmins >= MAX_ADMINS) {
            printf("\nCannot create more admin accounts. Maximum limit reached.");
        } else {
            printf("Enter admin name:\t");
            scanf("%s", admins[numAdmins].name);
            printf("Enter admin password:\t");
            scanf("%s", admins[numAdmins].password);

            numAdmins++;
            saveAdminsToFile();
            printf("\nAdmin account created successfully.");
        }
    if(opt == 4){
        printf("\nAdmin Name:\t");
        scanf("%s", adminPword);

        // Check if the entered admin name and password match any admin account
        int adminIndex;
        for (adminIndex = 0; adminIndex < numAdmins; adminIndex++) {
            if (strcmp(admins[adminIndex].name, adminPword) == 0) {
                printf("\n\t\tWelcome %s (Admin)", adminPword);
                // Admin-specific functionality can be added here
                break;
            }
        }

        if (adminIndex == numAdmins) {
            printf("\nInvalid admin name or password.");
        }

        }
    }
    
    return 0;
}
    