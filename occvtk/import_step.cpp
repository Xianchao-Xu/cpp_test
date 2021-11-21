#include <STEPControl_Reader.hxx>
#include <Standard_Integer.hxx>
#include <TopoDS_Shape.hxx>
#include <IFSelect_ReturnStatus.hxx>
#include <IFSelect_PrintCount.hxx>
#include <IVtkTools_ShapeDataSource.hxx>
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

    vtkNew<IVtkTools_ShapeDataSource> occSource;
    occSource->SetShape(new IVtkOCC_Shape(shape));

    vtkNew<vtkPolyDataMapper> mapper;
    mapper->SetInputConnection(occSource->GetOutputPort());
    
    vtkNew<vtkActor> actor;
    actor->SetMapper(mapper);
    
    vtkNew<vtkRenderer> ren;
    ren->AddActor(actor);

    vtkNew<vtkRenderWindow> renWin;
    renWin->AddRenderer(ren);
    renWin->SetSize(640, 480);

    vtkNew<vtkInteractorStyleTrackballCamera> istyle;
    vtkNew<vtkRenderWindowInteractor> iren;

    iren->SetRenderWindow(renWin);
    iren->SetInteractorStyle(istyle);

    renWin->Render();
    iren->Start();

    return 0;
}
