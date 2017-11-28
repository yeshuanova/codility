#include <cstdint>

int solution(int A, int B, int K) {
    // Cast type to avoid overflow and underflow
    int64_t Ax = A, Bx = B, Kx = K, result = 0;

    if (Ax % Kx == 0) {
        result = (Bx - Ax) / Kx + 1;
    } else {
        result = (Bx - Ax + (Ax % Kx)) / Kx;
    }

    return static_cast<int>(result);
}
