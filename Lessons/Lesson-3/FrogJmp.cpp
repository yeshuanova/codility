
int solution(int X, int Y, int D) {
    
    const int dist = Y - X;

    if (dist % D == 0) {
        return dist / D;
    } else {
        return dist / D + 1;
    }
}
