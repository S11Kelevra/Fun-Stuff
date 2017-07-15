/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nqueens2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eramirez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/14 12:32:53 by eramirez          #+#    #+#             */
/*   Updated: 2017/07/14 16:35:28 by eramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <xlocale.h>

int ft_attacked(int x, int y, int N, int board[N][N]);

void ft_printboard(int N, int board[N][N])
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (j < N)
	{
		while (i < N)
		{
			printf("%i ", board[j][i]);
			i++;
		}
		printf("\n");
		i = 0;
		j++;
	}
}

void ft_zeroboard(int N, int board[N][N])
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (i < N)
    {
        while (j < N)
        {
            board[i][j] = 0;
            j++;
        }
        j = 0;
        i++;
    }
}

int ft_nqueens(int N, int size, int board[size][size])
{
	int x;
	int y;

	x = 0;
	y = 0;

	if (N == 0)
	{
		printf("SOLUTION FOUND!\n");
		ft_printboard(size, board);
		return(1);
	}
	while (y < size)
	{
		x = 0;
		while (x < size)
		{
			if (ft_attacked(x, y, size, board) == 0)
			{
				board[y][x] = 1;
				if(ft_nqueens(N - 1, size, board) == 1)
					return (1);
				board[y][x] = 0;
			}	
			x++;
		}
	y++;	
	}
	return (0);
}

int main(int argc, char **argv)
{
	int i;

	i = argc;
    int board [atoi(argv[1])][atoi(argv[1])];
	int N;

    N = atoi(argv[1]);

    printf("Original %i x %i Board placing %i Queens:  \n", N, N, N);
    ft_zeroboard(N, board);
    ft_printboard(N, board);
	ft_nqueens(N, N, board);
	
    return 0;
}
