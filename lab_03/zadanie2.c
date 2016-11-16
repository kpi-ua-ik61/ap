/* ************************************************************************** */
/*                                                                            */
/*                                                        _____    ______     */
/*   zadanie2.c                                          (____ \  |  ___ \    */
/*                                                        _   \ \ | | _ | |   */
/*   By: dmaznytskyi <dmaznytskyi@gmail.com>             | |   | || || || |   */
/*                                                       | |__/ / | || || |   */
/*   Created: 2016/11/14 20:22:51 by dmaznytskyi         |_____/  |_||_||_|   */
/*   Updated: 2016/11/16 14:23:05 by dmaznytskyi                              */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	fb2[] = "abcdefghijklmnopqrstuvwxyzйцукенгшщзхъфывапролджэячсмитьбю!@#$%%^&*()_+=\\|'\"/,{}[]";
char	input_buffer[100];

void	zadanie2(void)
{
	int day;
	int	month;
	int year;
	int is_leap; // 0 - если не високосный год, 1 - если високосный
	int day_of_week;

	printf("Введіть рік, місяць та число\n");
	for (int i = 0; i < 3; i++)
	{
		if (i == 0)
		{
			printf("Введіть рік : ");
			scanf("%s", input_buffer);
			if (strpbrk(input_buffer, fb2) != NULL)
			{
				error(1);
				error(2);
				break ;
			}
			else
			{
				year = ft_atoi(input_buffer);
				if (year == 0)
				{
					error(3);
					error(2);
					break ;
				}
				if ()
			}
		}
	}
}
