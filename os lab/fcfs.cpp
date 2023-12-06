#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;cin>>n;
	vector<pair<pair<int,int>,int>> v;
	for(int i=0;i<n;++i)
	{
		int a,b;
		cin>>a>>b;
		v.push_back({{a,b},i+1});
	}
	sort(v.begin(),v.end());
	vector<int> ct,tat,wt;
	for(int i=0;i<n;++i)
	{
		if(i==0) ct.push_back(v[i].first.first+v[i].first.second);
		else if(ct[i-1]>=v[i].first.first) ct.push_back(v[i].first.second+ct[i-1]);
		else ct.push_back(v[i].first.second+v[i].first.first);
	}
	for(int i=0;i<n;++i)
	{
		tat.push_back(ct[i]-v[i].first.first);
	}
	float sum=0.0;
	for(int i=0;i<n;++i)
	{
		wt.push_back(tat[i]-v[i].first.second);
		sum+=wt[i];
	}
	cout<<"p  "<<"CT  "<<"TAT  "<<"WT  "<<endl;
	for(int i=0;i<n;++i)
	{
		cout<<v[i].second<<"   "<<ct[i]<<"   "<<tat[i]<<"   "<<wt[i]<<endl;
	}
	cout<<"AWT"<<" "<<sum/n<<endl;
}