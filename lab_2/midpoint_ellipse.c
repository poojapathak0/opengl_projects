#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <GLFW/glfw3.h>

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600

// Function to plot ellipse points with 4-way symmetry
void plotEllipsePoints(int xc, int yc, int x, int y) {
    // Plot all 4 symmetric points
    float glX, glY;
    
    // Point 1: (x, y)
    glX = ((xc + x) / (float)WINDOW_WIDTH) * 2.0f - 1.0f;
    glY = 1.0f - ((yc + y) / (float)WINDOW_HEIGHT) * 2.0f;
    glVertex2f(glX, glY);
    
    // Point 2: (-x, y)
    glX = ((xc - x) / (float)WINDOW_WIDTH) * 2.0f - 1.0f;
    glY = 1.0f - ((yc + y) / (float)WINDOW_HEIGHT) * 2.0f;
    glVertex2f(glX, glY);
    
    // Point 3: (x, -y)
    glX = ((xc + x) / (float)WINDOW_WIDTH) * 2.0f - 1.0f;
    glY = 1.0f - ((yc - y) / (float)WINDOW_HEIGHT) * 2.0f;
    glVertex2f(glX, glY);
    
    // Point 4: (-x, -y)
    glX = ((xc - x) / (float)WINDOW_WIDTH) * 2.0f - 1.0f;
    glY = 1.0f - ((yc - y) / (float)WINDOW_HEIGHT) * 2.0f;
    glVertex2f(glX, glY);
}

// Midpoint Ellipse Drawing Algorithm
void drawEllipse(int xc, int yc, int rx, int ry) {
    int x = 0;
    int y = ry;
    
    // Initial decision parameters
    float p1 = (ry * ry) - (rx * rx * ry) + (0.25 * rx * rx);
    int dx = 2 * ry * ry * x;
    int dy = 2 * rx * rx * y;
    
    glBegin(GL_POINTS);
    
    // Region 1: where slope > -1
    while (dx < dy) {
        plotEllipsePoints(xc, yc, x, y);
        
        if (p1 < 0) {
            x++;
            dx = dx + (2 * ry * ry);
            p1 = p1 + dx + (ry * ry);
        } else {
            x++;
            y--;
            dx = dx + (2 * ry * ry);
            dy = dy - (2 * rx * rx);
            p1 = p1 + dx - dy + (ry * ry);
        }
    }
    
    // Region 2: where slope < -1
    float p2 = ((ry * ry) * ((x + 0.5) * (x + 0.5))) + 
               ((rx * rx) * ((y - 1) * (y - 1))) - 
               (rx * rx * ry * ry);
    
    while (y >= 0) {
        plotEllipsePoints(xc, yc, x, y);
        
        if (p2 > 0) {
            y--;
            dy = dy - (2 * rx * rx);
            p2 = p2 + (rx * rx) - dy;
        } else {
            x++;
            y--;
            dx = dx + (2 * ry * ry);
            dy = dy - (2 * rx * rx);
            p2 = p2 + dx - dy + (rx * rx);
        }
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
    
    GLFWwindow* window = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Midpoint Ellipse Drawing", NULL, NULL);
    if (!window) {
        printf("Failed to create GLFW window\n");
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    
    printf("=== Midpoint Ellipse Drawing Algorithm ===\n");
    printf("Drawing ellipse at center (400, 300)\n");
    printf("Radius X (rx) = 250, Radius Y (ry) = 150\n");
    printf("Press ESC to close window\n\n");
    
    glPointSize(2.0f);
    
    while (!glfwWindowShouldClose(window)) {
        processInput(window);
        
        // Clear screen
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        
        glColor3f(1.0f, 1.0f, 1.0f);
        
        // Draw ellipse with center (400, 300), rx=250, ry=150
        drawEllipse(400, 300, 250, 150);
        
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    
    glfwTerminate();
    return 0;
}
