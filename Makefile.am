SUBDIRS = .
bin_PROGRAMS = mate-runner-applet

top_srcdir = .
top_builddir = .

AM_CXXFLAGS = $(GTK_CFLAGS) $(GLIB_CFLAGS) $(GIO_CFLAGS) $(DBUS_GLIB_CFLAGS) $(SOUP_CFLAGS) $(GIO_UNIX_CFLAGS) $(MATE_SETTINGS_CFLAGS) $(MATE_PANEL_APPLET_CFLAGS)

mate_runner_applet_SOURCES = src/mate-runner-applet.c
mate_runner_applet_CFLAGS = $(GTK_CFLAGS) $(GLIB_CFLAGS) $(GIO_CFLAGS) $(DBUS_GLIB_CFLAGS) $(SOUP_CFLAGS) $(GIO_UNIX_CFLAGS) $(MATE_SETTINGS_CFLAGS) $(MATE_PANEL_APPLET_CFLAGS)
mate_runner_applet_LDADD = $(GTK_LIBS) $(GLIB_LIBS) $(GIO_LIBS) $(DBUS_GLIB_LIBS) $(SOUP_LIBS) $(GIO_UNIX_LIBS) $(MATE_SETTINGS_LIBS) $(MATE_PANEL_APPLET_LIBS)

appletdir       = $(datadir)/mate-panel/applets
applet_in_files = org.mate.applets.MateRunnerApplet.mate-panel-applet.in
applet_DATA     = $(applet_in_files:.mate-panel-applet.in=.mate-panel-applet)

$(applet_in_files): $(applet_in_files).in Makefile
	$(AM_V_GEN)sed \
            -e "s|\@BINDIR\@|$(bindir)|" \
            -e "s|\@VERSION\@|$(PACKAGE_VERSION)|" \
            $< > $@

%.mate-panel-applet: %.mate-panel-applet.in $(INTLTOOL_MERGE) $(wildcard $(top_srcdir)/po/*po) ; $(INTLTOOL_MERGE) $(top_srcdir)/po/ $< $@ -d -u -c $(top_builddir)/po/.intltool-merge-cache

servicedir       = $(datadir)/dbus-1/services
service_in_files = org.mate.panel.applet.MateRunnerAppletFactory.service.in
service_DATA     = $(service_in_files:.service.in=.service)

org.mate.panel.applet.MateRunnerAppletFactory.service: $(service_in_files)
	$(AM_V_GEN)sed \
            -e "s|\@BINDIR\@|$(bindir)|" \
            $< > $@

uidir = $(datadir)/mate-2.0/ui
ui_DATA = 

CLEANFILES = $(applet_DATA) $(applet_DATA).in $(service_DATA)

EXTRA_DIST = \
 org.mate.applets.MateRunnerApplet.mate-panel-applet.in.in	\
 $(service_in_files)					\
 $(ui_DATA)

