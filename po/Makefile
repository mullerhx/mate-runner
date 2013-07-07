# Makefile for program source directory in GNU NLS utilities package.
# Copyright (C) 1995, 1996, 1997 by Ulrich Drepper <drepper@gnu.ai.mit.edu>
# Copyright (C) 2004-2008 Rodney Dawes <dobey.pwns@gmail.com>
#
# This file may be copied and used freely without restrictions.  It may
# be used in projects which are not available under a GNU Public License,
# but which still want to provide support for the GNU gettext functionality.
#
# - Modified by Owen Taylor <otaylor@redhat.com> to use GETTEXT_PACKAGE
#   instead of PACKAGE and to look for po2tbl in ./ not in intl/
#
# - Modified by jacob berkman <jacob@ximian.com> to install
#   Makefile.in.in and po2tbl.sed.in for use with glib-gettextize
#
# - Modified by Rodney Dawes <dobey.pwns@gmail.com> for use with intltool
#
# We have the following line for use by intltoolize:
# INTLTOOL_MAKEFILE

GETTEXT_PACKAGE = @GETTEXT_PACKAGE@
PACKAGE = MATEX-applet
VERSION = 0.0.1

SHELL = /bin/bash

srcdir = .
top_srcdir = ..
top_builddir = ..


prefix = /usr/local
exec_prefix = ${prefix}
datadir = ${datarootdir}
datarootdir = ${prefix}/share
libdir = ${exec_prefix}/lib
DATADIRNAME = @DATADIRNAME@
itlocaledir = $(prefix)/$(DATADIRNAME)/locale
subdir = po
install_sh = ${SHELL} /home/hm/Projects/mate_runner/install-sh
# Automake >= 1.8 provides /bin/mkdir -p.
# Until it can be supposed, use the safe fallback:
mkdir_p = $(install_sh) -d

INSTALL = /usr/bin/install -c
INSTALL_DATA = ${INSTALL} -m 644

GMSGFMT = @GMSGFMT@
MSGFMT = @MSGFMT@
XGETTEXT = @XGETTEXT@
INTLTOOL_UPDATE = @INTLTOOL_UPDATE@
INTLTOOL_EXTRACT = @INTLTOOL_EXTRACT@
MSGMERGE = INTLTOOL_EXTRACT="$(INTLTOOL_EXTRACT)" XGETTEXT="$(XGETTEXT)" srcdir=$(srcdir) $(INTLTOOL_UPDATE) --gettext-package $(GETTEXT_PACKAGE) --dist
GENPOT   = INTLTOOL_EXTRACT="$(INTLTOOL_EXTRACT)" XGETTEXT="$(XGETTEXT)" srcdir=$(srcdir) $(INTLTOOL_UPDATE) --gettext-package $(GETTEXT_PACKAGE) --pot

ALL_LINGUAS = @ALL_LINGUAS@

PO_LINGUAS=$(shell if test -r $(srcdir)/LINGUAS; then grep -v "^\#" $(srcdir)/LINGUAS; else echo "$(ALL_LINGUAS)"; fi)

USER_LINGUAS=$(shell if test -n "$(LINGUAS)"; then LLINGUAS="$(LINGUAS)"; ALINGUAS="$(ALL_LINGUAS)"; for lang in $$LLINGUAS; do if test -n "`grep \^$$lang$$ $(srcdir)/LINGUAS 2>/dev/null`" -o -n "`echo $$ALINGUAS|tr ' ' '\n'|grep \^$$lang$$`"; then printf "$$lang "; fi; done; fi)

USE_LINGUAS=$(shell if test -n "$(USER_LINGUAS)" -o -n "$(LINGUAS)"; then LLINGUAS="$(USER_LINGUAS)"; else if test -n "$(PO_LINGUAS)"; then LLINGUAS="$(PO_LINGUAS)"; else LLINGUAS="$(ALL_LINGUAS)"; fi; fi; for lang in $$LLINGUAS; do printf "$$lang "; done)

POFILES=$(shell LINGUAS="$(PO_LINGUAS)"; for lang in $$LINGUAS; do printf "$$lang.po "; done)

DISTFILES = Makefile.in.in POTFILES.in $(POFILES)
EXTRA_DISTFILES = ChangeLog POTFILES.skip Makevars LINGUAS

