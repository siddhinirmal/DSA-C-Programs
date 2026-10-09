#include <stdio.h>

int isPrime(int n)
{
    int i;

    if (n < 2)
        return 0;

    for (i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
            return 0;
    }

    return 1;
}

void generatePrimes(int primes[], int q)
{
    int num = 2;
    int count = 0;

    while (count < q)
    {
        if (isPrime(num))
        {
            primes[count] = num;
            count++;
        }

        num++;
    }
}

int main()
{
    int n, q;
    int number[100000];
    int stackA[100000];
    int stackB[100000];
    int stackC[100000];
    int primes[1200];

    int topA, topB, topC;
    int i, j;

    printf("Enter number of plates and number of iterations: ");
    scanf("%d %d", &n, &q);

    printf("Enter %d plate numbers:\n", n);

    for (i = 0; i < n; i++)
    {
        printf("Plate %d: ", i + 1);
        scanf("%d", &number[i]);
    }

    generatePrimes(primes, q);

    printf("\nPrime numbers used: ");

    for (i = 0; i < q; i++)
    {
        printf("%d ", primes[i]);
    }

    printf("\n");

    /* Put all plates into stack A */
    topA = -1;

    for (i = 0; i < n; i++)
    {
        topA++;
        stackA[topA] = number[i];
    }

    printf("\nAll plates are pushed into Stack A.\n");

    /* Perform q iterations */
    for (i = 0; i < q; i++)
    {
        topB = -1;
        topC = -1;

        printf("\n--- Iteration %d ---\n", i + 1);
        printf("Current prime: %d\n", primes[i]);

        /* Process stack A */
        while (topA >= 0)
        {
            int value = stackA[topA];
            topA--;

            if (value % primes[i] == 0)
            {
                topB++;
                stackB[topB] = value;
            }
            else
            {
                topC++;
                stackC[topC] = value;
            }
        }

        printf("Plates divisible by %d:\n", primes[i]);

        /* Print divisible plates */
        while (topB >= 0)
        {
            printf("%d\n", stackB[topB]);
            topB--;
        }

        /* Stack C becomes Stack A */
        topA = -1;

        for (j = 0; j <= topC; j++)
        {
            topA++;
            stackA[topA] = stackC[j];
        }

        printf("Remaining plates moved to Stack A.\n");
    }

    printf("\nRemaining plates:\n");

    /* Print remaining plates */
    while (topA >= 0)
    {
        printf("%d\n", stackA[topA]);
        topA--;
    }

    printf("\nProgram completed successfully.\n");

    return 0;
}
