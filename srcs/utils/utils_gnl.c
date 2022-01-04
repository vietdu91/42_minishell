/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_gnl.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emtran <emtran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 11:44:28 by emtran            #+#    #+#             */
/*   Updated: 2022/01/04 12:14:26 by emtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*ft_pushinyourline(char *save)
{
	char	*str;
	int		i;

	i = 0;
	if (!save)
		return (0);
	while (save[i] != '\0' && save[i] != '\n')
		i++;
	str = ft_strcalloc((size_t)i);
	if (str == NULL)
		return (NULL);
	i = 0;
	while (save[i] != '\0' && save[i] != '\n')
	{
		str[i] = save[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

int	ft_secu_av_tout(char *save)
{
	if (save)
	{
		free(save);
		save = NULL;
	}
	return (-1);
}

int	ft_n_ta_race(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*ft_savebryan(char *save)
{
	char	*str;
	int		i;
	int		j;
	int		len;

	i = 0;
	j = 0;
	len = ft_strlen(save);
	while (save[i] != '\0' && save[i] != '\n')
		i++;
	str = ft_strcalloc(len - i + 1);
	if (!str)
		return (NULL);
	i++;
	while (i < len)
		str[j++] = save[i++];
	str[j] = '\0';
	if (save)
		free(save);
	return (str);
}

int	get_next_line(int fd, char **line)
{
	char			buff[BUFFER_SIZE + 1];
	static char		*save;
	int				ret;

	if (BUFFER_SIZE < 1 || fd < 0 || fd > 1024
		|| !line || read(fd, NULL, 0) != 0)
		return (ft_secu_av_tout(save));
	ret = 1;
	while (ft_n_ta_race(save) == 0 && ret != 0)
	{
		ret = read(fd, buff, BUFFER_SIZE);
		if (ret == -1)
			return (ft_secu_av_tout(save));
		buff[ret] = '\0';
		save = ft_strjoin(save, buff);
	}
	*line = ft_pushinyourline(save);
	save = ft_savebryan(save);
	if (ret == 0)
	{
		free(save);
		save = NULL;
		return (0);
	}
	return (1);
}