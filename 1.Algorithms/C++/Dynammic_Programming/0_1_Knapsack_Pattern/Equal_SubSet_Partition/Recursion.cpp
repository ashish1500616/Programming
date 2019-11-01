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

        return this->canPartitionRecursive(num, sum / 2, 0);
    }

private:
    bool canPartitionRecursive(const vector<int> &num, int sum, int currentIndex)
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

        // recursive call after choosing the number at the currentIndex
        // if the number at currentIndex exceeds the sum, we shouldn't process this
        if (num[currentIndex] <= sum)
        {
            if (canPartitionRecursive(num, sum - num[currentIndex], currentIndex + 1))
            {
                return true;
            }
        }

        // recursive call after excluding the number at the currentIndex
        return canPartitionRecursive(num, sum, currentIndex + 1);
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