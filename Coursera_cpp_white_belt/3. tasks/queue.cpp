#include <iostream>
#include <vector>
#include <string>
using  namespace std;

int main() {
    string operation;
    int i;
    vector<int> queue;
    vector<int> worry;
    int q;
    cin >> q;
    for (int j = 0; j < q; j++) {
        cin >> operation;
        if (operation == "WORRY_COUNT") {
            int count = 0;
            for (int k = 0; k < queue.size(); k++) {
                if (queue[k] == 1)
                    count++;
            }
            worry.push_back(count);
        } else {
            cin >> i;
            if (operation == "WORRY")
                queue[i] = 1;
            else if (operation == "QUIET")
                queue[i] = 0;
            else if (operation == "COME") {
                if (i > 0) {
                    for (int k = 0; k < i; k++)
                        queue.push_back(0);
                } else {
                    for (int k = 0; k < (-1 * i); k++)
                        queue.pop_back();
                }
            }
        }
    }

    for (auto value : worry)
        cout << value <<endl;
    return 0;
}