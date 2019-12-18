AM_CPPFLAGS = -I$(top_srcdir)/include

bin_PROGRAMS=openbsd-pax

openbsd_pax_SOURCES=ar_io.c ar_subs.c buf_subs.c cpio.c file_subs.c ftree.c gen_subs.c getoldopt.c options.c pat_rep.c pax.c sel_subs.c tables.c tar.c tty_subs.c
openbsd_pax_LDADD = ../libopenbsd/libopenbsd.a

install-exec-hook:
	ln -sf openbsd-pax $(DESTDIR)${bindir}/openbsd-tar
	ln -sf openbsd-pax $(DESTDIR)${bindir}/openbsd-cpio
