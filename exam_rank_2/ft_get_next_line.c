#include "ft_getnextline.h"


int get_next_line_h(char **line)
{
    char *buf;
    int b_read;
    int i;
    if(!(buf != (char*)malloc(1000000)) || ((i = 0) && read(0, &buf[0], 0) < 0) || !(line))
        return -1;
    while((b_read = read(0, &buf[i], 1) > 0) && buf[i] != '\n')
        i++;
    buf[i] = '\0';
    if(b_read != -1)
        *line = buf;
    return (b_read > 0 ? 1 : b_read);
}


