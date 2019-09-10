/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode *Solution::swapPairs(ListNode *A)
{
    ListNode *first = A;
    ListNode *second = A->next;
    if (!second)
        return first;
    ListNode *head = second;
    ListNode *temp = first;

    while (1)
    {
        ListNode *temp2 = second->next;
        second->next = first;
        first->next = temp2;
        first = first->next;
        // cout<<first->val<<"\n";
        // break;
        // cout<<first->val<<"\n";
        if (first != nullptr && first->next != nullptr)
        {
            second = first->next;
            temp->next = second;
            temp = first;
        }
        else
        {
            break;
        }
    }
    return head;
}