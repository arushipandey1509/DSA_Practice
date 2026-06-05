#include<bits/stdc++.h>
using namespace std;

//Brute force-O(n^2)
int majority(vector<int>& arr){
    int n = arr.size();
    int mini = (int)n/2+1;
    for(int i=0;i<n;i++){
        int cnt=0;
        for(int j=0;j<n;j++){
            if(arr[i]==arr[j]) cnt++;
        }
        if(cnt>=mini) return arr[i];
    }
    return -1;
}

//optimal-1 using extra space
int majorityOptimal1(vector<int>& arr){
    int n = arr.size();
    int mini = (int)n/2+1;
    unordered_map<int,int> mp;
    for(int it : arr) mp[it]++;
    for(int i=0;i<n;i++){
        if(mp[arr[i]]>=mini){
            return arr[i];
        }
    }
    return -1;
}

//Optimal
int majorityOptimal2(vector<int>& arr){
    int n = arr.size();
    int let = -1;
    int count = 0;
    for(int it : arr){
        if(count==0){
            let=it;
            count=1;
        }
        else if(it==let) count++;
        else count--;
    }
    count=0;
    for(int it : arr){
        if(it==let) count++;
    }
    int mini =(int)n/2+1;
    if(count>=mini) return let;
    return -1;
}

int main(){
    int n;
    cout<<"Size : ";
    cin>>n;
    vector<int> arr(n);
    cout<<"Arrays element : ";
    for(int i=0;i<n;i++) cin>>arr[i];
    // int ans = majority(arr);
    // cout<<"Majority element : "<<ans;

    // int ans = majorityOptimal1(arr);
    // cout<<"Majority element : "<<ans;

    int ans = majorityOptimal2(arr);
    cout<<"Majority element : "<<ans;
    return 0;
}
