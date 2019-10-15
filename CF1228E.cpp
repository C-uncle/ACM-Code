// 题意：有一个n*n的格子，你可以往格子填1~k中任意数字，需要保证每行，每列的最小值都是1.
#include <iostream>
using namespace std;
typedef long long int ll;
const int maxn = 255;
const int mod = 1e9 + 7;
ll n, k, f[maxn][maxn], C[maxn][maxn], k1[maxn], k2[maxn];

int main(){
    cin >> n >> k;
    k1[0] = k2[0] = 1;
    for (int i = 1; i <= n; i++){
        k1[i] = k1[i-1] * k % mod;
        k2[i] = k2[i-1] * (k-1) % mod;
    }
    for (int i = 0; i <= n; i++){
        for (int j = 0; j <= i; j++){
            if (j == 0) C[i][j] = 1;
            else C[i][j] = (C[i-1][j] + C[i-1][j-1]) % mod;
        }
    }
    f[0][0] = 1;
    for (int i = 1; i <= n; i++){
        for (int j = 0;j <= n; j++){
            if (f[i-1][j] == 0) continue;
            for (int k = 0; k <= n && j + k <= n; k++){
                if (k == 0) f[i][j+k] += f[i-1][j] * (k1[j] - k2[j] + mod) % mod * k2[n-j] % mod;
                else f[i][j+k] += f[i-1][j] * (k1[j] % mod * C[n-j][k] % mod * k2[n-j-k] % mod) % mod;
                f[i][j+k] %= mod;
            }
        }
    }
    cout << f[n][n] << endl;
    return 0;
}
