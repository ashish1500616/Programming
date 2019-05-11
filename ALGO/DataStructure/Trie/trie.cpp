#include <bits/stdc++.h>
#define hashmap unordered_map<char, node*>
using namespace std;

class node
{
public:
    char data;
    hashmap h;
    bool isTerminal;

    node(char c)
    {
        data = c;
        isTerminal = false;
    }
};
class Trie
{
    node* root;

public:
    Trie()
    {
        root = new node('\0');
    }
    void addWord(char* word)
    {
        node* temp = root;
        for (int i = 0; word[i] != '\0'; i++)
        {
            char ch = word[i];
            if (temp->h.count(ch) == 0)
            {
                node* child = new node(ch);
                temp->h[ch] = child;
                temp = child;
            }
            else
            {
                temp = temp->h[ch];
            }
            temp->isTerminal = true;
        }
    }
    bool search(char* word)
    {
        node* temp = root;
        for (int i = 0; word[i] != '\0'; i++)
        {
            char ch = word[i];
            if (temp->h.count(ch))
            {
                temp = temp->h[ch];
            }
            else
            {
                return false;
            }
            cout << temp->data << " ";
        }
        return temp->isTerminal;
    }
};
int main()
{
    char word[10][100] = { "apples", "ape", "coder", "coding blocks", "no" };
    Trie t;
    for (int i = 0; i < 6; i++)
    {
        t.addWord(word[i]);
    }
    char searhWord[100];
    cin.getline(searhWord, 100);
    if (t.search(searhWord))
    {
        cout << "Search Word Found" << endl;
    }
    else
    {
        cout << "Not Found" << endl;
    }
    return 0;
}