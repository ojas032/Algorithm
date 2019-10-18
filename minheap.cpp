#include<iostream>
#include<algorithm>

using namespace std;

int n;



void max_heapify(int a[],int i){
    int length=n;
    int l=2*i;
    int r=2*i+1;
    int largest;
    if(l<=n &&  a[l]>a[i]){
        largest=l;
    }
    else largest=i;
    if(r<=n && a[r]>a[largest])
    largest=r;
    if(largest!=i){
    swap(a[i],a[largest]); 
    max_heapify(a,largest);
    }
}


void build_max(int a[]){
    int size=n/2;
    for(int i=size;i>=1;i--){
        max_heapify(a,i);
    }
}



int main(){
    cin>>n;
    int a[n+1];
    for(int i=1;i<=n;i++)cin>>a[i];
    build_max(a);
    for(int i=1;i<=n;i++)
    cout<<a[i]<<" ";}