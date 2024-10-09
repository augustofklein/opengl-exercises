#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <stdio.h>
#include <math.h>

// Key callback function to handle closing the window when ESC is pressed
static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
        glfwSetWindowShouldClose(window, GLFW_TRUE);
        printf("Pressionado ESC : Saindo da aplicação!\n");
    }
}

void drawSquare(float size, float r, float g, float b)
{
    glColor3f(r, g, b);
    glBegin(GL_QUADS);

    glVertex2f(-size / 2, -size / 2);
    glVertex2f(size / 2, -size / 2);
    glVertex2f(size / 2, size / 2);
    glVertex2f(-size / 2, size / 2);

    glEnd();
}

int main(void)
{
    GLFWwindow* window;

    // Initialize the GLFW library
    if (!glfwInit())
        return -1;

    // Create a windowed mode window and its OpenGL context
    window = glfwCreateWindow(640, 480, "Sobreposição de quadrados", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    // Make the window's context current
    glfwMakeContextCurrent(window);

    // Initialize GLEW (after the OpenGL context is made current)
    glewExperimental = true;
    if (glewInit() != GLEW_OK)
    {
        fprintf(stderr, "Failed to initialize GLEW\n");
        getchar();
        glfwTerminate();
        return -1;
    }
    else
    {
        fprintf(stderr, "Using GL Version %s\n", glGetString(GL_VERSION));
    }

    // Set the keyboard callback function
    glfwSetKeyCallback(window, key_callback);

    // Main rendering loop
    while (!glfwWindowShouldClose(window))
    {
        // Clear the color buffer
        glClear(GL_COLOR_BUFFER_BIT);

        glPushMatrix();
        glRotatef(45, 0.0f, 0.0f, 1.0f);
        drawSquare(0.7f, 0.0f, 1.0f, 0.0f);
        glPopMatrix();

        drawSquare(0.7f, 0.0f, 0.0f, 1.0f);

        glfwSwapBuffers(window);

        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
