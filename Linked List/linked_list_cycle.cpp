// Detecting Linked List Cycle

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// detect cycles
bool *detectCycles(ListNode *head){
  if(head==NULL || head->next==NULL)
    return false;
  ListNode *slow=head;
  ListNode *fast=head;
  while(fast && fast->next){
    slow=slow->next;
    fast=fast->next->next;
    if(slow==fast)
      return true;
  }
  return false;
}


// finding entry point of cycle
ListNode *detectCycles(ListNode *head){
  if(!head || !head->next)
    return NULL;
  ListNode *slow=head;
  ListNode *fast=head;
  while(fast && fast->next){
    slow=slow->next;
    fast=fast->next;
    if(slow==fast)
      break;
  }
  if(!(fast && fast->next))
    return false;
  while(head!=slow){
    head=head->next;
    slow=slow->next;
  }
  return head;
}
