#include <GL/glut.h>
#include <math.h>
#include <stdio.h>

#define PI 3.14159265

// Original triangle vertices
float original[3][2] = {
    {100.0, 100.0},
    {150.0, 100.0},
    {125.0, 150.0}
};

// Intermediate and final transformed vertices
float stage1[3][2], stage2[3][2], stage3[3][2], stage4[3][2];

void init() {
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0.0, 500.0, 0.0, 500.0);
}

// Composite transformation: Translation -> Rotation -> Scaling -> Shearing
void compositeTransform() {
    // Stage 1: Translation (tx=100, ty=50)
    float tx = 100.0, ty = 50.0;
    for(int i = 0; i < 3; i++) {
        stage1[i][0] = original[i][0] + tx;
        stage1[i][1] = original[i][1] + ty;
    }
    
    // Stage 2: Rotation (45 degrees about center 250, 250)
    float angle = 30.0 * PI / 180.0;
    float pivotX = 250.0, pivotY = 250.0;
    float cosTheta = cos(angle);
    float sinTheta = sin(angle);
    
    for(int i = 0; i < 3; i++) {
        float x = stage1[i][0] - pivotX;
        float y = stage1[i][1] - pivotY;
        
        float xNew = x * cosTheta - y * sinTheta;
        float yNew = x * sinTheta + y * cosTheta;
        
        stage2[i][0] = xNew + pivotX;
        stage2[i][1] = yNew + pivotY;
    }
    
    // Stage 3: Scaling (sx=1.5, sy=1.5 about point 250, 250)
    float sx = 1.5, sy = 1.5;
    float fixedX = 250.0, fixedY = 250.0;
    
    for(int i = 0; i < 3; i++) {
        float x = stage2[i][0] - fixedX;
        float y = stage2[i][1] - fixedY;
        
        float xNew = x * sx;
        float yNew = y * sy;
        
        stage3[i][0] = xNew + fixedX;
        stage3[i][1] = yNew + fixedY;
    }
    
    // Stage 4: X-Shearing (shx=0.3)
    float shx = 0.3;
    
    for(int i = 0; i < 3; i++) {
        stage4[i][0] = stage3[i][0] + shx * stage3[i][1];
        stage4[i][1] = stage3[i][1];
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
    
    // Apply composite transformation
    compositeTransform();
    
    // Draw all stages
    drawTriangle(original, 0.0, 0.0, 1.0);    // Blue - Original
    drawTriangle(stage1, 0.0, 1.0, 1.0);      // Cyan - After Translation
    drawTriangle(stage2, 1.0, 1.0, 0.0);      // Yellow - After Rotation
    drawTriangle(stage3, 1.0, 0.5, 0.0);      // Orange - After Scaling
    drawTriangle(stage4, 1.0, 0.0, 0.0);      // Red - Final (After Shearing)
    
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
    printf("Composite Transformations (4 Transformations)\n");
    printf("==============================================\n");
    printf("Blue:   Original Triangle\n");
    printf("Cyan:   After Translation (tx=100, ty=50)\n");
    printf("Yellow: After Rotation (30° about center)\n");
    printf("Orange: After Scaling (sx=1.5, sy=1.5)\n");
    printf("Red:    Final Result After X-Shearing (shx=0.3)\n\n");
    printf("All transformations use homogeneous coordinate systems\n");
    printf("Press Q or ESC to exit\n\n");
    
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Composite Transformations");
    
    init();
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    
    return 0;
}
