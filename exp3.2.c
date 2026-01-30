//create an array1 with the elements insert the elements in i position in array1`and delete the elemnrt from j postionin array1
#include <stdio.h>
int main() {
    int a[100], n, i, j, k, ele;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter elements: ");
    for(k = 0; k < n; k++)
        scanf("%d", &a[k]);
    printf("Position to insert: ");
    scanf("%d", &i);
    printf("Element to insert: ");
    scanf("%d", &ele);
    for(k = n; k > i - 1; k--)
        a[k] = a[k - 1];
    a[i - 1] = ele;
    n++;
    printf("Position to delete: ");
    scanf("%d", &j);
    for(k = j - 1; k < n - 1; k++)
        a[k] = a[k + 1];
    n--;
    printf("Final array: ");
    for(k = 0; k < n; k++)
        printf("%d ", a[k]);
    return 0; }

