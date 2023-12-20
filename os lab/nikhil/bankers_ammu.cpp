#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	vector<vector<int>> v;
	vector<vector<int>> v1;
	for(int i=0;i<n;++i)
	{
		int a,b,c;
		cin>>a>>b>>c;
		v.push_back({a,b,c});
	}
	for(int i=0;i<n;++i)
	{
		int a,b,c;
		cin>>a>>b>>c;
		v1.push_back({a,b,c});
	}
	int a,b,c;
	cin>>a>>b>>c;
	vector<vector<int>> vv1;
	for(int i=0;i<n;++i)
	{
		vv1.push_back({v1[i][0]-v[i][0],v1[i][1]-v[i][1],v1[i][2]-v[i][2]});
	}
	//for(auto i:vv1) cout<<i[0]<<" "<<i[1]<<" "<<i[2]<<endl;
	vector<int> t;
	vector<vector<int>> m(n,vector<int>(3));
	for(int j=0;j<n;++j)
	{
		if(t.size()==n) break;
		int i;
		for(i=0;i<n;++i)
		{
			if(vv1[i][0]<=a and vv1[i][1]<=b and vv1[i][2]<=c)
			{
				a+=v[i][0];
				b+=v[i][1];
				c+=v[i][2];
				t.push_back(i);
				m[i]={a,b,c};
				vv1[i][0]=vv1[i][1]=vv1[i][2]=INT_MAX;
			}
		}
		//cout<<a<<" "<<b<<" "<<c<<endl;
		//cout<<t.size()<<endl;
	}
	if(t.size()<5)
	{
		cout<<"not safe"<<endl;
	}
	for(auto i:m) cout<<i[0]<<" "<<i[1]<<" "<<i[2]<<endl;
	for(auto i:t) cout<<i<<" ";
}