#include<bits/stdc++.h>

using namespace std;

long long mod=100000007;

/// Time :0.108 ,very fast 

int main()

{
    int tc;
    scanf("%d",&tc);
    int caso=0;
    while(tc--)
    {
        caso++;
        int n,k;
        scanf("%d%d",&n,&k);
        int arr[n];
        for(int i=0;i<n;i++)
        {
            scanf("%d",&arr[i]);
        }
        long long dp[k+1];
        memset(dp,0,sizeof(dp));
        dp[0]=1;
        for(int j=0;j<n;j++)
        {
            for(int i=arr[j];i<=k;i++)
            {
                dp[i]=(dp[i]+dp[i-arr[j]]);
                if(dp[i]>=mod)
                {
                    dp[i]=dp[i]-mod;
                }
            }
        }
        printf("Case %d: %lld\n",caso,dp[k]);
    }
    return 0;
}
