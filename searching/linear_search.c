#include <stdio.h>
int main()
{
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    int k;
    scanf("%d", &k);
    for (int i = 0; i < n; i++)
    {
        if (k == arr[i])
        {
            printf("at %d th index the key is present", i);
            break;
        }
    }
    printf("-1");
    return 0;
}