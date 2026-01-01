#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <GLFW/glfw3.h>

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600

// DDA Line Drawing Algorithm
void drawLineDDA(int x1, int y1, int x2, int y2) {
    int dx = x2 - x1;
    int dy = y2 - y1;
    
    // Calculate steps required
    int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);
    
    // Calculate increment in x and y for each step
    float xIncrement = (float)dx / steps;
    float yIncrement = (float)dy / steps;
    
    // Starting point
    float x = x1;
    float y = y1;
    
    // Plot the points
    glBegin(GL_POINTS);
    for (int i = 0; i <= steps; i++) {
        // Convert screen coordinates to OpenGL coordinates (-1 to 1)
        float glX = (x / WINDOW_WIDTH) * 2.0f - 1.0f;
        float glY = 1.0f - (y / WINDOW_HEIGHT) * 2.0f;
        
        glVertex2f(glX, glY);
        
        x += xIncrement;
        y += yIncrement;
    }
    glEnd();
}

void processInput(GLFWwindow* window) {
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, 1);
}

int main() {
    // Initialize GLFW
    if (!glfwInit()) {
        printf("Failed to initialize GLFW\n");
        return -1;
    }
    
    // Create window
    GLFWwindow* window = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "DDA Line Drawing Algorithm", NULL, NULL);
    if (!window) {
        printf("Failed to create GLFW window\n");
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    
    printf("=== DDA Line Drawing Algorithm ===\n");
    printf("Drawing simple line from (100,100) to (700,500)\n");
    printf("Press ESC to close window\n\n");
    
    // Clear screen with black background
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    
    // Set point size and color
    glPointSize(2.0f);
    glColor3f(1.0f, 1.0f, 1.0f);
    
    // Draw one simple diagonal line using DDA algorithm
    drawLineDDA(100, 100, 700, 500);
    
    glfwSwapBuffers(window);
    
    // Wait for window close
    while (!glfwWindowShouldClose(window)) {
        processInput(window);
        glfwPollEvents();
    }
    
    glfwTerminate();
    return 0;
}
