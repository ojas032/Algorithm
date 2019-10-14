#include<iostream>
#include<algorithm>

using namespace std;

int partition(int a[],int p,int r){
int i=p-1;
int x=a[r];
for(int j=p;j<r;j++){
if(a[j]<=x){
i++;
swap(a[i],a[j]);
}
}
swap(a[i+1],a[r]);
return i+1;
}


int r_partition(int a[],int p,int r){
int q=rand()%r+p;
swap(a[r],a[q]);
return partition(a,p,r);
}


int q_sort(int a[],int p,int r){
if(p<r){
int q=r_partition(a,p,r);
q_sort(a,p,q-1);
q_sort(a,q+1,r);
}
}



int main(){
int n;
cin>>n;
int a[n+1];
for(int i=0;i<n;i++)
cin>>a[i];
q_sort(a,0,n-1);
for(int i=0;i<n;i++)
cout<<a[i]<<" ";
}
