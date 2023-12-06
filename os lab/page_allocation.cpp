#include<bits/stdc++.h>
using namespace std;
//*******************//
#define loop(i,n) for(auto i=0;i<n;++i)
#define ump unordered_map<int,int>
#define mp map<int,int>
#define us unordered_set<int>
#define se set<int>
#define int long long
#define ull unsigned int
#define pii pair<int,int>
#define vi vector<int>
#define all(x) x.begin(),x.end()
#define sum(v) accumulate(all(v),0LL)
#define countbits(x) __builtin_popcount(x)
#define pb(x) emplace_back(x)
#define pob pop_back()
#define yes cout<<"YES"<<endl;
#define no cout<<"NO"<<endl;
#define Nikhil ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define inf 1e9
const int mod=1e6;
//********************************************************************//
template<typename T> istream &operator>>(istream &cin,vector<T>&a){for(auto &i:a) cin>>i; return cin;}
template<typename T> ostream &operator<<(ostream &cout,vector<T>&a){for(auto &i:a) cout<<i<<" "; return cout;}
template <typename T> void put(T s){ cout<<s<<'\n';}
template <typename T> void puts(T s){ cout<<s<<" ";}
//********************************************************************//
ull fastpow(ull a, ull b) {ull res = 1;while (b > 0) {if (b & 1)res = res * a;a = a * a;b >>= 1;}return res;}

ull modpow(ull a, ull b, ull m) {a %= m;ull res = 1;while (b > 0) {if (b & 1)res = res * a % m;a = a * a % m;b >>= 1;}return res;}

ull pow(ull a,ull b) {ull res=1;while(b>0){if(b&1) res*=a;a=a*a;b>>=1;}return res;}

ull ceil(ull a,ull b){return (a+b-1)/b;}

vector<int> sieve(int n){int *arr = new int[n + 1]();vector<int> vect;for (int i = 2; i <= n; i++)if (arr[i] == 0){vect.push_back(i);for (int j = 2 * i; j <= n; j += i)arr[j] = 1;}return vect;}

bool is_prime(int n){if(n<=1) return 0;for(int i=2;i*i<=n;++i){if(n%i==0) return 0;}return 1;}

void dfs(int cur,vector<vi> &v,int par)
{
    cout<<cur<<" ";
    for(int child:v[cur])
    {
        if(child!=par)
        {
            dfs(child,v,cur);
        }
    }
}

int bin(int low,int high)
{
    while((high-low)>1)
    {
        int mid=(low+high)/2;
        if(mid)
        {
             low=mid+1;
        }
        else
        {
             high=mid-1;
        }
    }
}

//********************************************************************//


void solve()
{
    unordered_map<int,int> m;
    int n,k;
    cin>>n>>k;
    vi v(n);
    cin>>v;
    int c=0;
    vi v1;
    for(auto i:v)
    {
    	for(auto i:m) cout<<i.first<<" "<<i.second<<endl;
    		cout<<endl;
    	if(m.find(i)!=m.end()){v1.push_back(i);continue;}
    	if(m.size()!=k)
    	{
    		for(auto &i:m) i.second++;
    		m[i]++;
    		c++;
    		v1.push_back(i);
    	}
    	else
    	{
    		int ind;
    		int c1=0;
    		vector<int> temp(1e5,0);
    		for(auto i:v1) cout<<i<<" ";
    			cout<<endl;
    		for(int j=v1.size()-1;j>=0;--j)
    		{
    			if(m.find(v1[j])!=m.end() and temp[v1[j]]==0) {temp[v1[j]]=1;c1++;}
    			if(c1==k) {ind=v1[j];break;}
    		}
    		cout<<ind<<endl;
    		m.erase(ind);
    		for(auto &i:m) i.second++;
    		m[i]++;
    		c++;
    		v1.push_back(i);
    	}
    }
    for(auto i:m) cout<<i.first<<" "<<i.second<<endl;
    cout<<"Number of frames:-"<<c<<endl;
}
signed main() {Nikhil;int T = 1;cin >> T;while (T--){solve();}return 0;}