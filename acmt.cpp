#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    scanf("%d",&t);
    while (t--){
        int a,b;
        scanf("%d %d",&a,&b);
        int co=0;
        while (a>0 && b>0){
            if (!((a>=2 && b>=1) || (a>=1 && b>=2)))
                break;
            if (a>b){
                a-=2;
                b--;
                co++;
            }
            else{
                a--;
                b-=2;
                co++;
            }
        }
        printf("%d\n",co);
    }
    return 0;
}
