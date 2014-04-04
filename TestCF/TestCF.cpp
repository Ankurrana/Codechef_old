#include "iostream"
#include "string"
#include "cstdio"

#define iterate(n) for(int i=0;i<n;i++)
typedef long long int lld;

using namespace std;

int main(){
	lld o,z,i,j,k,ans;
	string s = "110";
	string p = "10";
	
	scanf("%lld %lld",&z,&o);

	if( o>z ){
		int diff = o - z; //is def. positive
		if( o >(2*z+2))
			printf("-1");
		else if( o == 2*z+2 ){
			iterate(o)
				printf("110");
			printf("11");
		}
		else if( o<(2*z+2) && o>(2*z) ){
			iterate(o)
				printf("110");
			printf("1");
		}
		else if(o<2*z){
			int diff = o - z;
			iterate(z-diff)
				printf("10");
			iterate(diff)
				printf("110");
		}
		else
			printf("Code 1..\n");
	}else{
		if(z>o+1)
			printf("-1");
		else if( z == o+1 ){
			printf("0");
		iterate(o)
			printf("10");
		}else{
			printf("Hrer...2");
		}
	}	


	return 0;
}