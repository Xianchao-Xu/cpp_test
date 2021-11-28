#include <BRepPrimAPI_MakeBox.hxx>
#include <IVtkVTK_ShapeData.hxx>
#include <IVtkOCC_ShapeMesher.hxx>
#include <vtkType.h>
#include <vtkAutoInit.h>
#include <vtkRenderWindow.h>
#include <vtkActor.h>
#include <vtkRenderer.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkPolyDataMapper.h>
#include <vtkInteractorStyleTrackballCamera.h>

VTK_MODULE_INIT(vtkRenderingOpenGL2)
VTK_MODULE_INIT(vtkInteractionStyle)

int main()
{
    BRepPrimAPI_MakeBox mkBox(1., 2., 3);
    const TopoDS_Shape& shape = mkBox.Shape();

    IVtkOCC_Shape::Handle aShapeImpl = new IVtkOCC_Shape(shape);
    IVtkVTK_ShapeData::Handle aDataImpl = new IVtkVTK_ShapeData();
    IVtk_IShapeMesher::Handle aMesher = new IVtkOCC_ShapeMesher(0.0001, 12.0*M_PI/180, 0, 0);
    aMesher->Build(aShapeImpl, aDataImpl);
    vtkPolyData* aPolyData = aDataImpl->getVtkPolyData();

    vtkNew<vtkPolyDataMapper> mapper;
    mapper->SetInputData(aPolyData);
    
    vtkNew<vtkActor> actor;
    actor->SetMapper(mapper);
    
    vtkNew<vtkRenderer> ren;
    ren->AddActor(actor);

    vtkNew<vtkRenderWindow> renWin;
    renWin->AddRenderer(ren);
    renWin->SetSize(960, 800);

    vtkNew<vtkInteractorStyleTrackballCamera> istyle;
    vtkNew<vtkRenderWindowInteractor> iren;

    iren->SetRenderWindow(renWin);
    iren->SetInteractorStyle(istyle);

    renWin->Render();
    iren->Start();

    return 0;
}
