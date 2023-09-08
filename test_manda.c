#include <stdio.h>

void	initiate_sort(a_list, b_list, b_pivot)
{
	if (a_list -> value < b_pivot)
		printf("pa");
	else if ((a_list -> value < a_list -> next -> value) && (a_list -> next -> value < b_pivot))
	{
		if (b_list -> value)
			//do ft_scan_b_list :: check that b_list has some work with swap or not
			printf("scan_b_list");
		else
			printf("sa");
	}
	else
	{
		if (b_list -> value  > b_list -> next -> value)
			printf("rs");
		else
			printf("ra");
	}
}

//keep last element as seperate list is best

// after finish initate_sort
//
// ** b_list should do work sort for 3 times before implement to a_list sort;  2 of them should get que for 3 workload only;
//

// a_list sort
//
void	a_list_sort(a_list, b_list, a_pivot)
{
	t_list a_last_element = get_last_element(a_last_element, a_list);
	while (a_list -> value != a_pivot && fin_check(a_list, a_pivot))
	{
		if (a_list -> value < a_list -> next -> value)
		{
			if (a_list -> value < a_last_element && a_list -> next -> value > a_last_element)
			{
				//do (rra, sa)
				printf("rra \n sa \n");
			}
			printf("ra")
		}
		else if (a_list -> value > a_list -> next -> value)
		{
			if (a_last_element -> value > a_list -> next -> value)
				printf("ra");
			else
				printf("sa");
		}
	
	}
}
