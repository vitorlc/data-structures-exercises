#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

bool vogal(char c);

int main()
{
    int n, i, j, count, casos;
    char palavra[1000];

    scanf("%d", &casos);

    int res[casos];
    getchar();
    for (i = 0; i < casos; i++){
        count = 0;
        fgets(palavra, 100, stdin);
        for (j = 0; j < strlen(palavra); j++){
            if (vogal(palavra[j]))
            {
                count++;
            }
        }
        res[i] = count;
    }

    for (i = 0; i < casos; i++)
    {
        printf("%d\n", res[i]);
    }

    return 0;
}

bool vogal(char c)
{
    c = toupper(c);
    if (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U')
        return true;
    else
        return false;
}
