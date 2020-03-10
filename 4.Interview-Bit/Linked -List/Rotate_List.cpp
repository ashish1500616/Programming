
ListNode *Solution::rotateRight(ListNode *A, int B)
{
    ListNode *fast = A;
    ListNode *slow = A, *ans = nullptr;
    int count = 0;

    while (count < B)
    {
        if (fast->next)
        {
            fast = fast->next;
        }
        else
        {
            fast = A;
        }

        count++;
    }
    while (fast and fast->next)
    {
        slow = slow->next;
        fast = fast->next;
    }
    //  Handle When there is only one element .
    if (!slow->next)
    {
        return A;
    }
    ListNode *r = slow->next;
    ans = r;
    slow->next = nullptr;
    while (r->next)
    {
        r = r->next;
    }
    r->next = A;
    return ans;
}