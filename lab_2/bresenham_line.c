#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <GLFW/glfw3.h>

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600

// Bresenham Line Drawing Algorithm for |m| < 1
void bresenhamLow(int x1, int y1, int x2, int y2) {
    int dx = x2 - x1;
    int dy = y2 - y1;
    int yi = 1;
    
    if (dy < 0) {
        yi = -1;
        dy = -dy;
    }
    
    int p = 2 * dy - dx;
    int y = y1;
    
    glBegin(GL_POINTS);
    for (int x = x1; x <= x2; x++) {
        float glX = (x / (float)WINDOW_WIDTH) * 2.0f - 1.0f;
        float glY = 1.0f - (y / (float)WINDOW_HEIGHT) * 2.0f;
        glVertex2f(glX, glY);
        
        if (p > 0) {
            y = y + yi;
            p = p + 2 * (dy - dx);
        } else {
            p = p + 2 * dy;
        }
    }
    glEnd();
}

// Bresenham Line Drawing Algorithm for |m| >= 1
void bresenhamHigh(int x1, int y1, int x2, int y2) {
    int dx = x2 - x1;
    int dy = y2 - y1;
    int xi = 1;
    
    if (dx < 0) {
        xi = -1;
        dx = -dx;
    }
    
    int p = 2 * dx - dy;
    int x = x1;
    
    glBegin(GL_POINTS);
    for (int y = y1; y <= y2; y++) {
        float glX = (x / (float)WINDOW_WIDTH) * 2.0f - 1.0f;
        float glY = 1.0f - (y / (float)WINDOW_HEIGHT) * 2.0f;
        glVertex2f(glX, glY);
        
        if (p > 0) {
            x = x + xi;
            p = p + 2 * (dx - dy);
        } else {
            p = p + 2 * dx;
        }
    }
    glEnd();
}

// Main Bresenham function that decides which algorithm to use
void drawLineBresenham(int x1, int y1, int x2, int y2) {
    if (abs(y2 - y1) < abs(x2 - x1)) {
        // |m| < 1
        if (x1 > x2) {
            bresenhamLow(x2, y2, x1, y1);
        } else {
            bresenhamLow(x1, y1, x2, y2);
        }
    } else {
        // |m| >= 1
        if (y1 > y2) {
            bresenhamHigh(x2, y2, x1, y1);
        } else {
            bresenhamHigh(x1, y1, x2, y2);
        }
    }
}

void processInput(GLFWwindow* window) {
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, 1);
}

int main() {
    if (!glfwInit()) {
        printf("Failed to initialize GLFW\n");
        return -1;
    }
    
    GLFWwindow* window = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Bresenham Line Drawing Algorithm", NULL, NULL);
    if (!window) {
        printf("Failed to create GLFW window\n");
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    
    printf("=== Bresenham Line Drawing Algorithm ===\n");
    printf("Line 1: (50, 300) to (750, 450) - |m| < 1\n");
    printf("Line 2: (400, 50) to (500, 550) - |m| >= 1\n");
    printf("Press ESC to close window\n\n");
    
    glPointSize(2.0f);
    
    while (!glfwWindowShouldClose(window)) {
        processInput(window);
        
        // Clear screen
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        
        glColor3f(1.0f, 1.0f, 1.0f);
        
        // Line 1: |m| < 1 (gentle slope, more horizontal)
        drawLineBresenham(50, 300, 750, 450);
        
        // Line 2: |m| >= 1 (steep slope, more vertical)
        drawLineBresenham(400, 50, 500, 550);
        
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    
    glfwTerminate();
    return 0;
}
