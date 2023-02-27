#include <stdio.h>

int main(void)
{
	while (1) {
		for (int i = 1; i < 100; i++) {
			if (i % 3 == 0 && i % 6 == 0)
				// 终止两层循环
				goto END;
			printf("%d 不符合\n", i);
		}
	}
END:
	printf("跳出来了\n");

	return 0;
}
	
