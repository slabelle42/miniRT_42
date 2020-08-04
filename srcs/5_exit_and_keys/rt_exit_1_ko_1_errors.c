/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_exit_1_ko_1_errors.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slabelle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/24 13:06:37 by slabelle          #+#    #+#             */
/*   Updated: 2020/07/24 13:06:38 by slabelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	rt_exit_ko_limit(int error_nb)
{
	if (error_nb == ERR_LIMIT_AMB)
		rt_exit_ko_message(error_nb,
			"ambiant light ratio limits are [0.0,1.0] :o");
	else if (error_nb == ERR_LIMIT_FOV)
		rt_exit_ko_message(error_nb, "camera fov limits are [0,180] :o");
	else if (error_nb == ERR_LIMIT_LIGHT)
		rt_exit_ko_message(error_nb, "light ratio limits are [0.0,1.0] :o");
	else if (error_nb == ERR_LIMIT_COLOR)
		rt_exit_ko_message(error_nb, "color R,G,B limits are [0-255] :o");
	else if (error_nb == ERR_MALLOC)
		rt_exit_ko_message(error_nb, "malloc fail D:");
	else
		ft_putendl_fd("Error 0: not specified... yet ;)", 1);
	exit(-1);
}

static void	rt_exit_ko_information(int error_nb)
{
	if (error_nb == ERR_INFO_UNKN_OUT)
		rt_exit_ko_message(error_nb, "unknown character between infos :/");
	else if (error_nb == ERR_INFO_UNKN_IN)
		rt_exit_ko_message(error_nb, "unknown character before value :/");
	else if (error_nb == ERR_INFO_COMMA)
		rt_exit_ko_message(error_nb, "you must use , to separate values :o");
	else if (error_nb == ERR_INFO_DOT)
		rt_exit_ko_message(error_nb, "you must follow a . by a number :o");
	else if (error_nb == ERR_INFO_DIGIT)
		rt_exit_ko_message(error_nb, "there is a limit of 10 digits, sorry :o");
	else if (error_nb == ERR_INFO_NULL)
		rt_exit_ko_message(error_nb, "informations must be > 0 :o");
	else if (error_nb == ERR_INFO_SHAD)
		rt_exit_ko_message(error_nb, "unknown value, sh must be set to 0 :o");
	else if (error_nb > ERR_INFO_SHAD)
		rt_exit_ko_limit(error_nb);
	exit(-1);
}

static void	rt_exit_ko_element(int error_nb)
{
	if (error_nb == ERR_ELEM_UNKN)
		rt_exit_ko_message(error_nb, "unknown element in .rt file :/");
	else if (error_nb == ERR_ELEM_UNIQ)
		rt_exit_ko_message(error_nb, "R and A elements must be unique :o");
	else if (error_nb == ERR_ELEM_MISS)
		rt_exit_ko_message(error_nb, "missing information in this element :o");
	else if (error_nb > ERR_ELEM_MISS)
		rt_exit_ko_information(error_nb);
	exit(-1);
}

void		rt_exit_ko(int error_nb)
{
	if (error_nb == ERR_FILE_NAME_MISS)
		rt_exit_ko_message(error_nb, "missing argument :'( I need a file name");
	else if (error_nb == ERR_FILE_NAME_RT)
		rt_exit_ko_message(error_nb, "wrong file type :'( I need a .rt file");
	else if (error_nb == ERR_FILE_NAME_UNKN)
		rt_exit_ko_message(error_nb, "wrong file name :'( I can't find it");
	else if (error_nb == ERR_FILE_RES)
		rt_exit_ko_message(error_nb, "no resolution in .rt file, try again :p");
	else if (error_nb == ERR_FILE_CAM)
		rt_exit_ko_message(error_nb, "no camera available, what a shame :p");
	else if (error_nb == ERR_FILE_LIGHT)
		rt_exit_ko_message(error_nb, "no light to see, it's too sad :p");
	else if (error_nb == ERR_FILE_OBJ)
		rt_exit_ko_message(error_nb, "no object to show, be more creative :p");
	else if (error_nb > ERR_FILE_OBJ)
		rt_exit_ko_element(error_nb);
	exit(-1);
}
