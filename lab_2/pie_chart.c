#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <GLFW/glfw3.h>

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600
#define PI 3.14159265359

// Function to draw a filled pie slice
void drawPieSlice(float centerX, float centerY, float radius, float startAngle, float endAngle, float r, float g, float b) {
    glColor3f(r, g, b);
    
    glBegin(GL_TRIANGLE_FAN);
    
    // Center point
    float glX = (centerX / WINDOW_WIDTH) * 2.0f - 1.0f;
    float glY = 1.0f - (centerY / WINDOW_HEIGHT) * 2.0f;
    glVertex2f(glX, glY);
    
    // Draw the arc
    int numSegments = 100;
    for (int i = 0; i <= numSegments; i++) {
        float angle = startAngle + (endAngle - startAngle) * i / numSegments;
        float x = centerX + radius * cos(angle);
        float y = centerY + radius * sin(angle);
        
        glX = (x / WINDOW_WIDTH) * 2.0f - 1.0f;
        glY = 1.0f - (y / WINDOW_HEIGHT) * 2.0f;
        glVertex2f(glX, glY);
    }
    
    glEnd();
}

// Function to draw pie chart
void drawPieChart(float centerX, float centerY, float radius, float data[], int numSlices) {
    // Calculate total
    float total = 0;
    for (int i = 0; i < numSlices; i++) {
        total += data[i];
    }
    
    // Colors for different slices
    float colors[][3] = {
        {1.0f, 0.0f, 0.0f},  // Red
        {0.0f, 1.0f, 0.0f},  // Green
        {0.0f, 0.0f, 1.0f},  // Blue
        {1.0f, 1.0f, 0.0f},  // Yellow
        {1.0f, 0.0f, 1.0f},  // Magenta
        {0.0f, 1.0f, 1.0f}   // Cyan
    };
    
    float currentAngle = 0;
    
    for (int i = 0; i < numSlices; i++) {
        float sliceAngle = (data[i] / total) * 2 * PI;
        
        drawPieSlice(centerX, centerY, radius, currentAngle, currentAngle + sliceAngle,
                     colors[i % 6][0], colors[i % 6][1], colors[i % 6][2]);
        
        currentAngle += sliceAngle;
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
    
    GLFWwindow* window = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Pie Chart", NULL, NULL);
    if (!window) {
        printf("Failed to create GLFW window\n");
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    
    printf("=== Pie Chart Implementation ===\n");
    printf("Press ESC to close window\n\n");
    
    // Sample data for pie chart
    float data[] = {30, 20, 25, 15, 10};
    int numSlices = 5;
    
    printf("Pie Chart Data:\n");
    printf("Slice 1 (Red):     30 (30%%)\n");
    printf("Slice 2 (Green):   20 (20%%)\n");
    printf("Slice 3 (Blue):    25 (25%%)\n");
    printf("Slice 4 (Yellow):  15 (15%%)\n");
    printf("Slice 5 (Magenta): 10 (10%%)\n");
    printf("\n");
    
    while (!glfwWindowShouldClose(window)) {
        processInput(window);
        
        // Clear screen
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        
        // Draw the pie chart at center of window
        drawPieChart(400, 300, 200, data, numSlices);
        
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    
    glfwTerminate();
    return 0;
}
