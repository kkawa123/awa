#include <stdio.h>

int Max(int x, int y)
{
	if (x > y)
		return x;
	else
		return y;
}



int main()
{
	int x = 0;
	int y = 0;
	printf("请输入要比较的两个数:");

	scanf("%d%d", &x, &y);
	int max = 0;
	max = Max(x, y);
	printf("%d\n", max);
	return 0;
}
//我好niubi