#include <iostream>
#include "queue.h"

using namespace std;

int main() {
    int n, k;
    if (!(cin >> n >> k)) return 0;

    int A[105];
    for (int i = 0; i < n; i++) cin >> A[i];

    if (k <= 0) {
        for (int i = 0; i < n; i++) cout << 0 << (i == n-1 ? "" : " ");
        cout << endl;
        return 0;
    }

    Queue q;
    init(&q);
    long long total_sekarang = 0;

    for (int i = 0; i < n; i++) {
        enqueue(&q, A[i]);
        total_sekarang += A[i];

        if (i >= k) {
            total_sekarang -= front(&q);
            dequeue(&q);
        }

        if (i >= k - 1) {
            cout << total_sekarang;
            if (i < n - 1) cout << " ";
        }
    }
    cout << endl;

    return 0;
}
