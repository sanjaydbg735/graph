#include<bits/stdc++.h>
using namespace std;

const int N = 100005;

int arr[N],seg[N*4];

// calling from main  build(0,0,n-1)
void build(int ind,int low,int high){
	if(low==high){
		seg[ind]=arr[low];
		return;
	}

	int mid = (high+low)/2;
	build(2*ind+1,low,mid);
	build(2*ind+2,mid+1,high);

	seg[ind]=max(seg[2*ind+1],seg[2*ind+2]);  // max of left and right child.
}

// calling query(0,0,n-1,l,r)
int query(int ind,int low,int high,int l,int r){
	if(low>=l && high<=r){
		return seg[ind];
	}
	if(low>r || high<l){
		return INT_MIN;
	}

	int mid=(low+high)/2;
	int left = query(2*ind+1,low,mid,l,r);
	int right = query(2*ind+2,mid+1,high,l,r);

	return max(left,right);
}

// single update
// calling pointUpdate(0,0,n-1,node,val);
void pointUpdate(int ind,int low,int high,int node,int val){
	if(low==high){
		seg[low]+=val;
		return;
	}

	int mid = (low+high) >> 1;
	if(node>=low && node<=mid){ // into left part
		pointUpdate(2*ind+1,low,mid,node,val);
	}
	else{
		pointUpdate(2*ind+2,mid+1,high,node,val);
	}

	seg[ind] = max(seg[2*ind+1] , seg[2*ind+2]);

}

int main(){
	int n,q;cin>>n>>q;
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	build(0,0,n-1);

	while(q--){
		//TODO for each query maximun in range (l,r)
		int l,r;cin>>l>>r;
		int sum = query(0,0,n-1,l,r);
		cout<<sum<<endl;
	}
}