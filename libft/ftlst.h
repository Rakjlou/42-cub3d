/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftlst.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 02:37:36 by nsierra-          #+#    #+#             */
/*   Updated: 2022/03/28 21:59:13 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FTLST_H
# define FTLST_H

# include <stddef.h>
# include "libft.h"

typedef enum e_lst_direction
{
	ASC,
	DESC,
	END
}	t_lst_direction;

typedef struct s_node
{
	void				*data;
	struct s_node		*prev;
	struct s_node		*next;
}	t_node;

typedef struct s_lst
{
	size_t				size;
	t_node				*first;
}	t_lst;

typedef struct s_iter
{
	t_lst				*lst;
	t_node				*current;
	t_node				*end;
	void				*data;
	size_t				pos;
	t_lst_direction		dir;
	int					flag;
}	t_iter;

/* Main functions */
t_lst	*lst_new(void);
t_bool	lst_is_empty(t_lst *lst);
t_node	*lst_node_at(t_lst *lst, size_t pos);
t_node	*lst_node_front(t_lst *lst);
t_node	*lst_node_back(t_lst *lst);
void	*lst_data_at(t_lst *lst, size_t pos);
void	*lst_data_front(t_lst *lst);
void	*lst_data_back(t_lst *lst);
int		lst_push_back(t_lst *lst, void *data);
int		lst_push_front(t_lst *lst, void *data);
void	*lst_pop_back(t_lst *lst, void (*free_fun)(void *));
void	*lst_pop_front(t_lst *lst, void (*free_fun)(void *));
int		lst_insert(t_lst *lst, void *data, size_t pos);
void	lst_change_first_by_pos(t_lst *lst, size_t pos);
void	lst_change_first_by_node(t_lst *lst, t_node *node);
void	*lst_remove(t_lst *lst, size_t pos, void (*free_fun)(void *));
void	lst_swap(t_lst *lst, size_t pos1, size_t pos2);
void	lst_bubble_sort(t_lst *lst, int (*cmp)(void *, void *));
void	lst_print(t_lst *lst, void (*print_f)(void *), int m);
void	lst_destroy(t_lst **lst, void (*f)(void *));
void	lst_destroy_nodes(t_lst *lst, void (*del)(void *));
char	**lst_as_cmatrix(t_lst *lst, int duplicate);

/* Nodes */
t_node	*node_new(void *data);
void	*node_destroy(t_node **node, void (*free_fun)(void *));
void	node_swap(t_node *node1, t_node *node2);
void	node_insert_between(t_node *to_insert, t_node *before, t_node *after);

/* Iterator */
t_iter	*iter_new(t_lst *lst, t_lst_direction dir);
void	iter_init(t_iter *it, t_lst *lst, t_lst_direction dir);
int		iter_next(t_iter *it);

#endif
