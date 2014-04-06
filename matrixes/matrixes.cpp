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
#define p(n) printf("%d\n",n);
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

// int n_combinations(long a){
// 	int i,j,k,ans = 0;
// 	for(i=2;i<sqrt(a);i++){
// 		if(a%i == 0)
// 			ans += 2;
// 	}
// 	ans += 2;
// 	if( (int)sqrt(a) * (int)sqrt(a) == a)
// 		ans++;
// 	return ans;
// }

lld ad(lld n){
	lld k,ans = 0;
	lld m = sqrt(n);
	for(k=1;k<=m;k++){
		ans += (lld)n/k;
	}
	ans *= 2;
	ans -= (m*m);
	return ans;
}

lld solve(lld n){
	lld i = 0;
	lld ans = 0;
	lld a,b,c,d,k,j;

	for(i=1;i<((n+1)/2);i++){
		a = i;
		d = n-i;
		k = a * d;
			ans += ad(k-1);
		// cout << "ans += " << ans << endl ;
	}
	ans = ans * 2;

	if(n%2 == 0) //if not odd
		ans += ad( ((n/2)*(n/2)) - 1 );
	// ans *= 2;
	// if( (2 * (int)(n/2)) == n ){
	// 	ans += ad((n/2 * (n/2))-1);
	// }
	return ans;
}
 
 
int main(){
	lld i,z,n,j,k,t,h,ans = 0;
	lld a,b,c,d;
	get(t);
	
	while(t--){
		get(n);
		printf("%lld\n",solve(n));			
	}

	// f[1] = 1;
	// f[0] = 0;
	// for(i = 2;i<=390625;i++){
	// 	f[i] = n_combinations(i) + f[i-1];
	// }

	// for(i=1;i<=10;i++){
	// 	// cout << f[i] << endl;
	// }

	// for(i=1;i<10;i++){
	// 	cout <<  "for i =" <<  i  <<  ":" <<  ad(i) << endl;
	// }

	// get(t);

	// iterate(t){
	// 	get(n);

	// }
	// for(i = 1;i<=30;i++){
	// 	cout << "a[" << i << "] = " << ad(i) << endl; 
	// }



	// for(i=3;i<=2500;i++)
	// 	cout << i << " = " << solve(i) << endl;

	// cout << solve(3) << endl;

	return 0;
}