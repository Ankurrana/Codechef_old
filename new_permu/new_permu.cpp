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
 
bool decrease(pair< int,int > i,pair < int,int > j) { return ( i.first >= j.first); }
bool increase(pair< int,int > i,pair < int,int > j) { return ( i.first <= j.first); }


void solve(vector < pair< int, int > > &a,lld s){
		vector < pair< int, int > >::iterator it;
		vector < pair< int, int > >::reverse_iterator rit;
		lld  sum = 0;
		vector < int > ca; 
		sort(a.begin(),a.end(),decrease);

		// cout << "First the array is sorted in decreasing Order" << endl;

		// for(it=a.begin();it!=a.end();it++){
		// 	cout << (*it).first << "second = " << (*it).second <<endl ;
		// 	// printf("%d ",(*it).second );
		// }


		for(rit=a.rbegin();rit!=a.rend();rit++){
			// cout << (*rit).first << "second = " << (*rit).second <<endl ;
			sum += (*rit).first;
			(*rit).first = sum; 
		}

		// for(rit=a.rbegin();rit!=a.rend();rit++){
		// 	cout << (*rit).first << "second = " << (*rit).second <<endl ;
		// 	// sum += (*rit).first;
		// 	// (*rit).first = sum; 
		// }
		// for(it=a.begin();it!=a.end();it++){
		// 	cout << (*it).first << "second = " << (*it).second <<endl;
		// 	// printf("%d ",(*it).second );
		// }

		for(it=a.begin();it!=a.end();it++){
			if( (*it).first <= s )
				break;
		}

		// cout << (*it).first ;
		sort(a.begin(),it,increase);
		sort(it,a.end(),increase);

		for(it=a.begin();it!=a.end();it++){
			// cout << (*it).first << "second = " << (*it).second <<endl;
			printf("%d ",(*it).second );
		}

}


int main(){
	int i,z,n,j,k,t,h,ans = 0;
	int b,c,d,s;
	get(t);

	vector < pair< int, int > > a;
	vector < pair< int, int > >::iterator it;
	
	while(t--){
		get(n);
		get(k);
		get(s);
		a.clear();

		iterate(n){
			get(z);
			a.push_back(make_pair(z,i+1));
		}

		solve(a,s);

		// for(it=a.begin();it!=a.end();it++){
		// 	// cout << (*it).first << "second = " << (*it).second <<endl ;
		// 	printf("%d ",(*it).second );
		// }
		printf("\n");
	}
	// a.push_back( make_pair(3,1) );
	// a.push_back( make_pair(4,2) );
	// a.push_back( make_pair(1,3) );
	// a.push_back( make_pair(5,4) );
	// a.push_back( make_pair(5,5) );

	// solve(a,4);
 
	return 0;
}