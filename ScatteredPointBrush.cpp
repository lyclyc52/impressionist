//
// PointBrush.cpp
//
// The implementation of Point Brush. It is a kind of ImpBrush. All your brush implementations
// will look like the file with the different GL primitive calls.
//

#include "impressionistDoc.h"
#include "impressionistUI.h"
#include "ScatteredPointBrush.h"
#include <cstdlib>



extern float frand();

ScatteredPointBrush::ScatteredPointBrush(ImpressionistDoc* pDoc, char* name) :
	ImpBrush(pDoc, name)
{
}

void ScatteredPointBrush::BrushBegin(const Point source, const Point target)
{
	ImpressionistDoc* pDoc = GetDocument();
	ImpressionistUI* dlg = pDoc->m_pUI;




	glPointSize(1);
	BrushMove(source, target);
}

void ScatteredPointBrush::BrushMove(const Point source, const Point target)
{
	ImpressionistDoc* pDoc = GetDocument();
	ImpressionistUI* dlg = pDoc->m_pUI;

	if (pDoc == NULL) {
		printf("ScatteredPointBrush::BrushMove  document is NULL\n");
		return;
	}

	int size = pDoc->getSize();




	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++) {
			if ((rand() % 3) == 0) {
				glBegin(GL_POINTS);
				SetColor(Point(source.x - size / 2.0 + i, source.y - size / 2.0 + j));
				glVertex2d(target.x - size / 2.0 + i, target.y - size / 2.0 + j);
				glEnd();
			}
		};



	
}

void ScatteredPointBrush::BrushEnd(const Point source, const Point target)
{
	// do nothing so far
}

