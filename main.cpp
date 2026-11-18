// PRN: 202501100023
// Personalization key: S=23 (last 4 digits of PRN = 0023)
//   Scenario  : PRN mod 3 = 1 -> Student Marks
//   Dataset   : v[i] = (23 + 13*i) mod 100, i = 0..19
//   Hash func : PRN odd  -> Mid-square method
//   Collision : PRN mod 2 = 1 -> Separate chaining
//   Table size: m = 13 (prime, chosen by me)

#include <iostream>
#include <vector>
#include <list>
using namespace std;

vector<int> generateMarks(int S, int n) {
    vector<int> v;
    for (int i = 0; i < n; i++) v.push_back((S + 13 * i) % 100);
    return v;
}

const int M = 13;

// Mid-square: square the key, take the middle two digits of the
// 4-digit square (drop last digit, keep next two), then mod M.
int midSquareHash(int key) {
    long long sq = (long long)key * key;
    int mid = (int)((sq / 10) % 100);
    return mid % M;
}

class HashTable {
    vector<list<int>> table;
public:
    HashTable() : table(M) {}
    void insert(int key) {
        int idx = midSquareHash(key);
        for (int k : table[idx])
            if (k == key) { cout << "Duplicate " << key << " ignored" << endl; return; }
        table[idx].push_back(key);   // separate chaining: append to bucket list
        cout << "Insert " << key << " -> bucket " << idx << endl;
    }
    bool search(int key) {
        for (int k : table[midSquareHash(key)]) if (k == key) return true;
        return false;
    }
    void display() {
        cout << "\nFinal hash table (m=" << M << "):" << endl;
        for (int i = 0; i < M; i++) {
            cout << "[" << i << "] ";
            for (int k : table[i]) cout << k << " -> ";
            cout << "NULL" << endl;
        }
    }
};

int main() {
    vector<int> marks = generateMarks(23, 20);
    cout << "Student marks dataset: ";
    for (int x : marks) cout << x << " ";
    cout << endl;
    HashTable ht;
    for (int x : marks) ht.insert(x);
    ht.display();

    // Tests: duplicate key and search
    ht.insert(23);
    cout << "search(53) = " << ht.search(53) << ", search(99) = " << ht.search(99) << endl;
    return 0;
}
