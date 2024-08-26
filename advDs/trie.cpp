    //trie
#include<bits/stdc++.h>
using namespace std;
//array of size 26 and a boolean flag 
class TrieNode{
    TrieNode *links[26];
    bool flag = false;
    public:
        bool containsKey(char ch){
            return (links[ch-'a']!=NULL);
        }
        void put(char ch,TrieNode *node){
            links[ch-'a'] = node;
        }
        TrieNode* get(char ch){
            return links[ch-'a'];
        }
        void setEnd(){
            flag = true;
        }
        bool isEnd(){
            return flag;
        }
};
class Trie{
    TrieNode *root;
    public:
        Trie(){
            root = new TrieNode();
        }
        //o(len(word))
        void insert(string word){
            TrieNode *node = root;
            for(int i=0;i<word.length();i++){
                if(!node->containsKey(word[i])){
                    node->put(word[i],new TrieNode());
                }
                //moves to reference track
                node = node->get(word[i]);
            }
            node->setEnd();
        }
        bool search(string word){
            TrieNode *node = root;
            for(int i=0;i<word.length();i++){
                if(!node->containsKey(word[i]))return false;
                node = node->get(word[i]);
            }
            if(node->isEnd())return true;
            return false;
           }
        bool startsWith(string prefix){
            TrieNode* node = root;
            for(int i=0;i<prefix.length();i++){
                if(!node->containsKey(prefix[i]))return false;
                node = node->get(prefix[i]);
            }
            return true;
        }  
        string contains(string word){
            TrieNode* node = root;
            string ans = "";
            for(int i=0;i<word.size();i++){
                if(node->isEnd()){
                    return ans;
                }
                if(!node->containsKey(word[i])){
                    return word;
                }
                ans+=word[i];
                node = node->get(word[i]);
            }
            return word;
        }  
};
int main(){
    
    return 0;
}