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
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {

        ListNode*final;

        for(int i=0;i<k;i++) {
            ListNode*  temp=head;
            while (temp->next->next!=nullptr) {
                temp=temp->next;
            }
            final= temp->next;
            final->next=head;
            temp->next=nullptr;
            head=final;
        }


        return final;

    }
};
int main() {
    ListNode * heap= new ListNode(0);
    heap->next= new ListNode(1);
    heap->next->next= new ListNode(2);
    Solution *solution= new Solution;
    auto f =solution->rotateRight(heap,4);
    heap->printList(f);

}
