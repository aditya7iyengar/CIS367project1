#include "Cone.h"
#include <cmath>
#include <iostream>

/* This example uses color buffer to colorize the vertices */
Cone::~Cone() {
    glDeleteBuffers(1, &vertex_buffer);
    glDeleteBuffers(1, &index_buffer);
    glDeleteBuffers(1, &color_buffer);
}

void Cone::build(int Nsegments) {
    glGenBuffers(1, &vertex_buffer);
    glGenBuffers(1, &index_buffer);
    glGenBuffers(1, &color_buffer);

    float d_angle = 2 * M_PI / Nsegments;
    float angle = 0.0f;

    /* the first point is the TIP of the cone */
    vertex.push_back (0.0f);
    vertex.push_back (0.0f);
    vertex.push_back (CONE_HEIGHT);

    /* must push an RGB triplet for each vertex */
    color.push_back(0.999f);
    color.push_back(0.0f);
    color.push_back(0.0f);
    for (int k = 0; k < Nsegments; k++) {
        float x = CONE_RADIUS * cos(angle);
        float y = CONE_RADIUS * sin(angle);
        vertex.push_back (x);
        vertex.push_back (y);
        vertex.push_back (0.0f);
        /* vary the green and blue component around
         * the base of the cone */
        color.push_back (0.3f);
        color.push_back (abs(cos(angle)));
        color.push_back (abs(sin(angle)));
        angle += d_angle;
    }

    /* the last point is needed for the center of the base */
    vertex.push_back (0);
    vertex.push_back (0);
    vertex.push_back (0);
    color.push_back (1.0f);
    color.push_back (0.9f);
    color.push_back (1.0f);

    for (int k = 0; k < Nsegments + 1; k++)
        index.push_back(k);
    index.push_back (1);

    /* index of the base center */
    index.push_back ((vertex.size() - 1)/3);
    for (int k = 1; k < Nsegments + 1; k++)
        index.push_back(k);
    index.push_back (1);

    glBindBuffer (GL_ARRAY_BUFFER, vertex_buffer);
    glBufferData (GL_ARRAY_BUFFER,
            vertex.size() * sizeof(GLfloat), vertex.data(), GL_STATIC_DRAW);

    glBindBuffer (GL_ARRAY_BUFFER, color_buffer);
    glBufferData (GL_ARRAY_BUFFER,
            color.size() * sizeof(GLfloat), color.data(), GL_STATIC_DRAW);
    glBindBuffer (GL_ARRAY_BUFFER, 0);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, index_buffer);
    glBufferData (GL_ELEMENT_ARRAY_BUFFER, index.size() * sizeof(GLushort),
            index.data(), GL_STATIC_DRAW);
    glBindBuffer (GL_ELEMENT_ARRAY_BUFFER, 0);
}

void Cone::render() const {
    glPushAttrib(GL_ENABLE_BIT);
    glBindBuffer(GL_ARRAY_BUFFER, vertex_buffer);
    glVertexPointer(3, GL_FLOAT, 0, 0);
    glBindBuffer(GL_ARRAY_BUFFER, color_buffer);
    glColorPointer(3, GL_FLOAT, 0, 0);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, index_buffer);

    const int N = index.size()/2;
    /* draw triangle-fan for the cone skin */
    glDrawElements(GL_TRIANGLE_FAN, N, GL_UNSIGNED_SHORT, 0);

    /* draw triangle-fan for the cone base, but they are
     * rendered in clockwise order */
    glFrontFace(GL_CW);
    glDrawElements(GL_TRIANGLE_FAN, N, GL_UNSIGNED_SHORT, (void *)(N * sizeof(GLushort)));


    glBindBuffer (GL_ARRAY_BUFFER, 0);
    glBindBuffer( (GL_ELEMENT_ARRAY_BUFFER), 0);

    glPopAttrib();
}