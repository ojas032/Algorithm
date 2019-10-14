#include<iostream>
#include<algorithm>
#define ll long long int
using namespace std;

ll vis[1000000];
ll dp[1000000];

ll paren(ll n){
    ll ans=0;
    if(n==1)
    return 1;
    else
    {ll k;
    for(int  k=1;k<n;k++){
    ll a,b;
    if(vis[k])
    a=dp[k];
    else
    a=paren(k),dp[k]=a,vis[k]=1;
    if(vis[n-k])
    b=dp[n-k];
    else
    b=paren(n-k),dp[n-k]=b,vis[n-k]=1;

    ans+=a*b;
    
    }
    }
    return ans;
}


int main(){
    int n;
    cin>>n;
    cout<<paren(n)<<" ";
}