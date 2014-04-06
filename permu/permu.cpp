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
 
inline int scan2(){
	int n=0,s=1;
	char p=getw();
	if(p=='-') s=-1;
	while((p<'0'||p>'9')&&p!=EOF&&p!='-') p=getw();
	if(p=='-') s=-1,p=getw();
	while(p>='0'&&p<='9') { n = (n<< 3) + (n<< 1) + (p - '0'); p=getw(); }
	return n*s;
}
 
bool myfunction(pair< int,int > i,pair < int,int > j) { return ( i.first <= j.first); }



int main(){
	int i,z,n,j,k,t,h,ans = 0;
	int b,c,d,s;
	get(t);

	vector < pair< int, int > > a;
	vector < pair< int, int > >::iterator it;;
	
	while(t--){
		get(n);
		get(k);
		get(s);
		a.clear();

		iterate(n){
			get(z);
			a.push_back(make_pair(z,i+1));
		}

		sort(a.begin(),a.end(),myfunction);

		for(it=a.begin();it!=a.end();it++){
			// cout << (*it).first << "second = " << (*it).second <<endl ;
			printf("%d ",(*it).second );
		}
		printf("\n");
	}
	
 
	return 0;
}