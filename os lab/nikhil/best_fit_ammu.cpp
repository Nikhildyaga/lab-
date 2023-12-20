#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,m;
	cin>>n>>m;
	vector<int> process(n),chunks(m),wastage(m,0);
	for(int i=0;i<n;++i) cin>>process[i];
	for(int i=0;i<n;++i) cin>>chunks[i];
	for(int i=0;i<n;++i)
	{
		int j,ind=-1,mini=INT_MAX;
		for(j=0;j<m;++j)
		{
			if(chunks[j]-process[i]<mini and (chunks[j]-process[i])>0)
			{
				ind=j;
				mini=chunks[j]-process[i];
			}
		}
		if(ind==-1)
		{
			cout<<i+1<<"th process will wait"<<endl;
			continue;
		}
		wastage[ind]=chunks[ind]-process[i];
		chunks[ind]=-1e9;
		cout<<i+1<<"th process will occupy "<<ind+1<<"th chunk"<<endl;
	}
	for(auto i:wastage) cout<<i<<" ";
}