#include<iostream>
#include<algorithm>
using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 * int val;
 * ListNode *next;
 * ListNode() : val(0), next(nullptr) {}
 * ListNode(int x) : val(x), next(nullptr) {}
 * ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        // 1. Handle empty list or single node list
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        ListNode* current = head;

        // Traverse the list
        while (current != nullptr && current->next != nullptr) {
            // Compare current node value with next node value
            if (current->val == current->next->val) {
                // Found a duplicate
                ListNode* temp = current->next;
                
                // Link current node to the node after the duplicate
                current->next = current->next->next;
                
                // Free memory (In LeetCode/Modern C++, 'delete' is preferred over 'free')
                delete temp;
                
            } else {
                current = current->next;
            }
        }

        return head;
    }
};