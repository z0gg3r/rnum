#! /bin/sh
remove_auto()
{
	echo "Remove Autotools stuff"
	rm -f config.h.in Makefile.in
	rm -f aclocal.m4 configure config.log config.status
	rm -rf autom4te*.cache
	rm -rf build-aux
}

add_auto()
{
	echo "Reconfigure Autotools"
	mkdir build-aux
	autoreconf -i
}

help()
{
	echo "Run 'autogen.sh' to reconfigure"
	echo "Run 'autogen.sh remove' to remove generated files"
	echo "Run 'autogen.sh add' to achieve the same as running without args"
	echo "Run 'autogen.sh help' to show this"
}

if [ -z "$1" ]
then
	remove_auto
	add_auto
	exit
fi

case $1 in
	remove) remove_auto ;;
	add) remove_auto; add_auto ;;
	help) help ;;
	*) help ;;
esac
