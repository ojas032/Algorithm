#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
    int n,a,b;
    cin>>n;
    vector<pair<int,int>> v;
    vector<int> ac;
    for(int i=0;i<n;i++){
    cin>>a>>b;
    v.push_back(make_pair(a,b));
    }

    int k=0;
    ac.push_back(k+1);
    for(int i=1;i<n;i++){
        if(v[i].first>=v[k].second){
            k=i;
            ac.push_back(i+1);
        }
    }

    for(int i=0;i<ac.size();i++)
    cout<<ac[i]<<" ";
}
