// Flattening a multilevel linkedlist
// only function which will return head after flattening

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

Node* flatten(Node* head){
  if(!head)
    return head;
  Node* curr=head;
  while(curr){
    if(curr->child){
      Node* x=curr->child;
      while(x->next)
        x=x->next;
      x->next=curr->next;
      if(curr->next)
        curr->next->prev=x;
      curr->next=curr->child;
      curr->child->prev=curr;
      curr->child=NULL;
    }
    curr=curr->next;
  }
  return head;
}
