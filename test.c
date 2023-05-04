#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>


char	*mallocseg(char *m, char *s, char c)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	m = (char *)malloc((i + 1) * sizeof(char));
	if (!m)
		return (NULL);
	m[i] = 0;
	return (m);
}

char	*pon(const char **s, char c, char *m)
{
	int	n;

	n = 0;
	if (m == 0)
		return (m);
	while (**s && **s != c)
	{
		m[n ++] = **s;
		(*s)++;
	}
	return (m);
}

int	pridimensioncount(char const *s, char c)
{
	int	p;

	p = 1;
	if (*s == c)
		p--;
	if (!*s)
		return (0);
	while (*s)
	{
		if ((*s == c && *(s + 1) != c) && *(s + 1) != '\0')
			p ++;
		s++;
	}
	return (p);
}

void	m_free(char **m, int i, int p)
{
	while (i - p++)
		free(*(--m));
	free(m);
}

char	**ft_split(char const *s, char c)
{
	char	**m;
	int		p;
	int		i;

	if (!s)
		return (NULL);
	else
		p = pridimensioncount(s, c);
	m = malloc((p + 1) * sizeof(char *));
	if (!m)
		return (NULL);
	i = p;
	m[p] = NULL;
	while (p--)
	{
		while (*s && *s == c)
			s++;
		*m = pon(&s, c, mallocseg(*m, (char *)s, c));
		if (!*m)
			m_free(m, i, p);
		m++;
	}
	return (m - i);
}


size_t	ft_strlen(const char *s)
{
	size_t	l;

	l = 0;
	while (s[l])
		l++;
	return (l);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s;
	int		l;

	if (!s1 || !s2)
		return (NULL);
	l = ft_strlen(s1) + ft_strlen(s2);
	s = malloc(l * sizeof(char) + 1);
	if (s == NULL)
		return (NULL);
	while (*s1)
		*s++ = *s1++;
	while (*s2)
		*s++ = *s2++;
	*s = 0;
	return (s - l);
}

void	ft_freecharmatrix(char **matrix)
{
	int	i;

	i = 0;
	while (matrix[i] != NULL)
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
}


int main(int argc, char **argv)
{
    int i = 0;
    argv = checker(argc, argv);
    while(argv[i])
        printf("%s\n", argv[i++]);
    return(0);
}