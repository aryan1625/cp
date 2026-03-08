#include<bits/stdc++.h>
using namespace std;
int mod = 998244353;
using ll = long long ;
using ld = long double ;
void computeLPS(string &pat,int m,vector<int>& lps){
    int len = 0,i=1;
    // consider abcdab --> [0,0,0,0,1,1]
    while(i<m){
        if(pat[i]==pat[len]){
            lps[i++] = ++len;
        }
        else{
            //consider aaacaaaa or abcdabca
            if(len!=0){
                //dont inc i
                len = lps[len-1];
            }else{
                lps[i++] = 0;
            }
        }
    }
    return ;
    
}
//return vector of indexes where we find the pattern !!
int kmpSearch(string &text,string &pattern){
    int m = pattern.size();
    int n = text.size();
    string newp = "";
    vector<int> ans;
    //longest prefix suffix-  abcdab here ab is the longest prefix suffix as it is same as the first two char
    vector<int> lps(m,0);
    //this will compute the lps array for us 
    computeLPS(pattern,m,lps);
    int i = 0;//text
    int j = 0;//pattern  
    while(i<n){
        if(text[i]==pattern[j]){
            i++;
            j++;
        }
        if(j==m){
            return i-j;
            j=lps[j-1];
        }
        else if(i<n && text[i]!=pattern[j]){
            if(j!=0){
                j = lps[j-1];
            }
            else{
                i++;
            }
        }
    }
    return -1;
}

int main(){
    ll t;
    cin>>t;
    while(t--){

        string a,b;
        cin>>a;
        cin>>b;
        string c = a+a;
        cout<<kmpSearch(c,b)<<endl;
    }
    return 0;
}