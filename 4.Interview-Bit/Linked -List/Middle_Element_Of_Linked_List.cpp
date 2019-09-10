/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
int Solution::solve(ListNode *A)
{
    ListNode *temp = A;
    ListNode *midElem = A;
    int c = 0;
    while (temp && temp->next != nullptr)
    {
        temp = temp->next->next;
        midElem = midElem->next;
        // if(c&1)
        // {
        //     midElem=midElem->next;
        // }
        // c+=1;
        // temp=temp->next;
    }
    return midElem->val;
}