// Include standard headers
#include <iostream>

// Include GLEW. Always include it before gl.h and glfw3.h, since it's a bit magic.
#include <GL/glew.h>

// Include GLFW
#include <GLFW/glfw3.h>
GLFWwindow* window;

// Include GLM
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
using namespace glm;

#include <common/shader.hpp>
#include <common/controls.hpp>

int main(){
    // Initialise GLFW
    if( !glfwInit() )
    {
        fprintf( stderr, "Failed to initialize GLFW\n" );
        return -1;
    }

    // make window
    glfwWindowHint(GLFW_SAMPLES, 4); // 4x antialiasing
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3); // We want OpenGL 3.3
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // To make MacOS happy; should not be needed
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); // We don't want the old OpenGL 

    // Open a window and create its OpenGL context
    window = glfwCreateWindow( 1024, 768, "Dodecahedron 2", NULL, NULL);
    if( window == NULL ){
        fprintf( stderr, "Failed to open GLFW window.\n" );
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window); 
    
    // Initialize GLEW
    glewExperimental = true; // Needed in core profile
    if (glewInit() != GLEW_OK) {
        fprintf(stderr, "Failed to initialize GLEW\n");
        glfwTerminate();
        return -1;
    }

    // Ensure we can capture the escape key being pressed below
    glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);

    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
    glfwPollEvents();
    glfwSetCursorPos(window, 1024/2, 768/2);

    // Backrgound: Dark Blue
    glClearColor(0.0f, 0.0f, 0.4f, 0.0f);

    // Enable depth test
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);

    GLuint VertexArrayID;
    glGenVertexArrays(1, &VertexArrayID);
    glBindVertexArray(VertexArrayID);

    // Create and compile program from shaders
    GLuint programID = LoadShaders( "VertexShader.vertexshader", "FragmentShader.fragmentshader" );

    // Get a hangle fot MVP uniform
    GLuint MatrixID = glGetUniformLocation(programID, "MVP");

    // // Projection Matrix
    // glm::mat4 Projection = glm::perspective(glm::radians(45.0f), 4.0f / 3.0f, 0.1f, 100.0f);
    // // Camera matrix
    // glm::mat4 View = glm::lookAt(
    //     glm::vec3(4,3,-3),
    //     glm::vec3(0,0,0),
    //     glm::vec3(0,1,0)
    // );
    // // Model matrix
    // glm::mat4 Model = glm::mat4(1.0f);

    // // MVP
    // glm::mat4 MVP = Projection * View * Model;
    float phi = (1 + sqrt(5)) / 2;
    float b = 0.5 / phi;
    float c = (2-phi) /2;

    static const GLfloat g_vertex_buffer_data[] = {
        //pentagon 1
        1.0f, 1.0f, 1.0f,
        1.618f, 0.0f, 0.618f,
        1.0f, -1.0f, 1.0f,
        1.0f, 1.0f, 1.0f,
        1.0f, -1.0f, 1.0f,
        0.0f, -0.618f, 1.618f,
        1.0f, 1.0f, 1.0f,
        0.0f, -0.618f, 1.618f,
        0.0f, 0.618f, 1.618f,
        //pentagon 2
        1.0f, 1.0f, 1.0f,
        0.0f, 0.618f, 1.618f,
        -1.0f, 1.0f, 1.0f,
        1.0f, 1.0f, 1.0f,
        -1.0f, 1.0f, 1.0f,
        -0.618f, 1.618f, 0,
        1.0f, 1.0f, 1.0f,
        -0.618f, 1.618f, 0,
        0.618f, 1.618f, 0.0f,
        //pentagon 3
        1.618f, 0.0f, 0.618f,
        1.618f, 0.0f, -0.618f,
        1.0f, 1.0f, -1.0f,
        1.618f, 0.0f, 0.618f,
        1.0f, 1.0f, -1.0f,
        1.0f, 1.0f, 1.0f,
        //pentagon 4
        1.0f, 1.0f, -1.0f,
        0.0f, 0.618f, -1.618f,
        0.0f, -0.618f, -1.618f,
        1.0f, 1.0f, -1.0f,
        0.0f, -0.618f, -1.618f,
        1.0f, -1.0f, -1.0f,
        1.0f, 1.0f, -1.0f,
        1.0f, -1.0f, -1.0f,
        -1.0f, -1.0f, -1.0f,
        //pentagon 5
        1.0f, 1.0f, -1.0f,
        0.618f, 1.618f, 0.0f,
        -0.618f, 1.618f, 0.0f,
        1.0f, 1.0f, -1.0f,
        -0.618f, 1.618f, 0.0f,
        -1.0f, 1.0f, -1.0f,
        1.0f, 1.0f, -1.0f,
        -1.0f, 1.0f, -1.0f,
        0.0f, 0.618f, -1.618f,
        //pentagon 6
        1.0f, -1.0f, 1.0f,
        0.618f, -1.618f, 0.0f,
        -0.618f, -1.618f, 0.0f,
        1.0f, -1.0f, 1.0f,
        -0.618f, -1.618f, 0.0f,
        -1.0f, -1.0f, 1.0f,
        1.0f, -1.0f, 1.0f,
        -1.0f, -1.0f, 1.0f,
        0.0f, -0.618f, 1.618f,
        //pentagon 7
        0.618f, -1.618f, 0.0f,
        1.0f, -1.0f, -1.0f,
        1.618f, 0.0f, -0.618f,
        0.618f, -1.618f, 0.0f,
        1.618f, 0.0f, -0.618f,
        1.618f, 0.0f, 0.618f,
        0.618f, -1.618f, 0.0f,
        1.618f, 0.0f, 0.618f,
        1.0f, -1.0f, 1.0f,
        //pentagon 8
        1.0f, -1.0f, -1.0f,
        0.0f, -0.618f, -1.618f,
        -1.0f, -1.0f, -1.0f,
        1.0f, -1.0f, -1.0f,
        -1.0f, -1.0f, -1.0f,
        -0.618f, -1.618f, 0.0f,
        1.0f, -1.0f, -1.0f,
        -0.618f, -1.618f, 0.0f,
        0.618f, -1.618f, 0.0f,
        //pentagon 9
        -1.0f, 1.0f, 1.0f,
        0.0f, 0.618f, 1.618f,
        0.0f, -0.618f, 1.618f,
        -1.0f, 1.0f, 1.0f,
        0.0f, -0.618f, 1.618f,
        -1.0f, -1.0f, 1.0f,
        -1.0f, 1.0f, 1.0f,
        -1.0f, -1.0f, 1.0f,
        -1.618f, 0.0f, 0.618f,
        //polygon 10
        -0.618f, 1.618f, 0.0f,
        -1.0f, 1.0f, -1.0f,
        -1.618f, 0.0f, -0.618f,
        -0.618f, 1.618f, 0.0f,
        -1.618f, 0.0f, -0.618f,
        -1.618f, 0.0f, 0.618f,
        -0.618f, 1.618f, 0.0f,
        -1.618f, 0.0f, 0.618f,
        -1.0f, 1.0f, 1.0f,
        //polygon 11
        -1.0f, 1.0f, -1.0f,
        -1.618f, 0.0f, -0.618f,
        -1.0f, -1.0f, -1.0f,
        -1.0f, 1.0f, -1.0f,
        -1.0f, -1.0f, -1.0f,
        0.0f, -0.618f, -1.618f,
        -1.0f, 1.0f, -1.0f,
        0.0f, -0.618f, -1.618f,
        0.0f, 0.618f, -1.618f,
        //polygon 12
        -0.618f, -1.618f, 0.0f,
        -1.0f, -1.0f, -1.0f,
        -1.618f, 0.0f, -0.618f,
        -0.618f, -1.618f, 0.0f,
        -1.618f, 0.0f, -0.618f,
        -1.618f, 0.0f, 0.618f,
        -0.618f, -1.618f, 0.0f,
        -1.618f, 0.0f, 0.618f,
        -1.0f, -1.0f, 1.0f
    };

    static const GLfloat g_color_buffer_data[] = { 
		0.583f,  0.771f,  0.014f,
		0.609f,  0.115f,  0.436f,
		0.327f,  0.483f,  0.844f,
		0.822f,  0.569f,  0.201f,
		0.435f,  0.602f,  0.223f,
		0.310f,  0.747f,  0.185f,
		0.597f,  0.770f,  0.761f,
		0.559f,  0.436f,  0.730f,
		0.359f,  0.583f,  0.152f,
		0.483f,  0.596f,  0.789f,
		0.559f,  0.861f,  0.639f,
		0.195f,  0.548f,  0.859f,
		0.014f,  0.184f,  0.576f,
		0.771f,  0.328f,  0.970f,
		0.406f,  0.615f,  0.116f,
		0.676f,  0.977f,  0.133f,
		0.971f,  0.572f,  0.833f,
		0.140f,  0.616f,  0.489f,
		0.997f,  0.513f,  0.064f,
		0.945f,  0.719f,  0.592f,
		0.543f,  0.021f,  0.978f,
		0.279f,  0.317f,  0.505f,
		0.167f,  0.620f,  0.077f,
		0.347f,  0.857f,  0.137f,
		0.055f,  0.953f,  0.042f,
		0.714f,  0.505f,  0.345f,
		0.783f,  0.290f,  0.734f,
		0.722f,  0.645f,  0.174f,
		0.302f,  0.455f,  0.848f,
		0.225f,  0.587f,  0.040f,
		0.517f,  0.713f,  0.338f,
		0.053f,  0.959f,  0.120f,
		0.393f,  0.621f,  0.362f,
		0.673f,  0.211f,  0.457f,
		0.820f,  0.883f,  0.371f,
		0.982f,  0.099f,  0.879f,
        0.583f,  0.771f,  0.014f,
		0.609f,  0.115f,  0.436f,
		0.327f,  0.483f,  0.844f,
		0.822f,  0.569f,  0.201f,
		0.435f,  0.602f,  0.223f,
		0.310f,  0.747f,  0.185f,
		0.597f,  0.770f,  0.761f,
		0.559f,  0.436f,  0.730f,
		0.359f,  0.583f,  0.152f,
		0.483f,  0.596f,  0.789f,
		0.559f,  0.861f,  0.639f,
		0.195f,  0.548f,  0.859f,
		0.014f,  0.184f,  0.576f,
		0.771f,  0.328f,  0.970f,
		0.406f,  0.615f,  0.116f,
		0.676f,  0.977f,  0.133f,
		0.971f,  0.572f,  0.833f,
		0.140f,  0.616f,  0.489f,
		0.997f,  0.513f,  0.064f,
		0.945f,  0.719f,  0.592f,
		0.543f,  0.021f,  0.978f,
		0.279f,  0.317f,  0.505f,
		0.167f,  0.620f,  0.077f,
		0.347f,  0.857f,  0.137f,
        0.583f,  0.771f,  0.014f,
		0.609f,  0.115f,  0.436f,
		0.327f,  0.483f,  0.844f,
		0.822f,  0.569f,  0.201f,
		0.435f,  0.602f,  0.223f,
		0.310f,  0.747f,  0.185f,
		0.597f,  0.770f,  0.761f,
		0.559f,  0.436f,  0.730f,
		0.359f,  0.583f,  0.152f,
		0.483f,  0.596f,  0.789f,
		0.559f,  0.861f,  0.639f,
		0.195f,  0.548f,  0.859f,
		0.014f,  0.184f,  0.576f,
		0.771f,  0.328f,  0.970f,
		0.406f,  0.615f,  0.116f,
		0.676f,  0.977f,  0.133f,
		0.971f,  0.572f,  0.833f,
		0.140f,  0.616f,  0.489f,
		0.997f,  0.513f,  0.064f,
		0.945f,  0.719f,  0.592f,
		0.543f,  0.021f,  0.978f,
		0.279f,  0.317f,  0.505f,
		0.167f,  0.620f,  0.077f,
		0.347f,  0.857f,  0.137f,
		0.055f,  0.953f,  0.042f,
		0.714f,  0.505f,  0.345f,
		0.783f,  0.290f,  0.734f,
		0.722f,  0.645f,  0.174f,
		0.302f,  0.455f,  0.848f,
		0.225f,  0.587f,  0.040f,
		0.517f,  0.713f,  0.338f,
		0.053f,  0.959f,  0.120f,
		0.393f,  0.621f,  0.362f,
		0.673f,  0.211f,  0.457f,
		0.820f,  0.883f,  0.371f,
		0.982f,  0.099f,  0.879f,
        0.583f,  0.771f,  0.014f,
		0.609f,  0.115f,  0.436f,
		0.327f,  0.483f,  0.844f,
		0.822f,  0.569f,  0.201f,
		0.435f,  0.602f,  0.223f,
		0.310f,  0.747f,  0.185f,
		0.597f,  0.770f,  0.761f,
		0.559f,  0.436f,  0.730f,
		0.359f,  0.583f,  0.152f,
		0.483f,  0.596f,  0.789f,
		0.559f,  0.861f,  0.639f,
		0.195f,  0.548f,  0.859f
    };

    GLuint vertexbuffer;
    glGenBuffers(1, &vertexbuffer);
    glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(g_vertex_buffer_data), g_vertex_buffer_data, GL_STATIC_DRAW);

    GLuint colorbuffer;
	glGenBuffers(1, &colorbuffer);
	glBindBuffer(GL_ARRAY_BUFFER, colorbuffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(g_color_buffer_data), g_color_buffer_data, GL_STATIC_DRAW);

    int ticks = 0;
    int rotate = 0;

    do{
        // Clear the screen. It's not mentioned before Tutorial 02, but it can cause flickering, so it's there nonetheless.
        glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

        // Use shader
        glUseProgram(programID);

        // MVP
        // glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &MVP[0][0]);

        // Compute the MVP matrix from keyboard and mouse input
		computeMatricesFromInputs();
		glm::mat4 ProjectionMatrix = getProjectionMatrix();
		glm::mat4 ViewMatrix = getViewMatrix();
		glm::mat4 ModelMatrix = glm::mat4(1.0);
        ModelMatrix = glm::rotate(ModelMatrix, 0.05f * ticks, glm::vec3(0,1,0));
		glm::mat4 MVP = ProjectionMatrix * ViewMatrix * ModelMatrix;

		// Send our transformation to the currently bound shader, 
		// in the "MVP" uniform
		glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &MVP[0][0]);

        // Draw 
        glEnableVertexAttribArray(0);
        glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
        glVertexAttribPointer(
            0,
            3,
            GL_FLOAT,
            GL_FALSE,
            0,
            (void*)0
        );
        glEnableVertexAttribArray(1);
		glBindBuffer(GL_ARRAY_BUFFER, colorbuffer);
		glVertexAttribPointer(
			1,                                // attribute. No particular reason for 1, but must match the layout in the shader.
			3,                                // size
			GL_FLOAT,                         // type
			GL_FALSE,                         // normalized?
			0,                                // stride
			(void*)0                          // array buffer offset
		);

        glDrawArrays(GL_TRIANGLES, 0, 36*3);
        glDisableVertexAttribArray(0);
        glDisableVertexAttribArray(1);

        // Swap buffers
        glfwSwapBuffers(window);
        glfwPollEvents();
        if (glfwGetKey( window, GLFW_KEY_R ) == GLFW_PRESS){
            rotate = 1;
	    }
        if (glfwGetKey( window, GLFW_KEY_C ) == GLFW_PRESS){
            rotate = 1;
	    }
        if (glfwGetKey( window, GLFW_KEY_S ) == GLFW_PRESS){
            rotate = 0;
            ticks = 0;
	    }
        if (rotate){
            ticks++;
        }

    } // Check if the ESC key was pressed or the window was closed
    while( glfwGetKey(window, GLFW_KEY_ESCAPE ) != GLFW_PRESS &&
        glfwWindowShouldClose(window) == 0 );

    // Cleanup VBO
    glDeleteBuffers(1, &vertexbuffer);
    glDeleteBuffers(1, &colorbuffer);
	glDeleteVertexArrays(1, &VertexArrayID);
    glDeleteProgram(programID);

	// Close OpenGL window and terminate GLFW
	glfwTerminate();

    return 0;

}