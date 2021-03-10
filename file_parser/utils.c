void	skip_space(char *line, int *i)
{
	while (line[*i] == ' ' || (line[*i] >= 8 && line[*i] <= 13))
		*i += 1;
}

int 	is_map(char *line)
{
	if (line[0] == '1' || line[0] == '2' || line[0] == '0' )
    //|| line[0] == 'N'
		//|| line[0] == 'S' || line[0] == 'W' || line[0] == 'E')
		return (1);
	return (0);
}

int		check_name(char *arg, char *ext)
{
	int	i;

	i = 0;
	while (arg[i] != '\0')
		i++;
	if ((i > 4 && arg[i - 1] == ext[2] && arg[i - 2] == ext[1])
		&& (arg[i - 3] == ext[0] && arg[i - 4] == '.'))
		return (1);
	return (0);
}