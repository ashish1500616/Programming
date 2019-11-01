using namespace std;

#include <iostream>
#include <vector>

class PartitionSet
{
public:
    bool canPartition(const vector<int> &num)
    {
        int sum = accumulate(num.begin(), num.end(), 0);
        if (sum & 1)
        {
            return 0;
        }

        int n = num.size();
        int op = 1 << n;
        for (int i = 1; i < op; i++)
        {
            int subs = 0;
            for (int j = 0; j < n; j++)
            {
                if (i & (1 << j))
                {
                    subs += num[j];
                    // cout << num[j] << " ";
                }
                // cout << "\n";
                if (subs == (sum / 2))
                {
                    return true;
                }
            }
        }
        return false;
    }
};