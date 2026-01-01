#include <stdio.h>
#include <GLFW/glfw3.h>

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600

// Function to plot 8 symmetric points
void plotCirclePoints(int xc, int yc, int x, int y) {
    float glX, glY;
    
    // Convert to OpenGL coordinates and plot all 8 symmetric points
    glX = ((xc + x) / (float)WINDOW_WIDTH) * 2.0f - 1.0f;
    glY = 1.0f - ((yc + y) / (float)WINDOW_HEIGHT) * 2.0f;
    glVertex2f(glX, glY);
    
    glX = ((xc - x) / (float)WINDOW_WIDTH) * 2.0f - 1.0f;
    glY = 1.0f - ((yc + y) / (float)WINDOW_HEIGHT) * 2.0f;
    glVertex2f(glX, glY);
    
    glX = ((xc + x) / (float)WINDOW_WIDTH) * 2.0f - 1.0f;
    glY = 1.0f - ((yc - y) / (float)WINDOW_HEIGHT) * 2.0f;
    glVertex2f(glX, glY);
    
    glX = ((xc - x) / (float)WINDOW_WIDTH) * 2.0f - 1.0f;
    glY = 1.0f - ((yc - y) / (float)WINDOW_HEIGHT) * 2.0f;
    glVertex2f(glX, glY);
    
    glX = ((xc + y) / (float)WINDOW_WIDTH) * 2.0f - 1.0f;
    glY = 1.0f - ((yc + x) / (float)WINDOW_HEIGHT) * 2.0f;
    glVertex2f(glX, glY);
    
    glX = ((xc - y) / (float)WINDOW_WIDTH) * 2.0f - 1.0f;
    glY = 1.0f - ((yc + x) / (float)WINDOW_HEIGHT) * 2.0f;
    glVertex2f(glX, glY);
    
    glX = ((xc + y) / (float)WINDOW_WIDTH) * 2.0f - 1.0f;
    glY = 1.0f - ((yc - x) / (float)WINDOW_HEIGHT) * 2.0f;
    glVertex2f(glX, glY);
    
    glX = ((xc - y) / (float)WINDOW_WIDTH) * 2.0f - 1.0f;
    glY = 1.0f - ((yc - x) / (float)WINDOW_HEIGHT) * 2.0f;
    glVertex2f(glX, glY);
}

// Mid-point Circle Drawing Algorithm
void drawCircleMidpoint(int xc, int yc, int radius) {
    int x = 0;
    int y = radius;
    int p = 1 - radius;  // Initial decision parameter
    
    glBegin(GL_POINTS);
    
    // Plot initial point
    plotCirclePoints(xc, yc, x, y);
    
    while (x < y) {
        x++;
        
        if (p < 0) {
            // Mid-point is inside, select E
            p = p + 2 * x + 1;
        } else {
            // Mid-point is outside, select SE
            y--;
            p = p + 2 * (x - y) + 1;
        }
        
        // Plot points in all octants
        plotCirclePoints(xc, yc, x, y);
    }
    
    glEnd();
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
    
    GLFWwindow* window = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Mid-point Circle Drawing Algorithm", NULL, NULL);
    if (!window) {
        printf("Failed to create GLFW window\n");
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    
    printf("=== Mid-point Circle Drawing Algorithm ===\n");
    printf("Circle center: (400, 300), radius: 150\n");
    printf("Press ESC to close window\n\n");
    
    glPointSize(2.0f);
    
    while (!glfwWindowShouldClose(window)) {
        processInput(window);
        
        // Clear screen
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        
        glColor3f(1.0f, 1.0f, 1.0f);
        
        // Draw circle at center of window
        drawCircleMidpoint(400, 300, 150);
        
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    
    glfwTerminate();
    return 0;
}
