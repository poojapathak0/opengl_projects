#include <GL/glut.h>
#include <stdio.h>

// Original rectangle vertices
float original[4][2] = {
    {150.0, 150.0},
    {250.0, 150.0},
    {250.0, 250.0},
    {150.0, 250.0}
};

// Transformed rectangle vertices
float transformed[4][2];

// Scaling parameters
float sx = 1.5, sy = 1.5;
float fixedX = 200.0, fixedY = 200.0; // fixed point for scaling

void init() {
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0.0, 500.0, 0.0, 500.0);
}

// Apply 2D scaling using homogeneous coordinates
void scale() {
    // Scaling matrix in homogeneous coordinates (about origin):
    // | sx  0   0 |
    // | 0   sy  0 |
    // | 0   0   1 |
    
    // For scaling about arbitrary point (fixedX, fixedY):
    // 1. Translate to origin
    // 2. Scale
    // 3. Translate back
    
    for(int i = 0; i < 4; i++) {
        // Translate to origin
        float x = original[i][0] - fixedX;
        float y = original[i][1] - fixedY;
        
        // Scale
        float xNew = x * sx;
        float yNew = y * sy;
        
        // Translate back
        transformed[i][0] = xNew + fixedX;
        transformed[i][1] = yNew + fixedY;
    }
}

void drawRectangle(float vertices[4][2], float r, float g, float b) {
    glColor3f(r, g, b);
    glBegin(GL_LINE_LOOP);
    for(int i = 0; i < 4; i++) {
        glVertex2f(vertices[i][0], vertices[i][1]);
    }
    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    
    // Draw original rectangle in blue
    drawRectangle(original, 0.0, 0.0, 1.0);
    
    // Apply scaling
    scale();
    
    // Draw transformed rectangle in red
    drawRectangle(transformed, 1.0, 0.0, 0.0);
    
    // Draw fixed point
    glColor3f(0.0, 1.0, 0.0);
    glPointSize(5.0);
    glBegin(GL_POINTS);
    glVertex2f(fixedX, fixedY);
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
    printf("2D Scaling\n");
    printf("Scaling Factors: sx = %.1f, sy = %.1f\n", sx, sy);
    printf("Fixed Point: (%.1f, %.1f)\n", fixedX, fixedY);
    printf("Blue: Original Rectangle\n");
    printf("Red: Scaled Rectangle\n");
    printf("Green Point: Fixed Point\n");
    printf("Press Q or ESC to exit\n\n");
    
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("2D Scaling");
    
    init();
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    
    return 0;
}
