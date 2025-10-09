#include <stdio.h>
#include <stdlib.h>

struct Edge {int u,v,w;};

int parent[50];
int find(int x){ return parent[x]==x?x:(parent[x]=find(parent[x])); }

int cmp(const void*a,const void*b){
    return ((struct Edge*)a)->w-((struct Edge*)b)->w;
}

int main(){
    int V,E,i,c=0; struct Edge e[100];
    printf("Enter vertices and edges: ");
    scanf("%d%d",&V,&E);
    for(i=0;i<E;i++) scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].w);
    for(i=0;i<V;i++) parent[i]=i;
    qsort(e,E,sizeof(e[0]),cmp);
    printf("Edge\tWeight\n");
    for(i=0;i<E && c<V-1;i++){
        int x=find(e[i].u),y=find(e[i].v);
        if(x!=y){ printf("%d-%d\t%d\n",e[i].u,e[i].v,e[i].w); parent[x]=y; c++; }
    }
    return 0;
}

