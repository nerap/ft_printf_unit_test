#include "mixed_test.h"

int		mix_test_02(void)
{
	t_data	data;
	int		pfd[2];
	int		ret;
	int		save_stdout;

	ft_write_test_name("%--.4u et %0d%12c%1c\\n, -12, 0, 0, 95");
	ft_connect_stdout(pfd, &save_stdout);
	data.r1 = ft_printf("%--.4u et %0d%12c%1c\n", -12, 0, 0, 95);
	data.s1 = ft_get_stdout(pfd, &save_stdout);
	ft_connect_stdout(pfd, &save_stdout);
	data.r2 = printf("%--.4u et %0d%12c%1c\n", -12, 0, 0, 95);
	data.s2 = ft_get_stdout(pfd, &save_stdout);
	ret = 0;
	if (data.r1 != data.r2)
		ret = -1;
	if (ft_strcmp(data.s1, data.s2))
		ret = -1;
	ft_write_rslt(data, ret);
	ft_strdel(&data.s1);
	ft_strdel(&data.s2);
	return (ret);
}
