void hanoi(int n, char A, char B, char C)//¾­µäµÝ¹é
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