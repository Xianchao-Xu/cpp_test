#include <STEPControl_Reader.hxx>
#include <Standard_Integer.hxx>
#include <TopoDS_Shape.hxx>
#include <IFSelect_ReturnStatus.hxx>
#include <IFSelect_PrintCount.hxx>
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
    STEPControl_Reader reader;
    IFSelect_ReturnStatus stat = reader.ReadFile("assembly_solid.stp");
    IFSelect_PrintCount mode = IFSelect_CountByItem;
    Standard_Integer NbRoots = reader.NbRootsForTransfer();
    Standard_Integer num = reader.TransferRoots();
    Standard_Integer NbTrans = reader.TransferRoots();
    TopoDS_Shape result = reader.OneShape();
    TopoDS_Shape shape = reader.Shape();

    Handle_IVtkOCC_Shape aShapeImpl = new IVtkOCC_Shape(shape);
    Handle_IVtkVTK_ShapeData aDataImpl = new IVtkVTK_ShapeData();
    Handle_IVtk_IShapeMesher aMesher = new IVtkOCC_ShapeMesher(0.0001, 12.0 * M_PI / 180, 0, 0);
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
