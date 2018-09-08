/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minishell.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoroita <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/03 14:48:00 by anoroita          #+#    #+#             */
/*   Updated: 2018/09/03 14:48:07 by anoroita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MINISHELL_H
# define FT_MINISHELL_H
# include "libft.h"
# include <sys/stat.h>
# include <sys/wait.h>
# include <signal.h>

typedef struct	s_env
{
	char			*var;
	char			*value;
	struct s_env	*next;

}				t_env;

typedef struct	s_all
{
	t_env		*env;
	char		*path;
	char		**array;
	pid_t		pid;
	int			prompt;
	char		*home;
}				t_all;

typedef enum	e_error
{
	SYSCALL = 1,
	SYSPID,
	ARG_ENV,
	UNSET_ARG,
	ENV_ERROR,
	CD_ERROR,
}				t_error;

void			ft_sh_start(t_all *all);
int				ft_check_eviron(char **env, t_all *all);
t_env			*env_start(void);
t_env			*env_save(char *var, char *value);
void			ft_push(t_all *all, t_env *env);
void			ft_stock_env(char **env, t_all *all);
void			ft_environ(char **str, t_all *all);
void			ft_error_msg(int i, char *str);
char			*ft_tab_to_space(char *cmd);
char			**ft_env_assign(char *env);
char			**ft_tild_split(char **split, char *home);
void			ft_print_env(t_all	*all);
void			ft_set_environ(char **str, t_all *all);
int				ft_setenv_exist(char **str, t_all *all);
int				ft_unset_env(char **str, t_all *all);
void			ft_list_search(t_env *prev, char **str, int i);
int				ft_display_prompt(void);
void			ft_erase_sig_char(int i);
pid_t			save_pid(pid_t pid);
void			read_cmd(char *cmd, t_all *all);
int				ft_is_builtin(char *str);
void			ft_exec_builtin(char **str, t_all *all);
void			ft_exit_cmd(char **str);
int				ft_is_binary(char *str, t_all *all);
void			ft_exec_binary(char **str, t_all *all);
void			ft_env_to_array(t_all *all);
int				ft_check_binary(char **split, struct stat stat, \
				t_all *all, char *str);
void			ft_sh_exec_error(char *str);
void			ft_cd(char **str, t_all *all);
void			ft_sh_mod_pwd(t_all *all, char *str, char *pwd);
void			ft_change_dir(char *pwd, t_all *all, char *str);
void			ft_cd_old_pwd(t_all *all, char *pwd);
void			ft_shell_error(int i);
void			ft_shell_error_2(int i);

#endif
