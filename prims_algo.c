#include <stdio.h>
int main()
{
    int n, i, j;
    int cost[10][10];
    int visited[10] = {0};
    int min, u, v;
    int total = 0;
    int edges = 0;
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter the adjacency matrix:\n");
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            scanf("%d", &cost[i][j]);
            if(cost[i][j] == 0)
                cost[i][j] = 999;
        }
    }
    // Start from vertex 0
    visited[0] = 1;
    printf("\nEdges of Minimum Spanning Tree:\n");
    while(edges < n - 1)
    {
        min = 999;
        for(i = 0; i < n; i++)
        {
            if(visited[i] == 1)
            {
                for(j = 0; j < n; j++)
                {
                    if(visited[j] == 0 && cost[i][j] < min)
                    {
                        min = cost[i][j];
                        u = i;
                        v = j;
                    }
                }
            }
        }
        printf("%d - %d = %d\n", u, v, min);
        total = total + min;
        visited[v] = 1;
        edges++;
    }
    printf("\nMinimum Cost = %d\n", total);
   return 0;
}