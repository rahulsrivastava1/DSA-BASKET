// Copy linked list with random pointers

Node* copyRandom(Node* head){
  if(!head)
    return NULL;
  
  // First step
  // Creating a copy node and placing between temp and temp->next
  Node* temp=head;
  while(temp){
    Node* node=new Node(temp->val);
    node->next=temp->next;
    temp->next=node;
    temp=node->next;
  }
  
  // Second step
  // Placing random pointers of copy list
  temp=head;
  while(temp){
    temp->next->random=(temp->random)?temp->random->next:NULL;
    temp=temp->next->next;
  }
  
  // Third step
  //
  temp=head;
  Node* dummy=new Node(0);
  Node* copy=dummy;
  Node* front=head;
  while(temp){
    front=temp->next->next;
    copy->next=temp->next;
    temp->next=front;
    copy=copy->next;
    temp=temp>next;
  }
  return dummy->next;
}
