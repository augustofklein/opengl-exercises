#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <stdio.h>
#include <math.h> // for sin and cos

// Key callback function to handle closing the window when ESC is pressed
static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
        glfwSetWindowShouldClose(window, GLFW_TRUE);
        printf("Pressionado ESC : Saindo da aplicação!\n");
    }
}

void drawPentagon(float radius)
{
    const int numSides = 5;
    const float angleIncrement = 2.0f * M_PI / numSides;

    glColor3f(1.0f, 1.0f, 0.0f);

    glBegin(GL_POLYGON);

    for (int i = 0; i < numSides; i++) {
        float angle = i * angleIncrement;
        float x = radius * cos(angle);
        float y = radius * sin(angle);
        glVertex2f(x, y);
    }

    glEnd();
}

int main(void)
{
    GLFWwindow* window;

    // Initialize the GLFW library
    if (!glfwInit())
        return -1;

    // Create a windowed mode window and its OpenGL context
    window = glfwCreateWindow(640, 480, "GLFW com GLEW", NULL, NULL);
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
        glClear(GL_COLOR_BUFFER_BIT);

        drawPentagon(0.5f);

        glfwSwapBuffers(window);

        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
