#include <stdio.h>

int ackermann(int m, int n);


int main () {
    int n1, n2;

    scanf("%d %d", &n1, &n2);
    
    printf("%d\n", ackermann(n1, n2));

    return 0;
}

int ackermann(int m, int n) {
    if (m == 0){
        return n + 1;
    } else if (n == 0 && m > 0) {
        return ackermann(m-1, 1);
    } else if (n > 0 && m> 0) {
        return ackermann(m-1, ackermann(m, n-1));
    }

}