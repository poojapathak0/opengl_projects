#include <GL/glut.h>
#include <windows.h>
#include <stdio.h>

// Original triangle vertices
float original[3][2] = {
    {100.0, 100.0},
    {200.0, 100.0},
    {150.0, 200.0}
};

// Transformed triangle vertices
float transformed[3][2];

// Translation parameters
float tx = 150.0, ty = 100.0;

void init() {
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 500.0, 0.0, 500.0);
}

void translate() {
    for(int i = 0; i < 3; i++) {
        transformed[i][0] = original[i][0] + tx;
        transformed[i][1] = original[i][1] + ty;
    }
}

void drawTriangle(float vertices[3][2], float r, float g, float b) {
    glColor3f(r, g, b);
    glBegin(GL_LINE_LOOP);
    for(int i = 0; i < 3; i++) {
        glVertex2f(vertices[i][0], vertices[i][1]);
    }
    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    
    // Draw original triangle in blue
    drawTriangle(original, 0.0, 0.0, 1.0);
    
    // Apply translation
    translate();
    
    // Draw transformed triangle in red
    drawTriangle(transformed, 1.0, 0.0, 0.0);
    
    // Draw axes
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_LINES);
    glVertex2f(0, 250); glVertex2f(500, 250);
    glVertex2f(250, 0); glVertex2f(250, 500);
    glEnd();
    
    glFlush();
}

void keyboard(unsigned char key, int x, int y) {
    switch(key) {
        case 'q':
        case 'Q':
        case 27: // ESC
            exit(0);
            break;
    }
}

int main(int argc, char** argv) {
    printf("2D Translation\n");
    printf("Translation Vector: tx = %.1f, ty = %.1f\n", tx, ty);
    printf("Blue: Original Triangle\n");
    printf("Red: Translated Triangle\n");
    printf("Press Q or ESC to exit\n\n");
    
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("2D Translation");
    
    init();
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    
    return 0;
}
