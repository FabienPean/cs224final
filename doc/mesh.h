#ifndef MESH_H
#define MESH_H

#include <QVector>
#include <string>
#include "vector.h"

struct Ball
{
    Vector3 center;

    // local coordinate frame of ellipsoid (includes scale factors)
    Vector3 ex, ey, ez;

    // index into Mesh::balls
    int parentIndex;

    // temporary values used by b_mesh code, are only set immediately before calling
    QVector<int> childrenIndices;

    Ball() : ex(1, 0, 0), ey(0, 1, 0), ez(0, 0, 1), parentIndex(-1) {}
    Ball(const Vector3 &center, float radius, int parentIndex = -1) : center(center), ex(radius, 0, 0), ey(0, radius, 0), ez(0, 0, radius), parentIndex(parentIndex) {}

    float minRadius() const { return min(min(ex.length(), ey.length()), ez.length()); }
    float maxRadius() const { return max(max(ex.length(), ey.length()), ez.length()); }
    void draw() const;
};

struct Vertex
{
    Vector3 pos;
    Vector3 normal;

    Vertex() {}
    Vertex(const Vector3 &pos) : pos(pos) {}

    void draw() const;
};

struct Index
{
    // index into Mesh::vertices
    int index;

    // texture coordinate
    Vector2 coord;

    Index() {}
    Index(int index) : index(index) {}
};

struct Triangle
{
    Index a, b, c;

    Triangle() {}
    Triangle(int a, int b, int c) : a(a), b(b), c(c) {}
};

struct Quad
{
    Index a, b, c, d;

    Quad() {}
    Quad(int a, int b, int c, int d) : a(a), b(b), c(c), d(d) {}
};

class Mesh
{
private:
    unsigned int vertexBuffer;
    unsigned int triangleIndexBuffer;
    unsigned int lineIndexBuffer;
    QVector<Vertex> cachedVertices;
    QVector<int> triangleIndices;
    QVector<int> lineIndices;

public:
    QVector<Ball> balls;
    QVector<Vertex> vertices;
    QVector<Triangle> triangles;
    QVector<Quad> quads;

    Mesh() : vertexBuffer(0), triangleIndexBuffer(0), lineIndexBuffer(0) {}
    ~Mesh();

    void updateChildIndices();
    void updateNormals();
    void uploadToGPU();

    void drawFill() const;
    void drawWireframe() const;
    void drawKeyBalls(float alpha = 1) const;
    void drawInBetweenBalls() const;
    void drawBones() const;

    bool loadFromOBJ(const std::string &file);
    bool saveToOBJ(const std::string &file);
};

#endif // MESH_H
