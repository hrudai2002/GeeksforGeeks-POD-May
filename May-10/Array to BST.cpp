Solution *left, *right;
     int val;
     
     vector<int> ans;
     Solution* createNode(int val) {
         Solution* node = new Solution();
         node->val = val;
         node->left = node->right = NULL;
         return node;
     }
     Solution* treeConvert(vector<int> nums, int l, int r) {
         if(l > r) return NULL;
         
         int mid = (l  +  r) / 2;
         Solution* root = createNode(nums[mid]);
         
         root->left = treeConvert(nums, l, mid - 1);
         root->right = treeConvert(nums, mid + 1, r);
         
         return root;
         
     }
     void preorder(Solution* node) {
         if(node) {
             ans.push_back(node->val);
             preorder(node->left);
             preorder(node->right);
         }
     }
     vector<int> sortedArrayToBST(vector<int>& nums) {
        Solution *root = treeConvert(nums, 0, nums.size() - 1);
        preorder(root);
        return ans;
     }
