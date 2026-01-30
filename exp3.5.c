// wap to find a product of two matrices using pointers
#include <stdio.h>
int main(){
    int r1,c1,r2,c2,i,j,k;
    int a1[10][10],a2[10][10],pro[10][10];
    printf("Enter rows & columns first matrix: ");
    scanf("%d%d",&r1,&c1);
    printf("Enter rows & columns second matrix: ");
    scanf("%d%d",&r2,&c2);
    if(c1!=r2){
        printf("product not possible\n");   return 0;    }
    printf("Enter first matrix:\n");
    for(i=0;i<r1;i++){
        for(j=0;j<c1;j++){
            scanf("%d",&a1[i][j]);        }    }
    printf("Enter second matrix:\n");
    for(i=0;i<r2;i++){
        for(j=0;j<c2;j++){
            scanf("%d",&a2[i][j]);        }    }
    for(i=0;i<r1;i++){
        for(j=0;j<c2;j++){
            pro[i][j]=0;
            for(k=0;k<c1;k++){
                pro[i][j]+=*(*(a1+i)+k)**(*(a2+k)+j);            }        }    }
    printf("Product of two matrices:\n");
    for(i=0;i<r1;i++){
        for(j=0;j<c2;j++){
            printf("%d ",*(*(pro+i)+j));        }        printf("\n");    }
    return 0;}
