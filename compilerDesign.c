// To Write a C program to identify whether a given line is a comment or not.

#include <stdio.h>
void main()
{
    char com[30];
    int i = 2, a = 0;
    printf("\n Enter comment:");
    gets(com);
    if (com[0] == '/'){
        if (com[1] == '/')
            printf("\n It is a comment");
        else if (com[1] == '*'){
            for (i = 2; i <= 30; i++){
                if (com[i] == '*' && com[i + 1] == '/'){
                    printf("\n It is a comment");
                    a = 1;
                    break;
                }
                else
                    continue;
            }
            if (a == 0)
                printf("\n It is not a comment");
        }
        else
            printf("\n It is not a comment");
    }
    else
        printf("\n It is not a comment");
    getch();
}

// To Write a C program to recognize strings under 'a', 'a*b+', 'abb'

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void main(){
    char s[20], c;
    int state = 0, i = 0;
    printf("\n Enter a string:");
    gets(s);
    while (s[i] != '\0'){
        switch (state){
        case 0:
            c = s[i++];
            if (c == 'a')
                state = 1;
            else if (c == 'b')
                state = 2;
            else
                state = 6;
            break;
        case 1:
            c = s[i++];
            if (c == 'a')
                state = 3;
            else if (c == 'b')
                state = 4;
            else
                state = 6;
            break;
        case 2:
            c = s[i++];
            if (c == 'a')
                state = 6;
            else if (c == 'b')
                state = 2;
            else
                state = 6;
            break;
        case 3:
            c = s[i++];
            if (c == 'a')
                state = 3;
            else if (c == 'b')
                state = 2;
            else
                state = 6;
            break;
        case 4:
            c = s[i++];
            if (c == 'a')
                state = 6;
            else if (c == 'b')
                state = 5;
            else
                state = 6;
            break;
        case 5:
            c = s[i++];
            if (c == 'a')
                state = 6;
            else if (c == 'b')
                state = 2;
            else
                state = 6;
            break;
        case 6:
            printf("\n %s is not recognised.", s);
            exit(0);
        }
    }
    if (state == 1)
        printf("\n %s is accepted under rule 'a'", s);
    else if ((state == 2) || (state == 4))
        printf("\n %s is accepted under rule 'a*b+'", s);
    else if (state == 5)
        printf("\n %s is accepted under rule 'abb'", s);
    getch();
}
// Write a C program to test whether a given identifier is valid or not
#include <stdio.h>
#include <conio.h>
void main(){

    int i = 0, flag = 0;
    char keyw[10][10] = {"int", "float", "break", "long", "char", "for", "if", "switch", "else", "while"}, a[10];
    printf("Enter Identifier : ");
    gets(a);
    for (i = 0; i < 10; i++){
        if ((strcmp(keyw[i], a) == 0)){
            flag = 1;
        }
    }
    if (flag == 1){
        printf("\n%s is Keyword.", a);
    }
    else{
        flag = 0;
        if ((a[0] == '_') || (isalpha(a[0]) != 0)){
            for (i = 1; a[i] != '\0'; i++){
                if ((isalnum(a[i]) == 0) && (a[i] != '_')){
                    flag = 1;
                }
            }
        }
        else{
            flag = 1;
        }
    }
    if (flag == 0){
        printf("\n%s is an Identifier.", a);
    }
    else{
        printf("\n%s is Not an Identifier.", a);
    }
}
// To write a C program to simulate lexical analyser for validating operators

#include <stdio.h>
#include <conio.h>
void main(){
    char s[5];
    printf("\n Enter any operator:");
    gets(s);
    switch (s[0]){\

    case '>':
        if (s[1] == '=')
            printf("\n Greater than or equal");
        else
            printf("\n Greater than");
        break;
    case '<':
        if (s[1] == '=')
            printf("\n Less than or equal");
        else
            printf("\nLess than");
        break;
    case '=':
        if (s[1] == '=')
            printf("\nEqual to");
        else
            printf("\nAssignment");
        break;
    case '!':
        if (s[1] == '=')
            printf("\nNot Equal");
        else
            printf("\n Bit Not");
        break;
    case '&':
        if (s[1] == '&')
            printf("\nLogical AND");
        else
            printf("\n Bitwise AND");
        break;
    case '|':
        if (s[1] == '|')
            printf("\nLogical OR");
        else
            printf("\nBitwise OR");
        break;
    case '+':
        printf("\n Addition");
        break;
    case '-':
        printf("\nSubstraction");
        break;
    case '*':
        printf("\nMultiplication");
        break;
    case '/':
        printf("\nDivision");
        break;
    case '%':
        printf("Modulus");
        break;
    default:
        printf("\n Not a operator");
    }
}
//

#include <stdio.h>
#include <conio.h>
#include <string.h>
char s[20], stack[20];
void main()
{
    char m[5][6][3] = { "tb", " ", " ", "tb", " ", " ", " ", "+tb", " ", " ", "n", "n", "fc",
     " ", " ", "fc", " ", " ", " ", "n", "*fc", "a "," n "," n ", "","","","(e) ","",}                                                             "};
    int size[5][6] = {2, 0, 0, 2, 0, 0, 0, 3, 0, 0, 1, 1, 2, 0, 0, 2, 0, 0, 0, 1, 3, 0, 1, 1, 1, 0, 0, 3, 0, 0};
    int i, j, k, n, str1, str2;
    clrscr();
    printf("\n Enter the input string: ");
    scanf("%s", s);
    strcat(s, "$");
    n = strlen(s);
    stack[0] = '$';
    stack[1] = 'e';
    i = 1;
    j = 0;
    printf("\nStack Input\n");
    printf("__________________\n");
    while ((stack[i] != '$') && (s[j] != '$'))
    {
        if (stack[i] == s[j])
        {
            i--;
            j++;
        }
        switch (stack[i])
        {
        case 'e':
            str1 = 0;
            break;
        case 'b':
            str1 = 1;
             break;
        case 't':
            str1 = 2;
            break;
        case 'c':
            str1 = 3;
            break;
        case 'f':
            str1 = 4;
            break;
        }
        switch (s[j])
        {
        case 'i':
            str2 = 0;
            break;
        case '+':
            str2 = 1;
            break;
        case '*':
            str2 = 2;
            break;
        case '(':
            str2 = 3;
            break;
        case ')':
            str2 = 4;
            break;
        case '$':
            str2 = 5;
            break;
        }
if(m[str1][str2][0]=='\0')
{
printf("\nERROR");
exit(0); }
else if(m[str1][str2][0]=='n') i--;
else if(m[str1][str2][0]=='i')
stack[i]='i';
else {
            for (k = size[str1][str2] - 1; k >= 0; k--)
            {
                stack[i] = m[str1][str2][k];
                i++;
            }
            i--; }
for(k=0;k<=i;k++)
printf(" %c",stack[k]);
printf(" ");
for(k=j;k<=n;k++)

printf("%c",s[k]);
printf(" \n ");
    }
    printf("\n SUCCESS");
    getch();
}
