#include <iostream>
using namespace std;
int main() {
    // Write C++ code here
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int m;
        cin>>m;
        int on=0;
        int off=0;
        for(int j=0;j<m*2;j++){
            int temp;
            cin>>temp;
            if(temp==1)on++;
            else off++;
            
        }
        
        int mx,mn;
        if(on==off){
            mx=on;
        }else if(on>off){
           mx= off;
        }else{
           mx=on;
        }
        if(off%2==0){
            mn=0;
        }else{
            mn=1;
        }
        cout<<mn<<" "<<mx<<endl;
    }

    return 0;
}