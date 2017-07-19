QT       += core gui opengl
TARGET = cs224final
TEMPLATE = app
FORMS    += mainwindow.ui
INCLUDEPATH += ui doc util b_mesh
DEPENDPATH += ui doc util b_mesh

INCLUDEPATH += $$PWD/../../sdk/vcpkg/installed/x64-windows/include
DEPENDPATH += $$PWD/../../sdk/vcpkg/installed/x64-windows/lib $$PWD/../../sdk/vcpkg/installed/x64-windows/bin
LIBS += -lglu32 -L$$PWD/../../sdk/vcpkg/installed/x64-windows/lib/ -L$$PWD/../../sdk/vcpkg/installed/x64-windows/bin/ -lglew32
LIBS += -lopengl32

# NDEBUG disables asserts
release {
    DEFINES += NDEBUG
}

# DEFINES += ANIM_DEBUG

# floating-point render targets are horribly broken on most
# of the cs department machines so only compile this on a mac
macx {
    DEFINES += USE_SHADER_MATERIALS
}

HEADERS += \
    util/vector.h \
    ui/mainwindow.h \
    ui/camera.h \
    ui/view.h \
    util/geometry.h \
    ui/tools.h \
    doc/mesh.h \
    doc/document.h \
    b_mesh/meshconstruction.h \
    util/selectionrecorder.h \
    util/raytracer.h \
    b_mesh/catmullclark.h \
    doc/commands.h \
    b_mesh/meshevolution.h \
    b_mesh/edgefairing.h \
    util/chull.h \
    util/convexhull3d.h \
    util/curvature.h \
    util/matrix.h \
    b_mesh/trianglestoquads.h \
    util/shader.h \
    util/texture.h \
    ui/meshsculpter.h \
    util/metamesh.h \
    util/meshacceleration.h \
    ui/jointrotation.h \
    util/meshinfo.h

SOURCES += \
    ui/mainwindow.cpp \
    ui/main.cpp \
    ui/camera.cpp \
    ui/view.cpp \
    doc/document.cpp \
    util/geometry.cpp \
    ui/tools.cpp \
    doc/mesh.cpp \
    b_mesh/meshconstruction.cpp \
    doc/objfileformat.cpp \
    util/selectionrecorder.cpp \
    util/raytracer.cpp \
    b_mesh/catmullclark.cpp \
    doc/commands.cpp \
    b_mesh/meshevolution.cpp \
    b_mesh/edgefairing.cpp \
    util/chull.cpp \
    util/convexhull3d.cpp \
    util/curvature.cpp \
    util/matrix.cpp \
    b_mesh/trianglestoquads.cpp \
    util/shader.cpp \
    util/texture.cpp \
    ui/meshsculpter.cpp \
    util/metamesh.cpp \
    util/meshacceleration.cpp \
    ui/jointrotation.cpp \
    util/meshinfo.cpp \
    util/vector.cpp

RESOURCES += \
    resources.qrc

OTHER_FILES += \
    README \
    shaders/normaldepth.vert \
    shaders/normaldepth.frag \
    shaders/finalcomposite.vert \
    shaders/finalcomposite.frag






# find . -type d | sed 's/$/ \\/' | sed 's/\.\//util\/wm5\//'
INCLUDEPATH += \
    util/wm5/LibCore \
    util/wm5/LibCore/Assert \
    util/wm5/LibCore/DataTypes \
    util/wm5/LibCore/Memory \
    util/wm5/LibMathematics \
    util/wm5/LibMathematics/Base \
    util/wm5/LibMathematics/Algebra \
    util/wm5/LibMathematics/ComputationalGeometry \
    util/wm5/LibMathematics/Query \
    util/wm5/LibMathematics/Rational

# find . -name *.cpp | sed 's/$/ \\/' | sed 's/\.\//util\/wm5\//'
SOURCES += \
    util/wm5/LibCore/Assert/Wm5Assert.cpp \
    util/wm5/LibCore/Wm5CorePCH.cpp \
    util/wm5/LibMathematics/Algebra/Wm5Vector2.cpp \
    util/wm5/LibMathematics/Algebra/Wm5Vector3.cpp \
    util/wm5/LibMathematics/Algebra/Wm5Vector4.cpp \
    util/wm5/LibMathematics/Base/Wm5BitHacks.cpp \
    util/wm5/LibMathematics/Base/Wm5Float1.cpp \
    util/wm5/LibMathematics/Base/Wm5Float2.cpp \
    util/wm5/LibMathematics/Base/Wm5Float3.cpp \
    util/wm5/LibMathematics/Base/Wm5Float4.cpp \
    util/wm5/LibMathematics/Base/Wm5Math.cpp \
    util/wm5/LibMathematics/ComputationalGeometry/Wm5ConvexHull.cpp \
    util/wm5/LibMathematics/ComputationalGeometry/Wm5ConvexHull1.cpp \
    util/wm5/LibMathematics/ComputationalGeometry/Wm5ConvexHull2.cpp \
    util/wm5/LibMathematics/ComputationalGeometry/Wm5ConvexHull3.cpp \
    util/wm5/LibMathematics/Query/Wm5Query.cpp \
    util/wm5/LibMathematics/Rational/Wm5IVector2.cpp \
    util/wm5/LibMathematics/Rational/Wm5IVector3.cpp \
    util/wm5/LibMathematics/Wm5MathematicsPCH.cpp

