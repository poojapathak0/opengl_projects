#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <stdio.h>
#include <stdlib.h>

// Original triangle vertices
float original[3][2] = {
    {100.0, 100.0},
    {200.0, 100.0},
    {150.0, 200.0}
};

// Transformed triangle vertices
float transformed[3][2];

// Translation parameters
float tx = 150.0, ty = 100.0;

void translate() {
    for(int i = 0; i < 3; i++) {
        transformed[i][0] = original[i][0] + tx;
        transformed[i][1] = original[i][1] + ty;
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
    
    // Draw original triangle in blue
    drawTriangle(original, 0.0, 0.0, 1.0);
    
    // Apply translation
    translate();
    
    // Draw transformed triangle in red
    drawTriangle(transformed, 1.0, 0.0, 0.0);
    
    // Draw axes
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_LINES);
    glVertex2f(0, 250); glVertex2f(500, 250);
    glVertex2f(250, 0); glVertex2f(250, 500);
    glEnd();
}

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GLFW_TRUE);
    if (key == GLFW_KEY_Q && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GLFW_TRUE);
}

int main() {
    printf("2D Translation\n");
    printf("Translation Vector: tx = %.1f, ty = %.1f\n", tx, ty);
    printf("Blue: Original Triangle\n");
    printf("Red: Translated Triangle\n");
    printf("Press Q or ESC to exit\n\n");
    
    if (!glfwInit()) {
        fprintf(stderr, "Failed to initialize GLFW\n");
        return -1;
    }
    
    GLFWwindow* window = glfwCreateWindow(500, 500, "2D Translation", NULL, NULL);
    if (!window) {
        fprintf(stderr, "Failed to create window\n");
        glfwTerminate();
        return -1;
    }
    
    glfwMakeContextCurrent(window);
    glfwSetKeyCallback(window, key_callback);
    
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        fprintf(stderr, "Failed to initialize GLAD\n");
        return -1;
    }
    
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, 500.0, 0.0, 500.0, -1.0, 1.0);
    glMatrixMode(GL_MODELVIEW);
    
    glClearColor(1.0, 1.0, 1.0, 1.0);
    
    while (!glfwWindowShouldClose(window)) {
        display();
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    
    glfwTerminate();
    return 0;
}
