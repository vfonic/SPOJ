#include <bits/stdc++.h>
using namespace std;
typedef pair<double,int> ip;
bool mst[101];
vector<ip>adj[101];
double bfs(int s,int d)
{
    priority_queue<ip> pq;
    pq.push(make_pair(0,s));
    double ans=1;
    while(!pq.empty())
    {
        int u=pq.top().second;
        double p=pq.top().first;
        if(p!=0.0)
            ans*=p;
        mst[u]=true;
        pq.pop();
        if(u==d)
            return ans*100;
        for(auto it=adj[u].begin();it!=adj[u].end();it++)
        {
            if(!mst[it->second])
                pq.push(make_pair(it->first,it->second));
        }
    }
}
int main()
{
	int n,m,u,v;
	double p;
	scanf("%d",&n);
	while(n)
    {
        scanf("%d",&m);
        while(m--)
        {
            scanf("%d%d%f",&u,&v,&p);
            adj[u].push_back(make_pair(p/100,v)),adj[v].push_back(make_pair(p/100,u));
        }
        printf("%0.6f\n",bfs(1,n));
        for(int i=1;i<=n;i++)
        {
            adj[i].clear();
            mst[i]=false;
        }
        scanf("%d",&n);
    }
	return 0;
}
