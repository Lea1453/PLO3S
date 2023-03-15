#ifndef _ICPLAYER_H_
#define _ICPLAYER_H_

void CreatePolyData(vtkSmartPointer<vtkPolyData> polydata);
void PerturbPolyData(vtkSmartPointer<vtkPolyData> polydata);
void TranslatePolyData(vtkSmartPointer<vtkPolyData> polydata);
void AxesLines(vtkSmartPointer<vtkPolyData> linesPolyData);

/**
 * Convert points to glyphs.
 *
 * @param points - The points to glyph
 * @param scale - The scale, used to determine the size of the glyph
 * representing the point, expressed as a fraction of the largest side of the
 * bounding box surrounding the points. e.g. 0.05
 *
 * @return The actor.
 */
/*vtkSmartPointer<vtkActor> PointToGlyph(vtkPoints* points, double const& scale);*/

#endif
