#include<stdio.h>
int main() {
    int n, a, b, d, i, c, e = 0, t = 1000000000;
    scanf("%d", &n);
    for (i = 1; i <= n; i++) {
        scanf("%d %d", &a, &b);
        d = a / b;
        c = a / (b + 1) + 1;
        if (c > e)
            e = c;
        if (t > d)
            t = d;
    }
    printf("%d %d", e, t);

    return 0;
}