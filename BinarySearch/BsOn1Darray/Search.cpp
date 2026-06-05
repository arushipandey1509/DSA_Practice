#include<bits/stdc++.h>
using namespace std;
int find(vector<int>& arr, int x){
    int n = arr.size();
    for(int i=0;i<n;i++){
        if(arr[i]==x) return i;
    }
    return -1;
}
int findOptimal(vector<int>& arr, int x){
    int n = arr.size();
    int low = 0;
    int high = n-1;
    while(low<=high){
        int mid = (low+high)/2;
        if(arr[mid]==x) return mid;
        else if(arr[mid]>x) high = mid-1;
        else low = mid+1;
    }
    return -1;
}
int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    int target;
    cin>>target;
    int ind = find(arr,target);
    cout<<ind<<endl;
    ind = findOptimal(arr,target);
    cout<<ind<<endl;
    return 0;
}
