class Solution {
public:
    ListNode* solve(ListNode* head1,ListNode* head2){
    if(!head1)return head2;
    if(!head2)return head1;

    if(head1->val>head2->val){
        head2->next=solve(head1,head2->next);
        return head2;
    }else{
        head1->next=solve(head1->next,head2);
        return head1;
    }
    return NULL;    
}
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        return solve(l1,l2);
    }
};
