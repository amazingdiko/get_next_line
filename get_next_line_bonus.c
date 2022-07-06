/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmozella <wmozella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 21:15:11 by wmozella          #+#    #+#             */
/*   Updated: 2021/11/19 23:53:24 by wmozella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_separator(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			return (i);
		i ++;
	}
	return (-1);
}

char	*ft_swapfree(char *buff, int check)
{
	char	*mem;

	mem = ft_substr(buff, check + 1, ft_strlen(buff));
	free (buff);
	buff = NULL;
	buff = ft_strdup(mem);
	free (mem);
	mem = NULL;
	return (buff);
}

char	*ft_next_line(char **buff, int check)
{
	char	*line;

	line = ft_substr(*buff, 0, check + 1);
	*buff = ft_swapfree(*buff, check);
	return (line);
}

char	*ft_null_line(char **buff, int ret)
{
	char	*new_line;

	if (ret == 0 && *buff != NULL)
	{
		new_line = ft_strdup(*buff);
		free (*buff);
		*buff = NULL;
		if (ft_strlen(new_line) == 0)
		{
			free (new_line);
			new_line = NULL;
			return (NULL);
		}
		return (new_line);
	}
	return (NULL);
}

char	*get_next_line(int fd)
{
	char		str[BUFFER_SIZE + 1];
	static char	*buff[FD_MAX];
	int			check;
	int			ret;

	check = -1;
	if (fd < 0 || BUFFER_SIZE <= 0 || read (fd, 0, 0))
		return (NULL);
	if (!buff[fd])
	{
		ft_read(str, &ret, fd);
		buff[fd] = ft_strdup(str);
	}
	while (check == -1 && ret != 0)
	{
		check = ft_separator(buff[fd], '\n');
		if (check == -1)
		{
			ft_read(str, &ret, fd);
			buff[fd] = ft_strjoin (buff[fd], str);
		}
		else
			return (ft_next_line(&buff[fd], check));
	}
	return (ft_null_line(&buff[fd], ret));
}
