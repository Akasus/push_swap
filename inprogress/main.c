/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumeis <lbaumeis@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 20:09:54 by lbaumeis          #+#    #+#             */
/*   Updated: 2024/04/15 14:24:51 by lbaumeis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include <stdio.h>




// int		ft_find(char *str, int c);
// int		valid_arg(char **av);

int	ft_find(char *str, int c)
{
	int	i;
	int	occ;


	i = 0;
	occ = 0;
	while (str[i])
	{
		if (str[i] == c)
			occ++;
		i++;
	}
	if (c == '\0')
		return (1);
	else if (occ == 0)
		return (-1);
	return (occ);
}

int	valid_arg(char **av)
{
	int		x;
	char	*in;

	x = 0;
	in = av[1];
	if (ft_find(in, ' ') == -1)
	{
		if (ft_atoi(in) >= INT_MIN && ft_atoi(in) <= INT_MAX)
			return (ft_printf("only one number\n"), 0);
		else
			return (ft_printf("not valid\n"), 0);
	}
	if (in[0] == '-')
		x++;

	else if (in[0] == ' ')
		return (0);


	while (in[x])
	{
		if (in[x] == '-' && ft_isdigit(in[x + 1]))
			x++;
		while (in[x] && ft_isdigit(in[x]))
			x++;
		if (in[x] == ' ' && (in[x + 1] == '-' || ft_isdigit(in[x + 1])))
			x++;
	}
	
	return (1);
}

// int main(int ac, char **av)
// {
// 	if (ac <= 1 || (ac == 2 && !valid_arg(av)))
//  		return (0);	

// 	t_list *head=malloc(sizeof(t_list));

// 	if(!head)
// 		return (0);

// 	head->data = 1;
// 	head->prev = NULL;

// 	t_list * current = head;

// 	for(int i = 0; i < 10; i++) {
// 		t_list* node = malloc(sizeof(t_list));

// 		node->data = i;
// 		current->next = node;
// 		node->prev = current;
// 		current = node;
// 	}

// 	current = head;
// 	for (size_t i = 0; i < 10; i++)
// 	{
// 		printf("Address: %p | next: %p | prev: %p | Value %d\n", *&current,*&current->next,*&current->prev, current->data);
// 		current = current->next;
// 	}

// 	current = realloc(current,0);

// 	return 0;
	
// }

int f_atoi(const char *str) {
	int result = 0;
	int sign = 1;

	while(str != NULL && *str != '\0'){

		result *= 10;
		if(*str == ' ' || (*str >= '\t' && *str <= '\r')){
			str++;
			continue;
		}
		else if (*str == '-')
		{
			sign = -1;
		}
		else if (*str >= '0' && *str <= '9')
		{
			result += *str - '0';
		}
		str++;
	}
	result *= sign;

	return result;
}


int parseHex(char *str){
	int result = 0;
	int power = 1;
	int len = strlen(str);


	str = str+ len -1;
	
	for(int i = len -1; i >= 0; i--){
		if(*str >= '0' && *str <= '9') {
			result += (*str - '0') * power;
		}
		else if (*str >='A' && *str <= 'F')
		{
			result += (*str - ('A' -10)) * power;
		}
		else if(*str >= 'a' && *str <= 'f')
		{
			result += (*str - ('a' -10)) * power;
		}
		str--;
		power *=16;
	}
	return result;
}

int main (int ac, char **av){
	if (ac <= 1 || (ac == 2 && !valid_arg(av)))
 		return (0);	

		
	printf("5.3E3");

	char *str = "34AC";

	int s = parseHex(str);
	printf("%d",s);

	int a = f_atoi(" \r\r -123");
	printf("%d",a);
	a = f_atoi("-130954");
	printf("%d",a);
	a = f_atoi("8936");
	printf("%d",a);
	a = f_atoi("+85436");
	printf("%d",a);
	
}


// int main(int ac, char **av)
// {
//     t_list *stack_a;
// 	t_list *head;
//     t_list *stack_b;
// 	int		counter;
	
// 	if (ac <= 1 || (ac == 2 && !valid_arg(av)))
// 		return (0);	
// 	counter = 0;
// 	stack_a = NULL;
// 	head = (t_list *) malloc(sizeof(t_list));
// 	if (!head)
// 		return (0);
// 	stack_a = head;
// 	stack_b = NULL;
// 	parse_arguments(ac, av, &stack_a);
// 	stack_a = head;
// 	if (!stack_a)
// 		return (0);
// 	counter += sort(&stack_a, &stack_b, counter);
// 	if (is_sorted(&stack_a))
// 		ft_printf("done with: %d steps\n", counter);
// 	ft_free_list(&stack_a);
// 	ft_free_list(&stack_b);
//     return (0);
// }






