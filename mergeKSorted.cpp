/**
Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
struct Comparator
{
    bool operator()(const ListNode *node1, const ListNode *node2)
    {
        return node1->val > node2->val;
    }
};
class Solution
{
  public:
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {

        if (lists.size() == 0)
            return NULL;
        priority_queue<ListNode *, vector<ListNode *>, Comparator> pq;
        for (auto &it : lists)
            if (it != NULL)
                pq.push(it);

        ListNode *ret = new ListNode(INT_MIN);
        ListNode *head = new ListNode(INT_MIN);

        while (!pq.empty())
        {

            ListNode *minElem = pq.top();
            pq.pop();
            if (ret->val == INT_MIN)
            {
                head = new ListNode(minElem->val);
                ret = head;
            }
            else
            {
                ret->next = new ListNode(minElem->val);
                ret = ret->next;
            }
            if (minElem->next != NULL)
                pq.push(minElem->next);
            else
                continue;
        }

        if (ret->val == INT_MIN)
            return NULL;
        else
            ret->next = NULL;
        return head;
    }
};