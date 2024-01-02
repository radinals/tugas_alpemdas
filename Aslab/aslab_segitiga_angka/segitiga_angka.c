#include <stdio.h>

int
main()
{
	int pattern = 95371;

	for (int i = 1; (pattern / i) > 0; i *= 10) {
		int k = 1;
		while ((pattern / k) > 0) k *= 10;

		for (int j = k; j > 0; j /= 10) {
			int p = (pattern / i) / j % 10;
			if (p == 0)
				putchar(' ');
			else
				printf("%d ", p);
		}

		putchar('\n');
	}
	return 0;
}
