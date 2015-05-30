/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apantiez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/30 15:42:26 by apantiez          #+#    #+#             */
/*   Updated: 2015/05/30 16:03:27 by apantiez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "philo.h"

static void key_callback(GLFWwindow *window,\
		int key, int scancode, int action, int mods)
{
	(void)mods;
	(void)scancode;
	(void)action;
	(void)key;
	(void)window;
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GL_TRUE);
/*	game = uf_get_game();
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GL_TRUE);
	else if (key == GLFW_KEY_LEFT)
		move_board(game, 1);
	else if (key == GLFW_KEY_RIGHT)
		move_board(game, 0);
	else if (key == GLFW_KEY_P)
		game->paused = 1;
	else if (key == GLFW_KEY_O)
		game->paused = 0;*/
}

void		init_glfw(t_gen *gen)
{
	if (!glfwInit())
		exit(0);
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
	gen->window = glfwCreateWindow(WIN_WIDTH, WIN_HEIGHT,
			"Philo", NULL, NULL);
	if (!gen->window)
	{
		glfwTerminate();
		exit(1);
	}
	glfwMakeContextCurrent(gen->window);
	glfwSwapInterval(1);
	glfwSetKeyCallback(gen->window, key_callback);
}
