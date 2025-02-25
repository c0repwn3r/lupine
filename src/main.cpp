#include <lupine.h>

int main() {
    const char* name = "name";
    Lupine lupine(name, 800, 600); 
    if(lupine.err == -1) {
        return -1;
    }

    lupine.registerKey(GLFW_KEY_ESCAPE, [&lupine](){ glfwSetWindowShouldClose(lupine.window, true); });

    //
    /*Triangle t(glm::vec3(0,0,0), glm::vec3(-2,0,0), glm::vec3(0,-2,0),
            glm::vec3(1,1,1), glm::vec3(1,1,1), glm::vec3(1,1,1));*/
    Rectangle rect(glm::vec3(-.5,-.5,0), 2, 2, glm::vec3(0, 0, 0), glm::vec3(1,1,1));
    Triangle t(glm::vec3(0,0,0), glm::vec3(-2,0,0), glm::vec3(0,-2,0),
            glm::vec3(1,1,1), glm::vec3(1,1,1), glm::vec3(1,1,1));
    while (!glfwWindowShouldClose(lupine.window)) {
        lupine.processInput();

	//lupine.background(124, 152, 194, 255);
	// Use new Colors!
	// Color(int r, g, b, a)
	// Color(int r, b, b, float a)
	// Color(string hexCode, int a)
	// Color(string hexCode, float a)
	// hexCode can be UPPERCASE or lower case, with or without #
	lupine.background(Color("#7C98C2", 255));

        lupine.use();

        lupine.render();

        glfwSwapBuffers(lupine.window);
        glfwPollEvents();
    }

    return 0;
}
