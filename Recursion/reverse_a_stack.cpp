// Reverse a stack

void insert(stack<int>& stack,int ele){
    if(stack.size()==0){
        stack.push(ele);
        return;
    }
    int temp=stack.top();
    stack.pop();
    insert(stack,ele);
    stack.push(temp);
}
void reverseStack(stack<int> &stack) {
    if(stack.size()==0)
        return;
    if(stack.size()==1)
        return;
    int temp=stack.top();
    stack.pop();
    reverseStack(stack);
    insert(stack,temp);
}
