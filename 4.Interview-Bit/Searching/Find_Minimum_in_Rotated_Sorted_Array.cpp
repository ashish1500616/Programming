class Solution
{
public:
    int findMin(vector<int> &nums)
    {
        int l = 0;
        int n = nums.size();
        int h = n - 1;
        // 4 5 6 7 0 1 2
        // 0 1 2 3 4 5 6
        // Note To find the pivot we check the middle element with the last element of the array.
        // Thus on finding the pivot we check the next element.
        int ans = -1;
        while (l <= h)
        {
            int mid = (l + h) / 2; //3
            if ((mid == 0 || nums[mid] < nums[mid - 1]) && ((mid == n - 1) || nums[mid] < nums[mid + 1]))   
            {
                // return mid;
                ans = nums[mid];
                break;
            }
            else if (nums[mid] > nums[n - 1])
            {
                l = mid + 1;
            }
            else
            {
                h = mid - 1;
            }
        }
        return ans;
    }
};