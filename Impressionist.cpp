//
// impressionist.cpp
//
// The main driver program for the other parts. We have two major components,
// UI and Doc.
// They do have a link to each other as their member such that they can 
// communicate.
//

#include <stdio.h>

#include <FL/Fl.h>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>

#include "impressionistUI.h"
#include "impressionistDoc.h"

ImpressionistUI *impUI;
ImpressionistDoc *impDoc;

int main(int	argc, 
		 char**	argv) 
{
	impDoc = new ImpressionistDoc();

	// Create the UI
	impUI = new ImpressionistUI();

	// Set the impDoc which is used as the bridge between UI and brushes
	impUI->setDocument(impDoc);
	impDoc->setUI(impUI);

	Fl::visual(FL_DOUBLE|FL_INDEX);

	impUI->show();

	return Fl::run();
}

// global functions
float frand()
{
	return (float)rand()/RAND_MAX;
}

int irand(int max)
{
	return rand()%max;
}






//
//
//
//
//#include <stdio.h>
//
//#include <FL/Fl.H>
//#include <FL/Fl_Window.H>
//#include <FL/Fl_Menu_Bar.H>
//#include <FL/Fl_Value_Slider.H>
//#include <FL/Fl_Button.H>
//#include <FL/Fl_Box.H>
//
//#include <FL/fl_file_chooser.H> 
//#include <FL/fl_ask.h>
//
//Fl_Window* window;
//Fl_Window* dlg;
//Fl_Menu_Bar* menubar;
//Fl_Slider* slider;
//Fl_Button* button;
//
//void cb_file_select(Fl_Widget* o, void* v) {
//	char msg[256];
//	char* newfile = fl_file_chooser("Choose_a_file", "*.cpp", nullptr);
//	if(newfile != nullptr) {
//		sprintf(msg, "You choose %s", newfile);
//		fl_message(msg);
//	}
//}
//
//void cb_open_dialog(Fl_Widget* o, void* v) {
//	dlg->show();
//}
//
//
//void cb_pass(Fl_Widget* o, void* v) {
//	fl_message((char*)v);
//}
//
//void cb_quit(Fl_Widget* o, void* v) {
//	dlg->hide();
//	window->hide();
//}
//
//void cb_about() {
//	fl_message("This is about .");
//}
//
//void cb_slides(Fl_Widget* o, void* v) {
//	window->resize(window->x(), window->y(),
//		10 * (int)(((Fl_Slider*)o)->value()), window->h());
//	menubar->resize(0, 0, 10 * (int)(((Fl_Slider*)o)->value()), 25);
//}
//
//void cb_reset(Fl_Widget* o, void* v) {
//	slider->value(20);
//	cb_slides(slider, (void*)20);
//}
//
//char fltk[] = "kltk";
//char opengl[] = "opengl";
//
//Fl_Menu_Item menuitems[] = {
//	{ "&File" , 0 , 0 , 0 , FL_SUBMENU },
//		{ "File &Selector . . ." , FL_ALT + 's', (Fl_Callback*)cb_file_select } ,
//		{"Open &Dialog" , FL_ALT + 'd' , (Fl_Callback*)cb_open_dialog , 0 , FL_MENU_DIVIDER } ,
//		{ "&Fltk" , FL_ALT + 'f', (Fl_Callback*)cb_pass , (void*)fltk },
//		{ "&OpenGl" , FL_ALT + 'o', (Fl_Callback*)cb_pass , (void*)opengl , FL_MENU_DIVIDER } ,
//		{ "&Quit" , FL_ALT + 'q' , (Fl_Callback*)cb_quit },
//		{0},
//
//	{ "&Help" , 0 , 0 , 0 , FL_SUBMENU } ,
//		{ "&About" , FL_ALT + 'a', (Fl_Callback*)cb_about } ,
//		{ 0 },
//
//	{0}
//
//};
//
//int main(int argc, char** argv) {
//	window = new Fl_Window(300, 300, 200, 200, "Foo");
//	menubar = new Fl_Menu_Bar(0, 0, 200, 25);
//	menubar->menu(menuitems);
//
//	window->callback(cb_quit);
//	window->when(FL_HIDE);
//	window->end();
//
//	dlg = new Fl_Window(300, 530, 200, 70, "dialog");
//	slider = new Fl_Value_Slider(0, 10, 150, 20, "Slider");
//	slider->type(FL_HOR_NICE_SLIDER);
//	slider->labelfont(FL_COURIER);
//	slider->labelsize(12);
//	slider->minimum(1);
//	slider->maximum(40);
//	slider->step(1);
//	slider->value(20);
//	slider->align(FL_ALIGN_BOTTOM_RIGHT);
//	slider->callback(cb_slides);
//
//	Fl_Button* button = new Fl_Button(60, 40, 80, 20, "Reset");  
//	button->callback(cb_reset);
//
//	dlg->end();
//
//	window->show(argc, argv);
//
//	return Fl::run();
//}











