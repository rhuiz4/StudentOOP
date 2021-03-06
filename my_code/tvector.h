//
//  tvec.h
//  test
//
//  Created by Rihui Zheng on 6/26/19.
//  Copyright © 2019 Rihui Zheng. All rights reserved.
//

//#ifndef tvec_h
//#define tvec_h
//
//const int DEF_CAPACITY = 10;
//const int CAPACITY_MULT = 2;
//
//template <typename T>
//class Iterator {
//    /*
//     * This class supports ranged for loops.
//     * It includes:
//     * Iterator(T*)
//     * operator++
//     * operator*
//     * operator!=
//     * */
//    friend bool operator!=(Iterator& rhs, Iterator& lhs) {
//        return rhs.tptr == lhs.tptr;
//    }
//
//public:
//    Iterator(T* tp) : tptr(tp) {}
//
//    Iterator& operator++() {
//        tptr++;
//        return *this;
//    }
//
//    T operator*() { return *tptr; }
//
//private:
//    T* tptr;
//};
//
//
//template <typename T>
//class MyVec {
//public:
//    MyVec() : sz(0), capacity(DEF_CAPACITY) {
//        data = new T[DEF_CAPACITY];
//    }
//
//
//    MyVec(int sz, T val) : sz{sz} {
//        capacity = sz * 2;
//        data = new T[capacity];
//        for (int i = 0; i < sz; i++) {
//            data[i] = val;
//        }
//    }
//
//    // copy control:
//    MyVec(const MyVec<T>& v2) {
//        copy(v2);
//    }
//
//    ~MyVec() { delete [] data; }
//
//    MyVec& operator=(const MyVec& v2) {
//        if (this != &v2) {
//            delete [] data;
//            copy(v2);
//        }
//        return *this;
//    }
//
//    /*
//     * Puts an element at the back of a vector.
//     * */
//    void push_back(T val) {
//        sz++;
//        if (sz > capacity) {
//            std::cout << "\n**** Increasing capacity ****\n";
//            T* old_data = data;
//            data = new T[capacity * CAPACITY_MULT];
//            for (int i = 0; i < sz; i++) {
//                data[i] = old_data[i];
//            }
//            capacity *= CAPACITY_MULT;
//            delete [] old_data;
//        }
//        data[sz - 1] = val;
//    }
//
//    int size() const { return sz; }
//
//    T operator[](int i) const {
//        return data[i];
//    }
//
//    T& operator[](int i) {
//        return data[i];
//    }
//
//    Iterator<T> begin() const { return Iterator<T>(data); }
//    Iterator<T> end() const { return Iterator<T>(data + size()); }
//
//private:
//    void copy(const MyVec<T>& v2) {
//        sz = v2.sz;
//        capacity = v2.capacity;
//        data = new T[capacity];
//        for (int i = 0; i < sz; i++) {
//            data[i] = v2.data[i];
//        }
//    }
//
//    T* data;
//    int sz;
//    int capacity;
//};
//
//
//template <typename T>
//void print_vector(const MyVec<T>& v) {
//    for (int i = 0; i < v.size(); i++)
//        std::cout << v[i] << ", ";
//    std::cout << std::endl;
//}
//
//template <typename T>
//bool operator==(MyVec<T>& v1, MyVec<T>& v2) {
//    if (v1.size() != v2.size()) return false;
//
//    for(int i = 0; i < v1.size(); i++) {
//        if (v1[i] != v2[i]) return false;
//    }
//    return true;
//}
//
//#endif /* tvec_h */


#ifndef tvector_h
#define tvector_h

const int DEF_CAPACITY = 10;
const int CAPACITY_MULT = 2;
using namespace std;

template <typename T>
class MyVec {
public:
    
    MyVec(){
        sz = 0;
        capacity = DEF_CAPACITY;
        data = new int[DEF_CAPACITY];
    }
    
    MyVec(int sz, T val=T()): sz(sz) {
        capacity = sz;
        data = new T[capacity];
        for(int i = 0; i < sz; ++i){
            data[i] = val;
        }
    }
    
    // copy control:
    MyVec(const MyVec& v2){
        copy(v2);
    }
    ~MyVec() { delete [] data; }
    
    MyVec& operator=(const MyVec& v2){
        copy(v2);
        return *this;
    }
    
    void push_back(T val){
        if (sz == capacity){
            // get new array of capacity*2 and copy over old data, delete old array
            capacity *= 2;
            int* new_data = new int[capacity];
            // coping old data
            for (int i = 0; i < size(); i++){
                new_data[i] = data[i];
            }
            // delete old array
            delete[] data;
            
            // set ptr to new array
            data = new_data;
            
        }
        data[sz++] = val;
    }
    
    int size() const { return sz; }
    
    T operator[](int i) const {
        return data[i];
    }
    T& operator[](int i){
        return data[i];
    }
    
    
private:
    void copy(const MyVec& v2) {
        sz = v2.sz;
        capacity = v2.capacity;
        data = new T[capacity];
        for (int i = 0; i < sz; i++) {
            data[i] = v2.data[i];
        }
    }
    
    T* data;
    int sz;
    int capacity;
};

template <typename T>
void print_vector(const MyVec<T>& v){
    for(int i = 0; i < v.size(); ++i){
        cout << v[i] << endl;
    }
}

template <typename T>
bool operator==(MyVec<T>& v1, MyVec<T>& v2){
    if(v1.size()!=v2.size()) return false;
    else{
        for(int i = 0; i < v1.size();++i){
            if(v1[i]!= v2[i]) return false;
        }
    }
    return true;
}




#endif /* tvector_h */
