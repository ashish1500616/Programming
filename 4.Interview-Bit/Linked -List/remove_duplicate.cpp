/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

ListNode *Solution::deleteDuplicates(ListNode *A)
{
    while (A->next && A->val == A->next->val)
    {
        while (A->next && A->val == A->next->val)
            A = A->next;
        A = (A->next) ? A->next : nullptr;
        if (!A)
            return A;
    }
    ListNode *firstNode = (!A) ? nullptr : A;
    ListNode *secondNode = (firstNode && firstNode->next) ? firstNode->next : nullptr;
    ListNode *thirdNode = (secondNode && secondNode->next) ? secondNode->next : nullptr;
    while (thirdNode)
    {
        if (secondNode->val == thirdNode->val)
        {
            while (thirdNode->next && secondNode->val == thirdNode->val)
                thirdNode = thirdNode->next;
            if (secondNode->val == thirdNode->val)
            {
                firstNode->next = nullptr;
                break;
            }
            else
            {
                firstNode->next = thirdNode;
                secondNode = thirdNode;
                thirdNode = thirdNode->next;
            }
        }
        else
        {
            firstNode = firstNode->next;
            secondNode = secondNode->next;
            thirdNode = thirdNode->next;
        }
    }
    return A;
}
