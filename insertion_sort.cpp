#include<isotream>
#include<algorithm>

using namespace std;

main(){
    int n,a[101];
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    for(int i=1;i<n;i++){
        int key=a[i];
        while(i>0 && a[i-1]>key){
            a[i]=a[i-1];
            i--;
        }
        a[i]=key;
    }

    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
}