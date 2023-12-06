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
		int ind=-1,maxi=INT_MIN,j;
		for(j=0;j<m;++j)
		{
			if(maxi<chunks[j])
			{
				maxi=chunks[j];
				ind=j;
			}
		}
		if(chunks[ind]<process[i])
		{
			cout<<i<<"th process will wait"<<endl;
			continue;
		}
		wastage[ind]=chunks[ind]-process[i];
		chunks[ind]=0;
		cout<<i+1<<"th process will occupy "<<ind+1<<"th chunk"<<endl;

	}
	for(auto i:wastage) cout<<i<<" ";
}