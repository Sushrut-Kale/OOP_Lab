#include <iostream>
#include <list>
#include <vector>
#include <algorithm>
using namespace std;

// Display List
void displayList(const list<int> &l) {
    for (list<int>::const_iterator it = l.begin();
         it != l.end(); ++it) {
        cout << *it << " ";
    }

    cout << endl;
}

// Display Vector
void displayVector(const vector<int> &v) {
    for (vector<int>::const_iterator it = v.begin();
         it != v.end(); ++it) {
        cout << *it << " ";
    }

    cout << endl;
}

int main() {
    // PART A: List Container
    cout << "===== PART A: list class as a container ====="
         << endl;

    list<int> myList;

    myList.push_back(30);
    myList.push_back(10);
    myList.push_back(50);
    myList.push_front(20);

    cout << "After push_back / push_front: ";
    displayList(myList);

    cout << "Size = " << myList.size() << endl;

    cout << "Front = " << myList.front()
         << ", Back = " << myList.back() << endl;

    myList.sort();

    cout << "After sort(): ";
    displayList(myList);

    myList.reverse();

    cout << "After reverse(): ";
    displayList(myList);

    list<int>::iterator it = myList.begin();
    ++it;

    myList.insert(it, 40);

    cout << "After insert(40) at position 2: ";
    displayList(myList);

    myList.remove(20);

    cout << "After remove(20): ";
    displayList(myList);

    myList.pop_front();
    myList.pop_back();

    cout << "After pop_front(), pop_back(): ";
    displayList(myList);

    cout << "Final size = " << myList.size() << endl;

    // PART B: Vector Container
    cout << "\n===== PART B: vector class as a container ====="
         << endl;

    vector<int> v;

    v.push_back(25);
    v.push_back(5);
    v.push_back(15);
    v.push_back(10);

    cout << "After push_back: ";
    displayVector(v);

    cout << "Size = " << v.size()
         << ", v[1] = " << v[1]
         << ", v.at(2) = " << v.at(2) << endl;

    sort(v.begin(), v.end());

    cout << "After sort(): ";
    displayVector(v);

    reverse(v.begin(), v.end());

    cout << "After reverse(): ";
    displayVector(v);

    vector<int>::iterator pos =
        find(v.begin(), v.end(), 10);

    if (pos != v.end()) {
        cout << "Element 10 found at index "
             << (pos - v.begin()) << endl;
    }

    v.insert(v.begin() + 1, 20);

    cout << "After insert(20) at index 1: ";
    displayVector(v);

    v.erase(v.begin());

    cout << "After erase() of first element: ";
    displayVector(v);

    v.pop_back();

    cout << "After pop_back(): ";
    displayVector(v);

    int sum = 0;

    for (vector<int>::size_type i = 0;
         i < v.size(); i++) {
        sum += v[i];
    }

    cout << "Sum of elements = " << sum << endl;

    v.clear();

    cout << "After clear(): size = " << v.size()
         << ", empty = "
         << (v.empty() ? "Yes" : "No") << endl;

    return 0;
}

