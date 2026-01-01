#include <GL/glut.h>
#include <math.h>
#include <stdio.h>

#define PI 3.14159265

// Original triangle vertices
float original[3][2] = {
    {200.0, 200.0},
    {300.0, 200.0},
    {250.0, 300.0}
};

// Transformed triangle vertices
float transformed[3][2];

// Rotation parameters
float angle = 45.0; // degrees
float pivotX = 250.0, pivotY = 250.0; // rotation center

void init() {
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0.0, 500.0, 0.0, 500.0);
}

// Apply 2D rotation using homogeneous coordinates
void rotate() {
    // Rotation matrix in homogeneous coordinates (about origin):
    // | cos(θ)  -sin(θ)  0 |
    // | sin(θ)   cos(θ)  0 |
    // |   0        0     1 |
    
    // For rotation about arbitrary point (pivotX, pivotY):
    // 1. Translate to origin
    // 2. Rotate
    // 3. Translate back
    
    float theta = angle * PI / 180.0;
    float cosTheta = cos(theta);
    float sinTheta = sin(theta);
    
    for(int i = 0; i < 3; i++) {
        // Translate to origin
        float x = original[i][0] - pivotX;
        float y = original[i][1] - pivotY;
        
        // Rotate
        float xNew = x * cosTheta - y * sinTheta;
        float yNew = x * sinTheta + y * cosTheta;
        
        // Translate back
        transformed[i][0] = xNew + pivotX;
        transformed[i][1] = yNew + pivotY;
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
    
    // Apply rotation
    rotate();
    
    // Draw transformed triangle in red
    drawTriangle(transformed, 1.0, 0.0, 0.0);
    
    // Draw pivot point
    glColor3f(0.0, 1.0, 0.0);
    glPointSize(5.0);
    glBegin(GL_POINTS);
    glVertex2f(pivotX, pivotY);
    glEnd();
    
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
    printf("2D Rotation\n");
    printf("Rotation Angle: %.1f degrees\n", angle);
    printf("Pivot Point: (%.1f, %.1f)\n", pivotX, pivotY);
    printf("Blue: Original Triangle\n");
    printf("Red: Rotated Triangle\n");
    printf("Green Point: Pivot\n");
    printf("Press Q or ESC to exit\n\n");
    
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("2D Rotation");
    
    init();
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    
    return 0;
}
