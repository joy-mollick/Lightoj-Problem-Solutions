#include<bits/stdc++.h>
 
using namespace std;
 
const int mx=105;
 
typedef unsigned long long ll;
 
typedef pair<int,ll> ipair;
 
vector<ipair>adj[mx];
ll dist[mx];
 
void djkstra(int s)
{
    priority_queue<ipair,vector<ipair>,greater<ipair> >pq;
    pq.push(make_pair(s,0));// 0 indicating for only shortest path .........
    dist[s]=0;
    while(!pq.empty())
    {
        ipair q=pq.top();
        pq.pop();
        int u=q.first;
        vector<ipair>::iterator it;
        for(it=adj[u].begin();it!=adj[u].end();it++)
        {
            int v=(*it).first;
            ll weight=(*it).second;
            if(dist[v]>dist[u]+weight)
            {
                dist[v]=dist[u]+weight;
                pq.push(make_pair(v,dist[v]));
            }
        }
    }
}
int main()
 
{
    //ios_base::sync_with_stdio(false);cin.tie(NULL);
    int tc;
    scanf("%d",&tc);
    int u,v,n,r;
    ll w;
    for(int j=1;j<=tc;j++)
    {
        scanf("%d%d",&n,&r);
         for(int i=1;i<=n;i++)
        {
            dist[i]=INT_MAX;
            adj[i].clear();
        }
        while(r--)
        {
            scanf("%d%d%lld",&u,&v,&w);
            adj[u].push_back(make_pair(v,w));
            adj[v].push_back(make_pair(u,w));
        }
        djkstra(1);
        if(dist[n]==INT_MAX) printf("Case %d: Impossible\n",j);
        else
        printf("Case %d: %llu\n",j,dist[n]);
    }
    return 0;
}
