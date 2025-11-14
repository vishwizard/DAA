#include <bits/stdc++.h>
using namespace std;

int closestSubarraySumToK(int a[], int n, int k) {
    set<int> s;
    int presum = a[0];
    s.insert(a[0]);
    int mini = abs(a[0] - k);
    int sum = presum;

    for (int i = 1; i < n; i++) {
        presum += a[i];
        s.insert(presum);
        auto it = s.lower_bound(presum - k);

        if (s.find(k) != s.end())
            return k;

        if (it == s.begin()) {
            int diff = *it;
            if (abs((presum - diff) - k) < mini) {
                mini = abs((presum - diff) - k);
                sum = presum - diff;
            }
            if (abs(presum - k) < mini) {
                mini = abs((presum - diff) - k);
                sum = presum - diff;
            }
        } else if (it != s.end()) {
            int diff = *it;
            if (abs((presum - diff) - k) < mini) {
                mini = abs((presum - diff) - k);
                sum = presum - diff;
            }
            it--;
            diff = *it;
            if (abs((presum - diff) - k) < mini) {
                mini = abs((presum - diff) - k);
                sum = presum - diff;
            }
        } else {
            if (abs(presum - k) < mini) {
                mini = abs(presum - k);
                sum = presum;
            }
        }
    }

    return sum;
}

int main() {
    int a[] = { -5, 12, -3, 4, -15, 6, 1 };
    int n = sizeof(a) / sizeof(a[0]);
    int k = 2;
    cout << closestSubarraySumToK(a, n, k);
    return 0;
}
