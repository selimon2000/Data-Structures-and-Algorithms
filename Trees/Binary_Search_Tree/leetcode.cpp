#include <vector>
#include <queue>
#include <cstdint>
#include <iostream>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// Old Skool
// class Solution {
// public:
//     vector<vector<int>> levelOrder (TreeNode* root) {
//         ios::sync_with_stdio(false);
//         vector<vector<int>> ret_vec; if(!root) return ret_vec;
//         queue<TreeNode*> node_q;
//         node_q.emplace(root);

//         ret_vec.push_back(vector<int>());

//         uint16_t i = node_q.size();
//         while (!node_q.empty()) {
//             const TreeNode* node = node_q.front();
//             node_q.pop();
//             ret_vec.back().push_back(node->val);

//             if(node->left) node_q.emplace(node->left);
//             if(node->right) node_q.emplace(node->right);

//             --i;
//             if(i==0) {
//                 i = node_q.size();
//                 ret_vec.push_back(vector<int>());
//             }
//         }

//         // With my algorithm essential to pop_back as there's always an empty vector in the 2 Dimensional Vector
//         ret_vec.pop_back();

        
//         return ret_vec;
//     }
// };


// Better Method
class Solution {
public:
    vector<vector<int>> levelOrder (TreeNode* root) {
        ios::sync_with_stdio(false);
        
        vector<vector<int>> ret_vec; if(!root) return ret_vec;
        queue<TreeNode*> node_q;
        node_q.emplace(root);

        while (!node_q.empty()) {
            vector<int> level_vec;
            for (uint16_t i = node_q.size(); i != 0; --i) {
                const TreeNode *node = node_q.front();
                node_q.pop();
                level_vec.push_back(node->val);

                if (node->left)     node_q.emplace(node->left);
                if (node->right)    node_q.emplace(node->right);
            }

            ret_vec.push_back(level_vec);
        }

        
        return ret_vec;
    }
};