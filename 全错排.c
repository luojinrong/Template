long long qcp(int n)
{
	if (n == 1)
		return 0;
	else if (n == 2)
		return 1;
	else
		return (qcp(n - 1) + qcp(n - 2))*(n - 1);
}