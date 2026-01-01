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

// Shearing parameters
float shx = 0.5; // X-shear
float shy = 0.3; // Y-shear
int shearType = 1; // 1=X-shear, 2=Y-shear

void init() {
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0.0, 500.0, 0.0, 500.0);
}

// Apply 2D shearing using homogeneous coordinates
void shear() {
    // X-Shearing matrix in homogeneous coordinates:
    // | 1   shx  0 |
    // | 0    1   0 |
    // | 0    0   1 |
    
    // Y-Shearing matrix in homogeneous coordinates:
    // | 1    0   0 |
    // | shy  1   0 |
    // | 0    0   1 |
    
    for(int i = 0; i < 4; i++) {
        float x = original[i][0];
        float y = original[i][1];
        
        if(shearType == 1) {
            // X-Shearing: x' = x + shx * y, y' = y
            transformed[i][0] = x + shx * y;
            transformed[i][1] = y;
        } else {
            // Y-Shearing: x' = x, y' = shy * x + y
            transformed[i][0] = x;
            transformed[i][1] = shy * x + y;
        }
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
    
    // Apply shearing
    shear();
    
    // Draw transformed rectangle in red
    drawRectangle(transformed, 1.0, 0.0, 0.0);
    
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
        case '1':
            shearType = 1;
            printf("X-Shearing (shx = %.1f)\n", shx);
            glutPostRedisplay();
            break;
        case '2':
            shearType = 2;
            printf("Y-Shearing (shy = %.1f)\n", shy);
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
    printf("2D Shearing\n");
    printf("Blue: Original Rectangle\n");
    printf("Red: Sheared Rectangle\n");
    printf("Press 1: X-Shearing (shx = %.1f)\n", shx);
    printf("Press 2: Y-Shearing (shy = %.1f)\n", shy);
    printf("Press Q or ESC to exit\n\n");
    
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("2D Shearing");
    
    init();
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    
    return 0;
}
