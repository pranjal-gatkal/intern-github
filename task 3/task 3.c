#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
// Function to check if a string is a C keyword
int isKeyword(char buffer[]){
    char keywords[32][10]={
        "auto","break","case","char","const","continue","default","do","double","else","enum","extern","float","for","goto","if","int","long","register","return",
        "short","signed","sizeof","static","struct","switch","typedef","union","unsigned","void","volatile","while"};
        for(int i=0;i<32;++i){
            if(strcmp(keywords[i],buffer)==0){
                return 1;
            }
        }
        return 0;
    }

    int main(){
        char ch,buffer[15],operators[]="+-*/%=><";
        FILE*fp;
        int i,j=0;

        // Open the input file (ensure you have a file named "input.txt" in the same folder)
        fp = fopen("input.txt","r");

        if (fp == NULL){
            print("Error:Could not open file.Please create 'input.txt'.\n");
            exit(0);

        }
        printf("---Lexical Analysis Results---\n");

        while((ch = fgetc(fp)) !=EOF){
            // Identify Operators
            for(i=0;i<8;++i){
                if(ch== operators[i]){
                    printf("Operator:%c\n",ch);
                }
            }
            // Identify Keywords and identifiers
            if(isalnum(ch)){
                buffer[i++] = ch;
            } else if ((ch==''||ch=='\n'||ch=='\t'||ch==';'||ch==',')&&(j!=0)){
                buffer[i]='\0';
                j=0;
                if(isKeyword(buffer)){
                    printf("Keyword:%s\n",buffer);
                } else {
                    printf("Identifier:%s\n",buffer);
                }
            }
        }
        fclose(fp);
        return0;
    }
}