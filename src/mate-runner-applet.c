/* Mate Runner Applet
 * Copyright (c) 2004, HJ Muller
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 *
 * Author:
 *   HJ Muller <mullerhx@gmail.com>
 */

#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

#include <string.h>

#include <glib/gi18n.h>
#include <gtk/gtk.h>
#include <mate-panel-applet.h>


void mate_runner_activate_cb(GtkWidget *widget, gpointer data);
void mate_runner_insert_text_handler_cb(GtkEntry *entry, const gchar *text, gint length, gint position, gpointer data);

static const char factory_iid[] = "MateRunnerAppletFactory";
static const char applet_iid[] = "MateRunnerApplet";

static gboolean already_running = FALSE;

static void response_cb (GtkWidget *dialog, gint arg1, gpointer user_data) {
	gtk_widget_destroy (dialog);
}

static gboolean applet_factory (MatePanelApplet *applet, const char *iid, gpointer user_data) {

	gboolean retval = FALSE;

	if (!strcmp (iid, applet_iid)) {
		retval = mate_runner_applet_fill (applet); 
    }
	if (retval == FALSE) {
		exit (-1);
	}

	return retval;
}

mate_runner_applet_fill(MatePanelApplet *applet) {
	
	char *applet_list;
	GtkWidget *dialog;
	GtkWidget* cmdline;
	GtkWidget* event_box;
	
	if (already_running) {
	    return FALSE;
	}
	
	cmdline = gtk_entry_new();
	event_box = gtk_hbox_new(FALSE,1);
	gtk_container_add (GTK_CONTAINER(applet), GTK_HBOX(event_box));
	gtk_container_add (GTK_CONTAINER(event_box), GTK_ENTRY(cmdline));

	gtk_entry_set_editable(GTK_ENTRY(cmdline), TRUE);
	gtk_entry_set_text(GTK_ENTRY(cmdline), ""); 
	
	g_signal_connect(G_OBJECT(cmdline), "activate",G_CALLBACK(mate_runner_activate_cb),NULL); 
		     
	gtk_entry_set_max_length (GTK_ENTRY(cmdline), 50);
	gtk_widget_show_all (GTK_WIDGET (applet));
	
	already_running = TRUE;
		
	return TRUE;
}

void mate_runner_activate_cb(GtkWidget *widget, gpointer data) {
	
}

MATE_PANEL_APPLET_OUT_PROCESS_FACTORY (factory_iid,
				  PANEL_TYPE_APPLET,
				  "MateRunnerApplet",
				  (MatePanelAppletFactoryCallback)applet_factory, NULL)
