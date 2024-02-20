//Reverse Linked List
struct ListNode* reverseList(struct ListNode* head){

    struct ListNode* temp=NULL;
    struct ListNode* previous=NULL;

    while(head!=NULL)
    {
        temp=head->next;
        head->next=previous;
        previous=head;
        head=temp;
    }
    return previous;
}
