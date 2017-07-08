#include "bits/stdc++.h"
using namespace std;
unsigned arr[5000005],a,b,mod,k;
int main()
{
	//INPUT;
	scanf("%u%u%u%u",&a,&b,&mod,&k);
	for( int i=0 ; i<5000000 ; i++ )
    {
        a = 31014 * (a & 65535) + (a >> 16);
        b = 17508 * (b & 65535) + (b >> 16);
        arr[i] = ((a << 16) + b) % mod;
    }
    nth_element(&arr[0],&arr[k-1],&arr[5000000]);
    printf("%u\n",arr[k-1]);
    return 0;
} 
