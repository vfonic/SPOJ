#include <iostream>
#include <map>

using namespace std;

map<int,int> mp;
map<int,int>siz;

int root(int i)
{
    while(i!=mp[i])
    {
        mp[i]=mp[mp[i]];
        i=mp[i];
    }
    return i;
}

void weightedUnion(int x,int y)
{
    int rootX=root(x);
    int rootY=root(y);
    if(siz[rootX]<siz[rootY])
    {
        mp[rootX]=mp[rootY];
        siz[rootY]+=siz[rootX];
    }
    else
    {
        mp[rootY]=mp[rootX];
        siz[rootX]+=siz[rootY];
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    int n,m;
    cin>>n>>m;
    int ans=n;
    while(m--)
    {
        int x,y;
        cin>>x>>y;
        if(!mp[x])
        {
            mp[x]=x;
            siz[x]=1;
        }
        if(!mp[y])
        {
            mp[y]=y;
            siz[y]=1;
        }
        if(root(x)!=root(y))
        {
            weightedUnion(x,y);
            ans--;
        }
    }
    cout<<ans;
    return 0;
}
