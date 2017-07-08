#include "bits/stdc++.h"
using namespace std;
 
int arr[30003], B[30003];
int len, n;
void sqrt_decompose()
{
	double l = sqrt(n);
	len = (int)ceil(n / l);
	int flip = 0;
	while (1)
	{
		sort(B + flip*len, B + min(flip*len + len, n));
		flip++;
		if (flip*len + len > n){
			sort(B + flip*len, B + n);
			break;
		}
	}
}
int query(int i, int j, int K)
{
	int ans = 0;
	int startblock = i / len;
	int endblock = j / len;
	if (startblock == endblock){
		for (int k = i; k <= j; k++)if (arr[k]>K)ans++;
		return ans;
	}
	for (int k = i; k <= (startblock + 1)*len - 1; k++)if (arr[k] > K)ans++;
	for (int k = startblock + 1; k <= endblock - 1; k++)ans += len - (upper_bound(B + k*len, B + min(k*len + len, n), K) - (B + k*len));
	for (int k = endblock*len; k <= j; k++)if (arr[k] > K)ans++;
	return ans;
}
int main()
{
	//READ;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
		B[i] = arr[i];
	}
	sqrt_decompose();
	int q, a, b, c, i, j, k, ans = 0;
	scanf("%d", &q);
	while (q--)
	{
		scanf("%d%d%d", &a, &b, &c);
		i = a^ans;
		j = b^ans;
		k = c^ans;
		if (i < 1)i = 1;
		if (j > n)j = n;
		if (i > j) {
			ans = 0;
			printf("0\n");
			continue;
		}
		i--, j--;
		ans = query(i, j, k);
		printf("%d\n", ans);
	}
}
 
