package main

import (
    "fmt"
    // "strings"
)

type TreeNode struct {
    Val int
    Left *TreeNode
    Right *TreeNode
}

func main ()  {
    var root *TreeNode;
    var inputs []int;
    // use -1 for null node in binary tree
    inputs = []int{1,2,-1,3,-1,4,-1,5,-1,6,-1,7,-1};

    makeTree(inputs);
    printTreeNode(postorderTraversal(root));
}

func makeTree(inputs []int) {
    //
}

func printTreeNode(values []int) {
    fmt.Println("values ", values);
}

/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func postorderTraversal(root *TreeNode) []int {
    var values []int;
    var stack []TreeNode;
    // hash table of nodes seen so far
    var visited map[*TreeNode]int = make(map[*TreeNode]int);

    //     1
    //    /  \
    //   2    3
    //  / \   /
    // 4   5 6
    // postorder traversal: 4 5 2 6 3 1
    if (root == nil) {
        // special case
        return values;
    }
    stack = append(stack, *root);
    visited[root] = (*root).Val;
    for (len(stack) > 0) {
        seenRight := false;
        seenLeft := false;
        // add right child node to stack first
        if ((*root).Right != nil) {
            _, seenRight = visited[(*root).Right];
            if (!seenRight) {
                stack = append(stack, (*(*root).Right));
                // add right child node to hash table
                visited[(*root).Right] = (*(*root).Right).Val;
            }
        }
        // add left child node to stack
        if ((*root).Left != nil) {
            _, seenLeft = visited[(*root).Left];
            if (!seenLeft) {
                stack = append(stack, (*(*root).Left));
                // add left child node to hash table
                visited[(*root).Left] = (*(*root).Left).Val;
            }
        }
        if (seenRight || seenLeft) {
            // backtracking
            values = append(values, (*root).Val);
            stack = stack[0: len(stack) - 1];
        }
        if ((*root).Right == nil && (*root).Left == nil) {
            // leaf node
            values = append(values, (*root).Val);
            stack = stack[0: len(stack) - 1];
        }
        if (len(stack) > 0) {
            // advance to the top node in stack
            root = &(stack[len(stack) - 1]);
        }
    }
    return values;
}