/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhastag <skhastag@student.42heilbornn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 18:59:04 by skhastag          #+#    #+#             */
/*   Updated: 2024/04/10 20:32:06 by skhastag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int				value;
	int				index;
	int				push_cost;
	int				upper_middle;
	int				lowest_moves;
	struct s_stack	*target_node;
	struct s_stack	*next_node;
	struct s_stack	*prev_node;
}					t_stack_node;

int					is_integer(const char *str);
int					is_in_int_range(const char *str);
int					is_integers(char *argv[]);
int					has_duplicates(char *argv[]);
int					input_error(int argc, char *argv[]);

int					ft_check_space(int ch);
int					ft_check_digit(int ch);
int					ft_check_sign(const char *str, int *index);
int					ft_atoi(char const *str);

size_t				count_words(char const *s, char c);
size_t				get_word_len(char const *s, char c);
void				free_array(size_t i, char **array);
char				**main_split_work(char const *s, char c, char **array,
						size_t tot_words);
char				**ft_split(char const *s, char c);

void				push(t_stack_node **dest, t_stack_node **src);
void				push_to_a_from_b(t_stack_node **a, t_stack_node **b);
void				push_to_b_from_a(t_stack_node **a, t_stack_node **b);

void				rev_rotate(t_stack_node **head_node);
void				rev_rotate_a(t_stack_node **a);
void				rev_rotate_b(t_stack_node **b);
void				rev_rotate_both(t_stack_node **a, t_stack_node **b);

void				rotate(t_stack_node **head_node);
void				rotate_a(t_stack_node **a);
void				rotate_b(t_stack_node **b);
void				rotate_both(t_stack_node **a, t_stack_node **b);

void				swap(t_stack_node **stack);
void				swap_a(t_stack_node **a);
void				swap_b(t_stack_node **b);
void				swap_ab(t_stack_node **a, t_stack_node **b);

void				set_target_a(t_stack_node *a, t_stack_node *b);
void				cost_analysis_a(t_stack_node *a, t_stack_node *b);
void				set_cheapest(t_stack_node *stack);
void				init_nodes_a(t_stack_node *a, t_stack_node *b);

void				set_target_b(t_stack_node *a, t_stack_node *b);
void				init_nodes_b(t_stack_node *a, t_stack_node *b);
void				sort_three(t_stack_node **a);

void				append_node(t_stack_node **head, int n);
void				init_stack_a(t_stack_node **a, char *argv[], int flag);
t_stack_node		*get_cheapest(t_stack_node *head);
size_t				str_len(const char *str);
void				prep_for_push(t_stack_node **stack, t_stack_node *top_node,
						int is_stack_a);

int					stack_sorted(t_stack_node *stack);
t_stack_node		*find_min_node(t_stack_node *stack);
t_stack_node		*find_max_node(t_stack_node *stack);
void				node_indexing(t_stack_node *stack);
t_stack_node		*ft_lstlast(t_stack_node *lst);

long				ft_atol(char const *str);
int					ft_lstsize(t_stack_node *lst);
char				*ft_substr(char const *s, unsigned int start, size_t len);

int					main(int argc, char *argv[]);
void				free_stack(t_stack_node **stack);
void				free_argv(char *argv[]);
void				sort_stacks(t_stack_node **a, t_stack_node **b);
void				move_b_to_a(t_stack_node **a, t_stack_node **b);
void				move_a_to_b(t_stack_node **a, t_stack_node **b);
void				sort_main_rev_rotate_both(t_stack_node **a,
						t_stack_node **b, t_stack_node *cheapest_node);
void				sort_main_rotate_both(t_stack_node **a, t_stack_node **b,
						t_stack_node *cheapest_node);

#endif
