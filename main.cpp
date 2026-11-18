// PRN: 202501100023
// Personalization key:
//   S = 23 (last four digits of PRN = 0023)
//   Scenario: PRN mod 3 = 1 -> Student Marks
//   Dataset: v[i] = (23 + 13*i) mod 100, i = 0..19
//   Hash: odd PRN -> Mid-square method
//   Collision handling: odd PRN -> Separate chaining
//   Table size: m = 11 (smallest prime >= (S mod 23) + 11)

#include <iostream>
#include <iomanip>
#include <list>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

constexpr int TABLE_SIZE = 11;
constexpr int SEED = 23;
constexpr int DATASET_SIZE = 20;

vector<int> generateMarks() {
    vector<int> marks;
    marks.reserve(DATASET_SIZE);

    for (int i = 0; i < DATASET_SIZE; ++i) {
        marks.push_back((SEED + 13 * i) % 100);
    }

    return marks;
}

int midSquareHash(int key) {
    long long square = static_cast<long long>(key) * key;

    // This assignment's keys are 0–99, so their squares fit in four digits.
    ostringstream formatted;
    formatted << setw(4) << setfill('0') << square;
    const string digits = formatted.str();

    // Take the middle two digits of the four-digit square.
    const int middle = stoi(digits.substr(1, 2));
    return middle % TABLE_SIZE;
}

class HashTable {
private:
    vector<list<int>> buckets;

public:
    HashTable() : buckets(TABLE_SIZE) {}

    void insert(int key) {
        const int index = midSquareHash(key);
        list<int>& chain = buckets[index];

        for (int existing : chain) {
            if (existing == key) {
                cout << "Duplicate " << key << " ignored\n";
                return;
            }
        }

        chain.push_back(key);
        cout << "Insert " << key << " -> bucket " << index << '\n';
    }

    bool search(int key) const {
        const int index = midSquareHash(key);

        for (int existing : buckets[index]) {
            if (existing == key) {
                return true;
            }
        }

        return false;
    }

    void display() const {
        cout << "\nFinal hash table (m=" << TABLE_SIZE << "):\n";

        for (int i = 0; i < TABLE_SIZE; ++i) {
            cout << '[' << i << "] ";

            for (int key : buckets[i]) {
                cout << key << " -> ";
            }

            cout << "NULL\n";
        }
    }
};

int main() {
    const vector<int> marks = generateMarks();

    cout << "Student marks dataset: ";
    for (int mark : marks) {
        cout << mark << ' ';
    }
    cout << '\n';

    HashTable table;
    for (int mark : marks) {
        table.insert(mark);
    }

    table.display();

    table.insert(23); // Duplicate-key check
    cout << "search(53) = " << table.search(53) << '\n';
    cout << "search(99) = " << table.search(99) << '\n';

    return 0;
}
