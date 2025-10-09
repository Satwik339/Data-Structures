#include <stdio.h>
#include <limits.h>
#define V 10

int minKey(int key[], int mstSet[], int n) {
    int min = INT_MAX, idx = -1;
    for (int v = 0; v < n; v++)
        if (!mstSet[v] && key[v] < min)
            min = key[v], idx = v;
    return idx;
}

void primMST(int g[V][V], int n) {
    int parent[V], key[V], mstSet[V]={0};
    for (int i=0;i<n;i++) key[i]=INT_MAX;
    key[0]=0; parent[0]=-1;

    for (int c=0;c<n-1;c++) {
        int u=minKey(key,mstSet,n);
        mstSet[u]=1;
        for (int v=0;v<n;v++)
            if(g[u][v] && !mstSet[v] && g[u][v]<key[v])
                parent[v]=u, key[v]=g[u][v];
    }

    printf("Edge \tWeight\n");
    for (int i=1;i<n;i++)
        printf("%d - %d \t%d\n", parent[i], i, g[i][parent[i]]);
}

int main() {
    int n,g[V][V];
    printf("Enter number of vertices: ");
    scanf("%d",&n);
    printf("Enter adjacency matrix (0 if no edge):\n");
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            scanf("%d",&g[i][j]);
    primMST(g,n);
}

