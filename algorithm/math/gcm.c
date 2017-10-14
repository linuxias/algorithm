int gcm(int a, int b)
{
	if (b == 0)
		return a;
	return gcm(b, a%b);
}

