using namespace std;

#include <iostream>
#include <vector>

class PartitionSet
{
public:
    bool canPartition(const vector<int> &num)
    {
        int sum = 0;
        for (int i = 0; i < num.size(); i++)
        {
            sum += num[i];
        }

        // if 'sum' is a an odd number, we can't have two subsets with equal sum
        if (sum & 1)
        {
            return false;
        }

        vector<vector<int>> dp(num.size(), vector<int>(sum / 2 + 1, -1));
        return this->canPartitionRecursive(dp, num, sum / 2, 0);
    }

private:
    bool canPartitionRecursive(vector<vector<int>> &dp, const vector<int> &num, int sum,
                               int currentIndex)
    {
        // base check
        if (sum == 0)
        {
            return true;
        }

        if (num.empty() || currentIndex >= num.size())
        {
            return false;
        }

        // if we have not already processed a similar problem
        if (dp[currentIndex][sum] == -1)
        {
            // recursive call after choosing the number at the currentIndex
            // if the number at currentIndex exceeds the sum, we shouldn't process this
            if (num[currentIndex] <= sum)
            {
                if (canPartitionRecursive(dp, num, sum - num[currentIndex], currentIndex + 1))
                {
                    dp[currentIndex][sum] = 1;
                    return true;
                }
            }

            // recursive call after excluding the number at the currentIndex
            dp[currentIndex][sum] = canPartitionRecursive(dp, num, sum, currentIndex + 1) ? 1 : 0;
        }

        return dp[currentIndex][sum] == 1 ? true : false;
    }
};

int main(int argc, char *argv[])
{
    PartitionSet ps;
    vector<int> num = {1, 2, 3, 4};
    cout << ps.canPartition(num) << endl;
    num = vector<int>{1, 1, 3, 4, 7};
    cout << ps.canPartition(num) << endl;
    num = vector<int>{2, 3, 4, 6};
    cout << ps.canPartition(num) << endl;
}
