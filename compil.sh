make re
gcc -o ft_printf main.c libftprintf.a
make clean
if [ $? == 0 ]
then
	./ft_printf $*
fi
