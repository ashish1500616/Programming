class Solution
{
public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        int l = -1;
        int n = nums.size();
        vector<int> ans(2, -1);
        if (n == 0)
        {
            return ans;
        }
        // Cases: [5,6,7,7,8,8,8,9] ,t=9 op=[4,5]
        //        [1,2,3] t=2 [1,1]
        //        [1,2,3] t=1 [0,0]
        //        [1,2,3] t=3 [2,2]

        int h = n - 1;
        int li = 0;
        int mid;
        // Inclusive Bounds.
        while (h - l > 1)
        {
            mid = (l + h) / 2;
            if (nums[mid] >= target)
            {
                h = mid;
            }
            else
            {
                l = mid;
            }
        }
        li = h;
        if (nums[li] != target)
        {
            cout << li << "\n";
            return ans;
        }
        l = 0;
        h = n;
        while (h - l > 1)
        {
            mid = (l + h) / 2;
            if (nums[mid] <= target)
            {
                l = mid;
            }
            else
            {
                h = mid;
            }
        }
        if (nums[li] == nums[l])
        {
            ans[0] = li;
            ans[1] = l;
        }
        else
        {
            ans[0] = li;
            ans[1] = li;
        }
        return ans;
    }
};

// TC : LogN to find the last element Index + LogN to find the first element index 
        // f((g(n))) 
        // g(n) =logN+logN
        // O(logN)