#include<bits/stdc++.h> 
using namespace std;

int min_ind(vector<vector<int>>&arr,int n,int cur){
    int ans=-1;
    int m=INT_MAX;
    for(int i=0;i<n;i++){
      if(arr[i][0]<=cur){
        if(arr[i][2]<m){
          ans=i;
          m=arr[i][2];
        }
      }
    }
    return ans;
}
void priority(vector<vector<int>>&arr,int n){
    int cur=arr[0][0];
    int tat=0,wt=0;
    while(!arr.empty()){
      int b=min_ind(arr,arr.size(),cur);
      if(b==-1){
         cur=arr[0][0];continue;
      }
      cout<<cur<<" to "<<cur+arr[b][1]<<" "<<arr[b][3]<<endl;
      cur+=arr[b][1];
      int t=cur-arr[b][0];
      tat+=t;
      wt+=t-arr[b][1];
      arr.erase(arr.begin()+b);
    }
      cout<<"Turn around Time Is: "<<(double)tat/(double)n<<endl;
     cout<<"Average wating time Is: "<<(double)wt/(double)n<<endl;
}


int main(){
   int n;
   cin>>n;
   pair<int,int>p;
   vector<vector<int>>arr;
   for(int i=0;i<n;i++){
      int a,b,c;
     cin>>a>>b>>c; 
     arr.push_back({a,b,c,i+1});
   } 
   
   sort(arr.begin(),arr.end());
   priority(arr,n);
}
