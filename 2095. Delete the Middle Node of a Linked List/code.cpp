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
   ListNode *deleteMiddle(ListNode *head)
   {
      if (!head->next)
         return NULL;
      ListNode *head1 = head;
      ListNode *head2 = head;
      int cnt = 0;
      while (head1)
      {
         cnt++;
         head1 = head1->next;
      }
      int middle = (cnt / 2);
      int i = 1;
      while (i < middle)
      {
         head2 = head2->next;
         i++;
      }
      head2->next = head2->next->next;
      return head;
   }
};