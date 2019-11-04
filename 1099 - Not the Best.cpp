#include<bits/stdc++.h>

using namespace std;

const int mx=5001;

typedef unsigned long long ll;

typedef pair<int,ll> ipair;
typedef pair< int, pair<int,ll> >pii;
typedef pair<int,int> p;

vector<ipair>adj[mx];
ll dp[2][mx];

void djkstra(int s,int n)
{
    priority_queue<pii,vector<pii>,greater<pii> >pq;
    pq.push(make_pair(0,make_pair(s,0)));// 0 indicating for only shortest path .........
    dp[0][s]=0;
    while(!pq.empty())
    {
        pii q=pq.top();
        pq.pop();
        int id=q.first;
        ll dist=q.second.second;
        int u=q.second.first;
        if(u == n and id==1) return;
        if(dist > dp[id][u]) continue;
        vector<ipair>::iterator it;
        for(it=adj[u].begin();it!=adj[u].end();it++)
        {
            int v=(*it).first;
            ll weight=(*it).second;
           if(dist + weight < dp[0][v]){
                dp[1][v] = dp[0][v];// dp[0][v] will be updated , so second shortest_path dp[1][v] will be updated
                dp[0][v] = dist + weight;
                pq.push(make_pair(1, make_pair(v, dp[1][v])));
                pq.push(make_pair(0,make_pair( v, dp[0][v])));

            }else if(dist + weight > dp[0][v] && dist + weight < dp[1][v]){ //shortest path is not updated but second shortest path can be updated 
                dp[1][v] = dist + weight;
                pq.push(make_pair(1, make_pair(v, dp[1][v])));
            }
            //cout<<dp[1][v]<<" "<<v<<endl;
        }
    }
}
int main()

{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int tc;
    cin>>tc;
    int u,v,n,r;
    ll w;
    for(int j=1;j<=tc;j++)
    {
        cin>>n>>r;
         for(int i=1;i<=n;i++)
        {
            adj[i].clear();
            dp[0][i]=INT_MAX;
            dp[1][i]=INT_MAX;
        }
        while(r--)
        {
            cin>>u>>v>>w;
            adj[u].push_back(make_pair(v,w));
            adj[v].push_back(make_pair(u,w));
        }
        djkstra(1,n);
        printf("Case %d: %llu\n",j,dp[1][n]);
    }
    return 0;
}
