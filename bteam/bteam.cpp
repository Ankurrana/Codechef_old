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
 
// lld diff( vector< lld > &a){
// 	vector< lld >::iterator it;
// 	lld min = 9999999ULL, max = 0;
// 	for(it=a.begin();it!=a.end();it++){
// 		if(*it < min )
// 			min = *it;
// 		else if( *it > max )
// 			max = *it;
// 	}
// 	return (max - min);
// }

lld calculate_Difference(lld *a){
	lld i,j,k;
	lld min  = a[5];
	lld max = 0;
	for(i=0;i<15;i++){
		if( a[i] > max )
			max = a[i];
		if( a[i] < min ){
			min = a[i];
			// cout << "min changed for I = " << i << endl;
		}
	}
	// cout << "max = " << max << "and min is = " << min << endl; 
	return (max-min);

}



lld solve(){
	lld i,j,k;
	lld b,c;
	lld a[20] = {0};
	lld index = 1;
	lld min_difference = 1000001;

	for(i=1;i<=10;i++){
		for(j=0;j<15;j++){
			get(a[j]);
		}
		lld diff = calculate_Difference(a);
		// cout << diff << endl;
		if(diff <= min_difference){
			min_difference = diff;
			index = i;
		}
	}

	printf("%lld %lld\n",index,min_difference);

}


 
int main(){
	lld i,z,n,j,k,t,h,ans = 0;
	lld b,c,d; 
	lld min;
	// lld a[20];
	lld index = 1;
	lld min_difference = 1000001;
	get(t);

	while(t--){
		solve();
	}
 	
	// lld f[] = {5,0,2,3,4,7,8,9,10,11,12,13,14,15,100};
	// cout << calculate_Difference(f) << endl;


	return 0;
}