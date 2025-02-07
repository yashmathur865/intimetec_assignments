#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 10

typedef struct Node
{
    int key;
    int value;
    struct Node *next;
} Node;

Node *hashTable[TABLE_SIZE];

int hashFunction(int key)
{
    return key % TABLE_SIZE;
}

void insert(int key, int value)
{
    int index = hashFunction(key);
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->key = key;
    newNode->value = value;
    newNode->next = NULL;

    if (hashTable[index] == NULL)
    {
        hashTable[index] = newNode;
    }
    else
    {
        Node *temp = hashTable[index];
        while (temp)
        {
            if (temp->key == key)
            {
                temp->value = value;
                free(newNode);
                return;
            }
            if (temp->next == NULL)
                break;
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

int search(int key)
{
    int index = hashFunction(key);
    Node *temp = hashTable[index];
    while (temp)
    {
        if (temp->key == key)
        {
            return temp->value;
        }
        temp = temp->next;
    }
    return -1;
}

void delete(int key)
{
    int index = hashFunction(key);
    Node *temp = hashTable[index];
    Node *prev = NULL;

    while (temp)
    {
        if (temp->key == key)
        {
            if (prev == NULL)
            {
                hashTable[index] = temp->next;
            }
            else
            {
                prev->next = temp->next;
            }
            free(temp);
            printf("Key %d deleted.\n", key);
            return;
        }
        prev = temp;
        temp = temp->next;
    }
    printf("Key %d not found.\n", key);
}

void display()
{
    printf("Hash Table:\n");
    for (int iterator = 0; iterator < TABLE_SIZE; iterator++)
    {
        printf("Index %d: ", iterator);
        Node *temp = hashTable[iterator];
        while (temp)
        {
            printf("(%d, %d) -> ", temp->key, temp->value);
            temp = temp->next;
        }
    }
}

int main()
{
    int choice, key, value;
    while (1)
    {
        printf("\nEnter your choice:\n");
        printf("1. Insert\n2. Search\n3. Delete\n4. Display\n5. Exit\n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter key: ");
            scanf("%d", &key);
            printf("Enter value: ");
            scanf("%d", &value);
            insert(key, value);
            break;
        case 2:
            printf("Enter key: ");
            scanf("%d", &key);
            value = search(key);
            if (value != -1)
                printf("Value: %d\n", value);
            else
                printf("Key not found.\n");
            break;
        case 3:
            printf("Enter key: ");
            scanf("%d", &key);
            delete (key);
            break;
        case 4:
            display();
            break;
        case 5:
            printf("Exiting program.\n");
            return 0;
        default:
            printf("Invalid choice.\n");
        }
    }
}