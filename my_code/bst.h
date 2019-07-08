//#include <iostream>
//
//void indent(int level) {
//    // indent more at each level:
//    for (int i = 0; i < level; i++) std::cout << "  ";
//}
//
//template <typename T>
//class Bst {
//    friend void print_bst(const Bst<T>& bst, int level=0) {
//        indent(level);
//        level++;
//
//        std::cout << "data: " << bst.data << std::endl;
//        indent(level + 1);
//        std::cout << "left: ";
//
//        if (!bst.left) std::cout << "nullptr\n";
//        else {
//            std::cout << "\n";
//            indent(level);
//            print_bst(*bst.left, level);
//        }
//        indent(level + 1);
//        std::cout << "right: ";
//        if (!bst.right) std::cout << "nullptr\n";
//        else {
//            std::cout << "\n";
//            indent(level);
//            print_bst(*bst.right, level);
//        }
//        std::cout << std::endl;
//    }
//
//    public:
//        Bst(T d, Bst* p=nullptr, Bst* l=nullptr, Bst* r=nullptr)
//            : data(d), parent(p), left(l), right(r) {}
//
//        Bst<T>* insert(const T d) {
//            if (d < data) {
//                if (!left) {
//                    left = new Bst(d, this);
//                    return this;
//                }
//                else {
//                    return left->insert(d);
//                }
//            }
//            else {
//                if (!right) {
//                    right = new Bst(d, this);
//                    return this;
//                }
//                else {
//                    return right->insert(d);
//                }
//            }
//        }
//
//        Bst<T>* search(const T d) {
//            if (data == d) return this;
//            if (data < d) {
//                if (!right) return nullptr;
//                return right->search(d);
//            }
//            if (!left) return nullptr;
//            return left->search(d);
//        }
//
//        T get_val() const {
//            return data;
//        }
//
//    private:
//        T data;
//        Bst* parent;
//        Bst* left;
//        Bst* right;
//};
//

#include <iostream>

void indent(int level) {
    // indent more at each level:
    for (int i = 0; i < level; i++) std::cout << "  ";
}

template <typename T>
class Bst {
    friend void print_bst(const Bst<T>& bst, int level=0) {
        indent(level);
        level++;
        
        std::cout << "data: " << bst.data << std::endl;
        indent(level + 1);
        std::cout << "left: ";
        
        if (!bst.left) std::cout << "nullptr\n";
        else {
            std::cout << "\n";
            indent(level);
            print_bst(*bst.left, level);
        }
        indent(level + 1);
        std::cout << "right: ";
        if (!bst.right) std::cout << "nullptr\n";
        else {
            std::cout << "\n";
            indent(level);
            print_bst(*bst.right, level);
        }
        std::cout << std::endl;
    }
    
public:
    Bst(T d, Bst* p=nullptr, Bst* l=nullptr, Bst* r=nullptr)
    : data(d), parent(p), left(l), right(r) {}
    
    Bst<T>* search(T value){
        if(value < data){
            if(left == nullptr) return nullptr;
            else return left->search(value);
        }
        else if (value > data){
            if(right == nullptr) return nullptr;
            else return right->search(value);
        }
        else return this;
    }
    
    Bst<T>* insert(const T d) {
        if(d < this->data){
            if(this->left == nullptr) this->left = new Bst<T>(d, this);
            else this->left->insert(d);
        } else if (d > this->data) {
            if(this->right == nullptr) this->right = new Bst<T>(d, this);
            else this->right->insert(d);
        }
        return this;
    }
    
    T& min(){
        if (this->left == nullptr){
            return this->data;
        }
        return this->left->min();
    }
    
    T& max(){
        if (this->right == nullptr){
            return this->data;
        }
        return this->right->max();
    }
    
    T get_val() const {
        return data;
    }
    
    Bst<T>* predecessor(T d) {
        Bst<T>* curr = search(d);
        if (curr->left) {
            curr = curr->left;
            while (curr->right != nullptr) curr = curr->right;
            return curr;
        }
        else if (curr->parent) {
            while ((curr->parent)->data > curr->data) {
                curr = curr->parent;
            }
            return curr->parent;
        }
        else return nullptr;
    }
    
    
    Bst<T>* successor(T d){
        Bst<T>* curr = search(d);
        if(curr->right) {
            curr = curr->right;
            while (curr->left != nullptr) curr = curr->left;
            return curr;
        }
        while (curr->parent != nullptr) {
            if(curr->parent->data > d) break;
            curr = curr->parent;
        }
        return curr->parent;
    }
    
private:
    T data;
    Bst* parent;
    Bst* left;
    Bst* right;
};