POTFILES = \
	../accessx-status/applet.c \
	../accessx-status/org.mate.applets.AccessxStatusApplet.mate-panel-applet.in.in \
	../battstat/battstat_applet.c \
	../battstat/battstat_applet.ui \
	../battstat/battstat-hal.c \
	../battstat/battstat.schemas.in \
	../battstat/org.mate.applets.BattstatApplet.mate-panel-applet.in.in \
	../battstat/properties.c \
	../battstat/sounds/mate-battstat_applet.soundlist.in \
	../charpick/charpick.c \
	../charpick/charpick.schemas.in \
	../charpick/org.mate.applets.CharpickerApplet.mate-panel-applet.in.in \
	../charpick/properties.c \
	../cpufreq/cpufreq-applet.schemas.in \
	../cpufreq/cpufreq-preferences.ui \
	../cpufreq/org.mate.applets.CPUFreqApplet.mate-panel-applet.in.in \
	../cpufreq/src/cpufreq-applet.c \
	../cpufreq/src/cpufreq-prefs.c \
	../cpufreq/src/cpufreq-monitor-cpuinfo.c \
	../cpufreq/src/cpufreq-monitor-factory.c \
	../cpufreq/src/cpufreq-monitor-procfs.c \
	../cpufreq/src/cpufreq-popup.c \
	../cpufreq/src/cpufreq-selector/org.mate.cpufreqselector.policy.in \
	../drivemount/drive-button.c \
	../drivemount/drivemount.c \
	../drivemount/drivemount.schemas.in \
	../drivemount/org.mate.applets.DriveMountApplet.mate-panel-applet.in.in \
	../geyes/geyes.c \
	../geyes/geyes.schemas.in \
	../geyes/org.mate.applets.GeyesApplet.mate-panel-applet.in.in \
	../geyes/themes.c \
	../mateweather/mateweather-about.c \
	../mateweather/mateweather-applet.c \
	../mateweather/mateweather-dialog.c \
	../mateweather/mateweather-pref.c \
	../mateweather/main.c \
	../mateweather/org.mate.applets.MateWeatherApplet.mate-panel-applet.in.in \
	../invest-applet/data/Invest_Applet.server.in.in \
	../invest-applet/data/Invest_Applet.xml \
	../invest-applet/data/financialchart.ui \
	../invest-applet/data/prefs-dialog.ui \
	../invest-applet/invest/about.py \
	../invest-applet/invest/applet.py \
	../invest-applet/invest/chart.py \
	../invest-applet/invest/invest-applet.py \
	../invest-applet/invest/preferences.py \
	../invest-applet/invest/quotes.py \
	../invest-applet/invest/widgets.py \
	../mini-commander/MATE_MiniCommanderApplet.server.in \
	../mini-commander/src/about.c \
	../mini-commander/src/cmd_completion.c \
	../mini-commander/src/command_line.c \
	../mini-commander/src/exec.c \
	../mini-commander/src/help.c \
	../mini-commander/src/history.c \
	../mini-commander/src/macro.c \
	../mini-commander/src/mc-install-default-macros.c \
	../mini-commander/src/mini-commander-global.schemas.in \
	../mini-commander/src/mini-commander.ui \
	../mini-commander/src/mini-commander.schemas.in \
	../mini-commander/src/mini-commander_applet.c \
	../mini-commander/src/org.mate.applets.MiniCommanderApplet.mate-panel-applet.in.in \
	../mini-commander/src/preferences.c \
	../mixer/applet.c \
	../mixer/dock.c \
	../mixer/load.c \
	../mixer/mixer.schemas.in \
	../mixer/org.mate.applets.MixerApplet.mate-panel-applet.in.in \
	../mixer/preferences.c \
	../modemlights/modem-applet.c \
	../modemlights/modemlights.ui \
	../modemlights/org.mate.applets.ModemApplet.mate-panel-applet.in.in \
	../multiload/linux-proc.c \
	../multiload/load-graph.c \
	../multiload/main.c \
	../multiload/multiload.schemas.in \
	../multiload/netspeed.c \
	../multiload/org.mate.applets.MultiLoadApplet.mate-panel-applet.in.in \
	../multiload/properties.c \
	../null_applet/MATE_CDPlayerApplet.server.in \
	../null_applet/MATE_MailcheckApplet_Factory.server.in \
	../null_applet/MATE_MixerApplet.server.in \
	../null_applet/MATE_NullApplet_Factory.server.in.in \
	../null_applet/MATE_Panel_WirelessApplet.server.in \
	../null_applet/MATE_KeyboardApplet.server.in \
	../null_applet/null_applet.c \
	../stickynotes/data/MATE_StickyNotesApplet.server.in \
	../stickynotes/org.mate.applets.StickyNotesApplet.mate-panel-applet.in.in \
	../stickynotes/stickynotes.c \
	../stickynotes/stickynotes.ui \
	../stickynotes/stickynotes.schemas.in \
	../stickynotes/stickynotes_applet.c \
	../stickynotes/stickynotes_applet_callbacks.c \
	../stickynotes/stickynotes_callbacks.c \
	../timer-applet/data/TimerApplet.server.in.in \
	../timer-applet/data/TimerApplet.xml \
	../timer-applet/data/timer-applet.glade \
	../timer-applet/data/timer-applet.schemas.in \
	../timer-applet/src/timerapplet/controllers/GlobalController.py \
	../timer-applet/src/timerapplet/controllers/TimerApplet.py \
	../timer-applet/src/timerapplet/ui/ContinueTimerDialog.py \
	../timer-applet/src/timerapplet/ui/StartTimerDialog.py \
	../timer-applet/src/timerapplet/ui/StartNextTimerDialog.py \
	../timer-applet/src/timerapplet/ui/DurationChooser.py \
	../timer-applet/src/timerapplet/utils.py \
	../trashapplet/org.mate.applets.TrashApplet.mate-panel-applet.in.in \
	../trashapplet/src/trashapplet.c \
	../trashapplet/src/trash-empty.c \
	../trashapplet/trashapplet-empty-progress.ui

