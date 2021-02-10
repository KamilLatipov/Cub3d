#ifndef CUB3D_CUB3D_H
# define CUB3D_CUB3D_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct	s_list
{

}				t_list

int		get_next_line(int fd, char **line);
int		ft_strlen(const char *s);
char	*ft_strjoin(char *s1, char *s2, int length, int i);
char	*ft_get_line(int fd, char **line, char *remainder, int *ret);
char	*ft_free(char *buffer, char *remainder);
int 	main(int fd, char *argv[]);

#endif
