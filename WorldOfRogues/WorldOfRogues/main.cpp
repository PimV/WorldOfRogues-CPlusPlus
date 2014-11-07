#include "Game.h"
#include <Windows.h>

void SetWindow(int Width, int Height)
{
	_COORD coord;
	coord.X = Width;
	coord.Y = Height;

	_SMALL_RECT Rect;
	Rect.Top = 0;
	Rect.Left = 0;
	Rect.Bottom = Height - 1;
	Rect.Right = Width - 1;

	HANDLE Handle = GetStdHandle(STD_OUTPUT_HANDLE);      // Get Handle
	SetConsoleScreenBufferSize(Handle, coord);            // Set Buffer Size
	SetConsoleWindowInfo(Handle, TRUE, &Rect);            // Set Window Size
}

void main() 
{ 

	//SetWindow(1000,800);
	Game game;
	HWND console = GetConsoleWindow();

	//MoveWindow(window_handle, x, y, width, height, redraw_window);
	//MoveWindow(console, 800, 800, 800, 800, TRUE);
}