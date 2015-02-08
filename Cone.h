#ifndef CONE_H
#define CONE_H

#include <vector>
#include <GL/glew.h>

using namespace std;
class Cone {
private:
    const float CONE_HEIGHT = 1.0f;
    const float CONE_RADIUS = 0.5f;
    GLuint vertex_buffer, index_buffer, color_buffer;
    vector<GLushort> index;
    vector<GLfloat> color;
    vector<GLfloat> vertex;
public:
    ~Cone();
    void build(int);
    void render() const;
};
#endif