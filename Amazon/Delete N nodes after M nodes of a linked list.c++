#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    Node* linkdelete(Node* head, int n, int m) {
        if (!head) return head;
        Node* current = head;
        Node* temp;
        while (current) {
            for (int i = 1; i < m && current != nullptr; i++) {
                current = current->next;
            }
            if (!current) break;
            temp = current->next;
            for (int i = 0; i < n && temp != nullptr; i++) {
                Node* nextNode = temp->next;
                delete temp;
                temp = nextNode;
            }
            current->next = temp;
            current = temp;
        }
        return head;
    }
};

// Time Complexity: O(n)
// Space Complexity: O(1)