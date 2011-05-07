#ifndef METAMESH_H
#define METAMESH_H

#include "mesh.h"

class MetaVertex
{
public:
    int accelData;
    Vector3 &pos;
    Vector3 &normal;
    Vector3 prevPos;
    QVector<Quad *> neighbors;

    MetaVertex(Vertex &vertex) : accelData(0), pos(vertex.pos), normal(vertex.normal), prevPos(vertex.pos) {}
};

class MetaMesh
{
public:
    Mesh &mesh;
    QVector<MetaVertex *> vertices;

    MetaMesh(Mesh &mesh);
    ~MetaMesh();
};

#endif // METAMESH_H