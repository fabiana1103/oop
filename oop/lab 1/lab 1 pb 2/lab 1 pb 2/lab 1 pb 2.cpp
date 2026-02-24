#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main()
{
	char s[1000];
	char a[1000][1000];
	printf("introdu propozitia: ");
	if (!fgets(s, sizeof(s), stdin)) return 0;

	char* nl = strchr(s, '\n');
	if (nl) *nl = '\0';

	int n = 0;
	char* p = strtok(s, " ");
	while (p && n < 1000)
	{
		strncpy(a[n], p, 999);
		a[n][999] = '\0';
		n++;
		p = strtok(NULL, " ");
	}

	for (int i = 0; i < n - 1; ++i)
	{
		for (int j = i + 1; j < n; ++j)
		{
			int len1 = (int)strlen(a[i]);
			int len2 = (int)strlen(a[j]);
			int ok = 0;

			if (len2 > len1) {
				ok = 1;
			}
			else if (len1 == len2) {
				if (strcmp(a[i], a[j]) > 0) {
					ok = 1;
				}
			}

			if (ok) {
				char aux[1000];
				strcpy(aux, a[i]);
				strcpy(a[i], a[j]);
				strcpy(a[j], aux);
			}
		}
	}

	for (int i = 0; i < n; ++i) {
		printf("%s\n", a[i]);
	}

	return 0;
}