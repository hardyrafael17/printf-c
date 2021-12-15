
void	ft_bzero(void *s, size_t n)
{
	char			*cadena;
	size_t			i;

	cadena = (char *) s;
	i = 0;
	while (i < n)
	{
		cadena[i] = '\0';
		i++;
	}	
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*puntero;

	puntero = (void *)malloc(size * count);
	if (puntero == NULL)
		return (NULL);
	ft_bzero(puntero, size * count);
	return (puntero);
}
///////////Itoa////////////////
static void	min_neg(int o, char *cad)
{
	char	*num2;
	int		x;

	x = 0;
	num2 = "-2147483648";
	if (o == -2147483648)
	{
		while (num2[x] != '\0')
		{
			cad[x] = num2[x];
			x++;
		}
	}
}

static void	acaracteres(int o, int i, int n, char *cad)
{
	int	num;

	num = i;
	if (n < 0)
		n = n * -1;
	while (i >= 0)
	{
		cad[i] = (n % 10) + '0';
		n = n / 10;
		i--;
	}
	n = 0;
	cad[num + 1] = '\0';
	while (n <= num && o > 0)
	{
		cad[n] = cad[n + 1];
		n++;
	}
	if (o < 0)
		cad[0] = '-';
}

char	*ft_itoa(int num)
{
	int		i;
	char	*cad;
	int		n;
	int		o;

	o = num;
	n = num;
	i = 0;
	if (num < 0)
		num = num * -1;
	while (num != 0)
	{
		num = num / 10;
		i++;
	}
	cad = (char *)ft_calloc(i + 2, sizeof(char));
	if (cad == NULL)
		return (NULL);
	if (o == -2147483648)
	{
		min_neg(o, cad);
		return (cad);
	}
	acaracteres(o, i, n, cad);
	return (cad);
}


int	ft_printstring(char *str, int size)
{
	int	i;

	i = 0;
	if (!str)
	{
		write(1, "(null)", 6);
		return (size + 6);
	}
	while (str[i])
	{
		write(1, &str[i++], 1);
		size++;
	}
	return (size);
}


char    *ft_itoa_void(unsigned long int n, char *base)
{
        int			size;
        char			*a;
        unsigned long int       num;

        size = 0;
        num = n;
        if (num == 0)
                size++;
        while (num != 0)
        {
                num = num / 16; 
                size++;
        }
        a = malloc(size + 1); 
        a[size] = '\0';
        size--;
        while (n >= 16 && 0 < size)
        {
                a[size] = base[n % 16];
                n = n / 16; 
                size--;
        }
        a[size--] = base[n % 16];
        return (a);
}


size_t	printstr(char *str)
{
	int	i;
	size_t printedChars;

	printedChars = 0;
	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
		printedChars++;
	}
	return (printedChars);
}

int	ft_printchar(char c, int word_count)
{
	write(1, &c, 1);
	word_count++;
	return (word_count);
}

int	ft_printvoid(void *ptr, int word_count)
{
	long int	ptrnum;
	char		*strnum;
	int			i;

	i = 0;
	ptrnum = (unsigned long int)ptr;
	strnum = ft_itoa_void(ptrnum, "0123456789abcdefg");
	write(1, "0x", 2);
	word_count += 2;
	while (strnum[i])
	{
		write(1, &strnum[i], 1);
		i++;
		word_count++;
	}
	free(strnum);
	return (word_count);
}


int	ft_lp(char *str, int size)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i++], 1);
		size++;
	}
	free(str);
	return (size);
}

char	*ft_itoa_unsig(unsigned int n)
{
	char			*a;
	int				size;
	unsigned int	num;

	size = 0;
	num = n;
	if (num == 0)
		size++;
	while (num != 0)
	{
		num = num / 10;
		size++;
	}
	a = (char *)malloc((size + 1) * sizeof(char));
	if (!a)
		return (0);
	a[size--] = '\0';
	while (n >= 10)
	{
		a[size] = n % 10 + '0';
		n = n / 10;
		size--;
	}
	a[size--] = n + '0';
	return (a);
}

char	*ft_ib(unsigned int n, char *base)
{
	int				size;
	char			*a;
	unsigned int	num;

	size = 0;
	num = n;
	if (num == 0)
		size++;
	while (num != 0)
	{
		num = num / 16;
		size++;
	}
	a = malloc(size + 1);
	a[size] = '\0';
	size--;
	while (n >= 16 && 0 < size)
	{
		a[size] = base[n % 16];
		n = n / 16;
		size--;
	}
	a[size--] = base[n % 16];
	return (a);
}

int	ft_formatter(va_list args, char c, int word_count)
{
	if (c == 'c')
		word_count = ft_printchar(va_arg(args, int), word_count);
	if (c == 's')
		word_count = ft_printstring(va_arg(args, char *), word_count);
	if (c == 'p')
		word_count = ft_printvoid(va_arg(args, void *), word_count);
	if (c == 'd' || c == 'i')
		word_count = ft_lp(ft_itoa(va_arg(args, int)), word_count);
	if (c == 'u')
		word_count = ft_lp(ft_itoa_unsig(va_arg(args, unsigned int)), word_count);
	if (c == 'x')
		word_count = ft_lp(ft_ib(va_arg(args, int), "0123456789abcdef"), word_count);
	if (c == 'X')
		word_count = ft_lp(ft_ib(va_arg(args, int), "0123456789ABCDEF"), word_count);
	if (c == '%')
	{
		write(1, "%", 1);
		word_count++;
	}
	return (word_count);
}

