#include <cstring>
#include <iostream>
using namespace std;

char mat[101],str[101];
bool match[101][101];

int main () {
    int i,j,k;
    gets(mat);
    gets(str);
    match[0][0] = (mat[0] == str[0]
                   || mat[0] == '*'
                   || mat[0] == '?');
    for (i=1; i < strlen(str); i++)
        if (mat[0] == '*')
            match[0][i]=1;
        else
            match[0][i]=0;
    i = 0;
    int l = 0;
    while (mat[i] != '\0' && l <= 1) {
        if (mat[i] != '*') l++;
        if (mat[i] != '*' && mat[i] != str[0] && mat[i] != '?') break;
        if (l <= 1) match[i][0] = 1;
        i++;
    }
    for (i=1; i<strlen(mat); i++)
        for (j=1; j<strlen(str); j++) {
            if (mat[i]==str[j] || mat[i]=='?')
                match[i][j]=match[i-1][j-1];
            else if (mat[i]=='*') {
                bool mtc=0;
                for (k=0;k<=j;k++) mtc=mtc||match[i-1][k];
                match[i][j]=mtc;
            } else match[i][j]=0;
        }
    if (!match[strlen (mat)-1][strlen (str)-1]) cout<<"not matched\n";
    else cout<<"matched\n";

    for (int i=0; i<strlen(mat); i++) {
        for (int j=0; j<strlen(str); j++)
            printf("%d ", match[i][j]);
        printf("\n");
    }
    return 0;
}
