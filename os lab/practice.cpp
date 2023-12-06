#include<bits/stdc++.h>
using namespace std;
void shift(vector<int>&v1,int ele)
{
	int i;
	for(i=0;i<v1.size();++i)
	{
		if(v1[i]==ele) break;
	}
	while(i<v1.size()-1)
	{
		v1[i]=v1[i+1];
		++i;
	}
}
bool find(vector<int> &v1,int ele)
{
	for(int i=0;i<v1.size();++i)
	{
		if(v1[i]==ele) return 1;
	}
	return 0;
}
int main()
{
	int n,frames;
	cin>>n>>frames;
	vector<int> v(n);
	for(int i=0;i<n;++i)
	{
		cin>>v[i];
	}
	vector<int> v1(frames,-1);
	int k=0;
	for(int i=0;i<n;++i)
	{
		if(v1[frames-1]==-1)
		{
			if(find(v1,v[i])==1)
			{
				shift(v1,v[i]);
				v1[k-1]=v[i];
				cout<<"hit"<<endl;
				for(auto j:v1) cout<<j<<" ";
					cout<<endl;
			}
			else
			{
				cout<<"fault"<<endl;
				v1[k++]=v[i];
				for(auto j:v1) cout<<j<<" ";
					cout<<endl;
			}
		}
		else
		{
			if(find(v1,v[i])==1)
			{
				cout<<"hit"<<endl;
				shift(v1,v[i]);
				v1[frames-1]=v[i];
				for(auto j:v1) cout<<j<<" ";
					cout<<endl;
			}
			else
			{
				cout<<"fault"<<endl;
				shift(v1,v1[0]);
				v1[frames-1]=v[i];
				for(auto j:v1) cout<<j<<" ";
					cout<<endl;
			}
		}
	}
}