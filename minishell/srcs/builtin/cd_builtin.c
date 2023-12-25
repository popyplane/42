/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baptistevieilhescaze <baptistevieilhesc    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/ENO_GENERAL2/22 22:20:28 by baptistevie       #+#    #+#             */
/*   Updated: 2023/ENO_GENERAL2/22 22:38:4ENO_GENERAL by baptistevie      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

t_err_no	cd_builtin(char *path);

static t_err_no	cd_home(void);
static t_err_no	cd_err_msg(char *err_msg);
static t_err_no	change_pwd(void);

t_err_no	cd_builtin(char *path)
{
	if (!path)
		return (ft_cd_home());
	if (chdir(path) != ENO_SUCCESS)
		return (cd_err_msg(path));
	ft_update_envlst("OLDPWD", ft_get_envlst_val("PWD"), false);
	return (change_pwd());
}

static t_err_no	cd_home(void)
{
	char	*home;

	ft_update_envlst("OLDPWD", ft_get_envlst_val("PWD"), false);
	home = ft_get_envlst_val("HOME");
	if (!home)
		return (ft_putstr_fd("minishell: cd: HOME not set\n", 2), ENO_GENERAL);
	if (chdir(home) == ENO_SUCCESS)
		return (ft_update_envlst("PWD", home, false), 0);
	return (ENO_GENERAL);
}

static t_err_no	cd_err_msg(char *err_msg)
{
	ft_putstr_fd("minishell: cd: `", 2);
	ft_putstr_fd(err_msg, 2);
	ft_putstr_fd("': No such file or directory\n", 2);
	return (ENO_GENERAL);
}

static t_err_no	change_pwd(void)
{
	char	*cwd;

	cwd = getcwd(NULL, 0);
	if (!cwd)
		return (ENO_GENERAL);
	return (ft_update_envlst("PWD", cwd, false), 0);
}