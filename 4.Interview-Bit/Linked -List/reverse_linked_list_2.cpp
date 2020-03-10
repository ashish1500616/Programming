ListNode *succ=nullptr;
ListNode *reverse(ListNode *head,int n)
{
    if(n==1)
    {
        succ=head->next;
        return head;
    }
    ListNode * last =reverse(head->next,n-1);
    head->next->next=head;
    head->next=succ;
    return last;
}
ListNode *reverseB(ListNode *head ,int m,int n)
{
    if(m==1)
    {
        return reverse(head,n);
    }
    else
    {
        head->next=reverseB(head->next,m-1,n-1);
    }
    return head;
}
ListNode* Solution::reverseBetween(ListNode* A, int B, int C) {
    succ=nullptr;
    A=reverseB(A,B,C);
    return A;
}
