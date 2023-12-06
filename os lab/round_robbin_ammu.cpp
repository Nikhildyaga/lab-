#include<bits/stdc++.h>
using namespace std;
void find(vector<vector<int>> v,vector<int> &ready,int cur,int quantum)
{
	int c=0;
	cur+=2;
	for(int i=0;i<v.size();++i)
	{
		if(v[i][0]<=cur) ready.push_back(v[i][2]),c++;
	}
	ready.push_back(ready[ready.size()-c]);

}
void funround(vector<vector<int>> &v,int n,int quantum)
{
	int cur=v[0][0];
	vector<int> ready;
	while(!v.empty())
	{
		find(v,ready,cur,quantum);
		for(auto i:ready) cout<<i<<" ";
			cout<<endl;
		if(v[ready[0]][1]<quantum) v[ready[0]][1]=0,cur+=v[ready[0]][1];
		else v[ready[0]][1]-=quantum,cur+=quantum;
		if(v[ready[0]][1]==0) v.erase(v.begin());
		cout<<ready[0]<<endl<<endl;
		ready.erase(ready.begin());
	}
}
int main()
{
	int n,quantum;
	cin>>n>>quantum;
	vector<vector<int>> v;
	for(int i=0;i<n;++i)
	{
		int a,b;
		cin>>a>>b;
		v.push_back({a,b,i+1});
	}
	sort(v.begin(),v.end());
	funround(v,n,quantum);
}