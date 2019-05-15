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
    var seenRight bool;
    var seenLeft bool;
    //     1
    //    /  \
    //   2    3
    //  / \   /
    // 4   5 6
    // postorder traversal: 4 5 2 6 3 1
    if (root == nil) {
        return values;
    }
    stack = append(stack, *root);
    visited[root] = (*root).Val;
    // TODO: what if it's a null root?
    for (len(stack) > 0) {
        seenRight = false;
        seenLeft = false;
        // 1 3 2 5 4
        // 4 5 2
        if ((*root).Right != nil) {
            _, seenRight = visited[(*root).Right];
            fmt.Println("right ", (*root).Val);
            if (!seenRight) {
                fmt.Println("append right ", (*(*root).Right).Val);
                stack = append(stack, (*(*root).Right));
                // add right child node to hash table
                visited[(*root).Right] = (*(*root).Right).Val;
            } else {
                fmt.Println("seen right ", (*(*root).Right).Val)
            }
        }
        if ((*root).Left != nil) {
            _, seenLeft = visited[(*root).Left];
            fmt.Println("left ", (*(*root).Left).Val);
            if (!seenLeft) {
                fmt.Println("append left ", (*(*root).Left).Val);
                stack = append(stack, (*(*root).Left));
                // add left child node to hash table
                visited[(*root).Left] = (*(*root).Left).Val;
            } else {
                fmt.Println("seen left ", (*(*root).Left).Val)
            }
        }
        if (seenRight || seenLeft) {
            fmt.Println("backtracking ", (*root).Val)
            // backtracking
            values = append(values, (*root).Val);
            stack = stack[0: len(stack) - 1];
        }
        if ((*root).Right == nil && (*root).Left == nil) {
            // leaf node
            values = append(values, (*root).Val);
            stack = stack[0: len(stack) - 1];
        }
        fmt.Println(len(stack), " ", (*root).Val);
        fmt.Println("stack ", stack);
        fmt.Println("values ", values);
        if (len(stack) > 0) {
            root = &(stack[len(stack) - 1]);
        }
    }
    fmt.Println("values ", values);
    return values;
}