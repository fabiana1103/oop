#include <iostream>
#include <cmath> 

constexpr float operator"" _Kelvin(unsigned long long k) {
    return static_cast<float>(k - 273.15);
}
constexpr float operator"" _Kelvin(long double k) {
    return static_cast<float>(k - 273.15);
}
constexpr float operator"" _Fahrenheit(unsigned long long f) {
    return static_cast<float>((f - 32) * 5.0 / 9.0);
}
constexpr float operator"" _Fahrenheit(long double f) {
    return static_cast<float>((f - 32) * 5.0 / 9.0);
}

template <typename T>
class Tree {
public:
    struct Node {
        T value;
        Node** children;
        int children_count;
        int children_capacity;

        Node(T val) : value(val), children(nullptr), children_count(0), children_capacity(0) {}

        ~Node() {
            delete[] children;
        }

        void resize_if_needed() {
            if (children_count == children_capacity) {
                if (children_capacity == 0) {
                    children_capacity = 2;
                }
                else {
                    children_capacity = children_capacity * 2;
                }

                Node** new_children = new Node * [children_capacity];
                for (int i = 0; i < children_count; i++)
                    new_children[i] = children[i];
                delete[] children;
                children = new_children;
            }
        }
    };

private:
    Node* root;

public:
    Tree() : root(nullptr) {}

    Node* add_node(Node* parent, T value) {
        Node* new_node = new Node(value);
        if (parent == nullptr)
            root = new_node;
        else {
            parent->resize_if_needed();
            parent->children[parent->children_count++] = new_node;
        }
        return new_node;
    }

    Node* get_node(Node* parent) {
        if (parent == nullptr)
            return root;
        return parent;
    }

    void delete_node(Node* node) {
        if (node == nullptr) return;
        for (int i = 0; i < node->children_count; i++)
            delete_node(node->children[i]);
        if (node == root) root = nullptr;
        delete node;
    }

    Node* find(Node* current, T parameter, bool (*compare)(T, T)) {
        if (current == nullptr) return nullptr;
        if (compare(current->value, parameter))
            return current;
        for (int i = 0; i < current->children_count; i++) {
            Node* result = find(current->children[i], parameter, compare);
            if (result != nullptr) return result;
        }
        return nullptr;
    }

    Node* insert(Node* parent, int index, T value) {
        if (parent == nullptr || index < 0 || index > parent->children_count) return nullptr;
        parent->resize_if_needed();
        Node* new_node = new Node(value);
        for (int i = parent->children_count; i > index; i--)
            parent->children[i] = parent->children[i - 1];
        parent->children[index] = new_node;
        parent->children_count++;
        return new_node;
    }

    void sort(Node* node, bool (*compare)(T, T) = nullptr) {
        if (node == nullptr) return;
        for (int i = 0; i < node->children_count - 1; i++)
            for (int j = i + 1; j < node->children_count; j++) {
                bool ok = false;
                if (compare != nullptr)
                    ok = compare(node->children[j]->value, node->children[i]->value);
                else
                    ok = node->children[j]->value < node->children[i]->value;
                if (ok) {
                    Node* temp = node->children[i];
                    node->children[i] = node->children[j];
                    node->children[j] = temp;
                }
            }
    }

    int count(Node* node) {
        if (node == nullptr)
            node = root;
        if (node == nullptr) return 0;
        int total = 1;
        for (int i = 0; i < node->children_count; i++)
            total = total + count(node->children[i]);
        return total;
    }
};

bool compare_temperatures(float node_val, float param) {
    return std::abs(node_val - param) < 0.01f;
}

bool compare_descending(float a, float b) {
    return a > b;
}

int main()
{
    float a = 300_Kelvin;
    float b = 120_Fahrenheit;

    std::cout << "300 kelvin in celsius: " << a << '\n';
    std::cout << "120 fahrenheit in celsius: " << b << '\n';

    Tree<float> myTree;
    auto root = myTree.add_node(nullptr, a);
    myTree.add_node(root, b);
    myTree.add_node(root, 0_Kelvin);
    myTree.insert(root, 1, 100.0f);

    std::cout << "nr total noduri arbore: " << myTree.count(nullptr) << '\n';

    auto foundNode = myTree.find(root, b, compare_temperatures);
    if (foundNode) {
        std::cout << "am gasit nodul cu valoarea: " << foundNode->value << '\n';
    }

    myTree.sort(root);
    std::cout << "\ncopiii radacinii dupa sortare crescatoare:\n";
    for (int i = 0; i < root->children_count; i++) {
        std::cout << root->children[i]->value << "\n";
    }

    myTree.sort(root, compare_descending);
    std::cout << "\ncopiii radacinii dupa sortare descrescatoare:\n";
    for (int i = 0; i < root->children_count; i++) {
        std::cout << root->children[i]->value << "\n";
    }

    myTree.delete_node(root);
    return 0;
}