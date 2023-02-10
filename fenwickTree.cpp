#include<bits/stdc++.h>
using namespace std;

const int N = 1e5;

int fen[N];

void update(int i,int add){
	while(i<N){
		fen[i]+=add;
		i += (i&(-i));
	}
}
int sum(int i){
	int s=0;
	while(i>0){
		s+=fen[i];
		i=i-(i&(-i));
	}
	return s;
}

// finding lower bound of val
int find(int val){     
	int curr=0,ans=0,prevSum=0;
	for(int i=log2(N);i>=0;i--){
		if(fen[curr + (1<<i)] + prevSum < val){
			curr+=(1<<i);
			prevSum+=fen[curr];
		}
	}
	return curr+1;

}

int rangeSum(int l,int r){
	return sum(r)-sum(l-1);
}

int main(){
	int n;cin>>n;
	vector<int>v(n+1);
	for(int i=1;i<=n;i++){
		cin>>v[i];
		update(i,v[i]);  // creating fenwick tree
	}

	int ind = rangeSum(3,7);
	cout<<ind<<endl;

}















