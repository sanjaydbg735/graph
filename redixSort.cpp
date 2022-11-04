#include<bits/stdc++.h>
using namespace std;

int ithVal(int num,int ind){
	int val=num;
	while(ind--){
		val/=10;
	}
	return val%10;
}

void redixSort(vector<int>&v,int ind){
	int n=v.size();

	vector<int>cnt(10);
	for(auto x:v){
		int i=ithVal(x,ind);
		cnt[i]++;
	}

	vector<int>pos(10);
	pos[0]=0;
	for(int i=1;i<10;i++){
		pos[i]=pos[i-1]+cnt[i-1];
	}
	vector<int>v_new(n);
	for(auto x:v){
		int i=ithVal(x,ind);
		v_new[pos[i]]=x;
		pos[i]++;
	}
	v=v_new;
}

void sort(vector<int>&v){
	for(int i=0;i<9;i++){
		redixSort(v,i);
	}
}

int main(){
	int n;cin>>n;
	vector<int>v(n);
	for(int i=0;i<n;i++)cin>>v[i];

	sort(v);

	for(auto x:v){
		cout<<x<<' ';
	}
	cout<<endl;

	return 0;
}