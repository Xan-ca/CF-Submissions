#include<iostream>
using namespace std;
int main() {
    int a, c, b, d;
    cin >> a >> c >> b >> d;
    if (a >= b) {
        cout << a;
        return;
    }
    int n = (b-a)/(c+d);
    if ((b-1)%(c+d)!=0) n++;
    if (a+c*n > b-d*(n-1)) {
        cout << b - d*(n-1) << ln;
    }
    else {
        cout << a + n*c << ln;
    }
}
