#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int n, q;
    int i, j;
    int count;

    char **strings;
    char **queries;

    printf("Enter number of strings: ");
    scanf("%d", &n);

    strings = (char **)malloc(n * sizeof(char *));

    printf("Enter %d strings:\n", n);

    for (i = 0; i < n; i++)
    {
        strings[i] = (char *)malloc(101 * sizeof(char));
        printf("String %d: ", i + 1);
        scanf("%100s", strings[i]);
    }

    printf("\nEnter number of queries: ");
    scanf("%d", &q);

    queries = (char **)malloc(q * sizeof(char *));

    printf("Enter %d queries:\n", q);

    for (i = 0; i < q; i++)
    {
        queries[i] = (char *)malloc(101 * sizeof(char));
        printf("Query %d: ", i + 1);
        scanf("%100s", queries[i]);
    }

    printf("\nResults:\n");

    for (i = 0; i < q; i++)
    {
        count = 0;

        for (j = 0; j < n; j++)
        {
            if (strcmp(queries[i], strings[j]) == 0)
            {
                count++;
            }
        }

        printf("%s appears %d time(s)\n", queries[i], count);
    }

    for (i = 0; i < n; i++)
    {
        free(strings[i]);
    }

    for (i = 0; i < q; i++)
    {
        free(queries[i]);
    }

    free(strings);
    free(queries);

    return 0;
}
