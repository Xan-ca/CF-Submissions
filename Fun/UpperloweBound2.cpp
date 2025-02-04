#include<bits/stdc++.h>
using namespace std;
int lower_bound(vector<int>& v,int target){
int low=0;
int high=v.size()-1;
int mid;
while(high-low>1){
	mid=(high+low)/2;
	if(v[mid]>target){
		high=mid-1;
	}else{
		low=mid;
	}
}
 if(v[high]<=target){
return high;
} else if(v[low]<=target){
return low;
} else{
	return -1;
}
}
int upper_bound(vector<int>& v,int target){
int low=0;
int high=v.size()-1;
int mid;
while(high-low>1){
	mid=(high+low)/2;
	if(v[mid]>=target){
		high=mid-1;
	}else{
		low=mid;
	}
}
 if(v[high]<target){
return high;
} else if(v[low]<target){
return low;
} else{
	return -1;
}
}
int main(){
vector<int>vect={1,2,3,4,5,6,8,8,9,10,12};
cout<<lower_bound(vect,8)<<endl;
cout<<upper_bound(vect,8)<<endl;
return 0;
}