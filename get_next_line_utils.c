/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmozella <wmozella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 21:17:56 by wmozella          #+#    #+#             */
/*   Updated: 2021/11/19 23:40:41 by wmozella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		i ++;
	}
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	b;
	size_t	nb;
	size_t	j;
	char	*str;

	b = 0;
	nb = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (str == NULL)
		return (NULL);
	while (s1[j] != '\0')
		str[nb++] = s1[j++];
	while (s2[b] != '\0')
		str[nb++] = s2[b++];
	str[nb] = '\0';
	free (s1);
	s1 = NULL;
	return (str);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char	*str;
	int		i;

	if (!(s))
		return (NULL);
	if (len > ft_strlen(s + start))
		len = ft_strlen(s + start);
	str = (char *)malloc(sizeof(char) * (len + 1));
	i = 0;
	if (str == NULL)
		return (NULL);
	while (len-- && s[start] != '\0' && start < ft_strlen(s))
	{
		str[i] = s[start];
		i ++;
		start ++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_strdup(char *s1)
{
	char	*str;
	size_t	i;

	str = (char *)malloc(sizeof(char) * ft_strlen(s1) + 1);
	i = 0;
	if (str == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i ++;
	}
	str[i] = '\0';
	return (str);
}

void	ft_read(char *str, int *ret, int fd)
{
	*ret = read(fd, str, BUFFER_SIZE);
	str[*ret] = '\0';
}
