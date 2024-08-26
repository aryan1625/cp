#include<bits/stdc++.h>
using namespace std;
void computeLPS(string &pat,int m,vector<int>& lps){
    int len = 0,i=1;
    //consider abcdab --> [0,0,0,0,1,1]
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
vector<int> kmpSearch(string &text,string &pattern){
    int m = pattern.size();
    int n = text.size();
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
            ans.push_back(i-j);
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
    return ans;
}
int main(){
    string s = "aacecaaa#aaacecaa";
    vector<int> lps(17,0);
    computeLPS(s,17,lps);
    for(int i=0;i<lps.size();i++){
        cout<<lps[i]<<" ";
    }
    cout<<endl;
    return 0;
}