//distance vector
#include <stdio.h>
#define INF 999

int main() {
    int n,i,j,k,change,c[10][10],d[10][10];
    printf("Enter the number of nodes: ");
    scanf("%d",&n);
    printf("Enter the cost matrix (use %d for no direct path):\n",INF);
    for(i=0;i<n;i++) for(j=0;j<n;j++)
        scanf("%d",&c[i][j]),d[i][j]=c[i][j];
    do {
        change=0;
        for(i=0;i<n;i++) for(j=0;j<n;j++) for(k=0;k<n;k++)
            if(c[i][k]!=INF && d[k][j]!=INF && c[i][k]+d[k][j]<d[i][j])
                d[i][j]=c[i][k]+d[k][j],change=1;
    } while(change);
    printf("\nFinal Distance Vector Table:\n");
    for(i=0;i<n;i++) {
        printf("Routing table for Node %d:\n",i+1);
        for(j=0;j<n;j++) printf("To Node %d -> Cost: %d\n",j+1,d[i][j]);
        printf("\n");
    }
    return 0;
}


//link state
#include <stdio.h>
#define INF 999

int main() {
    int n,i,j,s,u,min,c[10][10],d[10],v[10]={0};
    printf("Enter the number of nodes: ");
    scanf("%d",&n);
    printf("Enter the cost matrix (use %d for no direct path):\n",INF);
    for(i=0;i<n;i++) for(j=0;j<n;j++) scanf("%d",&c[i][j]);
    printf("Enter the source node: ");
    scanf("%d",&s); s--;
    for(i=0;i<n;i++) d[i]=c[s][i];
    d[s]=0;
    for(i=0;i<n;i++) {
        min=INF; u=-1;
        for(j=0;j<n;j++) if(!v[j] && d[j]<min) min=d[j],u=j;
        if(u==-1) break;
        v[u]=1;
        for(j=0;j<n;j++) if(!v[j] && c[u][j]!=INF && d[u]+c[u][j]<d[j]) d[j]=d[u]+c[u][j];
    }
    printf("\nRouting table for Node %d:\n",s+1);
    for(i=0;i<n;i++) printf("To Node %d -> Cost: %d\n",i+1,d[i]);
    return 0;
}