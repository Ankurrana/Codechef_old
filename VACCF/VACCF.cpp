#include "iostream"
#include "cstdio"
#include "math.h"
using namespace std;

int main(){
	int i,n,x,k,sum,ans;
	scanf("%d%d",&n,&x);
	sum = 0;
	for(i=0;i<n;i++){
		scanf("%d",&k);
		sum += k;
	}
	sum = sum>0?sum:-sum;
	ans = sum/x;
	if(sum%x > 0)
		ans++;
	
	printf("%d\n",ans);
	return 0;
}