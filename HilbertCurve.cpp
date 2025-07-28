// Online C++ compiler to run C++ program online
#include <iostream>
#include <unordered_map>

using namespace std;

int FindIndexInHilbertCurve(int x, int y, int iter) {
    if (iter == 0) {
        return 1;
    }
    int len = 1 << (iter - 1);
    int num = 1 << (2 * (iter - 1));
    
    // 左上
    if (x < len && y >= len) {
        return num + FindIndexInHilbertCurve(x, y - len, iter - 1);
    }
    // 右上
    if (x >= len && y >= len) {
        return 2 * num + FindIndexInHilbertCurve(x - len, y - len, iter - 1);
    }
    // 右下
    if (x < len && y < len) {
        return FindIndexInHilbertCurve(y, x, iter - 1);
    }
    return 3 * num + FindIndexInHilbertCurve(len - y - 1, 2 * len - x - 1, iter - 1);
    
}

int main() {
    cout << FindIndexInHilbertCurve(1, 1, 2) << endl;
    cout << FindIndexInHilbertCurve(0, 1, 1) << endl;
    cout << FindIndexInHilbertCurve(2, 2, 2) << endl;
    return 0;
    
    
}
