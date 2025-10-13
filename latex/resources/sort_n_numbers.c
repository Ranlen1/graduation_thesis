#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

int main(void)
{
    int sizeOfArray;
    scanf("%d", &sizeOfArray);
    int *array = malloc(sizeOfArray *sizeof(int));

    for(int i = 0; i < sizeOfArray; ++i)
        scanf("%d", &array[i]);

    qsort(array, sizeOfArray, sizeof(int), compare);

    for(int i = 0; i < sizeOfArray; ++i)
        printf("%d\n", array[i]);

    free(array);
    return 0;
}