CATALOGS=$(shell LINGUAS="$(USE_LINGUAS)"; for lang in $$LINGUAS; do printf "$$lang.gmo "; done)

.SUFFIXES:
.SUFFIXES: .po .pox .gmo .mo .msg .cat

AM_DEFAULT_VERBOSITY = @AM_DEFAULT_VERBOSITY@
INTLTOOL_V_MSGFMT = $(INTLTOOL__v_MSGFMT_$(V))
INTLTOOL__v_MSGFMT_= $(INTLTOOL__v_MSGFMT_$(AM_DEFAULT_VERBOSITY))
INTLTOOL__v_MSGFMT_0 = @echo "  MSGFMT" $@;

.po.pox:
	$(MAKE) $(GETTEXT_PACKAGE).pot
	$(MSGMERGE) $< $(GETTEXT_PACKAGE).pot -o $*.pox

.po.mo:
	$(INTLTOOL_V_MSGFMT)$(MSGFMT) -o $@ $<

.po.gmo:
	$(INTLTOOL_V_MSGFMT)file=`echo $* | sed 's,.*/,,'`.gmo \
	  && rm -f $$file && $(GMSGFMT) -o $$file $<

.po.cat:
	sed -f ../intl/po2msg.sed < $< > $*.msg \
	  && rm -f $@ && gencat $@ $*.msg


all: all-@USE_NLS@

all-yes: $(CATALOGS)
all-no:

$(GETTEXT_PACKAGE).pot: $(POTFILES)
	$(GENPOT)

install: install-data
install-data: install-data-@USE_NLS@
install-data-no: all
install-data-yes: all
	linguas="$(USE_LINGUAS)"; \
	for lang in $$linguas; do \
	  dir=$(DESTDIR)$(itlocaledir)/$$lang/LC_MESSAGES; \
	  $(mkdir_p) $$dir; \
	  if test -r $$lang.gmo; then \
	    $(INSTALL_DATA) $$lang.gmo $$dir/$(GETTEXT_PACKAGE).mo; \
	    echo "installing $$lang.gmo as $$dir/$(GETTEXT_PACKAGE).mo"; \
	  else \
	    $(INSTALL_DATA) $(srcdir)/$$lang.gmo $$dir/$(GETTEXT_PACKAGE).mo; \
	    echo "installing $(srcdir)/$$lang.gmo as" \
		 "$$dir/$(GETTEXT_PACKAGE).mo"; \
	  fi; \
	  if test -r $$lang.gmo.m; then \
	    $(INSTALL_DATA) $$lang.gmo.m $$dir/$(GETTEXT_PACKAGE).mo.m; \
	    echo "installing $$lang.gmo.m as $$dir/$(GETTEXT_PACKAGE).mo.m"; \
	  else \
	    if test -r $(srcdir)/$$lang.gmo.m ; then \
	      $(INSTALL_DATA) $(srcdir)/$$lang.gmo.m \
		$$dir/$(GETTEXT_PACKAGE).mo.m; \
	      echo "installing $(srcdir)/$$lang.gmo.m as" \
		   "$$dir/$(GETTEXT_PACKAGE).mo.m"; \
	    else \
	      true; \
	    fi; \
	  fi; \
	done

