## Process this file with automake to produce Makefile.in

## Created by Anjuta

AM_CPPFLAGS = \
	-DPACKAGE_LOCALE_DIR=\""$(localedir)"\" \
	-DPACKAGE_SRC_DIR=\""$(srcdir)"\" \
	-DPACKAGE_DATA_DIR=\""$(pkgdatadir)"\" \
	$(DETECTBALL_CFLAGS)

AM_CFLAGS =\
	 -Wall\
	 -g

bin_PROGRAMS = detectball

detectball_SOURCES = \
	main.cc

detectball_LDFLAGS = 

detectball_LDADD = $(DETECTBALL_LIBS)


if NATIVE_WIN32
detectball_LDFLAGS += -mwindows
endif
