void hanoi(int n, char A, char B, char C)//����ݹ�
{
	if (n == 1)
		printf("from %c to %c\n", A, C);
	else
	{
		hanoi(n - 1, A, C, B);
		hanoi(1, A, B, C);
		hanoi(n - 1, B, A, C);
	}
}