//#include <iostream>
//#include "llist.h"
//
//using namespace std;
//
//
//
///*
// * Output a Node pointer.
// * */
//ostream& operator<<(ostream& os, const Node* nd) {
//    os << nd->data;
///*
//    if (!nd) os << "nullptr";
//    else {
//        os << "data: " << nd->data << " next: ";
//    }
//*/
//    return os;
//}
//
//
///*
// * Add a node to the end of a list.
// * */
//void add_at_end(Node*& head, int d) {
//    if (!head) head = new Node(d, nullptr);
//    else if (!head->next) head->next = new Node(d, nullptr);
//    else add_at_end(head->next, d);
//}
//
//
///*
// * Given the head of a list, print the whole thing.
// * Let's do this recursively!
// * */
//
//void print_list(ostream& os, const Node* curr) {
//    if (!curr) os << "NULLPTR\n";
//    else {
//        os << curr->data << " --> ";
//        print_list(os, curr->next);
//    }
//}
//
//
///*
// * Add a node at the front of a linked list.
// * */
//void add_at_front(Node*& head, int d) {
//    head = new Node(d, head);
//}
//
//
///*
// * Get the last node of a list.
// * */
//Node* last(Node* head) {
//    if (!head) return nullptr;
//    else if (!head->next) return head;
//    else return last(head->next);
//}
//
//
///*
// * Delete the first node and set head to firstnode->next.
// * De-allocate the memory for the node deleted.
// * */
//bool del_head(Node*& head) {
//    if (!head) return false;
//    else {
//        Node* temp = head;
//        head = head->next;
//        delete temp;
//        return true;
//    }
//}
//
//
///*
// * Delete the last node and set prev->next to nullptr.
// * De-allocate the memory for the node deleted.
// * */
//bool del_tail(Node*& curr) {
//    if (!curr) return false;
//    else {
//        if (curr->next == nullptr) {
//            delete curr;
//            curr = nullptr;
//            return true;
//        }
//        else {
//            return del_tail(curr->next);
//        }
//    }
//}
//
//
///*
// * Duplicate the entire list -- you must not share memory!
// * */
//Node* duplicate(Node* head) {
//    if (!head) {return nullptr;}
//    return new Node(head->data, duplicate(head->next));
//}
//
///*
// * Reverse the list: return a brand new list with everything reversed.
// * Once again, you must not share memory.
// * */
//Node* reverse(Node* curr, Node* new_next) {
//    if (!curr) return new_next;
//    else {
//        return reverse(curr->next, new Node(curr->data, new_next));
//    }
//}
//
//Node* join(Node*& list1, Node* list2) {
//    if (!list1) list1 = list2;
//    else last(list1)->next = list2;
//    return list1;
//}
//

#include <iostream>
#include "llist.h"

using namespace std;



/*
 * Output a Node pointer.
 * */
ostream& operator<<(ostream& os, const Node* nd) {
    if (!nd) os << "nullptr";
    else{
        os << "data: "<< nd->data << "\t";// << " next: "<< nd->next ;
    }
    return os;
}


/*
 * Add a node to the end of a list.
 * */
void add_at_end(Node*& head, int d) {
    if (!head){
        head = new Node(d,nullptr);
    }
    
    else{
        add_at_end(head->next, d);
    }
}


/*
 * Given the head of a list, print the whole thing.
 * Let's do this recursively!
 * */
void print_list(ostream& os, const Node* head) {
    os << head;
    if (head) print_list(os, head->next);
}

/*
 * Add a node at the front of a linked list.
 * */
void add_at_front(Node*& head, int d) {
    head = new Node (d, head);
}


/*
 * Get the last node of a list.
 * */
Node* last(Node* head) {
    if (!head) return nullptr;
    else if (!head->next) return head;
    else return last(head->next);
};




/*
 * Delete the first node and attach head to the 2nd node:
 * */
bool del_head(Node*& head){
    if (!head) return false;
    else{
        Node* temp = head;
        head = head->next;
        delete temp;
        return true;
    }
}

/*
 * Delete the last node and set prev->next to nullptr:
 * */
bool del_tail(Node*& curr){
    if (!curr) return false;
    else{
        if (curr->next == nullptr){
            delete curr;
            curr = nullptr;
            return true;
        }
        else{
            return del_tail(curr->next);
        }
        
    }
}

/*
 * Duplicate the entire list -- you must not share memory!
 * */
Node* duplicate(Node* head){
    if (!head) return nullptr;
    else{
        return new Node(head->data,duplicate(head->next));
    }
}

/*
 * Reverse the list: return a brand new list with everything reversed.
 * */
Node* reverse(Node* curr, Node* new_next){
    if (!curr) return new_next;
    else{
        return reverse(curr->next, new Node(curr->data,new_next));
    }
}

/*
 * Join two lists: tack list 2 onto the end of list 1:
 * Use existing memory.
 * */
Node* join(Node*& list1, Node* list2){
    last(list1)-> next = list2;
    return list1;
}
