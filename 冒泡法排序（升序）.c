void px(int jg[], int sl[], int n)//�뽻������һ��ʹ��Ч������
{
	int i, j;
	for (i = 0; i<n - 1; i++)
		for (j = 0; j<n - 1 - i; j++)
			if (jg[j] > jg[j + 1])
			{
				swap(&jg[j], &jg[j + 1]);
				swap(&sl[j], &sl[j + 1]);
			}
}