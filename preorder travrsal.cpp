class Solution {
public:
    
    vector<int> preorderTraversal(TreeNode* root) {
        
        vector<int> ans;
        if(root == NULL)
            return ans;

        ans.push_back(root->val);
        
        vector<int> leftPart = preorderTraversal(root->left);
        
        vector<int> rightPart = preorderTraversal(root->right);
        
        
    
        for(int x : leftPart)
            ans.push_back(x);
        

        for(int x : rightPart)
            ans.push_back(x);
        
        return ans;
    }
};
