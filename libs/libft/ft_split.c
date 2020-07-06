/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slabelle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 19:45:32 by slabelle          #+#    #+#             */
/*   Updated: 2019/10/24 15:50:56 by slabelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_split_free(char **wrds, int i)
{
	while (i >= 0)
	{
		free(wrds[i]);
		i--;
	}
	free(wrds);
}

char		*ft_split_getword(char const *s, char c)
{
	int		wrd_len;
	char	*wrd;
	int		i;

	wrd_len = 0;
	while (s[wrd_len] && s[wrd_len] != c)
		wrd_len++;
	if (!(wrd = malloc(sizeof(char) * (wrd_len + 1))))
		return (NULL);
	i = 0;
	while (i < wrd_len)
	{
		wrd[i] = s[i];
		i++;
	}
	wrd[i] = '\0';
	return (wrd);
}

const char	*ft_split_move(const char *s, char c, int is_wrd)
{
	if (is_wrd == 0)
	{
		while (*s && *s == c)
			s++;
	}
	else if (is_wrd == 1)
	{
		while (*s && *s != c)
			s++;
	}
	return (s);
}

int			ft_split_getcount(const char *s, char c)
{
	int		wrds_cnt;
	int		i;

	if (s)
	{
		wrds_cnt = 1;
		i = 0;
		while (s[i])
		{
			if (s[i] == c && s[i + 1])
				wrds_cnt++;
			i++;
		}
		return (wrds_cnt);
	}
	return (0);
}

char		**ft_split(char const *s, char c)
{
	int		wrds_cnt;
	char	**wrds;
	int		i;

	wrds_cnt = ft_split_getcount(s, c);
	if (!(wrds = malloc(sizeof(char *) * (wrds_cnt + 1))))
		return (NULL);
	i = 0;
	while (*s && i < wrds_cnt)
	{
		s = ft_split_move(s, c, 0);
		if (*s && *s != c)
		{
			if (!(wrds[i] = ft_split_getword(s, c)))
			{
				ft_split_free(wrds, i - 1);
				return (NULL);
			}
			s = ft_split_move(s, c, 1);
			i++;
		}
	}
	wrds[i] = NULL;
	return (wrds);
}
