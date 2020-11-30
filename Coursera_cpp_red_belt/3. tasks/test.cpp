#include <iostream>

using namespace std;

using ull = unsigned long long;

int integerPartition(int n, int k)
{
    if(k == 0)
        return 0;
    if(n == 0)
        return 1;
    if(n < 0)
        return 0;

    return integerPartition(n,k - 1) + integerPartition(n - k, k);
}

ull exp_sum(unsigned int n) {
    ull count;
    ull k = n;
    count = integerPartition(n, k);
    return count;
}

int main(){
    int n = 5;
    cout << exp_sum(n);
}