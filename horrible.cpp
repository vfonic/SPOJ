#include <iostream>
#include <string.h>
#define ll long long
#define SIZE 100001

using namespace std;

ll a[SIZE],segTree[4*SIZE+1],lazy[4*SIZE+1];

void constructSegTree(ll low,ll high,ll pos)
{
    if(low>high)
    {
        return;
    }
    if(low==high)
    {
        segTree[pos]=a[low];
        return;
    }
    ll mid=(low+high)/2;
    constructSegTree(low,mid,2*pos+1);
    constructSegTree(mid+1,high,2*pos+2);
    segTree[pos]=segTree[2*pos+1]+segTree[2*pos+2];
}

ll queryLazy(ll qlow,ll qhigh,ll low,ll high,ll pos)
{
    if(low>high)
    {
        return 0;
    }
    if(lazy[pos]!=0)
    {
        segTree[pos]+=(high-low+1)*lazy[pos];
        if(low!=high)   //Not a leaf node
        {
            lazy[2*pos+1]+=lazy[pos];
            lazy[2*pos+2]+=lazy[pos];
        }
        lazy[pos]=0;
    }
    //No overlap
    if(qlow>high||qhigh<low)
    {
        return 0;
    }
    //Total overlap
    if(qlow<=low&&qhigh>=high)
    {
        return segTree[pos];
    }
    //Partial overlap
    ll mid=(low+high)/2;
    return queryLazy(qlow,qhigh,low,mid,2*pos+1)+queryLazy(qlow,qhigh,mid+1,high,2*pos+2);
}

void updateRangeLazy(ll startRange,ll endRange,ll delta,ll low,ll high,ll pos)
{
    if(low>high)
    {
        return;
    }
    if(lazy[pos]!=0)
    {
        segTree[pos]+=(high-low+1)*lazy[pos];
        if(low!=high)
        {
            lazy[2*pos+1]+=lazy[pos];
            lazy[2*pos+2]+=lazy[pos];
        }
        lazy[pos]=0;
    }
    //No overlap
    if(startRange>high||endRange<low)
    {
        return;
    }
    //Total overlap
    if(startRange<=low&&endRange>=high)
    {
        segTree[pos]+=(high-low+1)*delta;
        if(low!=high)
        {
            lazy[2*pos+1]+=delta;
            lazy[2*pos+2]+=delta;
        }
        return;
    }
    //Partial overlap
    ll mid=(low+high)/2;
    updateRangeLazy(startRange,endRange,delta,low,mid,2*pos+1);
    updateRangeLazy(startRange,endRange,delta,mid+1,high,2*pos+2);
    segTree[pos]=segTree[2*pos+1]+segTree[2*pos+2];
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,c;
        cin>>n>>c;
        memset(a,0,sizeof a);
        memset(segTree,0,sizeof segTree);
        memset(lazy,0,sizeof lazy);
        ll op,p,q,v;
        while(c--)
        {
            cin>>op;
            if(op==1)
            {
                cin>>p>>q;
                cout<<queryLazy(p-1,q-1,0,n-1,0)<<endl;
            }
            else
            {
                cin>>p>>q>>v;
                updateRangeLazy(p-1,q-1,v,0,n-1,0);
            }
        }
    }
    return 0;
}
