#include <iostream>
#include <queue>
#include <vector>
/**
 * Definition for singly-linked list.
 */
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution
{
  public:
    ListNode *mergeKLists(std::vector<ListNode *> &lists)
    {
        std::priority_queue<int> pq;
        //init the heap with the first elements of the k-sorted lists
        for (int i = 0;i<lists.size();i++)
        {
            ListNode *head = lists[i];
            printf("Pushing: %d\n", head->val);
            pq.push(head->val);
        }

        ListNode *ret = new ListNode(5);
        return ret;
    }
};

int main()
{
    int K = 5;
    std::vector<ListNode *> lists(5);
    for (int i = 0; i < 5; i++)
    {
        int start = i + 1;
        ListNode *head = new ListNode(start);
        printf("%d\n", head->val);
        lists.push_back(head);
    }
    Solution solution;
    ListNode *ret = solution.mergeKLists(lists);
}
