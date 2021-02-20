#include <unistd.h>


int doubleorno(char c, char *str, int i)
{
    int r;

    r = 0;
    while(r < i && str[r])
    {
        if(str[r] == c)
            return 1;
		r++;
	}
	return 0;
}

int main(int argc, char **argv) 
{
    int i;

    i = 0;
	if(argc == 3)
	{
    while(argv[1][i])
    	{
        	if(!doubleorno(argv[1][i], argv[1], i) && doubleorno(argv[1][i], argv[2], 13812))
				write(1, &argv[1][i], 1);
			i++;
    	}
	}
	write(1, "\n", 1);
	return 0;
}







