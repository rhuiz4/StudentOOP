/*
 * Let's use the *Standard Template Library*!
 * First, we will include the headers we need:
 * */
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

/*
 * print_vec to print vectors
 * */
template <typename T>
void print_vec(const string& name, vector <T> container) {
    cout<< name << ": ";
    for (const T& item: container) {
        cout << item << " ";
    }
    cout<<endl;
    cout<<endl;
}

/*
 * Let's make a template for a `print_list` that can handle
 * lists of any type:
 * Templates are the C++ feature that enable generic programming.
 * */
template <typename T>
void print_list(const string& name, list <T> container) {
    cout<< name << ": ";
    for (const T& item: container) {
        
        cout << item << " ";
    }
    cout << endl;
    cout << endl;
}

/*
 * But, we can go even more generic, and make a `print` that can print
 * *containers* of any sequential type:
 * */
template <typename T>
void print(const string& name, T container) {
    cout<< name << ": ";
    for( const auto& item: container) {
        //auto is more widely used in more situations.
        //without auto we have to have a second template type.
        cout << item << " ";
    }
    cout<<endl;
    cout<<endl;
}


/*
 * A Cat class just so we can show these work on our types:
 * */
class Cat {
    friend ostream& operator<<(ostream& os, const Cat& cat) {
        os << "meow ";
        return os;
    }
};

/*
 * We could pass this `is_odd()` function in to a `find_if()`,
 * or pass a *lambda* instead.
 * */
<<<<<<< HEAD
bool is_odd(int n) {
    cout << "in function! n is: " << n << endl;
    return (n % 2) != 0;
}
=======
bool is_odd(int n) { return (n % 2) == 1; }
>>>>>>> upstream/master

/*
 * Or, we could have a *functor*!
 * */
class IsOdd {
    public:
        bool operator()(int n) {
            return (n % 2) == 1;
        }
};

class IsOdd {
public:
    bool operator()(int n) {
        cout << "in functor! n is: " << n << "\n";
        return (n % 2) != 0;
    }
    //we can overload parentheses
};

/*
 * Our main will exercise some STL capabilities.
 * */
