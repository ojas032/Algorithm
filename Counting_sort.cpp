#include<iostream>
#include<algorithm>
#include<cstring>
#include<climits>
using namespace std;

int cnt[1000000];

void countingsort(int a[],int b[],int k,int n){

    for(int i=1;i<=k;i++){cnt[i]+=cnt[i-1];}
    for(int i=n-1;i>=0;i--){
        b[cnt[a[i]]]=a[i];
        cnt[a[i]]--;
    }
}


int main(){
    int n;
    cin>>n;
    int a[n+1];
    int b[n+1];
    int maxi=INT_MIN;
    memset(cnt,0,sizeof(cnt));
    for(int i=0;i<n;i++){
        cin>>a[i];
        cnt[a[i]]++;
        maxi=max(maxi,a[i]);
        }
    countingsort(a,b,maxi,n);
    for(int i=1;i<=n;i++){
        cout<<b[i]<<" ";
    }
}