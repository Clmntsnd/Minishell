char	*to_lower(char *str)
{
	for (int i = 0; str[i]; i++)
		str[i] = str[i - 32];
	return (str)
}