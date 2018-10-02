#include <bits/stdc++.h>
using namespace std;
int dp[10500][150][2];  // 0 means Ada 1 means Vinit
int ori;

int func(int n,int m,int pla)
{
    if (dp[n][m][pla]!=-1)
        return dp[n][m][pla];

    if (m==0){
        if (n > ori){
            dp[n][m][0] = 1;
            dp[n][m][1] = 0;
        }
        else{
            dp[n][m][0] = 0;
            dp[n][m][1] = 1;
        }
        return dp[n][m][pla];
    }

    else{
        int npla = (pla == 1) ? 0 : 1 ;
        dp[n][m][pla] = 0;
        for (int i=0;i<4;i++){
            int n1[4];
            int nc=n;
            for (int j=3;j>=0;j--){
                n1[j] = nc%10;
                nc=nc/10;
            }
            if (n1[i]==9) n1[i]=0;
            else n1[i]++;
            nc=0;
            for (int j=0;j<4;j++){
                nc=nc*10+n1[j];
            }
            dp[n][m][pla] |= !(func(nc,m-1,npla));
        }
        return dp[n][m][pla];
    }

}

int main ()
{
    //freopen("in.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    while (t--){
        memset(dp,-1,sizeof(dp));
        int n,m;
        cin>>n>>m;
        ori = n;
        if (func(n,m,0) == 1)
            cout<<"Ada"<<endl;
        else
            cout<<"Vinit"<<endl;
    }
    return 0;
}
