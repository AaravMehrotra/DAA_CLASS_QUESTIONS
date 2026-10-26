#include <stdio.h>
int main(){
    int n = 5;
    int start[]  = {1, 2, 3, 4, 5};
    int finish[] = {3, 4, 5, 6, 7};
    int room[5];
    int rooms = 0;
    for (int i = 0; i < n; i++)
    {
        room[i] = -1;
    }
    for (int i = 0; i < n; i++)
    {
        int assigned = 0;
        for (int j = 0; j < rooms; j++){
            int available = 1;
            for (int k = 0; k < i; k++){
                if (room[k] == j &&
                    !(finish[k] <= start[i] ||
                      finish[i] <= start[k]))
                {
                    available = 0;
                    break;
                }
            }
            if (available)
            {
                room[i] = j;
                assigned = 1;
                break;
            }
        }
        if (!assigned)
        {
            room[i] = rooms;
            rooms++;
        }
    }
    printf("Minimum rooms required: %d\n", rooms);
    for (int i = 0; i < n; i++)
    {
        printf("Interval %d -> Room %d\n",
               i + 1, room[i] + 1);
    }
    return 0;}