/*
 * =====================================================================================
 *
 *       Filename:  zoj3310.c
 *
 *    Description:  zoj 3310
 *
 *        Version:  1.0
 *        Created:  08/29/2012 09:41:55 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  iceout (), ice.404.out@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdio.h>
int happypoints[1000001];
void unrequitedLove()
{
    int  N, i, temp;
    int result[2], max;

    while(scanf("%d",&N)!=EOF) {
        for (i = 0; i < N; i++) {
            scanf("%d",&happypoints[i]);
        }
        result[0] = 0;
        result[1] = happypoints[0];
        for (i = 1; i < N-1; i++) {
            temp = result[0];
            result[0] = result[0] > result[1] ? result[0] : result[1];
            result[1] = happypoints[i] + temp;
        }
        max = result[0] > result[1] ? result[0] : result[1];
        result[0] = 0;
        result[1] = 0;
        for (i = 1; i < N; i++) {
            temp = result[0];
            result[0] = result[0] > result[1] ? result[0] : result[1];
            result[1] = happypoints[i] + temp;
        }
        temp = result[0] > result[1] ? result[0] : result[1];
        printf("%d\n", temp > max ? temp : max);
    }
}
int main(int argc, char * const argv[])
{
    unrequitedLove();
    return 0;
}