int main() {
    int bjarnelen = 17;
    int dennislen = 14;
    
    char s[]  = "Bjarne Stroustrup";
    char s2[] = "Dennis Ritchie";
    
    cout << "C++ creator: " << s << "\n";
    cout<<endl;
    cout << "C creator, 4th letter: " << s2[3] << "\n";
    cout<<endl;
    
    /*
     * Let's do some things with a `vector`.
     * We will create it with a half-open range, and then sort it.
     * */
    vector<char> cvec(s2, s2 + dennislen);
    //DONE - Kori
    print_vec("cvec", cvec);
    
    sort(cvec.begin(), cvec.end());
    //DONE - Kori
    print_vec("sorted cvec", cvec);
    
    /*
     * Create a `char` list:
     * */
    list<char> clist(s, s + bjarnelen);
    list<char> clist2 = clist;
    list<char> clist3(s2, s2 + dennislen);
    /*
     * The STL provides us with a `reverse()` functions that
     * reverses an iterable structure:
     * */
    reverse(clist.begin(), clist.end());
    print_list("clist reversed", clist);
    print_list("clist2 not reversed", clist2);
    
    /*
     * But even after `clist` is reversed, `clist` and
     * `clist2` are still permutations of each other:
     * */
    list<char> clist4 = clist;
    cout << "Is clist a permutation of clist2? "
<<<<<<< HEAD
    << is_permutation(clist.begin(), clist.end(), clist2.begin())
    << endl; ;
    cout << "Is clist a permutation of clist3? "
    << is_permutation(clist.begin(), clist.end(), clist3.begin())
    << endl; ;
    
=======
        << is_permutation(clist.begin(), clist.end(), clist2.begin())
        << endl; ;
    cout << "Is clist4 a permutation of clist3? "
        << is_permutation(clist4.begin(), clist4.end(), clist3.begin())
        << endl; ;

>>>>>>> upstream/master
    /*
     * Testing a list of Cats:
     * */
    Cat catptr[] = { Cat(), Cat(), Cat() };
    list<Cat> catlist(catptr, catptr + 3);
    //this prints a list of type cat
    print_list("Cat list", catlist);
    
    /*
     * Testing an int list:
     * */
    int ilen = 8;
<<<<<<< HEAD
<<<<<<< HEAD
    int iptr[] = { 16, 32, 64, 9, 2, 4, 8, 17 };
=======
    int iptr[] = { 16, 32, 64, 128, 1, 44, 8, 17 };
>>>>>>> upstream/master
=======
    int iptr[] = { 16, 32, 64, 128, 256, 512, 1024, 1, 44, 8, 17 };
>>>>>>> upstream/master
    list<int> ilist(iptr, iptr + ilen);
    /*
     * Our print can work for lists as well as vectors:
     * */
    //DONE
    print("print: ilist", ilist);
    print("print: sorted cvec", cvec);
    /*
     * `sort()` does not work for lists, since they aren't random access.
     * Thus lists have their own `sort()` method, called below:
     * This *won't* work: `sort(ilist.begin(), ilist.end());`
     * */
<<<<<<< HEAD
    ilist.sort();
    print("ilist sorted", ilist);
    
=======
    // ilist.sort();
//    print("ilist sorted", ilist);

>>>>>>> upstream/master
    /*
     * Let's experiment with *iterators* a bit!
     * */
    list<int>::iterator odd_iter = find_if(ilist.begin(), ilist.end(),is_odd);
    cout << "First odd number in ilist is: " << *odd_iter << endl;
    odd_iter++;
    cout << "Second odd number in ilist is: " << *odd_iter << endl;
    /*
     * Here we are going to pass `is_odd()` to `find_if()`.
     * */
<<<<<<< HEAD
    
    /*
     * Here we are going to pass functor `IsOdd` to `find_if()`.
     * */
    
    IsOdd odd_functor = IsOdd();
    
    cout << "Is 6 odd? " << odd_functor(6) << endl;
    cout << "Is 7 odd? " << odd_functor(7) << endl;
    
    list<int>::iterator odd_iter2 = find_if(ilist.begin(), ilist.end(),odd_functor);
    cout << "First functor odd number in ilist is: " << *odd_iter2 << endl;
    odd_iter2 = find_if(++odd_iter2, ilist.end(),odd_functor);
    cout << "Second functor odd number in ilist is: " << *odd_iter2 << endl;
    
=======
    cout << "ilist begin is: " << *(ilist.begin()) << endl;
    cout << "ilist end is: " << *(ilist.end()) << endl;

    list<int>::iterator odd_iter = find_if(ilist.begin(),
            ilist.end(), is_odd);
    cout << "First odd number in ilist is: " << *odd_iter << endl;
    odd_iter++;
    cout << "The next number in ilist is: " << *odd_iter << endl;

    /*
     * Here we are going to pass functor `IsOdd` to `find_if()`.
     * */
    IsOdd odd_functor = IsOdd();
    cout << "Is 6 odd? " << odd_functor(6) << endl;
    cout << "Is 7 odd? " << odd_functor(7) << endl;
    list<int>::iterator odd_iter2 = find_if(ilist.begin(),
            ilist.end(), odd_functor);
    cout << "First odd number in ilist is: " << *odd_iter2 << endl;
    odd_iter2++;
    cout << "The next number in ilist is: " << *odd_iter2 << endl;

>>>>>>> upstream/master
    /*
     * Here we are going to pass a *lambda* to `find_if()`.
     * The lambda starts with `[]`. The point here is to show
     * that this form and the one above are identical in effect.
     --> lambda anon func
     * */
<<<<<<< HEAD
    list<int>::iterator odd_iter3 = find_if(ilist.begin(), ilist.end(), [](int n) {return (n%2) == 1;});
    cout << "First lambda odd number in ilist is: " << *odd_iter3 << endl;
    odd_iter3 = find_if(++odd_iter3, ilist.end(), [](int n) {return (n%2) == 1;});
    cout << "Second lambda odd number in ilist is: " << *odd_iter3 << endl;
    // cout << "First lambda odd number in list is: " << *if_iter3 << endl;
=======
    list<int>::iterator odd_iter3 = find_if(ilist.begin(),
            ilist.end(), [](int n) { return (n % 2) == 1; });
<<<<<<< HEAD
    cout << "First lambda odd number in ilist is: " << *odd_iter3 << endl;
    odd_iter3++;
    cout << "The next lambda number in ilist is: " << *odd_iter3 << endl;
>>>>>>> upstream/master
=======
    cout << "Using lambda first odd number in ilist is: " << *odd_iter3 << endl;

    list<int>::iterator even_iter = find_if(ilist.begin(),
            ilist.end(), [](int n) { return (n % 2) == 0; });
    cout << "Using lambda first even number in ilist is: " << *even_iter << endl;

    list<int>::iterator big_iter = find_if(ilist.begin(),
            ilist.end(), [](int n) { return (n > 999); });
    cout << "Using lambda first big number in ilist is: " << *big_iter << endl;
>>>>>>> upstream/master
}
