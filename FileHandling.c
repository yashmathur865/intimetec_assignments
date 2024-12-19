#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int isalpha(int c){
    return ((c>='a' && c<='z') || (c>='A' && c<='Z'));
}

struct User {
    int id;
    char name[50];
    int age;
};

void createFileIfNotExists(){
    FILE *file=fopen("users.txt","a");
    if(file){
        fclose(file);
    }
}

void createUser(){
    struct User user;

    FILE *readFile=fopen("users.txt", "r");
    if(!readFile){
        printf("Unable to open file for reading.\n");
        return;
    }

    printf("Enter User ID: ");
    if(scanf("%d", &user.id)!= 1){
        printf("User ID must be an integer.\n");
        while(getchar()!='\n');
        fclose(readFile);
        return;
    }
    getchar();

    struct User alreadyPresentUser;
    char line[500];
    while (fgets(line,sizeof(line), readFile)){
        sscanf(line,"%d,%49[^,],%d",&alreadyPresentUser.id,alreadyPresentUser.name,&alreadyPresentUser.age);
        if(alreadyPresentUser.id==user.id){
            printf("User ID %d already exists.\n",user.id);
            fclose(readFile);
            return;
        }
    }
    fclose(readFile);

    printf("Enter name:");
    fgets(user.name,sizeof(user.name),stdin);
    user.name[strcspn(user.name,"\n")]= '\0';

    for(int i = 0; i< strlen(user.name); ++i){
        if(!isalpha(user.name[i]) && user.name[i]!= ' '){
            printf("Name must contain alphabetic characters only.\n");
            return;
        }
    }

    printf("Enter age: ");
    if(scanf("%d",&user.age)!= 1 || user.age<= 0){
        printf("Invalid input. Age must be a positive integer.\n");
        while (getchar() != '\n');
        return;
    }


    FILE *writeFile = fopen("users.txt", "a");
    if (!writeFile) {
        printf("Error: Unable to open file for writing.\n");
        return;
    }

    fprintf(writeFile,"%d,%s,%d\n",user.id, user.name, user.age);
    fclose(writeFile);

    printf("User added successfully.\n");
}


void readUsers(){
   FILE *file=fopen("users.txt","r");
    if(!file){
        printf("Error: Unable to open file.\n");
        return;
    }
    char line[500];
    printf("\nUser Data:\n");
    while(fgets(line, sizeof(line), file)){
        printf("%s",line);
    }

    fclose(file);
}

void updateUser(){
    int id, found = 0;
    struct User user;

    printf("Enter the ID of the user to update: ");
    scanf("%d",&id);
    getchar();

    FILE *file=fopen("users.txt","r");
    if(!file){
        printf("Cannot Open File\n");
        return;
    }

    FILE *tempFile=fopen("temp.txt","w");
    if(!tempFile){
        printf("Cannot Open File\n");
        fclose(file);
        return;
    }

    char line[500];

    while(fgets(line, sizeof(line), file)){
        sscanf(line, "%d,%49[^,],%d", &user.id, user.name, &user.age);
        if (user.id==id){
            found = 1;
            printf("Enter new name: ");
            fgets(user.name, sizeof(user.name),stdin);
            user.name[strcspn(user.name, "\n")] ='\0';

            printf("Enter new age: ");
            scanf("%d", &user.age);
        }

        fprintf(tempFile,"%d,%s,%d\n",user.id,user.name, user.age);
    }

    fclose(file);
    fclose(tempFile);

    if(found){
        remove("users.txt");
        rename("temp.txt","users.txt");
        printf("User updated successfully.\n");
    }
    else{
        remove("temp.txt");
        printf("User not found.\n");
    }
}


void deleteUser(){
    int id, found=0;
    struct User user;

    printf("Enter the ID of the user to delete: ");
    scanf("%d", &id);
    FILE *file = fopen("users.txt", "r");
    if (!file){
        printf("Cannot Open File\n");
        return;
    }

    FILE *tempFile=fopen("temp.txt", "w");
    if(!tempFile){
        printf("Cannot Open File\n");
        fclose(file);
        return;
    }

    char line[500];
    while(fgets(line, sizeof(line),file)){
        sscanf(line,"%d,%49[^,],%d",&user.id,user.name, &user.age);
        if (user.id != id){
            fprintf(tempFile, "%d,%s,%d\n",user.id,user.name,user.age);
        }
        else {
            found = 1;
        }
    }

    fclose(file);
    fclose(tempFile);
    if(found){
        remove("users.txt");
        rename("temp.txt", "users.txt");
        printf("User deleted successfully.\n");
    }
    else{
        remove("temp.txt");
        printf("User not found.\n");
    }
}

int main(){
    int choice;

    createFileIfNotExists();
    while (1) {
        printf("\nWhat Operation You Want To Perform\n");
        printf("1. Create User\n");
        printf("2. Read All Users\n");
        printf("3. Update User\n");
        printf("4. Delete User\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        if (scanf("%d", &choice)!= 1) {
            printf("Please enter a number between 1 and 5.\n");
            while(getchar() != '\n');
            continue;
        }
        getchar();

        switch (choice) {
            case 1:
                createUser();
                break;
            case 2:
                readUsers();
                break;
            case 3:
                updateUser();
                break;
            case 4:
                deleteUser();
                break;
            case 5:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Please Choose Between 1 To 5\n");
        }
    }
    return 0;
}