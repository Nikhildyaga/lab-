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
		int j;
		for(j=0;j<m;++j)
		{
			if(chunks[j]>=process[i])
			{
				wastage[j]=chunks[j]-process[i];
				chunks[j]=0;
				cout<<i+1<<"th process will occupy "<<j+1<<"th chunk"<<endl;
				break;
			}
		}
		if(j==m) cout<<i+1<<"th process will wait"<<endl;
	}
	for(auto i:wastage) cout<<i<<" ";
}