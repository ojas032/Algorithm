#include<iostream>
#include<algorithm>
#include<vector>
int n;
using namespace std;

void insertion(vector<float> v){
    for(int i=1;i<v.size();i++){
        float key=v[i];
        int j=i-1;
        while(j>=0 && v[j]>key){
            v[j+1]=v[j];
            j=j-1;
        }
        v[j+1]=key;
    }
}


void bucket(float a[]){
vector<float> b[n+1];
for(int i=0;i<n;i++){
int bi=(int)(n*a[i]);    
b[bi].push_back(a[i]);
}
for(int i=0;i<n;i++)
insertion(b[i]);
    int index = 0; 
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < b[i].size(); j++) 
          a[index++] = b[i][j];

         
}


int main(){
    cin>>n;
    float a[n+1];
    for(int i=0;i<n;i++)
    cin>>a[i];
    bucket(a);
    
    for(int i=0;i<n;i++){
      cout<<a[i]<<'\n';
       //cout<<1<<"\n";
    } 
}
