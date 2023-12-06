#include<bits/stdc++.h> 
using namespace std;

int min_ind(vector<vector<int>>&arr,int n,int cur){
    int ans=-1;
    int m=INT_MAX;
    for(int i=0;i<n;i++){
      if(arr[i][0]<=cur){
        if(arr[i][1]<m){
          ans=i;
          m=arr[i][1];
        }
      }
    }
    return ans;
}
void sjf(vector<vector<int>>&arr,int n){
    int cur=arr[0][0];
    int tat=0,wt=0;

    while(!arr.empty()){
      int b=min_ind(arr,arr.size(),cur);
      if(b==-1){
         cur=arr[0][0];continue;
      }
      
      cout<<cur<<" to "<<cur+1<<" "<<arr[b][3]<<endl;
      cur+=1;
      arr[b][1]-=1;
    if(arr[b][1]==0){
      int t=cur-arr[b][0];
      tat+=t;
      wt+=t-arr[b][2];
      arr.erase(arr.begin()+b);
      }
    }
      cout<<"Turn around Time Is: "<<(double)tat/(double)n<<endl;
     cout<<"Average wating time Is: "<<(double)wt/(double)n<<endl;
}


int main(){
   int n;
   cin>>n;
   pair<int,int>p;
   vector<vector<int>>arr;
   cout<<"Enter Arrival time and burst time: "<<endl;
   for(int i=0;i<n;i++){
      int a,b;
     cin>>a>>b; 
     arr.push_back({a,b,b,i+1});
   } 
   
   sort(arr.begin(),arr.end());
   sjf(arr,n);
}
