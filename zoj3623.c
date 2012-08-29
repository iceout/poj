/*
 * =====================================================================================
 *
 *       Filename:  zoj3623.c
 *
 *    Description: Battle Ships is a new game which is similar to Star Craft. In this game, the enemy builds a defense tower,
 *    which has L longevity. The player has a military factory, which can produce N kinds of battle ships. The factory takes
 *    ti seconds to produce the i-th battle ship and this battle ship can make the tower loss li longevity every second when
 *    it has been produced. If the longevity of the tower lower than or equal to 0, the player wins. Notice that at each
 *    time, the factory can choose only one kind of battle ships to produce or do nothing. And producing more than one battle
 *    ships of the same kind is acceptable.
 *    Your job is to find out the minimum time the player should spend to win the game.
 *    
 *    Input
 *    There are multiple test cases.
 *    The first line of each case contains two integers N(1 ≤ N ≤ 30) and L(1 ≤ L ≤ 330), N is the number of the kinds of
 *    Battle Ships, L is the longevity of the Defense Tower. Then the following N lines, each line contains two integers ti
 *    (1 ≤ ti ≤ 20) and li(1 ≤ li ≤ 330) indicating the produce time and the lethality of the i-th kind Battle Ships.
 *    
 *    Output
 *    Output one line for each test case. An integer indicating the minimum time the player should spend to win the game. 
 *        Version:  1.0
 *        Created:  08/29/2012 09:34:20 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  iceout (), ice.404.out@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdio.h>
#include <string.h>
int t[350],l[350];
int result[350];
void battleships() {
    int N,L, i, j, temp;
    while(scanf("%d %d",&N,&L)!=EOF) {
        for(i=0;i<N;i++) {
            scanf("%d %d",&t[i],&l[i]);
        }
        memset(result,0,sizeof result);
        for(i=2; i < 350; i++) {
            for(j=0; j < N; j++) {
                if(t[j]<i) {
                    temp = l[j]*(i-t[j])+result[i-t[j]];
                    result[i]= temp > result[i] ? temp : result[i];
                }
            }
            if(result[i] >= L) {
                printf("%d\n", i);
                break;
            }
        }
    }

}
int main(int argc, char * const argv[])
{
    battleships();
    return 0;
}
