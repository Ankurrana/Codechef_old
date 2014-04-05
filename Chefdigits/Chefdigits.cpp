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


 
 
int main(){
	lld i,z,n,j,k,t,h,ans = 0;
	lld b,d,m,index,b1,b2;
	lld a[10][100001] = {0};	
	get(n);
	get(m);
	char str[100001];

	scanf("%s",str);

	for(i=0;i<n;i++){
		a[(int)(str[i]-'0')][i]++;
	}

	for(i=0;i<10;i++){
		z = 0;
		for(j=0;j<n;j++){
			z = z + a[i][j];
			a[i][j] = z;
			// printf("%lld ",a[i][j]);
		}
		// printf("\n");
	}

	for(j=0;j<m;j++){
		b1 = 0;
		get(index);
		index--;
		k = (int)(str[index]-'0');
		
		// printf("k = %d\n",k );
		// if(index == 0){
		// 	p(0);
		// 	continue;
		// }

		// for(j=0;j<10;j++){
		// 	printf("%lld\n",b1 );
		// 	b1 += labs(k*a[j][index-1] - j*a[j][index-1]);
		// }
		// for(j=k+1;j<10;j++){
		// 	b2 += (k - j*a[j][index-1]);
		// }	

		// p((int)(b1-b2));


		for(i=0;i<10;i++){
			if(i<k)
				b1 = b1 + (a[i][index-1])*(k-i);
			else
				b1 = b1 + (i-k)*(a[i][index-1]);
			// printf("%d\n",(int)b1);
		}


		p(b1);

	}

	return 0;
}