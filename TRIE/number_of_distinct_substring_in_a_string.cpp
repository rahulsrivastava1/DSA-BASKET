// Number of distinct substring in a string

struct Node {
    Node *links[26]; 
    
    bool containsKey(char ch) {
        return (links[ch - 'a'] != NULL); 
    }
    Node* get(char ch) {
        return links[ch-'a']; 
    }
    void put(char ch, Node* node) {
        links[ch-'a'] = node; 
    }
}; 
int countDistinctSubstrings(string &s)
{
    int count=0;
    Node* root=new Node();
    for(int i=0;i<s.size();i++){
        Node* node=root;
        for(int j=i;j<s.size();j++){
            if(!node->containsKey(s[j])){
                node->put(s[j],new Node());
                count++;
            }
            node=node->get(s[j]);
        }
    }
    return count+1;
}
