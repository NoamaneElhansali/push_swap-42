#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
int *ft_atoi_str(char *nptr,int count)
{
    int *arr_numbres;

    arr_numbres = malloc(count * sizeof(int));
    int (numbre), (positive), (i);
    i = 0;
	while (*nptr)
    {
        numbre = 0;
        positive = 1;
        while ((*nptr >= '\t' && *nptr <= '\r') || *nptr == ' ')
            nptr++;
        if (*nptr == '-' || *nptr == '+')
        {
            if (*nptr == '-')
                positive = -positive;
            nptr++;
        }
        while (*nptr >= '0' && *nptr <= '9')
        {
            numbre = (numbre * 10) + (*nptr - 48);
            nptr++;
        }
        arr_numbres[i++] = numbre * positive;
    }
	return (arr_numbres);
}

static int	ft_count_numbres(char *s)
{
	int	is_numbre;
	int	count;

	is_numbre = 0;
	count = 0;
	while (*s)
	{
        if (!((*s >= '0' && *s <= '9') || (*s == '+' || *s == '-') || (*s >= '\t' && *s <= '\r') || *s == ' '))
            return (-1);
		if (!((*s >= '\t' && *s <= '\r') || *s == ' ') && !is_numbre)
		{
			is_numbre = 1;
			count++;
		}
		else if ((*s >= '\t' && *s <= '\r') || *s == ' ')
            is_numbre = 0;
		s++;
	}
	return (count);
}
void	ft_putstr_fd(char *s, int fd)
{
	if (!s)
		return ;
	while (*s)
		write(fd, s++, 1);
}
void ft_read_para(char **argv)
{
    int count_numbres, i;
    int *numbres;
    while (*argv)
    {
        count_numbres = ft_count_numbres(*argv);
        if (count_numbres >= 0)
        {
            i = 0;
            numbres = ft_atoi_str(*argv,count_numbres);
            while (count_numbres > i)
                printf("%d\n",numbres[i++]);
            free(numbres);

            
        }
        else
        {
            ft_putstr_fd("Error\n",2);
        }
        argv++;
    }
    
}

int main(int argc, char *argv[])
{
    
    // if (argc > 2)
    // {
        ft_read_para(++argv);
        // int count_numbre;
        // count_numbre = ft_count_numbres("1 2a2 1   +1   5 55");
        // if (count_numbre > 0)
        //     printf("%d",count_numbre);
        // else
        //     write(2,"Error\n",7);
    // }
    return 0;
}
