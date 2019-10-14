#include<iostream>
#include<algorithm>
#include<cstring>
#include<climits>
using namespace std;

int main(){
    int n;
    cin>>n;
    int p[n+2];
    for(int i=0;i<n;i++)cin>>p[i];
    //matrix__chain

    int m[n+2][n+2]={0},s[n+2][n+2]={0};
    for(int i=0;i<=n;i++)
    m[i][i]=0;

    for(int l=2;l<n;l++){
        for(int i=1;i<n-l+1;i++){
            int j=i+l-1;
            int q;
            m[i][j]=INT_MAX;
            for(int k=i;k<j;k++){
            q=m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j];
            if(q<m[i][j]){
                m[i][j]=q;
                s[i][j]=k;
            }
            }
        }
        
    }
    

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<m[i][j]<<" ";
        }
        cout<<'\n';
    }
}