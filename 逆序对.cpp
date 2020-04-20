#include <iostream>
#include <cstdio>
using namespace std;
typedef long long ll;
int nums[100005], temp[100005], n;
int p1, p2, p;
ll cnt = 0;

void merge(int l1, int r1, int l2, int r2) {
    p1 = l1; p2 = l2; p = 0;
    while (p1 <= r1 && p2 <= r2) {
        if (nums[p1] <= nums[p2]) {
            temp[p++] = nums[p1++];
        }
        else {
            cnt += r1 - p1 + 1;
            temp[p++] = nums[p2++];
        }
    }
    while (p1 <= r1) temp[p++] = nums[p1++];
    while (p2 <= r2) temp[p++] = nums[p2++];
    for (int i = 0; i < p; ++i)
        nums[l1 + i] = temp[i];
}

void mergeSort(int l, int r) {
    if (l >= r) return ;
    int mid = (l + r) >> 1;
    mergeSort(l, mid);
    mergeSort(mid + 1, r);
    merge(l, mid, mid + 1, r);
}

int main() {
    ios::sync_with_stdio(0);
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> nums[i];
    mergeSort(1, n);
    cout << cnt << endl;
    return 0;
}
