#include<iostream>
#include<algorithm>

using namespace std;


void merge(int a[],int p,int q,int r1){

int n1=q-p+1;
int n2=r1-q;
int l[n1+2];
int r[n2+2];
for(int i=1;i<=n1;i++)
l[i]=a[p+i-1];
for(int j=1;j<=n2;j++)
r[j]=a[q+j];
l[n1+1]=99999999;
r[n2+1]=99999999;
int i=1;
int j=1;
for(int k=p;k<=r1;k++){
    if(l[i]<=r[j]){
        a[k]=l[i];
        i+=1;
    }
    else{
        a[k]=r[j];
        j+=1;
    }
}
}



void merge_sort(int  a[],int p,int r){
if(p<r){
    int q=(p+r)/2;
    merge_sort(a,p,q);
    merge_sort(a,q+1,r);
    merge(a,p,q,r);
}
}






int main(){
    int n;
    cin>>n;
    int a[1000];
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }

    merge_sort(a,1,n);

    for(int i=1;i<=n;i++)
    cout<<a[i]<<' ';
}