#include<stdio.h>
#include<math.h>
#include<string.h>

char A[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
char a[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
char num[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

int main()
{
	int lw = 0;                //行宽
	int s = 0;                 //校验级
	char code[10] = {0};       //词
	int n = 0;                 //数据码字数
	int l = 0;                 //词长度
	int k = 0;                 //校验码字数
	int m = 0;                 //有效码字数量
	int Date[10] = {0};        //数据码字
	int DM[20] = {0};          //有效数据码字
	int cu = 0;
	
	scanf("%d", &lw);
	scanf("%d", &s);

	if (s == -1)
	{
		k = 0;
	}
	else
	{
		k = pow(2, s + 1);
	}

	scanf("%s", code);
	l = strlen(code);
	
	int ty = 1; //1表示大写，2表示小写，3表示数字
	for (int i = 0; i < l; i++)
	{
		if (code[i] > 'A' && code[i] < 'Z')
		{
			if (ty == 2)
			{
				DM[n++] = 27;
				ty = 1;
			}
			else if (ty == 3)
			{
				DM[n++] = 28;
				ty = 1;
			}
			for (int j = 0; j < 25; j++)
			{
				if (A[j] == code[i])
				{
					DM[n++] = j;
					break;
				}
			}
		}
		else if (code[i] > 'a' && code[i] < 'z')
		{
			if (ty != 2)
			{
				DM[n++] = 27;
				ty = 2;
			}
			for (int j = 0; j < 25; j++)
			{
				if (a[j] == code[i])
				{
					DM[n++] = j;
					break;
				}

			}
		}
		else if (code[i] > '0' && code[i] < '9')
		{
			if (ty != 3)
			{
				DM[n++] = 28;
				ty = 3;
			}
			for (int j = 0; j < 10; j++)
			{
				if (num[j] == code[i])
				{
					DM[n++] = j;
					break;
				}
			}
		}
	}
	if (n % 2 != 0)
	{
		DM[n++] = 29;
	}
	

	for (; m < n / 2; m++)
	{
		Date[m] = DM[m * 2] * 30 + DM[m * 2 + 1];
	}

	cu = 1 + m + k;
	for (int i = 0; i < lw - cu % lw; i++)
	{
		Date[m++] = 900;
	}
	printf("%d\n", m + 1);//用于计算校验码字的数据码字
	for (int i = 0; i < m; i++)
	{
		printf("%d\n", Date[i]);
	}
	

	return 0;
}
