#include <algorithm>
#include <cctype>
#include <cstdio>
#include <cstring>
#include <functional>
#include <iostream>
#include <unistd.h>
#include <utility>
#include <vector>
#include <map>
 
#define getw getchar_unlocked
#define iterate(n) for(i=0;i<n;i++)
#define d_iterate(p,q) for(int i=p;i<=q;i++)
#define r_iterate(n,z) for(int i=n-1;i>=n-z;i--) /* z number of elements to the left of n */
#define p(n) printf("%d\n",n);
#define get(n) n = scan2();
// #define sort(k,q) qsort(k,q,sizeof(*k),comp);
#define print_array(k,n) iterate(n){ p(k[i]);}
#define ps(s) printf("%s\n",s);
#define repeat(n) for (int i = (0); i < n; i++)
#define ALL(x) (x).begin(), (x).end()
#define mp make_pair;
#define pb push_back;
// int comp(const void *e1,const void *e2){ return *((const lld *)e1) - *((const lld *)e2);}
 
typedef unsigned long long int lld;
typedef unsigned long int ld;
using namespace std;
 
inline lld scan2(){
	lld n=0,s=1;
	char p=getw();
	if(p=='-') s=-1;
	while((p<'0'||p>'9')&&p!=EOF&&p!='-') p=getw();
	if(p=='-') s=-1,p=getw();
	while(p>='0'&&p<='9') { n = (n<< 3) + (n<< 1) + (p - '0'); p=getw(); }
	return n*s;
}
 
char * shift(int k,char * s){ 
	//shifts the string to i position to the front 
	int l = strlen(s);
	int i = 0;
	char *a = new char[16];
	for(i=0;i<l;i++){
		a[ (i+k)%l ] = s[i];
	}	
	return a;
}
int main(){
	lld i,z,n,j,k,t,h,ans = 0;
	lld a,b,c,d;
	get(t);
	char o_str[16];
	char s_str[16];
	bool flag = 0;
	while(t--){
		flag = 0;
		scanf("%s",o_str);
		scanf("%s",s_str);

		for(i=0;i<strlen(o_str);i++){
			// cout << "String being compares are " << shift(i,s_str) << " and " << o_str << "result  = " << strcmp(shift(i,s_str),o_str) << endl ;

			if( strcmp(shift(i,s_str),o_str) == 0 ){
				flag = 1;
				break;
			}
		}
		if(flag)
			printf("YES\n");
		else
			printf("NO\n");

	}

	// cout << shift(3,str);

 
	return 0;
}