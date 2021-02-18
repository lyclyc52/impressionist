//
// PointBrush.cpp
//
// The implementation of Point Brush. It is a kind of ImpBrush. All your brush implementations
// will look like the file with the different GL primitive calls.
//

#include "impressionistDoc.h"
#include "impressionistUI.h"
#include "LineBrush.h"
#include <math.h>


#define PI acos(-1)


extern float frand();

LineBrush::LineBrush(ImpressionistDoc* pDoc, char* name) :
	ImpBrush(pDoc, name)
{
}

void LineBrush::BrushBegin(const Point source, const Point target)
{
	ImpressionistDoc* pDoc = GetDocument();
	ImpressionistUI* dlg = pDoc->m_pUI;



	BrushMove(source, target);
}

void LineBrush::BrushMove(const Point source, const Point target)
{
	ImpressionistDoc* pDoc = GetDocument();
	ImpressionistUI* dlg = pDoc->m_pUI;

	if (pDoc == NULL) {
		printf("LineBrush::BrushMove  document is NULL\n");
		return;
	}

	int size = pDoc->getSize();
	int width = pDoc->getWidth();
	int angle = pDoc->getAngle();


	glLineWidth(width);
	glBegin(GL_LINES);
		SetColor(source);

		glVertex2f(target.x - size / 2 * cos(angle / 360.0 * 2 * PI), target.y - size / 2 * sin(angle / 360.0 * 2 * PI));
		glVertex2f(target.x + size / 2 * cos(angle / 360.0 * 2 * PI), target.y + size / 2 * sin(angle / 360.0 * 2 * PI));

	glEnd();
}

void LineBrush::BrushEnd(const Point source, const Point target)
{
	// do nothing so far
}

