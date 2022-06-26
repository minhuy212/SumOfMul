#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {  
    // MỞ FILE NHẬP DỮ LIỆU
    ifstream in("input.txt"); 
    int n;
    in >> n;
    int* a = new int[n];
    int** f = new int* [n];
    for (int i = 0; i < n; i++) {
        in >> *(a + i);
        f[i] = new int[2];
    }
    in.close();
    // ĐÓNG FILE
    
    // BẮT ĐẦU GIẢI THUẬT
    f[0][0] = a[0] + a[1];
    f[0][1] = a[0] * a[1];
    for (int i = 1; i < n - 1; i++) { 
        f[i][0] = max(f[i - 1][0], f[i - 1][1]) + a[i + 1];
        f[i][1] = (f[i - 1][0] - a[i]) + (a[i] * a[i + 1]);  
    }
    // KẾT THÚC GIẢI THUẬT

    // XUẤT RA TỔNG TÍCH LỚN NHẤT
    cout << max(f[n - 2][0], f[n - 2][1]);

    return 0;
}