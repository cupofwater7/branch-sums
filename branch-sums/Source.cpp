#include <vector>
#include <iostream>
using namespace std;

// This is the class of the input root. Do not edit it.
class BinaryTree {
public:
    int value;
    BinaryTree* left;
    BinaryTree* right;

    BinaryTree(int value) {
        this->value = value;
        left = nullptr;
        right = nullptr;
    }
};


class TestBinaryTree : public BinaryTree {
public:
    TestBinaryTree(int value) : BinaryTree(value) {};

    BinaryTree* insert(vector<int> values, int i = 0) {
        if (i >= values.size())
            return nullptr;
        vector<BinaryTree*> queue = { this };
        while (queue.size() > 0) {
            BinaryTree* current = queue[0];
            queue.erase(queue.begin());
            if (current->left == nullptr) {
                current->left = new BinaryTree(values[i]);
                break;
            }
            queue.push_back(current->left);
            if (current->right == nullptr) {
                current->right = new BinaryTree(values[i]);
                break;
            }
            queue.push_back(current->right);
        }
        insert(values, i + 1);
        return this;
    }
};

void calcuBrandSum(BinaryTree* root, int count, vector<int>& sums);
vector<int> branchSums(BinaryTree* root);


int main()
{
    TestBinaryTree* tree = new TestBinaryTree(1);
    tree->insert({ 2, 3, 4, 5, 6, 7, 8, 9, 10 });
    vector<int> expected = { 15, 16, 18, 10, 11 };
    vector<int> end = branchSums(tree);
    for (int i = 0; i < end.size();i++)
    {
        cout << end[i] << " ";
    }
    return 0;
}


vector<int> branchSums(BinaryTree* root) {
    // Write your code here.
    vector<int> sums;
    calcuBrandSum(root, 0, sums);
    return sums;
}

void calcuBrandSum(BinaryTree* root, int count, vector<int>& sums)
{
    if (root == nullptr)
    {
        return;
    }

    int curntsum = count + root->value;


    if (root->right == nullptr && root->left == nullptr)
    {
        sums.push_back(curntsum);
        return;
    }

    calcuBrandSum(root->left, curntsum, sums);
    calcuBrandSum(root->right, curntsum, sums);
}