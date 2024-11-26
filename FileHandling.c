#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct User {
    int id;
    char name[50];
    int age;
};

void createFileIfNotExists(){

    FILE *file = fopen("users.txt", "a");
    if(file){
        fclose(file);
    }
}

void createUser(){
    struct User user;
    FILE *file=fopen("users.txt","a");

    if(!file){
        printf("Error: Unable to open file.\n");
        return;
    }

    printf("Enter User ID: ");
    scanf("%d", &user.id);
    getchar();//Consume newline
    printf("Enter name: ");
    fgets(user.name, sizeof(user.name), stdin);
    //Remove newline
    user.name[strcspn(user.name, "\n")]= '\0';
    printf("Enter age: ");
    scanf("%d", &user.age);

    fprintf(file, "%d,%s,%d\n", user.id, user.name, user.age);
    fclose(file);

    printf("User added successfully.\n");
}

void readUsers(){
   FILE *file = fopen("users.txt", "r");
    if (!file){
        printf("Error: Unable to open file.\n");
        return;
    }

    char line[500];
    printf("\nUser Data:\n");
    while (fgets(line, sizeof(line), file)){
        printf("%s", line);
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

    while (fgets(line, sizeof(line), file)) {
        sscanf(line, "%d,%49[^,],%d", &user.id, user.name, &user.age);
        if (user.id == id) {
            found = 1;
            printf("Enter new name: ");
            fgets(user.name, sizeof(user.name), stdin);
            user.name[strcspn(user.name, "\n")] = '\0';

            printf("Enter new age: ");
            scanf("%d", &user.age);
        }

        fprintf(tempFile, "%d,%s,%d\n", user.id, user.name, user.age);
    }

    fclose(file);
    fclose(tempFile);

    if(found){
        remove("users.txt");
        rename("temp.txt", "users.txt");
        printf("User(s) updated successfully.\n");
    }
    else{
        remove("temp.txt");
        printf("User not found.\n");
    }
}


void deleteUser(){
    int id, found = 0;
    struct User user;

    printf("Enter the ID of the user to delete: ");
    scanf("%d", &id);
    FILE *file = fopen("users.txt", "r");
    if (!file){
        printf("Cannot Open File\n");
        return;
    }

    FILE *tempFile = fopen("temp.txt", "w");
    if(!tempFile) {
        printf("Cannot Open File\n");
        fclose(file);
        return;
    }

    char line[500];
    while(fgets(line, sizeof(line), file)){
        sscanf(line, "%d,%49[^,],%d", &user.id, user.name, &user.age);
        if (user.id != id){
            fprintf(tempFile, "%d,%s,%d\n", user.id, user.name, user.age);
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
        scanf("%d", &choice);
        //To take the newline character which is not taken by scanf
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