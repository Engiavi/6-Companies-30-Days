
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        vector<int> arr;
        for (int i = 0; i < lists.size(); i++) {
            ListNode* temp = lists[i];
            while (temp) {
                arr.push_back(temp->val);
                temp = temp->next;
            }
        }
        sort(arr.begin(), arr.end());
        return convert(arr);
    }

private:
    ListNode* convert(vector<int>& arr) {
        if (arr.size() == 0)
            return NULL;
        ListNode* head = new ListNode(arr[0]);
        ListNode* mover = head;
        for (int i = 1; i < arr.size(); i++) {
            ListNode* temp = new ListNode(arr[i]);
            mover->next = temp;
            mover = temp;
        }
        return head;
    }
};
// time and space complexity
// time complexity: O(nlogn)
// space complexity: O(n)