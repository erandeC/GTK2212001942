#include <gtk/gtk.h>




gint delete_event(GtkWidget *widget, GdkEvent *event,gpointer data){
	g_print ("delete evento occurred\n");
	
	return TRUE;
}

void destroy(GtkWidget *widget, gpointer data){
	gtk_main_quit();
}

int main(int argc, char *argv[]){
	GtkWidget *window;
	GtkWidget *button;

	gtk_init (&argc, &argv);
	
	window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
	
	g_signal_connect (G_OBJECT(window), "delete_event",
	G_CALLBACK(delete_event), NULL);

	g_signal_connect (G_OBJECT(window), "destroy",
	G_CALLBACK(destroy), NULL);


	gtk_container_set_border_width (GTK_CONTAINER(window), 35);

	button = gtk_button_new_with_label("Belia E. Corona");

	g_signal_connect_swapped (G_OBJECT(button), "clicked",
			G_CALLBACK(gtk_widget_destroy),G_OBJECT(window));

	gtk_container_add (GTK_CONTAINER (window), button);
	
	gtk_widget_show (button);
	gtk_widget_show (window);

	gtk_main();


}
