#include<bits/stdc++.h>
using namespace std;
bool find(vector<int> &v1,int ele)
{
	for(int i=0;i<v1.size();++i)
	{
		if(v1[i]==ele) return 1;
	}
	return 0;
}
int predict(vector<int> &v1,vector<int>&v,int index)
{
	int farthest=index,res=-1;
	for(int i=0;i<v1.size();++i)
	{
		int j;
		for(j=index;j<v.size();++j)
		{
			if(v[j]==v1[i])
			{
				if(j>farthest)
				{
					farthest=j;
					res=i;
				}
				break;
			}
		}
		if(j==v.size()) return i;
	}
	return (res==-1)?0:res;
}
int main()
{
	int n,frames;
	cin>>n>>frames;
	vector<int> v(n);
	for(int i=0;i<n;++i) cin>>v[i];
	vector<int> v1;
    int k=0;
    for(int i=0;i<n;++i)
    {
    	if(find(v1,v[i])==1)
    	{
    		// hit++;
    		for(auto j:v1) cout<<j<<" ";
    			cout<<endl;
    		continue;
    	}
    	if(v1.size()<frames)
    	{
    		v1.push_back(v[i]);
    		for(auto j:v1) cout<<j<<" ";
    			cout<<endl;
    		continue;
    	}
    	else
    	{
    		int pos=predict(v1,v,i+1);
    		// fault++;
    		v1[pos]=v[i];
    		for(auto j:v1) cout<<j<<" ";
    			cout<<endl;
    	}

    }
}