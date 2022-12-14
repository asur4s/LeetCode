// 非递归写法
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == nullptr){
            return head;
        }

        ListNode* pHead = new ListNode();
        ListNode* NewHead = pHead;

        ListNode* pre = pHead;
        ListNode* cur = head;
        ListNode* next = head->next;

        while(cur != nullptr){
            bool flag = true;
            while(next != nullptr && cur->val == next->val){  // 不相同 / 尾部
                next = next->next;
                flag = false;
            }

            if(flag){
                NewHead->next = cur;
                cur->next = nullptr;
                NewHead = NewHead->next;
            }
            cur = next;
            if(cur == nullptr){
                break;
            }else if (cur->next == nullptr){
                NewHead->next = cur;
                cur->next = nullptr;
                NewHead = NewHead->next;
            }else{
                next = cur->next;
            }
        }

        return pHead->next;
    }
};


// 递归写法
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(nullptr == head || nullptr == head->next){
            return head;
        }

        ListNode *next;
        next = head->next;
        
        if(head->val == next->val){
            while(nullptr != next && next->val == head->val){
                next = next->next;
            }
            next = deleteDuplicates(next);
            return next;
        }else{
            head->next = deleteDuplicates(head->next);
            return head;
        }
    }
};