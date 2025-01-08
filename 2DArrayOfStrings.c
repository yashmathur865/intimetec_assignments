#include<stdio.h>
#include<string.h>

int isVowel(char c){
    if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u' || c=='A' || c=='E' || c=='I' || c=='O' || c=='U'){
        return 1;
    }
    return 0;
}

int main(){
    int rows,cols;
    printf("Enter number of rows: ");
    scanf("%d",&rows);
    printf("Enter the number of columns: ");
    scanf("%d",&cols);

    if(rows<1 || rows>10 || cols<1 || cols>10){
        return 1;
    }

    char mat[rows][cols][51];

    printf("Enter the names:\n");
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            printf("Name at (%d,%d): ",i,j);
            scanf("%s", mat[i][j]);
        }
    }
    printf("\n");

    int vowel_words=0,max_len=0,maxR,maxC;

    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            printf("%s ",mat[i][j]);
            if(isVowel(mat[i][j][0])){
                vowel_words++;
            }
            int word_length=strlen(mat[i][j]);
            if(word_length>max_len){
                max_len =word_length;
                maxR=i;
                maxC=j;
            }
        }
        printf("\n");
    }

    printf("Number of names starting with a vowel: %d\n", vowel_words);
    printf("Longest Name: %s\n", mat[maxR][maxC]);

    return 0;
}