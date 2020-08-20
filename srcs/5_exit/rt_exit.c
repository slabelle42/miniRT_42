/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slabelle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/28 20:49:12 by slabelle          #+#    #+#             */
/*   Updated: 2020/07/28 20:49:13 by slabelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	rt_exit_displayerror(int error_nb, char *message)
{
	ft_putstr_fd("Error ", 1);
	ft_putnbr_fd(-error_nb, 1);
	ft_putstr_fd(": ", 1);
	ft_putendl_fd(message, 1);
}

static char	*rt_exit_getmore(int error_nb)
{
	if (error_nb == ERR_ELEM_UNIQ)
		return ("R and A elements must be unique :o");
	else if (error_nb == ERR_ELEM_UNKN)
		return ("unknown element in .rt file :/");
	else if (error_nb == ERR_ELEM_MISS)
		return ("missing element in .rt file :/");
	else if (error_nb == ERR_ELEM_WRG)
		return ("invalid element description :/");
	else if (error_nb == ERR_INFO_NULL)
		return ("informations must be > 0 :o");
	else if (error_nb == ERR_INFO_DIGIT)
		return ("there is a limit of 5 digits, sorry :o");
	else if (error_nb == ERR_LIMIT)
		return ("you must check values limits :o");
	else if (error_nb == ERR_SHAD)
		return ("unknown value, sh must be set to 0 :o");
	else if (error_nb == ERR_MALLOC)
		return ("malloc fail D:");
	else if (error_nb == ERR_MLX)
		return ("minilibx fail D:");
	return ("not specified... yet ;)");
}

static char	*rt_exit_getmessage(int error_nb)
{
	if (error_nb == ERR_AC)
		return ("wrong number of arguments :'(");
	else if (error_nb == ERR_FILE_RT)
		return ("wrong file type :'( I need a .rt file");
	else if (error_nb == ERR_FILE_UNKN)
		return ("wrong file name :'( I can't find it");
	return (rt_exit_getmore(error_nb));
}

void		rt_exit(int error_nb)
{
	char	*message;

	if (error_nb < 0)
	{
		message = rt_exit_getmessage(error_nb);
		rt_exit_displayerror(error_nb, message);
		exit(-1);
	}
	ft_putendl_fd("Thanks for trying MiniRT :D", 1);
	exit(0);
}

void		rt_exit_parse(t_rt *rt, int error_nb)
{
	free(rt->file->line);
	close(rt->file->fd);
	ft_putstr_fd("( Stop on line ", 1);
	ft_putnbr_fd(rt->file->line_nb, 1);
	ft_putendl_fd(" )", 1);
	rt_exit(error_nb);
}
