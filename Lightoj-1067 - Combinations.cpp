#include <bits/stdc++.h>

 using namespace std;

 typedef long long ll;
 ll fact[1000002];

 const ll mod=1000003;

 ll po(ll a,ll b)
 {
     ll ans=1ll;
     while(b)
     {
         if(b&1)
         {
             ans=(ans*a)%mod;
         }
         b=b>>1;
         a=(a*a)%mod;
     }
     return (ans);
 }

 int main()

 {
     ll pro=1ll;
     fact[0]=1ll;
     for(ll i=1;i<=1000000;i++)
     {
         pro=(pro*i)%mod;
         fact[i]=(pro)%mod;
     }
     int tc,s=1;
     int n,r;
     scanf("%d",&tc);
     while(tc--)
     {
     scanf("%d%d",&n,&r);
     ll res=(po(fact[n-r],mod-2)*po(fact[r],mod-2))%mod;
     ll res1=(fact[n]*res)%mod;
     printf("Case %d: %lld\n",s,(res1%mod));
     s++;
     }
     return 0;
 }
