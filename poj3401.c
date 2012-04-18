#include <stdio.h>
#include <string.h>
int main(int argc, char * const argv[])
{
    /*储存动态规划的过程信息*/
    int stat[256][256];
    char str[256];
    int len = 0;
    int i, j;

    freopen("poj3401.in", "r", stdin);
    freopen("poj3401.out", "w", stdout);
    
    scanf("%s", str);
    len = strlen(str);
     for (j = 0; j < len; j++) {
        for (i = len-1; i >= 0; i--) {
            if (i > j) {
                stat[i][j] = 0;
            }
            else if (i == j) {
                stat[i][j] = 1;
            }
            else if (j-i == 1) {
                stat[i][j] = 2;
            }
            else {
                /*TODO*/
                for (t = j-2; t >= i; t--) {
                    if (str[t] == str[j]) {
                        tmp = stat[i][t-1] + stat[t+1][j-1];
                        if (tmp < min) {
                            min = tmp;
                        }
                    }
                    else {
                        tmp = stat[i][t] + stat[t+1][j];
                        if (tmp < min) {
                            min = tmp;
                        }
                    }
                }
                stat[i][j] = min;
                min = INT_MAX;
            }
        }
    }
    printf("%d\n", stat[0][len-1]);
    return 0;
}