//#include <FL/Fl.H>
//#include <FL/Fl_Gl_Window.H>
//#include <FL/gl.h>
//#define LEFT_MOUSE_DOWN 1
//#define RIGHT_MOUSE_DOWN 2
//static GLubyte drawColor[3][3] = { {255, 0, 0}, {0, 255, 0 }, {0, 0, 255 } };
//
//
//#ifndef WIN32
//#define min(a, b) (((a) < (b)) ? (a) : (b)) 
//#endif 
//
//class MyGLWindow : public Fl_Gl_Window {
//	void draw();
//	int handle(int);
//public:
//	MyGLWindow(int X, int Y, int W, int H, const char* L);
//
//	void SaveCurrentContent();
//	void RestoreContent();
//	int windowWidth, windowHeight;
//	int drawWidth, drawHeight;
//	int mx, my;
//	int isAnEvent;
//	int eventToDo;
//	int curColor;
//	unsigned char* buf, * bitstart;
//};
//
//MyGLWindow::MyGLWindow(int X, int Y, int W, int H, const char* L) : Fl_Gl_Window(X, Y, W, H, L)
//{
//	windowWidth = drawWidth = W;
//	windowHeight = drawHeight = H;
//	buf = new unsigned char[W * H * 3];
//	memset(buf, 0, W * H * 3);
//	curColor = 0;
//}
//
//
//
////Fl_Gl_Window
//
//
//
//void MyGLWindow::draw() {
//	if (!valid()) {
//		glClearColor(0.0f, 0.5f, 0.5f, 1.0);
//		glDisable(GL_DEPTH_TEST);
//		ortho();
//		glClear(GL_COLOR_BUFFER_BIT); // clear the window
//
//		windowWidth = w();
//		windowHeight = h();
//		int startrow = drawHeight - min(drawHeight, windowHeight);
//		if (startrow < 0) startrow = 0;
//		bitstart = buf + 3 * ((drawWidth *startrow));
//		RestoreContent();
//	}
//
//	if (!isAnEvent) {
//		RestoreContent();
//	}
//	else {
//		isAnEvent = 0; // clear i t after processing
//
//		switch (eventToDo) {
//			case LEFT_MOUSE_DOWN:
//				glColor3ubv(drawColor[curColor]);
//				glBegin(GL_QUADS);
//				glVertex2d(mx, (windowHeight-my));
//				glVertex2d(mx, (windowHeight-my)-20);
//				glVertex2d(mx + 20, (windowHeight-my)-20);
//				glVertex2d(mx + 20, (windowHeight-my));
//				glEnd();
//				SaveCurrentContent();
//				break;
//			case RIGHT_MOUSE_DOWN :
//				curColor = (curColor + 1) % 3;
//				break;
//		}
//	}
//}
//
//
//
//int MyGLWindow::handle(int event) {
//	switch (event) {
//	case FL_PUSH:
//		mx = Fl::event_x();
//		my = Fl::event_y();
//		if (Fl::event_button() > 1)
//			eventToDo = RIGHT_MOUSE_DOWN;
//		else
//			eventToDo = LEFT_MOUSE_DOWN;
//		isAnEvent = 1;
//		redraw();
//		return 1;
//
//	default: // tell FLTK that I don ' t understand other events 
//		return 0;
//	}
//
//	return 0;
//}
//
//
//
//
//
//void MyGLWindow::SaveCurrentContent()
//{
//	glReadBuffer(GL_BACK);
//	glPixelStorei(GL_PACK_ALIGNMENT, 1);
//	glPixelStorei(GL_PACK_ROW_LENGTH, drawWidth);
//	glReadPixels(0, windowHeight-min(drawHeight, windowHeight),
//		min(drawWidth, windowWidth), min(drawHeight, windowHeight),
//		GL_RGB, GL_UNSIGNED_BYTE, bitstart);
//}
//
//void MyGLWindow::RestoreContent() {
//	glDrawBuffer(GL_BACK);
//
//	glRasterPos2i(0, windowHeight - min(drawHeight, windowHeight));
//	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
//	glPixelStorei(GL_UNPACK_ROW_LENGTH, drawWidth);
//	glDrawPixels(min(drawWidth, windowWidth), min(drawHeight, windowHeight),
//		GL_RGB, GL_UNSIGNED_BYTE, bitstart);
//}
//
//MyGLWindow*  window;
//int main(int argc, char** argv) {
//	window = new MyGLWindow(200, 200, 300, 300, "GL_demo");
//	window->resizable(window);
//	window->show();
//	return Fl:: run();
//}