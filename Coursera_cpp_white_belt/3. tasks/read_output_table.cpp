#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

int main() {
    ifstream input("input.txt");
    int n, m, num;
    if (input) {
        input >> n >> m;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                input >> num;
                input.ignore(1);
                cout << setw(10) << num;
                if (j < m - 1)
                    cout << " ";
            }
            if (i < n - 1)
                cout << endl;
        }
    }
    return 0;
}
