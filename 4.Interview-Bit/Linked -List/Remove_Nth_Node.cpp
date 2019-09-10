/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode *Solution::removeNthFromEnd(ListNode *A, int B)
{
    ListNode *first = A;
    ListNode *second = A;
    int c = 1;
    while (c <= (B) && second)
    {
        second = second->next;
        c += 1;
    }
    if (!second)
        return first->next;
    while (second->next != nullptr)
    {
        first = first->next;
        second = second->next;
    }

    first->next = first->next->next;
    return A;
}