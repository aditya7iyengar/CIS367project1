#include "Lamborghini_struct.h"
#include <cmath>

Lamborghini_struct::~Lamborghini_struct() {
    glDeleteBuffers(1, &vertex_buffer);
    glDeleteBuffers(1, &index_buffer);
    glDeleteBuffers(1, &color_buffer);
}

void Lamborghini_struct::build(float l, float b_front, float b_middle, float b_back, float b_top,
        float h_front, float h_middle, float h_back, float h_top,
        float clr1, float clr2, float clr3) {

    glGenBuffers(1, &vertex_buffer);
    glGenBuffers(1, &index_buffer);
    glGenBuffers(1, &color_buffer);

    /* A1 0 */
    vertices.push_back(l/2);
    vertices.push_back(b_front/2);
    vertices.push_back(h_front);

    clr1 -= 0.05;
    clr2 -= 0.03;
    clr3 -= 0.01;
    colors.push_back(clr1);
    colors.push_back(clr2);
    colors.push_back(clr3);

    /* A2  1 */
    vertices.push_back(l/2);
    vertices.push_back(b_front/2);
    vertices.push_back(0);

    clr1 -= 0.05;
    clr2 -= 0.03;
    clr3 -= 0.01;

    colors.push_back(clr1);
    colors.push_back(clr2);
    colors.push_back(clr3);

    /* B1  2 */
    vertices.push_back(l/2);
    vertices.push_back(-b_front/2);
    vertices.push_back(h_front);

    clr1 -= 0.05;
    clr2 -= 0.03;
    clr3 -= 0.01;

    colors.push_back(clr1);
    colors.push_back(clr2);
    colors.push_back(clr3);

    /* B2  3 */
    vertices.push_back(l/2);
    vertices.push_back(-b_front/2);
    vertices.push_back(0);

    clr1 -= 0.05;
    clr2 -= 0.03;
    clr3 -= 0.01;

    colors.push_back(clr1);
    colors.push_back(clr2);
    colors.push_back(clr3);

    /* C1  4 */
    vertices.push_back(l/4);
    vertices.push_back(b_middle/2);
    vertices.push_back(h_middle);

    clr1 -= 0.05;
    clr2 -= 0.03;
    clr3 -= 0.01;

    colors.push_back(clr1);
    colors.push_back(clr2);
    colors.push_back(clr3);

    /* C2  5 */
    vertices.push_back(l/4);
    vertices.push_back(b_middle/2);
    vertices.push_back(0);

    clr1 -= 0.05;
    clr2 -= 0.03;
    clr3 -= 0.01;

    colors.push_back(clr1);
    colors.push_back(clr2);
    colors.push_back(clr3);

    /* D1  6  */
    vertices.push_back(l/4);
    vertices.push_back(-b_middle/2);
    vertices.push_back(h_middle);

    clr1 -= 0.05;
    clr2 -= 0.03;
    clr3 -= 0.01;

    colors.push_back(clr1);
    colors.push_back(clr2);
    colors.push_back(clr3);

    /* D2  7 */
    vertices.push_back(l/4);
    vertices.push_back(-b_middle/2);
    vertices.push_back(0);

    clr1 -= 0.05;
    clr2 -= 0.03;
    clr3 -= 0.01;

    colors.push_back(clr1);
    colors.push_back(clr2);
    colors.push_back(clr3);

    /* I1  8 */
    vertices.push_back(-l/2.5);
    vertices.push_back(b_back/2);
    vertices.push_back(h_back);

    clr1 += 0.10;
    clr2 += 0.06;
    clr3 += 0.02;

    colors.push_back(clr1);
    colors.push_back(clr2);
    colors.push_back(clr3);

    /* I2 9 */
    vertices.push_back(-l/2.5);
    vertices.push_back(b_back/2);
    vertices.push_back(0);

    clr1 += 0.05;
    clr2 += 0.03;
    clr3 += 0.01;

    colors.push_back(clr1);
    colors.push_back(clr2);
    colors.push_back(clr3);

    /* J1 10  */
    vertices.push_back(-l/2.5);
    vertices.push_back(-b_back/2);
    vertices.push_back(h_back);

    clr1 += 0.05;
    clr2 += 0.03;
    clr3 += 0.01;

    colors.push_back(clr1);
    colors.push_back(clr2);
    colors.push_back(clr3);

    /* J2 11 */
    vertices.push_back(-l/2.5);
    vertices.push_back(-b_back/2);
    vertices.push_back(0);

    clr1 += 0.05;
    clr2 += 0.03;
    clr3 += 0.01;

    colors.push_back(clr1);
    colors.push_back(clr2);
    colors.push_back(clr3);

    /* K1 12 */
    vertices.push_back(-l/2);
    vertices.push_back(b_back/2);
    vertices.push_back(h_back-.03);

    clr1 += 0.05;
    clr2 += 0.03;
    clr3 += 0.01;

    colors.push_back(clr1);
    colors.push_back(clr2);
    colors.push_back(clr3);

    /* K2 13 */
    vertices.push_back(-l/2);
    vertices.push_back(b_back/2);
    vertices.push_back(0.05);

    clr1 += 0.05;
    clr2 += 0.03;
    clr3 += 0.01;

    colors.push_back(clr1);
    colors.push_back(clr2);
    colors.push_back(clr3);

    /* L1 14 */
    vertices.push_back(-l/2);
    vertices.push_back(-b_back/2);
    vertices.push_back(h_back-0.03);

    clr1 += 0.05;
    clr2 += 0.03;
    clr3 += 0.01;

    colors.push_back(clr1);
    colors.push_back(clr2);
    colors.push_back(clr3);

    /* L2 15 */
    vertices.push_back(-l/2);
    vertices.push_back(-b_back/2);
    vertices.push_back(0.05);

    clr1 += 0.05;
    clr2 += 0.03;
    clr3 += 0.01;

    colors.push_back(clr1);
    colors.push_back(clr2);
    colors.push_back(clr3);

    /* E1 16 */
    vertices.push_back(0);
    vertices.push_back(b_top/2);
    vertices.push_back(h_top);

    clr1 -= 0.05;
    clr2 -= 0.03;
    clr3 -= 0.01;

    colors.push_back(clr1);
    colors.push_back(clr2);
    colors.push_back(clr3);

    /* F1 17 */
    vertices.push_back(0);
    vertices.push_back(-b_top/2);
    vertices.push_back(h_top);

    clr1 -= 0.05;
    clr2 -= 0.03;
    clr3 -= 0.01;

    colors.push_back(clr1);
    colors.push_back(clr2);
    colors.push_back(clr3);

    /* G1 18 */
    vertices.push_back(-l/5);
    vertices.push_back(b_top/2);
    vertices.push_back(h_top);

    clr1 -= 0.05;
    clr2 -= 0.03;
    clr3 -= 0.01;

    colors.push_back(clr1);
    colors.push_back(clr2);
    colors.push_back(clr3);

    /* H1 19 */
    vertices.push_back(-l/5);
    vertices.push_back(-b_top/2);
    vertices.push_back(h_top);

    clr1 -= 0.05;
    clr2 -= 0.03;
    clr3 -= 0.01;

    colors.push_back(clr1);
    colors.push_back(clr2);
    colors.push_back(clr3);

    /* base */
    /* quad strip */
    indices.push_back(0);
    indices.push_back(1);

    indices.push_back(4);
    indices.push_back(5);

    indices.push_back(8);
    indices.push_back(9);

    indices.push_back(12);
    indices.push_back(13);


    indices.push_back(14);
    indices.push_back(15);


    indices.push_back(10);
    indices.push_back(11);


    indices.push_back(6);
    indices.push_back(7);


    indices.push_back(2);
    indices.push_back(3);

    indices.push_back(0);
    indices.push_back(1);

    /* quad */
    indices.push_back(0);
    indices.push_back(4);
    indices.push_back(2);
    indices.push_back(6);

    /* quad*/
    indices.push_back(8);
    indices.push_back(12);
    indices.push_back(10);
    indices.push_back(14);

    /* top */
    /* quad strip*/
    indices.push_back(16);
    indices.push_back(4);

    indices.push_back(18);
    indices.push_back(12);


    indices.push_back(19);
    indices.push_back(14);

    indices.push_back(17);
    indices.push_back(6);

    indices.push_back(16);
    indices.push_back(4);

    /* quad */
    indices.push_back(16);
    indices.push_back(18);
    indices.push_back(17);
    indices.push_back(19);

    glBindBuffer(GL_ARRAY_BUFFER, vertex_buffer);
    glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(float), vertices.data(), GL_STATIC_DRAW);

    glBindBuffer (GL_ARRAY_BUFFER, color_buffer);
    glBufferData (GL_ARRAY_BUFFER,
            colors.size() * sizeof(GLfloat), colors.data(), GL_STATIC_DRAW);

    glUnmapBuffer(GL_ARRAY_BUFFER);
    glBindBuffer(GL_ARRAY_BUFFER, 0);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, index_buffer);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(GLushort),indices.data(), GL_STATIC_DRAW);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

}

