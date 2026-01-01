#include <GL/glut.h>
#include <stdio.h>

// Original triangle vertices
float original[3][2] = {
    {100.0, 150.0},
    {150.0, 250.0},
    {200.0, 150.0}
};

// Transformed triangle vertices (reflected about X-axis)
float reflectedX[3][2];

// Transformed triangle vertices (reflected about Y-axis)
float reflectedY[3][2];

// Transformed triangle vertices (reflected about origin)
float reflectedO[3][2];

int reflectionType = 1; // 1=X-axis, 2=Y-axis, 3=Origin

void init() {
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0.0, 500.0, 0.0, 500.0);
}

// Apply 2D reflection using homogeneous coordinates
void reflect() {
    // Reflection about X-axis:
    // | 1   0   0 |
    // | 0  -1   0 |
    // | 0   0   1 |
    
    // Reflection about Y-axis:
    // | -1  0   0 |
    // |  0  1   0 |
    // |  0  0   1 |
    
    // Reflection about origin:
    // | -1  0   0 |
    // |  0 -1   0 |
    // |  0  0   1 |
    
    for(int i = 0; i < 3; i++) {
        // Reflect about X-axis (y' = -y)
        reflectedX[i][0] = original[i][0];
        reflectedX[i][1] = 500.0 - original[i][1]; // Adjust for screen coordinates
        
        // Reflect about Y-axis (x' = -x)
        reflectedY[i][0] = 500.0 - original[i][0]; // Adjust for screen coordinates
        reflectedY[i][1] = original[i][1];
        
        // Reflect about origin (x' = -x, y' = -y)
        reflectedO[i][0] = 500.0 - original[i][0];
        reflectedO[i][1] = 500.0 - original[i][1];
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
    
    // Draw axes
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_LINES);
    glVertex2f(0, 250); glVertex2f(500, 250); // X-axis
    glVertex2f(250, 0); glVertex2f(250, 500); // Y-axis
    glEnd();
    
    // Draw original triangle in blue
    drawTriangle(original, 0.0, 0.0, 1.0);
    
    // Apply reflection
    reflect();
    
    // Draw reflected triangle based on type
    switch(reflectionType) {
        case 1:
            drawTriangle(reflectedX, 1.0, 0.0, 0.0);
            break;
        case 2:
            drawTriangle(reflectedY, 1.0, 0.0, 0.0);
            break;
        case 3:
            drawTriangle(reflectedO, 1.0, 0.0, 0.0);
            break;
    }
    
    glFlush();
}

void keyboard(unsigned char key, int x, int y) {
    switch(key) {
        case '1':
            reflectionType = 1;
            printf("Reflection about X-axis\n");
            glutPostRedisplay();
            break;
        case '2':
            reflectionType = 2;
            printf("Reflection about Y-axis\n");
            glutPostRedisplay();
            break;
        case '3':
            reflectionType = 3;
            printf("Reflection about Origin\n");
            glutPostRedisplay();
            break;
        case 'q':
        case 'Q':
        case 27: // ESC
            exit(0);
            break;
    }
}

int main(int argc, char** argv) {
    printf("2D Reflection\n");
    printf("Blue: Original Triangle\n");
    printf("Red: Reflected Triangle\n");
    printf("Press 1: Reflection about X-axis\n");
    printf("Press 2: Reflection about Y-axis\n");
    printf("Press 3: Reflection about Origin\n");
    printf("Press Q or ESC to exit\n\n");
    
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("2D Reflection");
    
    init();
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    
    return 0;
}
