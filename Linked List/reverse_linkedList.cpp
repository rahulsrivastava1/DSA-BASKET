/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

// First function using only one pointer and one temporary space created during loop
ListNode* reverseList(ListNode* head){
  ListNode* prev=NULL;
  while(head!=NULL){
    ListNode* next=head->next;
    head->next=prev;
    prev=head;
    head=temp;
  }return prev;
}

// Second function using three pointers
ListNode* reverseList(ListNode* head){
  ListNode* current=head,next=NULL,prev=NULL;
  while(current!=NULL){
    next=current->next;
    current->next=prev;
    prev=current;
    current=next:
  }
  return prev:
}

// Output
Input- 1->2->3->4->5
Output- 5->4->3->2->1