void Lamborghini_struct::render() const {
    glPushAttrib(GL_ENABLE_BIT);
    //glDisableClientState(GL_COLOR_ARRAY);
    glBindBuffer (GL_ARRAY_BUFFER, vertex_buffer);
    glVertexPointer(3, GL_FLOAT, 0, 0);
    glBindBuffer (GL_ARRAY_BUFFER, color_buffer);
    glColorPointer(3, GL_FLOAT, 0, 0);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, index_buffer);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, index_buffer);

    glDrawElements(GL_QUAD_STRIP, 18, GL_UNSIGNED_SHORT, 0);
    glDrawElements(GL_QUAD_STRIP, 4, GL_UNSIGNED_SHORT, (void*)(sizeof(GLushort)*18));
    glDrawElements(GL_QUAD_STRIP, 4, GL_UNSIGNED_SHORT, (void*)(sizeof(GLushort)*22));
    glDrawElements(GL_QUAD_STRIP,10, GL_UNSIGNED_SHORT, (void*)(sizeof(GLushort)*26));
    glDrawElements(GL_QUAD_STRIP, 4, GL_UNSIGNED_SHORT, (void*)(sizeof(GLushort)*36));


    glBindBuffer (GL_ARRAY_BUFFER, 0);
    glBindBuffer (GL_ELEMENT_ARRAY_BUFFER, 0);
    glPopAttrib();
}