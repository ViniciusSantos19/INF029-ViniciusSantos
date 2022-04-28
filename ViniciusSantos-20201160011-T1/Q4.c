#include <stdio.h>

int main()
{
    int n = 43211;
    int last_digit;
    int reverse;
    last_digit = n % 10;
    while(n > 0){
        reverse = reverse * 10 + n % 10;
        n = n/10;
    }
    printf("%d ",reverse);
}
