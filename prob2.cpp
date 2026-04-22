#include <iostream>
#include "queue.h"

using namespace std;

int main() {
    int n, k;
    
    // Gunakan while agar aman jika GitHub menguji banyak testcase sekaligus
    while (cin >> n >> k) {
        int A[105];
        for (int i = 0; i < n; i++) {
            cin >> A[i];
        }

        // JEBAKAN 1: Jika k bernilai 0 atau negatif sesuai batasan soal
        if (k <= 0) {
            cout << 0 << endl;
            continue; // Langsung lanjut ke testcase berikutnya
        }

        Queue q;
        init(&q);
        int total = 0;

        for (int i = 0; i < n; i++) {
            // Masukkan ke antrean
            enqueue(&q, A[i]);
            total += A[i];

            // Jika ukuran antrean sudah lebih dari k, keluarkan elemen terdepan
            if (i >= k) {
                total -= front(&q);
                dequeue(&q);
            }

            // Jika antrean sudah mencapai k elemen, cetak nilainya
            if (i >= k - 1) {
                cout << total;
                // Jangan cetak spasi di elemen paling akhir
                if (i < n - 1) {
                    cout << " ";
                }
            }
        }
        // Cetak enter di setiap akhir testcase
        cout << endl;
    }

    return 0;
}
