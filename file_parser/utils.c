void	skip_space(char *line, int *i)
{
	while (line[*i] == ' ' || line[*i] >= 8 && line[*i] <= 13)
		*i += 1;
}

int 	is_map(char *line)
{
	if (line == '1' || line == '2' || line == '0' || line == 'N'
		|| line == 'S' || line == 'W' || line == 'E')
		return (1);
	return (0);
}