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
    
    int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);
    
    float xIncrement = (float)dx / steps;
    float yIncrement = (float)dy / steps;
    
    float x = x1;
    float y = y1;
    
    glBegin(GL_POINTS);
    for (int i = 0; i <= steps; i++) {
        float glX = (x / WINDOW_WIDTH) * 2.0f - 1.0f;
        float glY = 1.0f - (y / WINDOW_HEIGHT) * 2.0f;
        
        glVertex2f(glX, glY);
        
        x += xIncrement;
        y += yIncrement;
    }
    glEnd();
}

// Function to draw axes
void drawAxes() {
    glColor3f(0.5f, 0.5f, 0.5f);
    
    // X-axis
    drawLineDDA(50, 500, 750, 500);
    
    // Y-axis
    drawLineDDA(50, 100, 50, 500);
}

// Function to draw data points
void drawDataPoint(int x, int y) {
    float glX = (x / (float)WINDOW_WIDTH) * 2.0f - 1.0f;
    float glY = 1.0f - (y / (float)WINDOW_HEIGHT) * 2.0f;
    
    glPointSize(8.0f);
    glBegin(GL_POINTS);
    glVertex2f(glX, glY);
    glEnd();
}

// Function to plot line graph from data
void plotLineGraph(int dataX[], int dataY[], int numPoints) {
    // Draw lines connecting data points
    glColor3f(0.0f, 1.0f, 0.0f); // Green for lines
    glPointSize(2.0f);
    
    for (int i = 0; i < numPoints - 1; i++) {
        drawLineDDA(dataX[i], dataY[i], dataX[i + 1], dataY[i + 1]);
    }
    
    // Draw data points
    glColor3f(1.0f, 0.0f, 0.0f); // Red for points
    for (int i = 0; i < numPoints; i++) {
        drawDataPoint(dataX[i], dataY[i]);
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
    
    GLFWwindow* window = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Line Graph Using DDA", NULL, NULL);
    if (!window) {
        printf("Failed to create GLFW window\n");
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    
    printf("=== Line Graph Generator Using DDA ===\n");
    printf("Plotting sample data points\n");
    printf("Press ESC to close window\n\n");
    
    // Sample data set (x, y coordinates)
    int dataX[] = {100, 200, 300, 400, 500, 600, 700};
    int dataY[] = {450, 350, 300, 250, 280, 200, 150};
    int numPoints = 7;
    
    printf("Data Points:\n");
    for (int i = 0; i < numPoints; i++) {
        printf("Point %d: (%d, %d)\n", i + 1, dataX[i], dataY[i]);
    }
    printf("\n");
    
    glPointSize(2.0f);
    
    while (!glfwWindowShouldClose(window)) {
        processInput(window);
        
        // Clear screen
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        
        // Draw axes
        drawAxes();
        
        // Plot the line graph
        plotLineGraph(dataX, dataY, numPoints);
        
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    
    glfwTerminate();
    return 0;
}
