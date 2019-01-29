/*******************************************
	PixelDrawing.cpp

	2D pixel based drawing functions
********************************************/

#include "stdafx.h"            // Precompiled headers for Visual Studio
#include "PixelPlotterForm.h"  // Class header file
#include <math.h>              // Need standard math functions for drawing circles

// All application definitions are contained in a 'namespace'. Namespaces primarily protect against
// variable name clashes when using many libraries together, they also promote good encapsulation
// Here the namespace is needed for the main drawing application - you can safely ignore it
namespace PixelPlotter         
{

////////////////////////////////////
// Instructions
////////////////////////////////////
//
// The functions below are initially empty, you need to implement them for the lab exercise.
// Note that they are all member functions of the class PixelPlotterForm, so they begin with 
// "PixelPlotterForm::". This does not affect how you write the functions
//
// The following function has already been declared:
//     SetViewportPixel( int X, int Y, Color PixelColour );
// To write the functions you only need to call this function once for each pixel in your shape
//
// Where necessary, use the definition of PI below
// Also note that <math.h> has already been included

const float PI = 3.14159f;


// Draw a rectangle with top-left at (X, Y) with given width, height and colour
void PixelPlotterForm::DrawRectangle( int X, int Y, int Width, int Height, Color PixelColour )
{
	// Fill in the correct code here
	int xPos = X;

	int yPos = Y;

	for (int i = 1; i < Width; i++)
	{
		SetViewportPixel(X, Y, PixelColour);
		X++;
	}

	for (int i = 0; i < Width; i++)
	{
		SetViewportPixel(xPos, yPos+Height-1, PixelColour);
		xPos++;
	}

	for (int i = 1; i < Height; i++)
	{
		SetViewportPixel(X, Y, PixelColour);
		Y++;
	}

	for (int i = 1; i < Height; i++)
	{
		SetViewportPixel(xPos-Width, yPos, PixelColour);
		yPos++;
	}
}


// Draw a line from (X1, Y1) to (X2, Y2) in given colour
void PixelPlotterForm::DrawLine( int X1, int Y1, int X2, int Y2, Color PixelColour )
{
	// Fill in the correct code here
	int MaxDist;
	float XStep;
	float YStep;
	float X = X1 + 0.5f;
	float Y = Y1 + 0.5f;

	XStep = (X2 - X1);
	YStep = (Y2 - Y1);
	MaxDist = (X2 - X1) + (Y2 - Y1);
	//just missing the ability to draw a line backwards using abs(X), its trying to convert the float of X to an int
	XStep = XStep / MaxDist;
	YStep = YStep / MaxDist;


	while (MaxDist >= 0)
	{
		SetViewportPixel(X, Y, PixelColour);
		X += XStep;
		Y += YStep;
		MaxDist -= 1;
	}

}



		//2pi radiens /Sides
	}

// Draw a regular polygon with the given number of sides. The centre of the polygon will be at
// (X, Y) and the points are on a circle of radius R
void PixelPlotterForm::DrawPolygon( int Sides, int X, int Y, int R, Color PixelColour )
{
	// Fill in the correct code here
}


// Draw a regular star with the given number of points. The centre of the star will be at (X, Y)
// and it the points are on a circle of radius R. The number of points will always be odd.
void PixelPlotterForm::DrawStar( int Sides, int X, int Y, int R, Color PixelColour )
{
	// Fill in the correct code here
}

	// Draw a circle with centre (X, Y) and radiuses RX (horizontal) and RY (vertical)
	void PixelPlotterForm::DrawCircle(int X, int Y, int R, Color PixelColour)
	{
		// Fill in the correct code here

		//not gonna lie I cant remember any of this so just ignore it
		int x = R;
		int y = 0;
		int dx = 1;
		int dy = 1;
		int err = dx - (R << 1);			//bitshifts r left 1
		while (x >= y)
		{
			SetViewportPixel(X + x, Y + y, PixelColour);
			SetViewportPixel(X + y, Y + x, PixelColour);
			SetViewportPixel(X - y, Y + x, PixelColour);
			SetViewportPixel(X - x, Y + y, PixelColour);
			SetViewportPixel(X - x, Y - y, PixelColour);
			SetViewportPixel(X - y, Y - x, PixelColour);
			SetViewportPixel(X + y, Y - x, PixelColour);
			SetViewportPixel(X + x, Y - y, PixelColour);

			if (err <= 0)
			{
				y++;
				err += dy;
				dy += 2;
			}

			if (err < 0)
			{
				x--;
				dx += 2;
				err += dx - (R << 1);
			}

		}

// Draw a circle with centre (X, Y) and radiuses RX (horizontal) and RY (vertical)
void PixelPlotterForm::DrawCircle( int X, int Y, int R, Color PixelColour )
{
	// Fill in the correct code here
}


} // end namespace PixelPlotter