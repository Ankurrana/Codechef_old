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
#define ps(s) printf("%s\n",s)
#define repeat(n) for (int i = (0); i < n; i++)
// #define clear(v) memset((v), 0, sizeof (v))
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
	lld b,c,d,p;
	lld r,l,s;
	bool flag;
	get(t);
	map < lld,bool > m;
	map < lld,bool >::iterator it;

	while(t--){
		m.clear();
		get(s);
		get(k);
		get(p);
		flag = 0;
		iterate(k){
			get(l);
			get(r);
			m[r] = 1; //means there's a division after 4
		}


		// for(it=m.begin();it!=m.end();it++){
		// 	cout << "Div at k:: " <<it->first << endl;
		// }



		iterate(p){
 			get(l);
			get(r);

			// cout <<  "Div at p: "  << r << endl; 

			if( m.find(r) == m.end() ){
				// cout << r << endl;
				flag = 1;
			}
		}

		if(flag == 1)
			ps("No");
		else
			ps("Yes");

	}
 
	return 0;
}