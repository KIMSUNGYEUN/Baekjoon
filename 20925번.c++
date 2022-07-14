#include <cstdio>
#include <string.h>
#include <algorithm>
using namespace std;


const int N_MAX = 200;
const int T_MAX = 1000;


int n, t;
int c[N_MAX], e[N_MAX];
int dp[T_MAX + 1][N_MAX];


int cost[N_MAX][N_MAX];


int main(){
    memset(dp, -1, sizeof(dp));
    scanf("%d %d", &n, &t);
    for (int i = 0; i < n; i++){
        scanf("%d %d", &c[i], &e[i]);
        if (c[i] == 0){
            dp[0][i] = 0;
        }
    }
    
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            scanf("%d", &cost[i][j]);
        }
    }
    
    for (int i = 1; i <= t; i++){
        for (int j = 0; j < n; j++){
            if (dp[i - 1][j] != -1){
                dp[i][j] = max(dp[i][j], dp[i - 1][j] + e[j]);
            }
            for (int k = 0; k < n; k++){
                int prev = i - cost[k][j];
                if (j == k || prev < 0) continue;
                
                if (dp[prev][k] != -1 && dp[prev][k] >= c[j]){
                    dp[i][j] = max(dp[i][j], dp[prev][k]);
                }
            }
        }
    }
    
    int ans = 0;
    for (int i = 0; i <= t; i++){
        for (int j = 0; j < n; j++){
            ans = max(ans, dp[i][j]);
        }
    }
    printf("%d\n", ans);
    
    return 0;
}
