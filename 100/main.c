#include <stdio.h>
#include <string.h>

#define MAX_IN 128

char input[MAX_IN];
int l, r, max_c;

int main() {
    int i, n, c;

    while(fgets(input, MAX_IN, stdin) != NULL) {
        sscanf(input, "%d%d", &l, &r);
        printf("%d %d", l, r);

        if(l > r) {
            n = l;
            l = r;
            r = n;
        }

        max_c = 0;
        for(i = l; i <= r; i++) {
            n = i;
            c = 1;
            while(n != 1) {
                if((n % 2) == 1) { /* n is odd */
                    n = 3 * n + 1;
                }
                else { /* n is even */
                    n = n / 2;
                }
                c++;
            }
            max_c = (max_c > c) ? max_c : c;
        }
        
        printf(" %d\n", max_c);
    }

    return 0;
}
