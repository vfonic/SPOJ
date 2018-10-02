#include <bits/stdc++.h>
using namespace std;
int main ()
{
    int t;
    scanf("%d",&t);
    while (t--){
        int n;
        scanf("%d",&n);
        int a[n];
        unsigned long long int sum[n];
        for (int i=0;i<n;i++){
            scanf("%d",&a[i]);
            if (i==0)
                sum[i]=a[i];
            else
                sum[i]=sum[i-1]+a[i];
        }
        unsigned long long int min=sum[n-2];
        for (int i=0;i<n;i++){
            if (i==0){
                unsigned long long int right=sum[n-1]-sum[i];
                if (right<min)
                    min=right;
            }
            else if (i==n-1){
                unsigned long long int left=sum[i-1];
                if (left<min)
                    min=left;
            }
            else{
                unsigned long long int left=sum[i-1];
                unsigned long long int right=sum[n-1]-sum[i];
                if ((left*2+right)<min)
                    min=left*2+right;
                if ((right*2+left)<min)
                    min=right*2+left;
            }
        }
        cout<<min<<endl;
    }
}
