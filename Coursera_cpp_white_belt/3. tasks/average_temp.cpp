#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> v;
    int n;
    int count = 0;
    cin >> n;
    double av_temp = 0;

    int i;
    for (i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        v.push_back(tmp);
        av_temp += tmp;
    }
    av_temp /= i;

    for (int i = 0; i < n; i++) {
        if (v[i] > av_temp)
            count++;
    }

    cout << count << endl;
    for (int i = 0; i < n; i++) {
        if (v[i] > av_temp)
            cout << i << ' ';
    }
    return 0;
}