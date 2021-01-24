#include <string>
#include <unordered_map>

using namespace std;

class Trie {
    struct Node
    {
	    std::pmr::unordered_map<char, Node*> umap;
        bool isEnd;
    };
    Node* root;
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new Node();
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        Node* temp = root;

        for (int i = 0;i < word.length();)
        {
            while (temp != nullptr &&
                temp->umap.find(word[i]) != temp->umap.end())
            {
                temp = temp->umap[word[i]];
                ++i;
            }

            if (i < word.length() &&
                nullptr != temp &&
                temp->umap.find(word[i]) == temp->umap.end())
            {
                temp->umap[word[i]] = new Node();
                temp = temp->umap[word[i]];
                ++i;
            }

            if (i == word.length())
            {
                temp->isEnd = true;
            }
            else
            {
                temp->isEnd = false;
            }
        }
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        Node* temp = root;
        for (int i = 0;i < word.length();)
        {
            while (temp != nullptr &&
                temp->umap.find(word[i]) != temp->umap.end())
            {
                temp = temp->umap[word[i]];
                ++i;
            }

            if (word.length() == i &&
                temp->isEnd == true)
            {
                return true;
            }
        }
        return false;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(std::string prefix) {
        Node* temp = root;
        for (int i = 0;i < prefix.length();)
        {
            while (temp != nullptr &&
                temp->umap.find(prefix[i]) != temp->umap.end())
            {
                temp = temp->umap[prefix[i]];
                ++i;
            }

            if (i == prefix.length())
            {
                return true;
            }
        }
        return false;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

int main()
{
    Trie* trie = new Trie();

    trie->insert("apple");
    trie->insert("appre");
    trie->insert("app");
    trie->search("apple");
    trie->search("app");
    trie->startsWith("app");
}