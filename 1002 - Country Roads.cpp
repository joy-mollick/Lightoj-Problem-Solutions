#include<bits/stdc++.h>

using namespace std;

const int mx=505;

typedef long long ll;
const ll INF=INT_MAX;

typedef pair<int,ll> p;
vector<int>adj[mx];
ll edge[mx][mx];
ll dis[mx];// this stores our minimum cost of all maximum of all path towrads to it

void bfs(int s)
{
                // this stores the maximum cost of all cost of the paths along to it
    queue<p>pq;
    p M,N;
    M.first=s;
    M.second=0;
    pq.push(M);
    dis[s]=0;
    while(!pq.empty())
    {
        M =pq.front();
        pq.pop();
        int u=M.first;
        vector<int>::iterator it;
        for(it=adj[u].begin();it!=adj[u].end();it++)
        {
             int v =(*it);
             N.first=v;// keeping node in first part 
             N.second=max(M.second,edge[u][v]);// keeping this maximum along this path in second part of pair N
             if(N.second<dis[v])
             {
                 dis[v]=N.second; // dist is the minimum of all coming towards this path in dist
                 pq.push(N);//
             }
        }
    }
}
int main()

{
    //ios_base::sync_with_stdio(false);cin.tie(NULL);
    int tc;
    scanf("%d",&tc);
    int u,v,n,r,s;
    ll w;
    for(int j=1;j<=tc;j++)
    {
        scanf("%d%d",&n,&r);
       for (int i = 0; i < mx; i++) {
            adj[i].clear();
            dis[i] = INF;
            for (int j = 0; j < mx; j++) {
                edge[i][j] = INF;
                edge[j][i] = INF;
            }
        }
        while(r--)
        {
            scanf("%d%d%lld",&u,&v,&w);
            u++,v++;
            if(w<edge[u][v]){ // Keeping minimum everytime
            adj[u].push_back(v);
            adj[v].push_back(u);
            edge[u][v] = w;
            edge[v][u] = w;}
        }
        scanf("%d",&s);
        s++;
        bfs(s);
        printf("Case %d:\n",j);
        for(int i=1;i<=n;i++){
        if(dis[i]==INT_MAX) printf("Impossible\n");
        else
        printf("%llu\n",dis[i]);}
    }
    return 0;
}
