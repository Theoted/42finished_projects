/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeville <tdeville@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 13:41:53 by tdeville          #+#    #+#             */
/*   Updated: 2022/03/23 09:37:25 by tdeville         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

long long int	timems(void)
{
	struct timeval	start;
	long long int	time;

	gettimeofday(&start, NULL);
	time = (start.tv_sec * 1000) + (start.tv_usec / 1000);
	return (time);
}

int	check_die_and_eat(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->ph_nb)
	{
		if (check_die(data, i))
			return (1);
		pthread_mutex_lock(&data->m_check);
		if (data->eats_done == data->ph_nb)
		{
			pthread_mutex_unlock(&data->m_check);
			return (1);
		}
		pthread_mutex_unlock(&data->m_check);
		if (i == data->ph_nb - 1)
			i = -1;
		usleep(100);
	}
	return (0);
}

int	try_eat(t_philo *philo)
{
	if (philo->data->ph_nb == 1)
		return (one_philo_eating(philo));
	while (!check_for_end(philo))
	{
		if (fork_and_eat(philo) == 1)
			break ;
		pthread_mutex_lock(&philo->data->m_gettime);
		philo->data->philos[philo->id].time_eat = timems();
		pthread_mutex_unlock(&philo->data->m_gettime);
		ft_mutex_unlock(philo);
		if (sleeping(philo) == 1)
			break ;
		if (thinking(philo) == 1)
			break ;
		philo->eats++;
		if (check_eats(philo))
			break ;
	}
	return (0);
}

void	*routine(void *arg)
{
	t_philo			*philo;

	philo = arg;
	while (philo->data->ready == 0)
		;
	if (philo->id % 2 != 0)
		ft_usleep((philo->data->eat / 2), philo);
	try_eat(philo);
	return (NULL);
}

int	main(int ac, char **av)
{
	t_data		data;
	int			i;

	if ((ac != 5 && ac != 6) || (check_args(ac, av)))
		return (return_error("Arg Error"));
	data = init_data(av);
	if (check_data(data))
		return (free_all(&data, "Arg Error", 0));
	init_philo(&data);
	i = -1;
	while (++i < data.ph_nb)
		if (pthread_create(&data.philos[i].thread, NULL,
				&routine, &data.philos[i]) == -1)
			return (free_all(&data, "Thread creating error", 1));
	data.ready = 1;
	if (check_die_and_eat(&data) == 1)
	{
		i = -1;
		while (++i < data.ph_nb)
			if (pthread_join(data.philos[i].thread, NULL) == -1)
				return (free_all(&data, "Thread joining error", 1));
	}
	free_all(&data, NULL, 1);
	return (0);
}
