#include <stdio.h>
#include <limits.h>
#define V 10

int minDist(int d[], int vis[], int n) {
    int min=INT_MAX, idx=-1;
    for(int i=0;i<n;i++) if(!vis[i] && d[i]<=min) min=d[i], idx=i;
    return idx;
}

void dijkstra(int g[V][V], int s, int n) {
    int d[V], vis[V]={0};
    for(int i=0;i<n;i++) d[i]=INT_MAX; d[s]=0;
    for(int c=0;c<n-1;c++) {
        int u=minDist(d,vis,n); vis[u]=1;
        for(int v=0;v<n;v++)
            if(!vis[v] && g[u][v] && d[u]+g[u][v]<d[v])
                d[v]=d[u]+g[u][v];
    }
    for(int i=0;i<n;i++) printf("%d -> %d\n", i,d[i]);
}

int main() {
    int n, g[V][V], s;
    printf("Vertices: "); scanf("%d",&n);
    printf("Adjacency matrix:\n");
    for(int i=0;i<n;i++) for(int j=0;j<n;j++) scanf("%d",&g[i][j]);
    printf("Source: "); scanf("%d",&s);
    dijkstra(g,s,n);
}

