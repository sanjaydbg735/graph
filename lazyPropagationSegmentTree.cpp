#include<bits/stdc++.h>
using namespace std;

const int N = 100005;

int arr[N],seg[N*4],lazy[N*4];

// calling from main  build(0,0,n-1)
void build(int ind,int low,int high){
	if(low==high){
		seg[ind]=arr[low];
		return;
	}

	int mid = (high+low)/2;
	build(2*ind+1,low,mid);
	build(2*ind+2,mid+1,high);

	seg[ind]=(seg[2*ind+1]+seg[2*ind+2]);  // sum of left and right child.
}

// calling query(0,0,n-1,l,r)
int querySum(int ind,int low,int high,int l,int r){

	if(lazy[ind]!=0){
		seg[ind]+=(high-low+1)*lazy[ind];
		if(low!=high){
			lazy[2*ind+1]+=lazy[ind];
			lazy[2*ind+2]+=lazy[ind];
		}
		lazy[ind]=0;
	}

	if(r<low || l>high || low>high) return 0;

	if(low>=l && high<=r){
		return seg[ind];
	}
	
	int mid=(low+high)/2;
	int left = querySum(2*ind+1,low,mid,l,r);
	int right = querySum(2*ind+2,mid+1,high,l,r);

	return (left+right);
}

// range update
// calling rangeUpdate(0,0,n-1,l,r,val);
void rangeUpdate(int ind,int low,int high,int l,int r,int val){
	
	if(lazy[ind]!=0){
		seg[ind]+=(high-low+1)*lazy[ind];
		if(low!=high){
			lazy[2*ind+1]+=lazy[ind];
			lazy[2*ind+2]+=lazy[ind];
		}
		lazy[ind]=0;
	}

	if(r<low || l>high || low>high) return;

	if(low>=l && high<=r){
		seg[ind]+=(high-low+1)*val;
		if(low!=high){
			lazy[2*ind+1]+=val;
			lazy[2*ind+2]+=val;
		}
		return;
	}

	int mid = (high+low)>>1;
	rangeUpdate(2*ind+1,low,mid,l,r,val);
	rangeUpdate(2*ind+2,mid+1,high,l,r,val);

	seg[ind]=seg[2*ind+1]+seg[2*ind+2];

}

int main(){
	int n,q;cin>>n>>q;
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	build(0,0,n-1);
	rangeUpdate(0,0,n-1,1,2,5);

	while(q--){
		//TODO for each query maximun in range (l,r)
		int l,r;cin>>l>>r;
		int sum = querySum(0,0,n-1,l,r);
		cout<<sum<<endl;
	}
}