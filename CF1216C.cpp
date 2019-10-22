// cf1216 C XiaoLei
// no done by myself
// 题意，有一块白块和两块黑块，求黑块是否完全挡住白块。
// 解法：考虑每块黑块与白块的重叠部分的面积之和是否会大于白块面积
// 需要考虑一种情况，两块黑块可能会有重叠，所以在计算面积和时需要使用容斥原理。
// ps 需要重点思考白块与黑块重叠部分的求法。
#include <iostream>
#include <cmath>
using namespace std;
typedef pair<int, int> pii;
typedef long long int ll;
#define mp(a,b) make_pair(a,b)
#define x first
#define y second
pii p[7];

pair<pii, pii> cube(pii a, pii b, pii c, pii d){
    // 求重叠部分
    int lf = max(min(a.x, b.x), min(c.x, d.x));  // 左下角的x坐标
    int rg = min(max(a.x, b.x), max(c.x, d.x));  // 右上角的x坐标
    int dn = max(min(a.y, b.y), min(c.y, d.y));  // 左下角的y坐标
    int up = min(max(a.y, b.y), max(c.y, d.y));  // 右上角的y坐标

    if (lf >= rg || dn >= up) return {{0,0},{0,0}}; // 判断是否会重叠
    else return {{lf,dn}, {rg,up}};
}

ll square(pii a, pii b){
    return 1ll * abs(a.x - b.x) * abs(a.y - b.y);
}

int main(){
    for (int i = 1; i <= 6; i++) cin >> p[i].x >> p[i].y;

    pair<pii, pii> wb1 = cube(p[1], p[2], p[3], p[4]);
    pair<pii, pii> wb2 = cube(p[1], p[2], p[5], p[6]);
    pair<pii, pii> wb12 = cube(wb1.x, wb1.y, wb2.x, wb2.y);

    ll swhite = square(p[1], p[2]);
    ll swb1 = square(wb1.x, wb1.y);
    ll swb2 = square(wb2.x, wb2.y);
    ll swb12 = square(wb12.x, wb12.y);

    // 容斥原理，判断黑块面积是否会大于白块面积。
    if (swhite > swb1 + swb2 - swb12) cout << "YES\n";
    else cout << "NO\n";
    return 0;
}
