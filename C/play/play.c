#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    int n, k, q;
    scanf("%d %d %d", &n, &k, &q);
    int a[n];
    k = k%n;
    for (int i = 0; i < n; i++)
	scanf("%d", &a[i]);
    for (int i = 0; i < q; i++){
		int temp;
		scanf("%d", &temp);
		int index;
		if (temp >= k) 
		    index = temp - k;
		else
		    index = temp - k + n;
		printf("%d\n", a[index]);
    }
    return 0;
}

