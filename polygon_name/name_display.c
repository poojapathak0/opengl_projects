#include <glad/glad.h>
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <stdio.h>

void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);
}

void processInput(GLFWwindow* window) {
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, 1);
}

// Draw letter P
void drawP(float x, float y, float size) {
    // Vertical bar
    glBegin(GL_POLYGON);
    glVertex2f(x, y);
    glVertex2f(x + size * 0.15f, y);
    glVertex2f(x + size * 0.15f, y + size);
    glVertex2f(x, y + size);
    glEnd();
    
    // Top horizontal bar
    glBegin(GL_POLYGON);
    glVertex2f(x, y + size * 0.85f);
    glVertex2f(x + size * 0.5f, y + size * 0.85f);
    glVertex2f(x + size * 0.5f, y + size);
    glVertex2f(x, y + size);
    glEnd();
    
    // Middle horizontal bar
    glBegin(GL_POLYGON);
    glVertex2f(x, y + size * 0.5f);
    glVertex2f(x + size * 0.5f, y + size * 0.5f);
    glVertex2f(x + size * 0.5f, y + size * 0.65f);
    glVertex2f(x, y + size * 0.65f);
    glEnd();
    
    // Right vertical bar
    glBegin(GL_POLYGON);
    glVertex2f(x + size * 0.35f, y + size * 0.65f);
    glVertex2f(x + size * 0.5f, y + size * 0.65f);
    glVertex2f(x + size * 0.5f, y + size * 0.85f);
    glVertex2f(x + size * 0.35f, y + size * 0.85f);
    glEnd();
}

// Draw letter O
void drawO(float x, float y, float size) {
    // Top bar
    glBegin(GL_POLYGON);
    glVertex2f(x, y + size * 0.85f);
    glVertex2f(x + size * 0.5f, y + size * 0.85f);
    glVertex2f(x + size * 0.5f, y + size);
    glVertex2f(x, y + size);
    glEnd();
    
    // Bottom bar
    glBegin(GL_POLYGON);
    glVertex2f(x, y);
    glVertex2f(x + size * 0.5f, y);
    glVertex2f(x + size * 0.5f, y + size * 0.15f);
    glVertex2f(x, y + size * 0.15f);
    glEnd();
    
    // Left bar
    glBegin(GL_POLYGON);
    glVertex2f(x, y);
    glVertex2f(x + size * 0.15f, y);
    glVertex2f(x + size * 0.15f, y + size);
    glVertex2f(x, y + size);
    glEnd();
    
    // Right bar
    glBegin(GL_POLYGON);
    glVertex2f(x + size * 0.35f, y);
    glVertex2f(x + size * 0.5f, y);
    glVertex2f(x + size * 0.5f, y + size);
    glVertex2f(x + size * 0.35f, y + size);
    glEnd();
}

// Draw letter J
void drawJ(float x, float y, float size) {
    // Top bar
    glBegin(GL_POLYGON);
    glVertex2f(x, y + size * 0.85f);
    glVertex2f(x + size * 0.5f, y + size * 0.85f);
    glVertex2f(x + size * 0.5f, y + size);
    glVertex2f(x, y + size);
    glEnd();
    
    // Vertical bar
    glBegin(GL_POLYGON);
    glVertex2f(x + size * 0.175f, y);
    glVertex2f(x + size * 0.325f, y);
    glVertex2f(x + size * 0.325f, y + size * 0.85f);
    glVertex2f(x + size * 0.175f, y + size * 0.85f);
    glEnd();
    
    // Bottom left bar
    glBegin(GL_POLYGON);
    glVertex2f(x, y);
    glVertex2f(x + size * 0.175f, y);
    glVertex2f(x + size * 0.175f, y + size * 0.15f);
    glVertex2f(x, y + size * 0.15f);
    glEnd();
}

// Draw letter A
void drawA(float x, float y, float size) {
    // Left vertical bar
    glBegin(GL_POLYGON);
    glVertex2f(x, y);
    glVertex2f(x + size * 0.15f, y);
    glVertex2f(x + size * 0.15f, y + size);
    glVertex2f(x, y + size);
    glEnd();
    
    // Right vertical bar
    glBegin(GL_POLYGON);
    glVertex2f(x + size * 0.35f, y);
    glVertex2f(x + size * 0.5f, y);
    glVertex2f(x + size * 0.5f, y + size);
    glVertex2f(x + size * 0.35f, y + size);
    glEnd();
    
    // Top bar
    glBegin(GL_POLYGON);
    glVertex2f(x, y + size * 0.85f);
    glVertex2f(x + size * 0.5f, y + size * 0.85f);
    glVertex2f(x + size * 0.5f, y + size);
    glVertex2f(x, y + size);
    glEnd();
    
    // Middle bar
    glBegin(GL_POLYGON);
    glVertex2f(x, y + size * 0.4f);
    glVertex2f(x + size * 0.5f, y + size * 0.4f);
    glVertex2f(x + size * 0.5f, y + size * 0.55f);
    glVertex2f(x, y + size * 0.55f);
    glEnd();
}

int main() {
    if (!glfwInit()) {
        printf("Failed to initialize GLFW\n");
        return -1;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);

    GLFWwindow* window = glfwCreateWindow(1000, 500, "POOJA - Polygon Name", NULL, NULL);
    if (window == NULL) {
        printf("Failed to create GLFW window\n");
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    if (!gladLoadGLLoader((void* (*)(const char*))glfwGetProcAddress)) {
        printf("Failed to initialize GLAD\n");
        return -1;
    }

    printf("Display: POOJA using Polygons\n");
    printf("Press ESC to close the window\n");

    while (!glfwWindowShouldClose(window)) {
        processInput(window);

        glClearColor(0.1f, 0.1f, 0.15f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        // Draw POOJA with different colors
        float letterSize = 0.35f;
        float spacing = 0.38f;
        float startX = -0.90f;
        float yPos = -0.175f;

        // P - Red/Pink
        glColor3f(1.0f, 0.3f, 0.5f);
        drawP(startX, yPos, letterSize);
        
        // O - Orange
        glColor3f(1.0f, 0.6f, 0.2f);
        drawO(startX + spacing, yPos, letterSize);
        
        // O - Yellow
        glColor3f(1.0f, 0.9f, 0.2f);
        drawO(startX + spacing * 2, yPos, letterSize);
        
        // J - Green
        glColor3f(0.3f, 1.0f, 0.4f);
        drawJ(startX + spacing * 3, yPos, letterSize);
        
        // A - Blue/Purple
        glColor3f(0.5f, 0.4f, 1.0f);
        drawA(startX + spacing * 4, yPos, letterSize);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    printf("Window closed. Goodbye!\n");
    return 0;
}
