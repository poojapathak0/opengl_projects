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
    glBegin(GL_POLYGON);
    glVertex2f(x, y);
    glVertex2f(x + size * 0.1f, y);
    glVertex2f(x + size * 0.1f, y + size);
    glVertex2f(x, y + size);
    glEnd();
    
    glBegin(GL_POLYGON);
    glVertex2f(x, y + size * 0.5f);
    glVertex2f(x + size * 0.4f, y + size * 0.5f);
    glVertex2f(x + size * 0.4f, y + size);
    glVertex2f(x, y + size);
    glEnd();
    
    glBegin(GL_POLYGON);
    glVertex2f(x + size * 0.4f, y + size * 0.9f);
    glVertex2f(x + size * 0.5f, y + size * 0.9f);
    glVertex2f(x + size * 0.5f, y + size * 0.6f);
    glVertex2f(x + size * 0.4f, y + size * 0.6f);
    glEnd();
}

// Draw letter O
void drawO(float x, float y, float size) {
    glBegin(GL_POLYGON);
    glVertex2f(x, y);
    glVertex2f(x + size * 0.5f, y);
    glVertex2f(x + size * 0.5f, y + size * 0.15f);
    glVertex2f(x, y + size * 0.15f);
    glEnd();
    
    glBegin(GL_POLYGON);
    glVertex2f(x, y + size * 0.85f);
    glVertex2f(x + size * 0.5f, y + size * 0.85f);
    glVertex2f(x + size * 0.5f, y + size);
    glVertex2f(x, y + size);
    glEnd();
    
    glBegin(GL_POLYGON);
    glVertex2f(x, y);
    glVertex2f(x + size * 0.1f, y);
    glVertex2f(x + size * 0.1f, y + size);
    glVertex2f(x, y + size);
    glEnd();
    
    glBegin(GL_POLYGON);
    glVertex2f(x + size * 0.4f, y);
    glVertex2f(x + size * 0.5f, y);
    glVertex2f(x + size * 0.5f, y + size);
    glVertex2f(x + size * 0.4f, y + size);
    glEnd();
}

// Draw letter J
void drawJ(float x, float y, float size) {
    glBegin(GL_POLYGON);
    glVertex2f(x + size * 0.2f, y + size * 0.8f);
    glVertex2f(x + size * 0.3f, y + size * 0.8f);
    glVertex2f(x + size * 0.3f, y + size);
    glVertex2f(x + size * 0.2f, y + size);
    glEnd();
    
    glBegin(GL_POLYGON);
    glVertex2f(x, y);
    glVertex2f(x + size * 0.3f, y);
    glVertex2f(x + size * 0.3f, y + size * 0.2f);
    glVertex2f(x, y + size * 0.2f);
    glEnd();
    
    glBegin(GL_POLYGON);
    glVertex2f(x, y);
    glVertex2f(x + size * 0.1f, y);
    glVertex2f(x + size * 0.1f, y + size * 0.85f);
    glVertex2f(x, y + size * 0.85f);
    glEnd();
}

// Draw letter A
void drawA(float x, float y, float size) {
    glBegin(GL_POLYGON);
    glVertex2f(x, y);
    glVertex2f(x + size * 0.1f, y);
    glVertex2f(x + size * 0.1f, y + size);
    glVertex2f(x, y + size);
    glEnd();
    
    glBegin(GL_POLYGON);
    glVertex2f(x + size * 0.4f, y);
    glVertex2f(x + size * 0.5f, y);
    glVertex2f(x + size * 0.5f, y + size);
    glVertex2f(x + size * 0.4f, y + size);
    glEnd();
    
    glBegin(GL_POLYGON);
    glVertex2f(x, y + size * 0.85f);
    glVertex2f(x + size * 0.5f, y + size * 0.85f);
    glVertex2f(x + size * 0.5f, y + size);
    glVertex2f(x, y + size);
    glEnd();
    
    glBegin(GL_POLYGON);
    glVertex2f(x, y + size * 0.4f);
    glVertex2f(x + size * 0.5f, y + size * 0.4f);
    glVertex2f(x + size * 0.5f, y + size * 0.5f);
    glVertex2f(x, y + size * 0.5f);
    glEnd();
}

int main() {
    if (!glfwInit()) {
        printf("Failed to initialize GLFW\n");
        return -1;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);

    GLFWwindow* window = glfwCreateWindow(900, 400, "POOJA - Name Display", NULL, NULL);
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

    printf("Display: POOJA\n");
    printf("Press ESC to close the window\n");

    while (!glfwWindowShouldClose(window)) {
        processInput(window);

        glClearColor(0.1f, 0.1f, 0.15f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        // Set color to bright cyan
        glColor3f(0.0f, 0.9f, 0.9f);

        // Draw POOJA with proper spacing
        float letterSize = 0.3f;
        float spacing = 0.35f;
        float startX = -0.85f;
        float yPos = -0.15f;

        drawP(startX, yPos, letterSize);
        drawO(startX + spacing, yPos, letterSize);
        drawO(startX + spacing * 2, yPos, letterSize);
        drawJ(startX + spacing * 3, yPos, letterSize);
        drawA(startX + spacing * 4, yPos, letterSize);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    printf("Window closed. Goodbye!\n");
    return 0;
}
