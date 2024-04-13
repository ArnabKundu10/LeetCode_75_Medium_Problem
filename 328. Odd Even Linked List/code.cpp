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
   ListNode *oddEvenList(ListNode *head)
   {
      if (head == NULL || head->next == NULL)
      {
         return head;
      }

      ListNode *prev = head;
      ListNode *head1 = prev;

      ListNode *aft = head->next;
      ListNode *head2 = aft;
      while (aft->next != NULL && aft->next->next != NULL)
      {
         prev->next = aft->next;

         prev = prev->next;

         aft->next = aft->next->next;
         aft = aft->next;
      }
      if (aft->next != NULL)
      {
         prev->next = aft->next;

         prev = prev->next;
         aft->next = NULL;
      }

      prev->next = head2;
      return head1;
      delete prev;
      delete aft;
      delete head2;
   }
};