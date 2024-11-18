#include <stdio.h>
#include <string.h>

int main() {
    char str[200];
    printf("Enter a string: ");
    if(fgets(str, sizeof(str), stdin)){
        str[strcspn(str, "\n")] = 0;
        printf("You entered: %s\n", str);
    }
}