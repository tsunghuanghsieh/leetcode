# [105. Construct Binary Tree from Preorder and Inorder Traversal](https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/)

Given two integer arrays `preorder` and `inorder` where `preorder` is the preorder traversal of a binary tree and `inorder` is the inorder traversal of the same tree, construct and return _the binary tree_.

**Example 1:**
![Example 1](https://assets.leetcode.com/uploads/2021/02/19/tree.jpg)
```
Input: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
Output: [3,9,20,null,null,15,7]
```

**Example 2:**
```
Input: preorder = [-1], inorder = [-1]
Output: [-1]
```

**Constraints:**
* `1 <= preorder.length <= 3000`
* `inorder.length == preorder.length`
* `-3000 <= preorder[i], inorder[i] <= 3000`
* `preorder` and `inorder` consist of unique values.
* Each value of `inorder` also appears in `preorder`.
* `preorder` is **guaranteed** to be the preorder traversal of the tree.
* `inorder` is **guaranteed** to be the inorder traversal of the tree.

## Interview
As of 01/24/2025, leetcode premium subscription says Google 5 times, Amazon and Snowflakes 2 times in the last 3 months, Microsoft 6 times and Facebook 4 times in the last 6 months.
