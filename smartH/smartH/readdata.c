#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
typedef struct
{
	char Light[10];
	char Fan[10];
	char Motor[10];
}SmartHome;
int main()
{
	int buffer[20] = { 0 };
	FILE* pf = fopen("data1.txt", "a+");
	SmartHome A = { 0 };
	if (pf != 0)
	{
		printf("Mo file thanh cong");
		char* key1 = "\"light\": \"";
		char* key2 = "\"fan\": \"";
		char* key3 = "\"motor\": \"";
		while (fgets((char*)buffer, sizeof(buffer), pf) != NULL)
		{
			char* key1_pos = strstr((const char*)buffer, key1);
			char* key2_pos = strstr((const char*)buffer, key2);
			char* key3_pos = strstr((const char*)buffer, key3);
			if (key1_pos != NULL)
			{
				int cnt1 = 0;
				key1_pos += strlen(key1);
				while (key1_pos[cnt1] != '\"')
				{
					A.Light[cnt1] = key1_pos[cnt1];
					cnt1++;
				}
			}
			if (key2_pos != NULL)
			{
				int cnt2 = 0;
				key2_pos += strlen(key2);
				while (key2_pos[cnt2] != '\"')
				{
					A.Fan[cnt2] = key2_pos[cnt2];
					cnt2++;
				}
			}
			if (key3_pos != NULL)
			{
				int cnt3 = 0;
				key3_pos += strlen(key3);
				while (key3_pos[cnt3] != '\"')
				{
					A.Motor[cnt3] = key3_pos[cnt3];
					cnt3++;
				}
			}
		}
		fclose(pf);
	}
	else printf("Mo file that bai");
	printf("\r\nDen: %s\r\nQuat: %s\r\nDong Co: %s",A.Light, A.Fan, A.Motor);
}