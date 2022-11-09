#include <vector>
#include <iostream>
#include <limits>
#include <utility>

using namespace std;

class SplayTree
{
private:
    struct Node;
    mutable Node * root = nullptr;
    std::size_t length = 0;

    static void rotate(Node * val);
    static void setParent(Node * child, Node * parent);
    static void keepParent(Node * v);
    static Node * createSubTree(Node *& vLink);
    Node * splay(Node * v) const;
    Node * find(Node * v, int key) const;
    static void inorderTraversal(const Node * x, std::vector<int> & vec);
    static void calcSize(Node * v);

public:
    bool contains(int value) const;
    int findMax(int k) const;
    bool insert(int value);
    bool remove(int value);

    std::size_t size() const;
    bool empty() const;

    std::vector<int> values() const;

    ~SplayTree();
};

struct SplayTree::Node
{
    Node * parent = nullptr;
    Node * left;
    Node * right;
    int value;
    int sz = 1;
    Node(int v, Node * l, Node * r)
            : left(l)
            , right(r)
            , value(v)
    {
    }
};

void SplayTree::calcSize(Node * v) {
    if (v == nullptr) return;
    v->sz = 1;
    if (v->left != nullptr) {
        v->sz += v->left->sz;
    }
    if (v->right != nullptr) {
        v->sz += v->right->sz;
    }
}

void SplayTree::setParent(Node * child, Node * parent)
{
    if (child != nullptr) {
        child->parent = parent;
    }
}

void SplayTree::keepParent(Node * v)
{
    setParent(v->left, v);
    setParent(v->right, v);
}

void SplayTree::inorderTraversal(const Node * x, std::vector<int> & vec)
{
    if (x != nullptr) {
        inorderTraversal(x->left, vec);
        vec.push_back(x->value);
        inorderTraversal(x->right, vec);
    }
}

std::vector<int> SplayTree::values() const
{
    std::vector<int> vec;
    vec.reserve(length);
    inorderTraversal(this->root, vec);
    return vec;
}

std::size_t SplayTree::size() const
{
    return length;
}

bool SplayTree::empty() const
{
    return length == 0;
}

SplayTree::Node * SplayTree::find(Node * v, int key) const
{
    while (v != nullptr) {
        if (key < v->value && v->left != nullptr) {
            v = v->left;
        }
        else if (key > v->value && v->right != nullptr) {
            v = v->right;
        }
        else {
            return splay(v);
        }
    }
    return nullptr;
}

int SplayTree::findMax(int k) const
{
    Node * v = root;
    while (v != nullptr) {
        int vRightSize = 0;
        if (v->right != nullptr) vRightSize = v->right->sz;
        if (k <= vRightSize) {
            v = v->right;
        } else if (k == vRightSize + 1) {
            splay(v);
            return v->value;
        } else if (k > vRightSize + 1){
            k = k - vRightSize - 1;
            v = v->left;
        } else {
            cout << "ERROR!";
            break;
        }
    }
    return 0;
}


bool SplayTree::contains(int value) const
{
    return root != nullptr && find(this->root, value)->value == value;
}

SplayTree::Node * SplayTree::createSubTree(Node *& vLink)
{
    setParent(vLink, nullptr);
    return std::exchange(vLink, nullptr);
}

bool SplayTree::insert(int key)
{
    if (contains(key)) {
        return false;
    }
    if (root == nullptr) {
        root = new Node(key, nullptr, nullptr);
    }
    else if (key < root->value) {
        root = new Node(key, createSubTree(root->left), root);
    }
    else {
        root = new Node(key, root, createSubTree(root->right));
    }
    keepParent(root);
    calcSize(root);
    length++;
    return true;
}

bool SplayTree::remove(int val)
{
    if (!contains(val)) {
        return false;
    }
    Node * leftR = root->left;
    Node * rightR = root->right;
    setParent(rightR, nullptr);
    setParent(leftR, nullptr);
    delete root;
    if (rightR == nullptr) {
        root = leftR;
        calcSize(root);
    }
    else if (leftR == nullptr) {
        root = rightR;
        calcSize(root);
    }
    else {
        rightR = find(rightR, leftR->value);
        rightR->left = leftR;
        leftR->parent = rightR;
        calcSize(rightR);
    }
    length--;
    return true;
}

void SplayTree::rotate(Node * val)
{
    bool leftSon = val->parent->left == val;
    Node *& valLink = leftSon ? val->parent->left : val->parent->right;
    Node *& sonLink = leftSon ? valLink->right : valLink->left;
    val = val->parent;
    Node * son = valLink;
    Node * par = val->parent;
    if (par != nullptr) {
        (par->left == val ? par->left : par->right) = son;
    }
    valLink = sonLink;
    sonLink = val;
    setParent(val, son);
    setParent(son, par);
    setParent(valLink, val);
    calcSize(val);
    calcSize(son);
    calcSize(par);
}

SplayTree::Node * SplayTree::splay(Node * val) const
{
    while (val->parent != nullptr) {
        if (val->parent->parent != nullptr && val->parent == val->parent->parent->left) {
            rotate(val->parent);
        }
        else if (val->parent->parent != nullptr) {
            rotate(val);
        }
        rotate(val);
    }
    root = val;
    calcSize(root);
    return val;
}

SplayTree::~SplayTree()
{
    while (root != nullptr) {
        remove(find(root, std::numeric_limits<int>::min())->value);
    }
}

int main()
{
    SplayTree tree;
    int n, a, b;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        if (a == 1) {
            tree.insert(b);
        } else if (a == 0) {
            cout << tree.findMax(b) << '\n';
        } else if (a == -1) {
            tree.remove(b);
        }
    }
}
