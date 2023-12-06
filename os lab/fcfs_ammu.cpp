#include<bits/stdc++.h>
using namespace std;

void funfcfs(vector<vector<int>> &v)
{
	int tat=0,wt=0;
	int cur=0;
	for(int i=0;i<v.size();++i)
	{
		if(cur<v[i][0])
		{
			cur=v[i][0]+v[i][1];
			tat+=cur-v[i][0];
			wt+=cur-v[i][0]-v[i][1];
			cout<<v[i][2]<<"  "<<cur<<"  "<<cur-v[i][0]<<"  "<<cur-v[i][0]-v[i][1]<<endl;
		}
		else
		{
			cur+=v[i][1];
			tat+=cur-v[i][0];
			wt+=cur-v[i][0]-v[i][1];
			cout<<v[i][2]<<"  "<<cur<<"  "<<cur-v[i][0]<<"  "<<cur-v[i][0]-v[i][1]<<endl;
		}
	}
	cout<<(double)tat/(double)v.size()<<endl;
	cout<<(double)wt/(double)v.size()<<endl;
}
int main()
{
	int n;
	cin>>n;
	vector<vector<int>> v;
	for(int i=0;i<n;++i)
	{
		int a,b;
		cin>>a>>b;
		v.push_back({a,b,i+1});
	}
	sort(v.begin(),v.end());
	funfcfs(v);
}