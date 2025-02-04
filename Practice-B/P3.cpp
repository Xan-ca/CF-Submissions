#include<iostream>
#include<vector>
using namespace std;
class curve{
    public:
    int first;
    int last;
    curve(){
        first=0;
        last=0;
    }
};
int main(){
    int n;
    cin>>n;
    curve Curve;
    vector<int>a;
       int temp;
    for(int j=0;j<n;j++){
    cin>>temp;
    a.push_back(temp);
    }
 
    int len=0;
    bool lock=false;
    int max=0;
    for(int i=0;i<n;i++){
        len=0;
        lock=false;
        Curve.first=i;

       for(int j=i+1;j<n;j++){
        if(a[j]>=a[j-1]&& lock==false){
          len++;
        }
        else if(a[j]<a[j-1]&& lock==false){
            lock=!lock;
            len++;
        }
        else if(a[j]<=a[j-1]&& lock==true){
            
            if(a[j]<a[j-1]){
                Curve.last=j;
            }
            len++;
        }
        else if(a[j]>a[j-1]&& lock==true){
            if(len>max){
                max=len;
            }
            break;
        }
       }
       i=Curve.last-1;
    }
    cout<< max;
    return 0;
}
