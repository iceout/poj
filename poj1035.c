#include <stdio.h>
#include <string.h>
#include <time.h>

char dic[10000][16];

int check(char *s, char *b, int small);

int main(int argc, char * const argv[])
{
    int i, j;
    int numdic = 0;

    char word[16];
    int lenword = 0;
    int replace[10000];
    int t;
    int count;


    clock_t start_time=clock();
    clock_t end_time;
    freopen("poj1035.in", "r", stdin);
    /*freopen("poj1035.out", "w", stdout);*/
    
    /*Read the dict*/
    while (1 == 1) {
        scanf("%s", dic[numdic]);
        if (dic[numdic][0] == '#') {
            break;
        }
        numdic++;
    }

    while (1 == 1) {
        scanf("%s", word);
        if (word[0] == '#') {
            break;
        }
        printf("%s", word);
        lenword = strlen(word);
        memset(replace, -1, 10000);
        t = 0;
        count = -1;
        i = 0;
        while (i < numdic) {
            if (lenword == strlen(dic[i])) {
                count = 0;
                for (j = 0; j < lenword; j++) {
                    if (word[j] != dic[i][j]) {
                        count++;
                    }
                }
                if (count == 0) {
                    printf(" is correct\n");
                    break;
                }
                else if (count == 1){
                    replace[t++] = i;
                }
            }
            else if (lenword+1 == strlen(dic[i])) {
                if (check(word, dic[i], lenword) == 1) {
                    replace[t++] = i;
                }
            }
            else if (lenword-1 == strlen(dic[i])) {
                if (check(dic[i], word, lenword-1) == 1) {
                    replace[t++] = i;
                }
            }
            i++;
        }
        if (count != 0) {
            printf(":");
            j = 0;
            while (j < t) {
                printf(" %s", dic[replace[j++]]);
            }
            printf("\n");
        }
    }
    end_time=clock();
    printf("time == %d\n", end_time-start_time);
    return 0;
}


int check(char *s, char *b, int small)
{
    int i = 0, j = 0;

    while (s[i] == b[j]) {
        i++;
        j++;
        if (i >= small) {
            return 1;
        }
    }
    j++;
    while (s[i] == b[j]) {
        i++;
        j++;
        if (i >= small) {
            return 1;
        }
    }

    return 0;
}
