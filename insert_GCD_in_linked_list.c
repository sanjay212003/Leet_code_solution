//Insert Greatest Common Divisors in Linked List
struct ListNode* insertGreatestCommonDivisors(struct ListNode* head){
   if(head==NULL || head->next==NULL) return head;
    struct ListNode *fir=head;
    struct ListNode *sec=head->next;
    int i,n1,n2,gcd;
    while(sec!=NULL){
    n1=fir->val; n2=sec->val;
        for(i=1; i <= n1 && i <= n2; ++i)
    {
        
        if(n1%i==0 && n2%i==0)
            gcd = i;
    }
      struct ListNode*np=(struct ListNode*)malloc(sizeof(struct ListNode));
        np->val=gcd;
        np->next=sec;
        fir->next=np;
        fir=sec;
        sec=sec->next;
    }
    
    return head;
}
