#include<bits/stdc++.h>
using namespace std;
int solve(int n,int a,int b,string &s){
    int x = 0,y = 0;
    set<pair<int,int>> us;
    int dx = 0,dy = 0;
    for(int i=0;i<n;i++){
        if(x==a &&y==b){
            return true;
        }
        us.insert({x,y});
        switch(s[i]){
            case 'N':
                y++;
                dy+=1;
                break;
            case 'S':
                y--;
                dy-=1;
                break;
            case 'E':
                x++;
                dx+=1;
                break;
            case 'W':
                x--;
                dx-=1;
                break;
            
        }
            if (x == a && y == b) return true;
    }
    while(true){
        if(x==a && y==b)return true;
        if(us.count({x,y})>0)break;
        us.insert({x,y});
        x += dx;
        y += dy;
    }
    return false;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,a,b;
        cin>>n>>a>>b;
        string s;
        cin>>s;
        if(solve(n,a,b,s)){
            cout<<"Yes"<<endl;
        }else{
            cout<<"No"<<endl;
        }
    }

    return 0;
}