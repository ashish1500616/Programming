/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode *reverse(ListNode * h)
{
    if(h->next==nullptr || h==nullptr)
    {
        return h;
    }
    ListNode *rest=reverse(h->next);
    h->next->next=h;
    h->next=nullptr;
    return rest;
}
ListNode* Solution::reverseList(ListNode* A, int B) {
    int c=1;
    ListNode *h=A;
    while(c<B and h) 
    {
        h=h->next;
        ++c;
    }
    ListNode * rest=(h->next) ? h->next : nullptr;
    h->next=nullptr;
    ListNode  * rN=reverse(A);
    if(rest)
        A->next=reverseList(rest,B);
    return rN;
}
