#include<bits/stdc++.h>

using namespace std;

const int mx=1e5;

pair<int,int>tree[4*mx+1];
int arr[mx];

void construct_segment_tree(int root_index,int b,int e)
{
    if(b==e)// begin and end range is equal means leaf node comes place this value
    {
        tree[root_index].second=arr[b];
        tree[root_index].first=0;
        return ;
    }
    int left=root_index*2;
    int right=(root_index*2)+1;
    int mid=(b+e)>>1;
    //alter=!alter;// one half will be left range and another half will be right range
    construct_segment_tree(left,b,mid);// left tree will be construct when left is root and b-mid is range
    construct_segment_tree(right,mid+1,e);
    tree[root_index].first=tree[left].first+1;
    int lev=tree[root_index].first;
    if(lev%2==1) tree[root_index].second=(tree[left].second|tree[right].second);
    else tree[root_index].second=(tree[left].second^tree[right].second);
    //cout<<tree[root_index]<<endl;
     //when left and right will be constructed then root_index will be sum of left and right
}

/*int query_sum(int root_index,int b,int e,int i,int j)
{
    if(i>e||j<b)// outside overlap nothing we get
    {
        return 0;
    }
    if(i<=b&&e<=j) // inside overlap ,so we will get value
    {
        return tree[root_index];
    }
    int left=2*root_index;
    int right=(2*root_index+1);
    int mid=(b+e)/2;
    int l1=query_sum(left,b,mid,i,j);
    int r1=query_sum(right,mid+1,e,i,j);
    return (l1^r1);
}*/

void update(int root_index,int b,int e,int i,int nwval)
{
     if(i>e||i<b)// outside overlap nothing we get
    {
        return;
    }
    if(i==b&&i==e) // that node we get
    {
        tree[root_index].second=nwval;
        //tree[root_index].first=0;
        return;
    }

    int left=(2*root_index);
    int right=(2*root_index)+1;
    int mid=(b+e)>>1;
    update(left,b,mid,i,nwval);
    update(right,mid+1,e,i,nwval);
    int lev=tree[root_index].first;
    if(lev%2==1) tree[root_index].second=(tree[left].second|tree[right].second);
    else tree[root_index].second=(tree[left].second^tree[right].second);
}

int main() {
    int n,q;
    scanf("%d%d",&n,&q);
    n=1<<n;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&arr[i]);
    }
   construct_segment_tree(1,1,n);
   //cout<<tree[1].second<<endl;
   int l,r;
   int c;
  // update(1,1,n,2,6);
   while(q--){
        scanf("%d%d",&l,&r);
       update(1,1,n,l,r);
   printf("%d\n",tree[1].second);
   }
   }
