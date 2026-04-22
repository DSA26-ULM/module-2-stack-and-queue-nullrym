#include <iostream>
#include <string>
#include <cstdlib> // Wajib pakai cstdlib untuk atoi()
#include "stack.h" // Tetap gunakan stack.h, jangan diubah

using namespace std;

int main() {
    int n;
    // Baca jumlah n simbol
    if (!(cin >> n)) return 0;

    Stack s;
    init(&s);

    for (int i = 0; i < n; i++) {
        string token;
        cin >> token;

        // Cek langsung apakah token adalah operator
        if (token == "+") {
            int val2 = peek(&s); pop(&s);
            int val1 = peek(&s); pop(&s);
            push(&s, val1 + val2);
        } else if (token == "-") {
            int val2 = peek(&s); pop(&s);
            int val1 = peek(&s); pop(&s);
            push(&s, val1 - val2);
        } else if (token == "*") {
            int val2 = peek(&s); pop(&s);
            int val1 = peek(&s); pop(&s);
            push(&s, val1 * val2);
        } else if (token == "/") {
            int val2 = peek(&s); pop(&s);
            int val1 = peek(&s); pop(&s);
            push(&s, val1 / val2);
        } else {
            // Jika bukan salah satu operator di atas, pasti dia angka.
            // Gunakan atoi() yang lebih kompatibel dengan auto-grader.
            push(&s, atoi(token.c_str()));
        }
    }

    // Tampilkan hasil akhir
    cout << peek(&s) << endl;

    return 0;
}
