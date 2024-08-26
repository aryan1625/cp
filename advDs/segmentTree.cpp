#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+2;
int arr[N],tree[4*N];
void build(int node,int start,int end){
    if(start==end){
        tree[node] = arr[start];
        return ;
    }
    //divide and conquer
    int mid = start + (end-start)/2;
    build(2*node,start,mid);
    build(2*node+1,mid+1,end);
    tree[node] = tree[2*node] + tree[2*node+1];
}
int main(){
    
    return 0;
}