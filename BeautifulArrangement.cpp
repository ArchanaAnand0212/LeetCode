#include<iostream>
using namespace std;
int countArrangement(int n);
int _countArrangement(int start, int pos[], int n);
bool allposone(int pos[],int n);
int countArrangement(int n){
	int pos[n+1]={0};
	return _countArrangement(1,pos,n);
}

int _countArrangement(int start, int pos[], int n){
	if(allposone(pos,n))
		return 1;
	if(start==n+1)
		return 0;
	int ans=0;
	for(int i=1;i<=n;i++){
		if(pos[i]==0 && (start%i==0 || i%start==0)){
			pos[i]=1;
			ans = ans + _countArrangement(start+1,pos,n);
			pos[i]=0;
		}
	}
	return ans;
}

bool allposone(int pos[],int n){
	for(int i=1;i<=n;++i){
		if(pos[i]==0)
			return false;
	}
	return true;
}
int main(){
	int n;
	cin>>n;
	cout<<countArrangement(n)<<endl;
	return 0;
}