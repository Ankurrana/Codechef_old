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
#include <math.h>
 
#define getw getchar_unlocked
#define iterate(n) for(i=0;i<n;i++)
#define d_iterate(p,q) for(int i=p;i<=q;i++)
#define r_iterate(n,z) for(int i=n-1;i>=n-z;i--) /* z number of elements to the left of n */
#define p(n) printf("%lld\n",n);
#define get(n) n = scan2();
// #define sort(k,q) qsort(k,q,sizeof(*k),comp);
#define print_array(k,n) iterate(n){ p(k[i]);}
#define ps(s) printf("%s\n",s);
#define repeat(n) for (int i = (0); i < n; i++)
#define clear(v) memset((v), 0, sizeof (v))
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

lld solve(lld i,lld j){
	//i is supposed to be the lower one
	lld i_level = (lld)log2(i);
	lld j_level = (lld)log2(j);
	lld p = j>>(j_level - i_level);
	lld q = i;


	while(p!=q) { 
		p = p>>1;
		q = q>>1; 
	}

	return (i_level+j_level-(2*(lld)log2(p)));

	// return 0;
}
 
 
int main(){
	lld i,z,n,j,k,t,h,ans = 0;
	lld a,b,c,d;
	// cout << solve(5,12);

	// cout << (lld)log2(5);
	get(t);
	
	while(t--){
		get(a);
		get(b);
		if(a>b)
			swap(a,b);
		p(solve(a,b));
	}
 
	return 0;
}