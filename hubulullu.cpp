#include <stdio.h>
int main()
{
	long long int t,n,term;
	scanf("%lld",&t);
	while(t--){
		scanf("%lld %lld",&n,&term);
		if(term==0)
		
			printf("Airborne wins.\n");
		else
			printf("Pagfloyd wins.\n");
	}
	return 0;
}