/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_attacked.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eramirez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/14 12:56:49 by eramirez          #+#    #+#             */
/*   Updated: 2017/07/14 17:36:00 by eramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int ft_rows(int y, int N, int board[N][N])
{
	int i;

	i = 0;
	while (i < N)
	{
		if (board[y][i] == 1)
			return 1;
		i++;
	}
	return 0;
}

int ft_coloumns(int x, int N, int board[N][N])
{
	int i;

	i = 0;
	while (i < N)
	{
		if (board[i][x] == 1)
			return 1;
		i++;
	}
	return 0;
}

int ft_upright(int x, int y, int N, int board[N][N])
{
	if (x != (N - 1) && y != 0)
	{
		while (x < N && y >= 0)
		{
			if (board[y][x] == 1)
				return 1;
			y--;
			x++;
		}
	}
	return(0);
}
int ft_upleft(int x, int y, int N, int board[N][N])
{
	if (x != 0 && y != 0)
	{
		while (x >= 0 && y >= 0)
		{
			if (board[y][x] == 1)
				return 1;
			y--;
			x--;
		}
	}
	return(0);
}
int ft_downright(int x, int y, int N, int board[N][N])
{
	if (x != (N - 1) && y != (N - 1))
	{
		while (x < N && y < N)
		{
			if (board[y][x] == 1)
				return 1;
			y++;
			x++;
		}
	}
	return(0);
}
int ft_downleft(int x, int y, int N, int board[N][N])
{
	if (x != 0 && y != (N - 1))
	{
		while (x >= 0 && y < N)
		{
			if (board[y][x] == 1)
				return 1;
			y++;
			x--;
		}
	}
	return(0);
}

int ft_attacked(int x, int y, int N, int board[N][N])
{
	if (ft_coloumns(x, N, board) == 1)
		return (1);
	if (ft_rows(y, N, board) == 1)
		return (1);
	if (ft_upright(x, y, N, board) == 1)
		return (1);
	if (ft_upleft(x, y, N, board) == 1)
		return (1);
	if (ft_downright(x, y, N, board) == 1)
		return (1);
	if (ft_downleft(x, y, N, board) == 1)
		return (1);
	return 0;
}
