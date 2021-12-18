// Complete String
// Longest word with all prefixes

struct Node{
    Node* links[26];
    bool flag=false;
    
    bool containsKey(char ch){
        return links[ch-'a']!=NULL;
    }
    
    Node* get(char ch){
        return links[ch-'a'];
    }
    
    void put(char ch,Node* node){
        links[ch-'a']=node;
    }
    
    void setEnd(){
        flag=true;
    }
    
    bool isEnd(){
        return flag;
    }
};

class Trie{
private:
    Node* root;
public:
    Trie(){
        root=new Node();
    }
    void insert(string word){
        Node* node=root;
        for(int i=0;i<word.size();i++){
            if(!node->containsKey(word[i])){
                node->put(word[i],new Node());
            }
            node=node->get(word[i]);
        }
        node->setEnd();
    }
    bool checkAllPrefixExists(string word){
        bool flag=true;
        Node* node=root;
        for(int i=0;i<word.size();i++){
            if(node->containsKey(word[i])){
                node=node->get(word[i]);
                flag = flag & node->isEnd();
            }else
                return false;
        }
        return flag;
    }
};
string completeString(int n, vector<string> &a){
    Trie* obj = new Trie();
    for(auto it:a){
       	obj->insert(it);
    }
    string longest="";
    for(auto it:a){
        if(obj->checkAllPrefixExists(it)){
            if(it.size()>longest.size()){
                longest=it;
            }else if(it.size()==longest.size() && it<longest){
                longest=it;
            }
        }
    }
    if(longest=="")
        return "None";
    return longest;
}
