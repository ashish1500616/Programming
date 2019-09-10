/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode *Solution::detectCycle(ListNode *A)
{
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    ListNode *fast_p = A;
    ListNode *slow_p = A;
    ListNode *ans = nullptr;
    unordered_set<ListNode *> s;
    while (A && A->next)
    {
        if (s.find(A) != s.end())
        {
            ans = A;
            break;
        }
        s.insert(A);
        A = A->next;
    }
    // while( fast  && slow && fast->next )
    // {
    //     slow=slow->next;
    //     cout<<"Slow"<<slow->val<<endl;
    //     fast=fast->next->next;
    //     cout<<fast->val<<endl;
    //     if(fast==slow)
    //     {
    //     ans=slow;
    //         // break;
    //     }
    // }
    // while (slow_p && fast_p && fast_p->next) {
    //     slow_p = slow_p->next;
    //     fast_p = fast_p->next->next;
    //     if (slow_p == fast_p) {
    //         ans=slow_p;
    //         break;
    //     }
    // }
    return ans;
}