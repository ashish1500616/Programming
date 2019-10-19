#define mod 1003
void numbersUptoLeaf(TreeNode *A, int &sum, int cs)
{
    cs = cs * 10 + A->val;
    cs %= mod;
    if (A->left == nullptr && A->right == nullptr)
    {
        sum += cs;
        sum %= mod;
        return;
    }
    if (A->left)
        numbersUptoLeaf(A->left, sum, cs);
    if (A->right)
        numbersUptoLeaf(A->right, sum, cs);
}
int Solution::sumNumbers(TreeNode *A)
{
    int sum = 0;
    numbersUptoLeaf(A, sum, 0);
    return sum;
}
