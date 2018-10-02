#include <stdio.h>
long long int mini(long long int n1,long long int n2)
{
	if (n1>n2)
		return (n1-n2);
	else
		return (n2-n1);
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--){

		int i=0,j,f=1,size1,size2;
		
		scanf("%d",&size1);
		long long int n1[size1];
		for (i=0;i<size1;i++)
			scanf("%lld",&n1[i]);
			
		scanf("%d",&size2);
		long long int n2[size2];
		for (i=0;i<size2;i++)
			scanf("%lld",&n2[i]);
			
		long long int min=mini(n1[0],n2[0]);
		for (i=0;i<size1;i++){
			for (j=0;j<size2;j++){
				if ((mini(n1[i],n2[j]))<min)
					min=(mini(n1[i],n2[j]));
			}
		}
		printf("%lld\n",min);
	}
	return 0;
}