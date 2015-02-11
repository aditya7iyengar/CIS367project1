#ifndef LAMBO_STRUCT_H
#define LAMBO_STRUCT_H

#include <vector>
#include <GL/glew.h>

using namespace std;

class Lamborghini_struct {

private:
    GLuint vertex_buffer, index_buffer, color_buffer;
    vector<float> vertices;
    vector<GLushort> indices;
    vector<GLfloat> colors;

public:
    ~Lamborghini_struct();
    void build (float l, float b_front, float b_middle,
            float b_back, float b_top, float h_front, float h_middle,
            float h_back,float h_top, float clr1, float clr2, float clr3);

    void render() const;
};
#endif