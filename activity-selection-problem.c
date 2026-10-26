#include <stdio.h>
void activitySelection(int start[], int finish[], int n){
    int i, j;
    printf("Selected activities: ");
    printf("%d ", 0);
    j = 0;
    for (i = 1; i < n; i++){
        if (start[i] >= finish[j]){
            printf("%d ", i);
            j = i;
        }
    }
}
int main()
{
    int start[] = {1, 3, 0, 5, 8, 5};
    int finish[] = {2, 4, 6, 7, 9, 9};
    int n = sizeof(start) / sizeof(start[0]);
    activitySelection(start, finish, n);
    return 0;}