# Empty stubs to satisfy archaic automake needs
dvi info ctags tags CTAGS TAGS ID:

# Define this as empty until I found a useful application.
install-exec installcheck:

uninstall:
	linguas="$(USE_LINGUAS)"; \
	for lang in $$linguas; do \
	  rm -f $(DESTDIR)$(itlocaledir)/$$lang/LC_MESSAGES/$(GETTEXT_PACKAGE).mo; \
	  rm -f $(DESTDIR)$(itlocaledir)/$$lang/LC_MESSAGES/$(GETTEXT_PACKAGE).mo.m; \
	done

check: all $(GETTEXT_PACKAGE).pot
	rm -f missing notexist
	srcdir=$(srcdir) $(INTLTOOL_UPDATE) -m
	if [ -r missing -o -r notexist ]; then \
	  exit 1; \
	fi

mostlyclean:
	rm -f *.pox $(GETTEXT_PACKAGE).pot *.old.po cat-id-tbl.tmp
	rm -f .intltool-merge-cache

clean: mostlyclean

distclean: clean
	rm -f Makefile Makefile.in POTFILES stamp-it
	rm -f *.mo *.msg *.cat *.cat.m *.gmo

maintainer-clean: distclean
	@echo "This command is intended for maintainers to use;"
	@echo "it deletes files that may require special tools to rebuild."
	rm -f Makefile.in.in

distdir = ../$(PACKAGE)-$(VERSION)/$(subdir)
dist distdir: $(DISTFILES)
	dists="$(DISTFILES)"; \
	extra_dists="$(EXTRA_DISTFILES)"; \
	for file in $$extra_dists; do \
	  test -f $(srcdir)/$$file && dists="$$dists $(srcdir)/$$file"; \
	done; \
	for file in $$dists; do \
	  test -f $$file || file="$(srcdir)/$$file"; \
	  ln $$file $(distdir) 2> /dev/null \
	    || cp -p $$file $(distdir); \
	done

update-po: Makefile
	$(MAKE) $(GETTEXT_PACKAGE).pot
	tmpdir=`pwd`; \
	linguas="$(USE_LINGUAS)"; \
	for lang in $$linguas; do \
	  echo "$$lang:"; \
	  result="`$(MSGMERGE) -o $$tmpdir/$$lang.new.po $$lang`"; \
	  if $$result; then \
	    if cmp $(srcdir)/$$lang.po $$tmpdir/$$lang.new.po >/dev/null 2>&1; then \
	      rm -f $$tmpdir/$$lang.new.po; \
            else \
	      if mv -f $$tmpdir/$$lang.new.po $$lang.po; then \
	        :; \
	      else \
	        echo "msgmerge for $$lang.po failed: cannot move $$tmpdir/$$lang.new.po to $$lang.po" 1>&2; \
	        rm -f $$tmpdir/$$lang.new.po; \
	        exit 1; \
	      fi; \
	    fi; \
	  else \
	    echo "msgmerge for $$lang.gmo failed!"; \
	    rm -f $$tmpdir/$$lang.new.po; \
	  fi; \
	done

Makefile POTFILES: stamp-it
	@if test ! -f $@; then \
	  rm -f stamp-it; \
	  $(MAKE) stamp-it; \
	fi

stamp-it: Makefile.in.in $(top_builddir)/config.status POTFILES.in
	cd $(top_builddir) \
	  && CONFIG_FILES=$(subdir)/Makefile.in CONFIG_HEADERS= CONFIG_LINKS= \
	       $(SHELL) ./config.status

# Tell versions [3.59,3.63) of GNU make not to export all variables.
# Otherwise a system limit (for SysV at least) may be exceeded.
.NOEXPORT:
