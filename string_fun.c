#include "monty.h"

/**
 * _strcmp - function compares strings.
 * @s1: srtring 1.
 * @s2: srtring 2.
 * Return: 0 if both are equal or -1 if not.
 */

int _strcmp(char *s1, char *s2)
{
	int i;

	for (i = 0; s1[i] == s2[i] && s1[i]; i++)
		;
	if (s1[i] > s2[i])
		return (1);
	if (s1[i] < s2[i])
		return (-1);
	return (0);
}

/**
 * searchs - function searchs if the char is in the string.
 * @str: string.
 * @ch: char.
 * Return: 1 if success 0 if not.
 */
int searchs(char *str, char ch)
{
	int cont = 0;

	while (str[cont] != '\0')
	{
		if (str[cont] == ch)
		{
			break;
		}
		cont++;
	}
	if (str[cont] == ch)
		return (1);
	else
		return (0);
}


/**
 * _strtoky - function to split string
 * @s: string.
 * @d: delimiters.
 * Return: the frist string.
 */
char *_strtoky(char *s, char *d)
{
	static char *ultimo;
	int i = 0, j = 0;

	if (!s)
		s = ultimo;
	while (s[i] != '\0')
	{
		if (searchs(d, s[i]) == 0 && s[i + 1] == '\0')
		{
			ultimo = s + i + 1;
			*ultimo = '\0';
			s = s + j;
			return (s);
		}
		else if (searchs(d, s[i]) == 0 && searchs(d, s[i + 1]) == 0)
			i++;
		else if (searchs(d, s[i]) == 0 && searchs(d, s[i + 1]) == 1)
		{
			ultimo = s + i + 1;
			*ultimo = '\0';
			ultimo++;
			s = s + j;
			return (s);
		}
		else if (searchs(d, s[i]) == 1)
		{
			j++;
			i++;
		}
	}
	return (NULL);
}
