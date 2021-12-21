#include <stdio.h>
#include <cs50.h>
#include <math.h>

int  main(void)
{
    float f;
    do
    {
        f =  get_float("Change owed: ");
    }
    while (f < 0);
    int cents = round(f * 100);
    int coins = 0;
    while (cents != 0)
    {

        coins += cents / 25;
        cents = cents % 25;
        //
        coins += cents / 10;
        cents %= 10;
        //
        coins += cents / 5;
        cents %= 5;
        //
        coins += cents / 1;
        cents %= 1;
    }

    printf("%d\n", coins);
}