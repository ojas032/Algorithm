#include<iostream>
#include<algorithm>
#include<climits>
#include<cmath>
#define ll long int 
using namespace std;

ll b[1000000];

void countingsort(ll a[],ll k,ll n,ll ep){
    
    int cnt[k+1]={0};
    for(int i=0;i<n;i++)cnt[(a[i]/ep)%10]++;
    for(int i=1;i<10;i++){cnt[i]+=cnt[i-1];}
    for(int i=n-1;i>=0;i--){
        b[cnt[(a[i]/ep)%10]]=a[i];
        cnt[(a[i]/ep)%10]--;
    }
    for (int i = 1; i <=n; i++) 
        a[i-1] = b[i]; 
    
}


int main(){
    ll n;
    cin>>n;
    ll a[n+1];
    ll maxi=INT_MIN;
    ll ep;
    for(int i=0;i<n;i++){
        cin>>a[i];
        maxi=max(maxi,a[i]);
        }
    int size=log10(maxi)+1;    

    for(int  i=0;i<size;i++){
        ep=1*pow(10,i);
        countingsort(a,maxi,n,ep);
    }

    for(int i=1;i<=n;i++){
        cout<<b[i]<<" ";
    }
    cout<<'\n';

}