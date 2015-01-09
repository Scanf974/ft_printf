int		ft_wstrlen(char *str)
{
	int		i;
	int		len;
	int		flag;

	i = 0;
	len = 0;
	while (str[i])
	{
		flag = 0;
		while (str[i] < 0 || str[i] > 127)
		{
			i++;
			flag = 1;
		}
		len++;
		if (!flag)
			i++;
	}
	return (len);
}
