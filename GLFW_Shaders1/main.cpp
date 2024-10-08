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

// Function to draw a yellow pentagon
void drawPentagon(float radius)
{
    const int numSides = 5;  // Pentagon has 5 sides
    const float angleIncrement = 2.0f * M_PI / numSides; // Angle between each vertex

    glColor3f(1.0f, 1.0f, 0.0f); // Set the color to yellow (RGB: 1, 1, 0)

    glBegin(GL_POLYGON); // Start drawing the pentagon

    // Generate the vertices of the pentagon
    for (int i = 0; i < numSides; i++) {
        float angle = i * angleIncrement;
        float x = radius * cos(angle); // X coordinate
        float y = radius * sin(angle); // Y coordinate
        glVertex2f(x, y);  // Set the vertex
    }

    glEnd(); // End drawing the pentagon
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
        // Clear the color buffer
        glClear(GL_COLOR_BUFFER_BIT);

        // Draw a yellow pentagon with a radius of 0.5
        drawPentagon(0.5f);

        // Swap front and back buffers
        glfwSwapBuffers(window);

        // Poll for and process events
        glfwPollEvents();
    }

    // Clean up and terminate GLFW
    glfwTerminate();
    return 0;
}
