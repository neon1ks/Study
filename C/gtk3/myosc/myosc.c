#include <gtk/gtk.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
//объявляем функцию, обработчик сигнала закрытия окна
static void destroy(GtkWidget*, gpointer);
//объявляем функцию, обработчки сигнала перерисовки окна
static void draw(GtkWidget*, GdkEventExpose*, gpointer);
//объявляем функцию, объявляющую область перерисовки недействительной
static gboolean time_handler(GtkWidget*);
//две переменные, смещение синусоиды и текущее положение точки графика
gint count = 0, t = 0;
double radianPerx = 2 * 3.14 / 90; //угол радиан, определяет расстояние между гребнями волн
const double uAmplit = 900; //амплитуда синусоиды
char *buf; //текстовый буфер для хранения текста метки

//главная функция приложения
int main(int argc, char* argv[])
{
	//Выделяем память для текстового буфера	
	buf = calloc(256, sizeof(char));
	//объявляем два виджета - окно и область для рисования
	GtkWidget *window, *drawing;
	//инициализируем gtk
	gtk_init(&argc, &argv);
	//создаем новое, обычное окно
	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	//задаем текст заголовка окна
	gtk_window_set_title(GTK_WINDOW(window), "Осциллограф");
	//запрещаем изменение размеров окна
	gtk_window_set_resizable(GTK_WINDOW(window), FALSE);
	//задаем размер окна
	gtk_widget_set_size_request(window, 600, 400);
	//задаем стартовую позицию - центр экрана
	gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
	//задаем отступы контейнера окна
	gtk_container_set_border_width(GTK_CONTAINER(window), 10);
	//создаем таймер, с периодом 100 миллисекунд и функцией обработки сигнала таймера time_handler
	g_timeout_add(150, (GSourceFunc) time_handler, (gpointer) window);
	
	//создаем новую область для рисования
	drawing = gtk_drawing_area_new();
	//помещаем ее в контейнер окна
	gtk_container_add(GTK_CONTAINER(window), drawing);
	
	//связываем сигнал уничтожения окна и функцию-обработчик
	g_signal_connect(window, "destroy", G_CALLBACK(destroy), NULL);
	//связываем сигнал перерисовки области рисования и функцию-обработчик
	g_signal_connect(drawing, "draw", G_CALLBACK(draw), NULL);
	//показывем все виджеты
	gtk_widget_show_all(window);
	//запускаем главный цикл программы
	gtk_main();
	//Освобождаем память у текстового буфера
	free(buf);
	return EXIT_SUCCESS;
}

static void draw(GtkWidget* drawarea, GdkEventExpose* event, gpointer data)
{
	int ya, xa; //переменные для хранения X и Y координат рисования
	//создаем область для рисования Cairo
	cairo_t *cr = gdk_cairo_create(gtk_widget_get_window (drawarea));
	//рисуем рамку, размером с область рисования
	cairo_rectangle (cr, event->area.x, event->area.y, event->area.width, event->area.height);
	//задаем толщину линии
	cairo_set_line_width (cr, 3);
	//задачем черный цвет
	cairo_set_source_rgb (cr, 0, 0, 0);
	//рисуем линию оси Y
  	cairo_move_to(cr, 40, 0);
	cairo_line_to (cr, 40, 350);
	cairo_stroke (cr);
	//рисуем линию оси X
	cairo_move_to (cr, 30, 340);
	cairo_line_to (cr, 600, 340);
	cairo_stroke (cr);	
	//задаем толщину линии
	cairo_set_line_width (cr, 0.7);
	//рисуем риски на оси X, линии сетки и текстовые метки
	xa = 40;
	while(xa < 600)
	{
		//задаем черный цвет
		cairo_set_source_rgb (cr, 0, 0, 0);
		//рисуем риски
		cairo_move_to (cr, xa, 333);
		cairo_line_to (cr, xa, 347);
		cairo_stroke (cr);
		//преобразовывем значение координаты риски в строку	
		sprintf(buf, "%i", xa-40); 
		//рисуем текст метки в нужной точке 
		cairo_move_to (cr, xa-2, 360);
		cairo_show_text(cr, buf);
		//задаем зеленый цвет
		cairo_set_source_rgb (cr, 0, 0.5, 0);
		//рисуем линии сетки
		cairo_move_to (cr, xa+40, 333);
		cairo_line_to (cr, xa+40, 0);
		cairo_stroke (cr);		
		xa += 40;		
	}
	//рисуем риски на оси Y, линии сетки и текстовые метки
	ya = 340;
	while(ya > 0)
	{
		//задаем черный цвет
		cairo_set_source_rgb (cr, 0, 0, 0);		
		cairo_move_to (cr, 33, ya);
		cairo_line_to (cr, 47, ya);
		cairo_stroke (cr);
		//преобразовывем значение координаты риски в строку	
		sprintf(buf, "%i", 340-ya); 
		//рисуем текст метки в нужной точке 
		cairo_move_to (cr, 12, ya+2);
		cairo_show_text(cr, buf);
		//задаем зеленый цвет
		cairo_set_source_rgb (cr, 0, 0.5, 0);
		//рисуем линии сетки
		cairo_move_to (cr, 47, ya-40);
		cairo_line_to (cr, 600, ya-40);
		cairo_stroke (cr);		
		ya -= 40;			
	}
	//рисуем синусоиду
	//задаем красный цвет и толщину линии
	cairo_set_source_rgb (cr, 1, 0, 0);
	cairo_set_line_width (cr, 4);	
	//устонавливаем начальную точку синусоиды
 	cairo_move_to(cr, t+40, ((uAmplit * sin(t * radianPerx + count)) * 0.1 + 160));
	//рисуем синусоиду
	while(t < 600)
	{
		cairo_line_to(cr, t+40, ((uAmplit * sin(t * radianPerx + count)) * 0.1 + 160));
		t++;
	}
	cairo_stroke (cr);
	//закрываем cr и освобождаем память
	cairo_destroy(cr);
}
//функция-обработчик сигнала таймера
static gboolean time_handler(GtkWidget* widget)
{
	//если передан нулевой параметр - возвращаем ложь
	if (gtk_widget_get_window (widget) == NULL) return FALSE;
	//увеличиваем значение переменной смещения графика
	count++;
	//обнуляем точку положения на графике
	t = 0;
	//заставляем окно перерисоваться
	gtk_widget_queue_draw(widget);
	return TRUE;
}
//функция-обработчик сигнала закрытия окна
static void destroy(GtkWidget* window, gpointer data)
{
	//завершаем главный цикл приложения
	gtk_main_quit();
}

