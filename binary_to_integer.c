//Convert Binary Number in a Linked List to Integer
int getDecimalValue(struct ListNode* head){
    int number = 0;
    int twos = 1;
    struct ListNode* p = head;
    while (p->next != NULL){
        p = p->next;
        twos *= 2;
    }
    p = head;
    while (p != NULL){
        number += p->val * twos;
        twos /= 2;
        p = p->next;
    }
    return number;
}
