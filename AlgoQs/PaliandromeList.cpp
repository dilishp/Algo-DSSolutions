#include <cstddef>

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
private:
    ListNode* m_node;
    int currCount = 0;
    bool isPalianDrome(ListNode* aNode, int limit)
    {
        if (NULL == aNode)
            return true;

        if (!isPalianDrome(aNode->next, limit))
            return false;

        if (currCount == limit - 1)
            return true;
    	
        if (m_node->val != aNode->val)
        {
            return false;
        }

        m_node = m_node->next;
        ++currCount;

        return true;
    }
public:
    bool isPalindrome(ListNode* head) {
        m_node = head;
        int nodeCount = 0;
        while (head)
        {
            ++nodeCount;
            head = head->next;
        }
        return isPalianDrome(m_node, nodeCount / 2);
    }
};

int main()
{
    Solution s;
    s.isPalindrome(new ListNode(1, new ListNode(2, new ListNode(2,new ListNode(1,NULL)))));
}