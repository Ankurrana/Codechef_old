#include "cstdio"
#include "iostream"
#include "vector"
#include "utility"
#include "algorithm"
using namespace std;




bool func( pair< int,int > a, pair < int, int > b ){ return a.first < b.first; };

int min_pairs_between(int a, int b){
	int ans = 0;
	ans = (b-a-1)/2 + (b-a-1)%2;
	return ans;
}	

int main(){
	int i,j,x,k,sum,ans,z;
	int flag;
	int max,min;

	vector< pair< int,bool > > v; //bool represents 0 : its in pair , 1 means it div2

	vector< pair< int,bool > >::iterator it;

	scanf("%d %d",&x,&k);
	max = x-1;
	max = max - k;
	for(int i=0;i<k;i++){
		scanf("%d",&flag);

		if(flag == 1){
			max--;
			scanf("%d",&z);
			scanf("%d",&z);
			v.push_back( make_pair(z,0) );
		}
		else if(flag == 2 ){
			scanf("%d",&z);
			v.push_back( make_pair(z,1) );
		}
	}

	v.push_back( make_pair(x,1) );


	

	sort(v.begin(),v.end(),func);

	min = 0;
	int g = 0;


	// for(it=v.begin();it!=v.end();it++){
	// 	printf("first = %d second = %d\n",it->first,it->second);
	// }

	for(it= v.begin();it!=v.end();it++){

		if(it->second == 1){  //it its a pair
			min += min_pairs_between(g,it->first);
		}else{
			min += min_pairs_between(g,it->first-1);

		}

		g = it->first;
	}

	printf("%d %d\n",min,max);


}