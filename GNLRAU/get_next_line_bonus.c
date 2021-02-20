

#include "get_next_line_bonus.h"

static char				*ft_checkn(char **aftern, char **line)
{
	char	*n;

	n = NULL;
	if (*aftern)
	{
		if ((n = ft_strchr(*aftern, '\n')))
		{
			*n = '\0';
			*line = ft_strdup(*aftern);
			ft_strcpy(*aftern, ++n);
		}
		else
		{
			*line = ft_strdup(*aftern);
			*aftern = ft_clear(*aftern);
		}
	}
	else
		*line = ft_strdup("");
	return (n);
}

static char				*ft_strjoin(const char *s1, const char *s2)
{
	char			*str;
	char			*tmp;
	int				i;
	int				r;

	i = 0;
	r = 0;
	tmp = (char *)s1;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	if (!(str = (char*)malloc(sizeof(char) * (ft_strlen(s1) + \
	ft_strlen(s2) + 1))))
		return (NULL);
	while (s1[r])
		str[i++] = s1[r++];
	r = 0;
	while (s2[r])
		str[i++] = s2[r++];
	str[i] = '\0';
	free(tmp);
	return (str);
}

static int				get_line(char **aftern, char *buf, int fd, char **line)
{
	char			*p;
	int				bytewr;

	p = ft_checkn(&aftern[fd], line);
	while (aftern[fd] == NULL && (bytewr = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[bytewr] = '\0';
		if ((p = ft_strchr(buf, '\n')))
		{
			*p = '\0';
			if (!(aftern[fd] = ft_strdup(++p)))
			{
				free(buf);
				return (-1);
			}
		}
		if (!(*line = ft_strjoin(*line, buf)))
		{
			free(buf);
			return (-1);
		}
	}
	return (aftern[fd] ? 1 : 0);
}

int						get_next_line(int fd, char **line)
{
	static char		*aftern[256];
	char			*buf;
	int				res;

	buf = 0;
	if (fd < 0 || BUFFER_SIZE < 1 || !line || read(fd, buf, 0))
		return (-1);
	if (!(buf = (char*)malloc(sizeof(char) * BUFFER_SIZE + 1)))
		return (-1);
	res = get_line(aftern, buf, fd, line);
	free(buf);
	return (res);
}
