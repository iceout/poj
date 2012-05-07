#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char dic[10000][16];
int sorted[10000][2];

int check(char *s, char *b, int small);

int comp(const void * p, const void * q)
{
    if (((int *)p)[1] < ((int *)q)[1]) {
        return -1;
    }
    else if (((int *)p)[1] == ((int *)q)[1]) {
        return strcmp(dic[((int *)p)[0]], dic[((int *)q)[0]]);
    }
    else {
        return 1;
    }
    /*return strcmp(dic[*(int *)p], dic[*(int *)q]);*/
    /*return strcmp(dic[((int *)p)[0]], dic[((int *)q)[0]]);*/
}

int main(int argc, char * const argv[])
{
    int i, j;
    int numdic = 0;

    char word[16];
    int lenword = 0;
    int replace[10000];
    /*int t;*/
    int count;
    int first, mid, last;
   
    /*Read the dict*/
    while (1 == 1) {
        scanf("%s", dic[numdic]);
        if (dic[numdic][0] == '#') {
            break;
        }
        replace[numdic] = 0;
        sorted[numdic][0] = numdic;
        sorted[numdic][1] = strlen(dic[numdic]);
        numdic++;
    }

    qsort(sorted, numdic, sizeof(int)*2, comp);

    /*for (i = 0; i < numdic; i++) {
        printf("%d: id=%d, len=%d\n", i, sorted[i][0], sorted[i][1]);
    }*/
    while (1 == 1) {
        scanf("%s", word);
        if (word[0] == '#') {
            break;
        }
        printf("%s", word);
        lenword = strlen(word);
        i = -1;
        while (++i < numdic && sorted[i][1] < lenword) {
            /* code */
        }

        if (i < numdic) {
            first = i;
            i--;
            while (++i < numdic && sorted[i][1] == lenword) {
                /* code */
            }
            last = i-1;
            mid = (last - first)/2;
            j = -1;
            while (1 == 1) {
                if (last < first) {
                    break;
                }
                mid = first + (last - first)/2;
                j = strcmp(dic[sorted[mid][0]], word);
                if (j == 0) {
                    printf(" is correct\n");
                    break;
                }
                else if (j < 0) {
                    first = mid+1;
                }
                else {
                    last = mid-1;
                }
            }
            if (j == 0) {
                continue;
            }
        }
        /*memset(replace, -1, 10000);*/
        count = -1;
        i = -1;
        while (++i < numdic && sorted[i][1] < lenword-1) {
            /* code */
        }
        while (i < numdic) {
            if (lenword == sorted[i][1]) {
                count = 0;
                for (j = 0; j < lenword; j++) {
                    if (word[j] != dic[sorted[i][0]][j]) {
                        count++;
                    }
                }
                if (count == 1){
                    replace[sorted[i][0]] = 1;
                }
            }
            else if (lenword+1 == sorted[i][1]) {
                if (check(word, dic[sorted[i][0]], lenword) == 1) {
                    replace[sorted[i][0]] = 1;
                }
            }
            else if (lenword-1 == sorted[i][1]) {
                if (check(dic[sorted[i][0]], word, lenword-1) == 1) {
                    replace[sorted[i][0]] = 1;
                }
            }
            else {
                break;
            }
            i++;
        }
        if (count != 0) {
            printf(":");
            j = 0;
            while (j < numdic) {
                if (replace[j] == 1) {
                    printf(" %s", dic[j]);
                    replace[j] = 0;
                }
                j++;
            }
            printf("\n");
        }
    }
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
