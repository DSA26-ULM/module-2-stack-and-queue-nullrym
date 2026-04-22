#include <iostream>
#include "queue.h"

using namespace std;

int main() {
    int n, k;
    if (!(cin >> n >> k)) return 0;

    int A[105];
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    Queue q;
    init(&q);
    
    int total = 0;

    for (int i = 0; i < n; i++) {
        enqueue(&q, A[i]);
        total += A[i];

        if (i >= k) {
            total -= front(&q);
            dequeue(&q);
        }

        if (i >= k - 1) {
            cout << total;
            if (i < n - 1) {
                cout << " ";
            }
        }
    }
    cout << endl;

    return 0;
}
