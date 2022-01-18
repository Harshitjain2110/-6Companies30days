/*
Find max 10 numbers in a list having 10M entries.
*/


//Using Min heap
#include<bits/stdc++.h>
using namespace std;
int main() {
    vector<int> arr = {1,4,5,3,10,7,24,2,20,25,23,24,16,13,18,25};
    int size = arr.size();
    priority_queue<int,vector<int>,greater<int>> pq;
    unordered_set<int> s;

    int i;
    for(i=0;i<10;i++){
        if(s.find(arr[i])==s.end()){
            s.insert(arr[i]);
            pq.push(arr[i]);
        }
    }

    for(;i<size;i++){
        if(s.find(arr[i])==s.end() and arr[i]>pq.top()){
            pq.pop();
            pq.push(arr[i]);
            s.insert(arr[i]);
        }
    }

    cout<<"Max 10 numbers are : "<<endl;

    while(!pq.empty()){
        int ele = pq.top();
        pq.pop();
        cout<<ele<<" ";
    }
}
