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
int predict(vector<int> time)
{
	int mini=INT_MAX,ind=-1;
	for(int i=0;i<time.size();++i)
	{
		if(time[i]<mini)
		{
			mini=time[i];
			ind=i;
		}
	}
	return ind;
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
    	if(find(v1,v[i])!=-1)
    	{
    		int pos=find(v1,v[i]);
    		time[pos]=count;
    		count++;
    		for(auto i:v1) cout<<i<<" ";
    			cout<<endl;
    	}
    	else if(v1.size()<frames)
    	{
    		v1.push_back(v[i]);
    		count++;
    		for(auto i:v1) cout<<i<<" ";
    			cout<<endl;
    	}
    	else if(find(v1,v[i])==-1)
    	{
    		int pos = predict(time);
    		v1[pos]=v[i];
    		time[pos]=v[i];
    		count++;
    		for(auto i:v1) cout<<i<<" ";
    			cout<<endl;
    	}
    }
}