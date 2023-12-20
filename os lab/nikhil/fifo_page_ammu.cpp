#include<bits/stdc++.h>
using namespace std;
int find(vector<int> v1,int ele)
{
	for(int i=0;i<v1.size();++i)
	{
		if(v1[i]==ele) return i;
	}
	return -1;
}
int main()
{
	int n,frames;
	cin>>n>>frames;
	vector<int> v(n);
	for(int i=0;i<n;++i) cin>>v[i];
	vector<int> v1,time(frames,-1);
	int count=0;
	for(int i=0;i<n;++i)
	{
		int pos=find(v1,v[i]);
		// cout<<pos<<endl<<endl;
		if(pos!=-1)
		{
			for(auto i:v1) cout<<i<<" ";
				cout<<endl;
			continue;
		}
		else if(v1.size()<frames)
		{
			v1.push_back(v[i]);
			time[v1.size()-1]=i;
			for(auto i:v1) cout<<i<<" ";
				cout<<endl;
		}
		else if(pos==-1)
		{
			int mini=INT_MAX,ind=-1;
			// for(auto i:time) cout<<i<<" ";
			// 	cout<<endl;
			for(int j=0;j<time.size();++j)
			{
				if(mini>time[j])
				{
					mini=time[j];
					ind=j;
				}
			}
			//cout<<ind<<endl;
			v1[ind]=v[i];
			time[ind]=i;
			for(auto i:v1) cout<<i<<" ";
				cout<<endl;
		}

	}
}