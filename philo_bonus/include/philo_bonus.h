/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchevet <jchevet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 04:37:22 by jchevet           #+#    #+#             */
/*   Updated: 2021/09/30 04:37:25 by jchevet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <time.h>
# include <sys/time.h>
# include <pthread.h>
# include <semaphore.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <errno.h>
# include <signal.h>

# define SEM_FORK "/sem_fork"
# define SEM_TALK "/sem_talk"

typedef struct s_info
{

	struct timeval	start;
	sem_t			*forks;
	sem_t			*talk;
	int				nb_of_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				meal_param;

}t_info;

typedef struct s_philo
{
	t_info			*info;
	int 			id;
	int				meals;
	int 			time_before_dying;
}t_philo;

//--------utils
int		ft_atoi(const char *nptr);
int		ft_strcmp(const char *s1, const char *s2);
int		time_in_ms(struct timeval start);
void 	custom_sleep(int time_to_do);
//--------init
void	init_info(t_info *info, t_philo *philo);
//--------Action
void	talk(t_philo *philo, char *str, time_t time);
void	take_forks(t_philo *philo);
void	eat(t_philo *philo);
void	sleepy(t_philo *philo);
//--------Status
void	philo_died(t_philo *philo);
int		meals_done(t_philo *philo);
//--------parsing
int		parse_args(int ac, char **av, t_info *info, t_philo *philo);
//--------Threads
void	create_thread(t_philo *philo);
//--------Forks
int		*create_process(t_philo *philo);
void	wait_process(t_info *info, int *philo_pid);
//--------Semaphore
void	create_semaphores(t_info *info);
void 	close_semaphores(t_info *info);
//--------Routine
void	routine(t_philo *philo);
//--------error
int		error(char *str);

#endif
