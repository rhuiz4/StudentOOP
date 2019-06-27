#ifndef vector_h
#define vector_h
const int DEF_CAPACITY = 10;
const int CAPACITY_MULT = 2;

class MyVec {
public:
        class Iterator {
        /*
         * This class supports ranged for loops.
         * It includes:
         * Iterator(int*)
         * operator++
         * operator*
         * operator!=
         * */
            friend bool operator!=(Iterator& rhs, Iterator& lhs) {
                return rhs.iptr != lhs.iptr;
            }

        public:
            
            Iterator(int* i): iptr(i) {}
            Iterator& operator++() {
                iptr++;
                return *this;
            }
            int operator*() { return *iptr; }

        private:
            int* iptr;
        };

        /*
         * Puts an element at the back of a vector.
         * */

        MyVec() {
            sz = 0;
            capacity = DEF_CAPACITY;
            data = new int[DEF_CAPACITY];
        }
    
    MyVec(int sz, int val) : sz{sz} {
        capacity = sz * 2;
        data = new int[capacity];
        for (int i = 0; i < sz; i++) {
            data[i] = val;
        }
    }
    
    // copy control:
    MyVec(const MyVec& v2) {
        copy(v2);
    }
    
    ~MyVec() { delete [] data; }
    
    MyVec& operator=(const MyVec& v2) {
        if (this != &v2) {
            delete [] data;
            copy(v2);
        }
        return *this;
    }
    
    void push_back(int val) {
        sz++;
        if (sz > capacity) {
            std::cout << "Increasing capacity\n";
            int* old_data = data;
            data = new int[capacity * CAPACITY_MULT];
            for (int i = 0; i < sz; i++) {
                data[i] = old_data[i];
            }
            capacity *= CAPACITY_MULT;
            delete [] old_data;
        }
        data[sz - 1] = val;
    }
    
    int size() const { return sz; }
    
    int operator[](int i) const {
        return data[i];
    }
    
    int& operator[](int i) {
        return data[i];
    }
    
    Iterator begin() const { return Iterator(data); }

    Iterator end() const { return Iterator(data + size()); }

private:
    void copy(const MyVec& v2) {
        sz = v2.sz;
        capacity = v2.capacity;
        data = new int[capacity];
        for (int i = 0; i < sz; i++) {
            data[i] = v2.data[i];
        }
    }
    
    
    int* data;
    int sz;
    int capacity;
    
};

void print_vector(const MyVec& v) {
    for (int i = 0; i < v.size(); i++)
        std::cout << v[i] << ", ";
    std::cout << std::endl;
}

bool operator==(MyVec& v1, MyVec& v2) {
    if (v1.size() != v2.size()) return false;

    for(int i = 0; i < v1.size(); i++) {
        if (v1[i] != v2[i]) return false;
    }
    return true;
}

#endif
