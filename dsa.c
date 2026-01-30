//convert uppercase input to lowercase using for loop
#include <stdio.h>
int main(){
    int i;
    char lo[50];
    printf("Enter a string: ");
    scanf("%s", lo);
    for(i=0;lo[i])
    {
        if(lo[i]>='A' && lo[i]<='Z')
        {
            lo[i]=lo[i]+32;
        }
    }    printf("Lowercase string: %s\n", lo);
    return 0;
}
