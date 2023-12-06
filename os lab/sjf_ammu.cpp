#include<bits/stdc++.h>
using namespace std;
find(vector<vector<int>> v,int cur)
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
void funsjf(vector<vector<int>> v,int n)
{
	int cur=v[0][0],tat=0,wt=0;
	while(!v.empty())
	{
		int pos=find(v,cur);
		if(pos==-1)
		{
			cur=v[0][0];
			continue;
		}
		cout<<cur<<" to "<<cur+v[pos][1]<<" "<<v[pos][2]<<endl;
		cur+=v[pos][1];
		int t=cur-v[pos][0];
		tat+=t;
		wt+=t-v[pos][1];
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
	funsjf(v,n);
}