

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

int			get_next_line(int fd, char **line);
char		*ft_strdup(const char *s1);
char		*ft_strchr(const char *s, int c);
size_t		ft_strlen(const char *s);
char		*ft_strcpy(char *s1, const char *s2);
char		*ft_clear(char *s);

#endif
