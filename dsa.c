
// write a program to find sum ofrows and columns of matrix of given order r*c
#include <stdio.h>
int main(){
    int r,c,i,j,sumr=0,sumc=0;
    printf("Enter number of rows and columns: ");
    scanf("%d%d",&r,&c);
    int a[r][c];
    printf("Enter elements of matrix:\n");
    for(i=0;i<r;i++)    {
        for(j=0;j<c;j++)       {
            scanf("%d",&a[i][j]);
        }    }
    for(i=0;i<r;i++){
        sumr=0;
        for(j=0;j<c;j++){
            sumr=sumr+a[i][j];        }
        printf("Sum of row %d: %d\n",i+1,sumr);}
            for(j=0;j<c;j++)    {
        sumc=0;
        for(i=0;i<r;i++)        {
            sumc=sumc+a[i][j];        }
        printf("Sum of column %d: %d\n",j+1,sumc);    }
    return 0;}
