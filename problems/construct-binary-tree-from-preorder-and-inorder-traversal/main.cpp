#include <fstream>
#include <iostream>
#include <queue>
#include <regex>
#include <vector>

using namespace std;

#include "Solution.cpp"

void printTreeNodesResult(TreeNode *root) {
    int lvl_nodes = 1, cnt_lvl_nodes = 1, cnt_null = 0;
    queue<TreeNode*> qNodes;
    qNodes.push(root);
    cout << "[";
    while (qNodes.size() > 0) {
        TreeNode *temp = qNodes.front();
        qNodes.pop();
        if (temp) cout << temp->val;
        else {
            cout << "null";
            cnt_null += 2;
        }
        if (temp) qNodes.push(temp->left);
        if (temp) qNodes.push(temp->right);
        if (temp && !temp->left) cnt_null++;
        if (temp && !temp->right) cnt_null++;
        cnt_lvl_nodes--;
        if (cnt_lvl_nodes == 0) {
            cnt_lvl_nodes = lvl_nodes *= 2;
            if (cnt_null == cnt_lvl_nodes) break;
            cnt_null = 0;
        }
        if (qNodes.size() > 0) cout << ",";
    }
    cout << "]: actual" << endl;
}

int main(int argc, char **argv) {
    Solution soln;
    ifstream fin;
    fin.open(argv[1]);
    if (!fin) {
        cout << "ERROR: " << argv[1] << " does not exist." << endl;
        exit(1);
    }
    string line_preorder, line_inorder, expected;
    fin >> line_preorder >> line_inorder >> expected;

    vector<int> preorder, inorder;
    regex patternNumber("-?\\d+");
    sregex_token_iterator itr_pre(line_preorder.begin(), line_preorder.end(), patternNumber);
    sregex_token_iterator itr_in(line_inorder.begin(), line_inorder.end(), patternNumber);
    for (; itr_pre != sregex_token_iterator() && itr_in != sregex_token_iterator(); itr_pre++, itr_in++) {
        preorder.emplace_back(stoi(*itr_pre));
        inorder.emplace_back(stoi(*itr_in));
    }
    cout << line_preorder << ": preorder" << endl;
    cout << line_inorder << ": inorder" << endl;
    cout << expected << ": expected" << endl;
    printTreeNodesResult(soln.buildTree(preorder, inorder));
    return 0;
}
