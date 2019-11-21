#ifndef LLRBT_H_
#define LLRBT_H_

#include <iostream>
#define RED true
#define BLACK false
#define COUNT 10

template <typename T>
struct Node {
    T key;
    Node *left, *right;
    size_t N;
    bool color;
    Node(T k) : key(k), left(0), right(0), N(1), color(RED) { }
    ~Node() { delete left; delete right; }
};

template <typename T>
class LLRBT
{
private:
    Node<T> *root = nullptr;
protected:
    Node<T>* insertUtil(Node<T> *x, const T key);
    Node<T>* removeUtil(Node<T> *x, const T key);
    Node<T>* rotate_left(Node<T> *x);
    Node<T>* rotate_right(Node<T> *x);
    Node<T>* FixUp(Node<T> *x);
    Node<T>* removeMin(Node<T> *x);
    void flip_color(Node<T> *x);
    size_t size(const Node<T> *x) const;
    bool is_red(const Node<T> *x) const;
    static void print2DUtil(const Node<T> *root, int space_count);
public:
    LLRBT();
    ~LLRBT();

    void insert(const T key);
    void remove(const T key);

    void print() const;
};

template <typename T>
LLRBT<T>::LLRBT()
{
}

template <typename T>
LLRBT<T>::~LLRBT()
{
    delete root;
}

template <typename T>
void LLRBT<T>::insert(const T key) {
    if (root) root->color = BLACK;
    root = insertUtil(root, key);
}

template <typename T>
Node<T>* LLRBT<T>::insertUtil(Node<T> *x, const T key) {
    if (!x) return new Node<T>(key);
    if (key < x->key) x->left = insertUtil(x->left, key);
    else if (key > x->key) x->right = insertUtil(x->right, key);
    ++x->N;
    if (is_red(x->right) && !is_red(x->left)) x = rotate_left(x);
    if (is_red(x->left) && is_red(x->left->left)) x = rotate_right(x);
    if (is_red(x->left) && is_red(x->right)) flip_color(x);
    return x;
}

template <typename T>
void LLRBT<T>::remove(const T key) {
    if (root) root->color = BLACK;
    root = removeUtil(root, key);
}

template <typename T>
Node<T>* LLRBT<T>::removeUtil(Node<T> *x, const T key) {
    if (key < x->key) {
        if (NULL != x->left) {
            if ((false == is_red(x->left)) && (false == is_red(x->left->left))) {
                flip_color(x);
                if ((NULL != x->right) && is_red(x->right->left)) {
                    x->right = rotate_right(x->right);
                    x = rotate_left(x);

                    flip_color(x);
                }
            }
            x->left = removeUtil(x->left, key);
        }
    }
    else {
        if (is_red(x->left)) {
            x = rotate_right(x);
        }
        if ((key == x->key) &&
            (NULL == x->right))
        {
            delete x;
            return NULL;
        }
        if (NULL != x->right) {
            if ((false == is_red(x->right)) && (false == is_red(x->right->left)))
            {
                flip_color(x);
                if ((NULL != x->left) && is_red(x->left->left)) {
                    x = rotate_right(x);
                    flip_color(x);
                }
            }
            if (key == x->key) {
                x->right = removeMin(x->right);
            }
            else {
                x->right = removeUtil(x->right, key);
            }
        }
    }

    return FixUp(x);
}

template <typename T>
Node<T>* LLRBT<T>::FixUp(Node<T> *x) {
    if (is_red(x->right))
        x = rotate_left(x);
    
    if (is_red(x->left) && is_red(x->left->left))
        x = rotate_right(x);
    
    if (is_red(x->left) && is_red(x->right))
        flip_color(x);

    return x;
}

template <typename T>
Node<T>* LLRBT<T>::removeMin(Node<T> *x) {
    if (NULL == x->left) {
        delete x;
        return NULL;
    }

    if ((false == is_red(x->left)) && (false == is_red(x->left->left))) {
        flip_color(x);

        if ((NULL != x->right) && is_red(x->right->left)) {
            x->right = rotate_right(x->right);
            x = rotate_left(x);

            flip_color(x);
        }
    }

    x->left = removeMin(x->left);

    return FixUp(x);
}

template <typename T>
Node<T>* LLRBT<T>::rotate_left(Node<T> *x) {
    auto y = x->right;
    size_t x_lt = size(x) - size(x->right);
    x->N = x->N - size(y) + size(y->left);
    y->N += x_lt;
    y->color = x->color;
    x->color = RED;
    x->right = y->left;
    y->left = x;
    return y;
}

template <typename T>
Node<T>* LLRBT<T>::rotate_right(Node<T> *x) {
    auto y = x->left;
    size_t x_rt = size(x) - size(x->left);
    x->N = x->N - size(y) + size(y->right);
    y->N += x_rt;
    y->color = x->color;
    x->color = RED;
    x->left = y->right;
    y->right = x;
    return y;
}

template <typename T>
void LLRBT<T>::flip_color(Node<T> *x) {
    x->color = !x->color;

    if (NULL != x->left) {
        x->left->color  = !x->left->color;
    }

    if (NULL != x->right) {
        x->right->color = !x->right->color;
    }
}

template <typename T>
size_t LLRBT<T>::size(const Node<T> *x) const {
    return x ? x->N : 0;
}

template <typename T>
bool LLRBT<T>::is_red(const Node<T> *x) const {
    return x ? x->color : false;
}

template <typename T>
void LLRBT<T>::print2DUtil (const Node<T> *root, int space_count) {
    // Base case  
    if (root == NULL)  
        return;
  
    // Increase distance between levels  
    space_count += COUNT;  
  
    // Process right child first  
    print2DUtil(root->right, space_count);  
  
    // Print current node after space_count  
    // count  
    std::cout << "\n";

    for (int i = COUNT; i < space_count - (2*root->color); i++)  
        std::cout << " ";
    if (root->color)
        std::cout << "[ " << root->key << " ]\n";
    else
        std::cout << root->key << "\n";
  
    // Process left child  
    print2DUtil(root->left, space_count);
}

template <typename T>
void LLRBT<T>::print () const {
    print2DUtil(root, 0);
}

#endif//LLRBT_H_