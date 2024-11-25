#include <bits/stdc++.h>
using namespace std;

struct TrieNode{
    TrieNode *child[26];
    bool wordEnd;
    TrieNode(){
      wordEnd = false;
      for(int i=0;i<26;++i){child[i]=nullptr;}
    }

};

class Trie{
private:
   TrieNode* root;

   void displayWordsHelper(TrieNode* node,string currentWord,vector<string>&words){
      if(node == nullptr)return;

      if(node->wordEnd){
         words.push_back(currentWord);
      }
       for(int i=0; i < 26; ++i) {
            if (node->child[i] != nullptr) {
                char c = 'a' + i;
                displayWordsHelper(node->child[i], currentWord + c, words);
            }
        }
   }
public:
    Trie(){root = new TrieNode();}

    void insertKey(const string& key){
        TrieNode* current = root;
        for(char c:key){
            if(current->child[c -'a']==nullptr){
                TrieNode* newNode = new TrieNode();
                current->child[c -'a'] = newNode;
            }
            current = current->child[c-'a'];
        }
        current->wordEnd = true;
    }
    bool searchKey(const string& key){
        TrieNode* current = root;
        for(char c: key){
            if(current->child[c - 'a']== nullptr){
                return false;
            }
            current = current->child[c - 'a'];
        }
        return current->wordEnd;
    }
    void deleteKey(const string& key){
        TrieNode* current = root;
        for(char c: key){
            if(current->child[c-'a']==nullptr){
                return;
            }
            current = current->child[c - 'a'];
        }
        current->wordEnd = false;
    }
    vector<string> displayWords() {
        vector<string> words;
        displayWordsHelper(root, "", words);
        return words;
    }
};
int main(){
    Trie Ishraq;
    Ishraq.insertKey("hello");
    Ishraq.insertKey("world");
    Ishraq.insertKey("kumar");
    Ishraq.deleteKey("world");
    Ishraq.insertKey("trie");
    Ishraq.insertKey("algorithm");
    cout << (Ishraq.searchKey("hello") ? "Found" : "Not Found") << endl;
    cout << (Ishraq.searchKey("world") ? "Found" : "Not Found") << endl;
    cout << (Ishraq.searchKey("hell") ? "Found" : "Not Found") << endl;
    cout << (Ishraq.searchKey("kumar") ? "Found" : "Not Found") << endl;


    vector<string> allWords = Ishraq.displayWords();
    for (const string& word : allWords) {
        cout << word << endl;
    }

}
