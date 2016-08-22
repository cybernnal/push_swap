/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbillard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/07 13:46:15 by tbillard          #+#    #+#             */
/*   Updated: 2016/05/20 21:34:14 by tbillard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	algo(t_env *env, int argc)
{
	if (!is_sort(env->p1, env->first1))
		return ;
	if (!is_rsort(env->p1, env->first1) || is_psort(env->p1, env->first1)
			|| argc <= 80)
	{
		sort_round(env);
		return ;
	}
	else
		sort_quick(env);
}

void	opt(t_env *env, int *argc, char ***argv)
{
	if ((ft_strcmp((*argv)[1], "-h") == 0))
	{
		ft_printf("Les options du push_swap:\n");
		ft_printf("'-o': Affiche le nombre d'operations.\n");
		ft_printf("'-l': Affiche la liste une fois triee.\n");
		ft_printf("'-v': Affiche la liste a chaque operations.\n");
		ft_printf("'-p': Affiche a cote des nombres 1 ou 0 s'ils ont ete");
		ft_printf("piveau ou non (quick sort).\n'-c': Affiche les ");
		ft_printf("differentes operations en differentes couleurs.\n");
		ft_printf("'-m': N'affiche pas les operations.\n'-qs' ou '-bs': ");
		ft_printf("permet de choisir l'algorithme a utiliser:\n\t'-qs': ");
		ft_printf("quick sort (par default pour les listes superieures a 80 ");
		ft_printf("elements).\n\t'-bs': buble sort (par default pour les ");
		ft_printf("listes inferieures a 80 elements et les listes reversed ");
		ft_printf("(ou presque)).\n");
		exit(0);
	}
	opt3(env, argc, argv);
	opt2(env, argc, argv);
}

void	init(t_env *env)
{
	env->p1 = NULL;
	env->p2 = NULL;
	env->first1 = NULL;
	env->first2 = NULL;
	env->op = 0;
	env->flag = 0;
}

void	end(t_env env)
{
	if (env.op)
		ft_putendl("");
	if (env.flag & 16)
		ft_printlst_p(env.p1);
	if (env.flag & 8)
	{
		ft_putstr("nombre d'op: ");
		ft_putnbr(env.op);
		ft_putendl("");
	}
}

int		main(int argc, char **argv)
{
	t_env		env;

	if (argc == 1 || (argv[argc - 1][0] == '-' && (argv[argc - 1][1] < '0'
					|| argv[argc - 1][1] > '9')))
		return (0);
	init(&env);
	opt(&env, &argc, &argv);
	if (argc == 1)
		return (0);
	sig_flag(&env, 1);
	if (dblon(argc, argv, &env) == -1 || build_lst(&env, argc) == -1)
		return (ft_error());
	if (env.flag & 32)
		sort_round(&env);
	if (env.flag & 64)
		sort_quick(&env);
	if (is_sort(env.p1, env.first1))
	{
		exept(&env, argc);
		algo(&env, argc);
	}
	end(env);
	free_lst(&env.p1);
	return (0);
}
