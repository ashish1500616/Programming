/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

ListNode *Solution::mergeTwoLists(ListNode *A, ListNode *B)
{
    ListNode *headA = A, *headB = B;
    ListNode *ans = nullptr;
    ListNode *ansHead;
    if (headA->val < headB->val)
    {
        ans = headA;
        headA = headA->next;
    }
    else
    {
        ans = headB;
        headB = headB->next;
    }
    ansHead = ans;
    while (headA && headB)
    {
        if (headA->val < headB->val)
        {
            ans->next = headA;
            headA = headA->next;
        }
        else
        {
            ans->next = headB;
            headB = headB->next;
        }
        ans = ans->next;
    }
    while (headA)
    {
        ans->next = headA;
        headA = headA->next;
        ans = ans->next;
    }
    while (headB)
    {
        ans->next = headB;
        headB = headB->next;
        ans = ans->next;
    }
    return ansHead;
}