/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
   void reorder(ListNode *&cpyhead, ListNode *head, int &middle, int cnt, int &sum)
   {
      if (!head)
      {
         middle = cnt / 2;
         return;
      }
      cnt++;
      reorder(cpyhead, head->next, middle, cnt, sum);
      if (cnt > middle)
      {
         sum = max(sum, (head->val + cpyhead->val));
         cpyhead = cpyhead->next;
      }
   }
   int pairSum(ListNode *head)
   {
      ListNode *head1 = head;
      int sum = 0, range = 0;
      ;
      reorder(head1, head, range, 0, sum);
      return sum;
   }
};