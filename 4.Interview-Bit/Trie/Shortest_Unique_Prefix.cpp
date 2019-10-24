
#define hashmap unordered_map<char, node *>
class node
{
public:
    char d;
    hashmap h;
    int freq;
    bool isTerminal;
    node(char data)
    {
        d = data;
        isTerminal = false;
        freq = 0;
    }
};
class Trie
{
    node *root;

public:
    Trie()
    {
        root = new node('\0');
    }
    void addWord(string word)
    {
        node *temp = root;
        for (int i = 0; word[i] != '\0'; i++)
        {
            char ch = word[i];
            if (temp->h.count(ch) == 0)
            {
                node *child = new node(ch);
                child->freq = 1;
                temp->h[ch] = child;
                temp = child;
            }
            else
            {
                temp = temp->h[ch];
                temp->freq++;
            }
        }
        temp->isTerminal = true;
    }
    int search(string word)
    {
        node *temp = root;
        int i;
        for (i = 0; word[i] != '\0'; i++)
        {
            char ch = word[i];
            // if((temp->v[ch-'a']==1))
            if ((temp->freq == 1))
            {
                return (i);
            }
            if (temp->h.count(ch))
            {
                temp = temp->h[ch];
            }
        }
        return (-1);
    }
};
vector<string> Solution::prefix(vector<string> &A)
{
    int n = A.size();
    Trie t;
    vector<string> ans;
    for (int i = 0; i < n; i++)
    {
        t.addWord(A[i]);
    }
    for (int i = 0; i < n; i++)
    {
        int in = t.search(A[i]);
        if (in == -1)
        {
            ans.push_back(A[i]);
        }
        else
            ans.push_back(A[i].substr(0, in));
    }
    return ans;
}
