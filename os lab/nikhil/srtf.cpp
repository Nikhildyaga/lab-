#include<bits/stdc++.h>
using namespace std;

int find(vector<vector<int>> v,int cur,int n)
{
	int ans=-1,m=INT_MAX;
	for(int i=0;i<v.size();++i)	
	{
		if(v[i][0]<=cur)
		{
			if(v[i][1]<m)
			{
				ans=i;
				m=v[i][1];
			}
		}
	}
	return ans;
}

void funpremprio(vector<vector<int>> &v,int n)
{
	int cur=v[0][0];
	while(!v.empty())
	{
		int pos=find(v,cur,n);
		if(pos==-1)
		{
			cur=v[0][0];
			continue;
		}
		v[pos][1]-=1;
		cout<<v[pos][2]<<" :-"<<cur<<" to "<<cur+1<<endl;
		cur+=1;
		if(v[pos][1]==0)
		v.erase(v.begin()+pos);
	}
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
	funpremprio(v,n);
}