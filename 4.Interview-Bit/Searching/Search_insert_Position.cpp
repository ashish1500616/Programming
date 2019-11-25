class Solution
{
public:
    int searchInsert(vector<int> &nums, int target)
    {
        int l = 0;
        int n = nums.size();
        int h = n - 1;
        while (l <= h)
        {
            int mid = (l + h) >> 1;
            if (nums[mid] >= target)
            {
                h = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }
        return l;
    }
};