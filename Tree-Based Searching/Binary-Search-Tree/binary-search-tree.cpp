#include <iostream>
#include <memory>
#include <vector>
#include <queue>
#include <optional>
#include <cassert>
#include <algorithm>
#include <limits>

template<typename T>
class BinarySearchTree {
private:
    struct Node {
        T data;
        std::unique_ptr<Node> left;
        std::unique_ptr<Node> right;

        explicit Node(const T& value)
            : data(value) {}
    };

    std::unique_ptr<Node> root;
    std::size_t nodeCount{0};

private:
    bool insert(std::unique_ptr<Node>& node, const T& value) {
        if (!node) {
            node = std::make_unique<Node>(value);
            ++nodeCount;
            return true;
        }

        if (value < node->data)
            return insert(node->left, value);

        if (value > node->data)
            return insert(node->right, value);

        return false;
    }

    bool contains(const Node* node, const T& value) const {
        if (!node) return false;

        if (value < node->data)
            return contains(node->left.get(), value);

        if (value > node->data)
            return contains(node->right.get(), value);

        return true;
    }

    Node* search(Node* node, const T& value) const {
        if (!node) return nullptr;

        if (value < node->data)
            return search(node->left.get(), value);

        if (value > node->data)
            return search(node->right.get(), value);

        return node;
    }

    const Node* minNode(const Node* node) const {
        if (!node) return nullptr;

        while (node->left)
            node = node->left.get();

        return node;
    }

    const Node* maxNode(const Node* node) const {
        if (!node) return nullptr;

        while (node->right)
            node = node->right.get();

        return node;
    }

    bool remove(std::unique_ptr<Node>& node, const T& value) {
        if (!node)
            return false;

        if (value < node->data)
            return remove(node->left, value);

        if (value > node->data)
            return remove(node->right, value);

        if (!node->left && !node->right) {
            node.reset();
        }
        else if (!node->left) {
            node = std::move(node->right);
        }
        else if (!node->right) {
            node = std::move(node->left);
        }
        else {
            const Node* successor = minNode(node->right.get());
            node->data = successor->data;
            remove(node->right, successor->data);
            return true;
        }

        --nodeCount;
        return true;
    }

    std::size_t height(const Node* node) const {
        if (!node)
            return 0;

        return 1 + std::max(
            height(node->left.get()),
            height(node->right.get())
        );
    }

    void clear(std::unique_ptr<Node>& node) {
        if (!node)
            return;

        clear(node->left);
        clear(node->right);
        node.reset();
    }

    void inorder(const Node* node, std::vector<T>& result) const {
        if (!node) return;

        inorder(node->left.get(), result);
        result.push_back(node->data);
        inorder(node->right.get(), result);
    }

    void preorder(const Node* node, std::vector<T>& result) const {
        if (!node) return;

        result.push_back(node->data);
        preorder(node->left.get(), result);
        preorder(node->right.get(), result);
    }

    void postorder(const Node* node, std::vector<T>& result) const {
        if (!node) return;

        postorder(node->left.get(), result);
        postorder(node->right.get(), result);
        result.push_back(node->data);
    }

    bool validate(
        const Node* node,
        const std::optional<T>& min,
        const std::optional<T>& max
    ) const {
        if (!node)
            return true;

        if (min && node->data <= *min)
            return false;

        if (max && node->data >= *max)
            return false;

        return validate(node->left.get(), min, node->data) &&
               validate(node->right.get(), node->data, max);
    }

    void prettyPrint(
        const Node* node,
        const std::string& prefix,
        bool isLeft
    ) const {
        if (!node)
            return;

        std::cout << prefix;

        std::cout << (isLeft ? "├── " : "└── ");

        std::cout << node->data << '\n';

        prettyPrint(
            node->left.get(),
            prefix + (isLeft ? "│   " : "    "),
            true
        );

        prettyPrint(
            node->right.get(),
            prefix + (isLeft ? "│   " : "    "),
            false
        );
    }

public:
    BinarySearchTree() = default;

    ~BinarySearchTree() {
        clear();
    }

    bool insert(const T& value) {
        return insert(root, value);
    }

    bool remove(const T& value) {
        return remove(root, value);
    }

    bool contains(const T& value) const {
        return contains(root.get(), value);
    }

    std::optional<T> search(const T& value) const {
        Node* node = search(root.get(), value);

        if (!node)
            return std::nullopt;

        return node->data;
    }

    bool update(const T& oldValue, const T& newValue) {
        if (!contains(oldValue))
            return false;

        if (oldValue != newValue &&
            contains(newValue))
            return false;

        remove(oldValue);
        insert(newValue);

        return true;
    }

    void clear() {
        clear(root);
        root.reset();
        nodeCount = 0;
    }

    bool empty() const {
        return nodeCount == 0;
    }

    std::size_t size() const {
        return nodeCount;
    }

    std::size_t height() const {
        return height(root.get());
    }

    std::optional<T> min() const {
        const Node* node = minNode(root.get());

        if (!node)
            return std::nullopt;

        return node->data;
    }

    std::optional<T> max() const {
        const Node* node = maxNode(root.get());

        if (!node)
            return std::nullopt;

        return node->data;
    }

    std::vector<T> inorder() const {
        std::vector<T> result;
        inorder(root.get(), result);
        return result;
    }

    std::vector<T> preorder() const {
        std::vector<T> result;
        preorder(root.get(), result);
        return result;
    }

    std::vector<T> postorder() const {
        std::vector<T> result;
        postorder(root.get(), result);
        return result;
    }

    std::vector<T> levelOrder() const {
        std::vector<T> result;

        if (!root)
            return result;

        std::queue<Node*> q;
        q.push(root.get());

        while (!q.empty()) {
            Node* current = q.front();
            q.pop();

            result.push_back(current->data);

            if (current->left)
                q.push(current->left.get());

            if (current->right)
                q.push(current->right.get());
        }

        return result;
    }

    bool validate() const {
        return validate(root.get(), std::nullopt, std::nullopt);
    }

    void prettyPrint() const {
        if (!root) {
            std::cout << "Tree is empty\n";
            return;
        }

        std::cout << root->data << '\n';

        prettyPrint(root->left.get(), "", true);
        prettyPrint(root->right.get(), "", false);
    }
};

template<typename T>
void printVector(const std::vector<T>& values) {
    for (const auto& value : values)
        std::cout << value << ' ';
    std::cout << '\n';
}

int main() {
    BinarySearchTree<int> bst;

    bst.insert(50);
    bst.insert(30);
    bst.insert(70);
    bst.insert(20);
    bst.insert(40);
    bst.insert(60);
    bst.insert(80);

    assert(bst.size() == 7);
    assert(bst.contains(50));
    assert(bst.contains(30));
    assert(!bst.contains(999));

    assert(bst.min().value() == 20);
    assert(bst.max().value() == 80);

    assert(bst.validate());

    std::cout << "\nBST Structure\n";
    bst.prettyPrint();

    std::cout << "\nInorder: ";
    printVector(bst.inorder());

    std::cout << "Preorder: ";
    printVector(bst.preorder());

    std::cout << "Postorder: ";
    printVector(bst.postorder());

    std::cout << "Level Order: ";
    printVector(bst.levelOrder());

    bst.update(60, 65);
    assert(bst.contains(65));

    bst.remove(20);
    bst.remove(70);

    assert(!bst.contains(20));
    assert(bst.validate());

    std::cout << "\nAfter Deletion\n";
    bst.prettyPrint();

    std::cout << "\nAll BST self-tests passed successfully.\n";

    return 0;
}
