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
 lld dp[1001];
 
lld solve(lld *f,lld *dis , lld n,lld max_dis){
	lld i , j ,k;
	dp[0] = 0;

	//each can be considered as a separate query , they are independent okay
	
	max_dis = 2 * max_dis ; //we need to determine upto this distance

	sort(f,f+n);

	lld min;
	for(i=1;i<=max_dis;i++){
			min = 9999999;
			for(j=1;j<=n && f[j-1]<=i ;j++){
					if( dp[i-f[j-1]] < min )
						min = dp[i-f[j-1]];
			}
			dp[i] = min + 1;
	}


	// iterate(max_dis+1)
	// 	cout << dp[i] << endl;
	lld sum = 0;
	for(i=0;i<n;i++){
		sum += dp[2*dis[i]];
	}

	return sum;
}





int main(){
	lld i,z,n,j,k,t,h,ans = 0;
	lld a,b,c,d;
	
	lld dis[501];
	lld f[501];

	lld max_dis = 0;
	get(t);
	
	while(t--){
		get(n);
		iterate(n){
			get(dis[i]);
			if( dis[i] > max_dis )
				max_dis = dis[i];
		}
		iterate(n)
			get(f[i]);


			dp[0] = 0;


		max_dis = 2 * max_dis ; 

		sort(f,f+n);

		lld min;
		for(i=1;i<=max_dis;i++){
			min = 9999999;
			for(j=1;j<=n && f[j-1]<=i ;j++){
					if( dp[i-f[j-1]] < min )
						min = dp[i-f[j-1]];
			}
			dp[i] = min + 1;
		}


		// iterate(max_dis+1)
		// 	cout << dp[i] << endl;
		lld sum = 0;
		for(i=0;i<n;i++){
			sum += dp[2*dis[i]];
		}

		p(sum);

	}
 
	return 0;
}