#include "Renderer.h"

void gf_render::Draw(shapes& tri, const float* COLOUR, glm::vec3 Position, Shader& shader,glm::vec3 Scale)
{
    if (shader.getShaderID() != -1) {

        glm::mat4 model = glm::mat4(1.0f);
        model = glm::translate(model, Position);
      //  shader.setMat4("model", model);
        shader.setMat4("model", glm::scale(model,Scale));

    }

    if (COLOUR == nullptr) {

        if (tri.getEBO() != 0) {
            glBindVertexArray(tri.getVAO());
            glDrawElements(GL_TRIANGLES, tri.getSize_Vertices(), GL_UNSIGNED_INT, 0);
            glBindVertexArray(0);
        }
        else {
            glBindVertexArray(tri.getVAO());
            glDrawArrays(GL_TRIANGLES, 0, tri.getSize_Vertices());
            glBindVertexArray(0);
        }

    }
    else{ 
        shader.setColor(COLOUR);

               if (tri.getEBO() != 0) {
            glBindVertexArray(tri.getVAO());
            glDrawElements(GL_TRIANGLES, tri.getSize_Vertices(), GL_UNSIGNED_INT, 0);
            glBindVertexArray(0);
        }
        else {
            glBindVertexArray(tri.getVAO());
            glDrawArrays(GL_TRIANGLES, 0, tri.getSize_Vertices());
            glBindVertexArray(0);
        }
    }
    

}

void gf_render::ClearScreen()
{
	glClearColor(0.2f, 0.3f, 0.3f, 1.0f); //Green color ;
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void gf_render::setWireframeMode(bool set)
{
    if(set)
    glPolygonMode(GL_FRONT_AND_BACK,
        GL_LINE);
    else
        glPolygonMode(GL_FRONT_AND_BACK,
            GL_FILL);
}


gf_render::Triangle::Triangle()
{
    set_name(name);

    float vertices[] = {
    -0.5f, -0.5f, 0.0f, // left  
     0.5f, -0.5f, 0.0f, // right 
     0.0f,  0.5f, 0.0f  // top   
    };

    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);


    glGenBuffers(1, &VBO); 
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
    size_vertices = 3;
}

gf_render::Triangle::~Triangle()
{
    glDeleteBuffers(1, &VAO);
    glDeleteBuffers(1, &VBO);
}

gf_render::Rect::Rect()
{
    set_name(name);
    float vertices[] = {
    0.5f, 0.5f, 0.0f,       // top right
    0.5f, -0.5f, 0.0f,      // bottom right
    -0.5f, -0.5f, 0.0f,     // bottom left
    -0.5f, 0.5f, 0.0f       // top left
    };
    unsigned int indices[] = {  // note that we start from 0!
    0, 1, 2,                    // first triangle
    2, 3, 0                     // second triangle
    };

    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);
    glGenBuffers(1, &VBO);
 
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glGenBuffers(1, &EBO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);


    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);


    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
    size_vertices = 6;

}

gf_render::Rect::~Rect()
{
    glDeleteBuffers(1, &VAO);
    glDeleteBuffers(1, &VBO);
    glDeleteBuffers(1, &EBO);
}


gf_render::Cube::Cube() {
    set_name(name);

    float vertices[] = {
        -0.5f, -0.5f, -0.5f, 0.0f, 0.0f,
        0.5f, -0.5f, -0.5f, 1.0f, 0.0f,
        0.5f, 0.5f, -0.5f, 1.0f, 1.0f,
        0.5f, 0.5f, -0.5f, 1.0f, 1.0f,
        -0.5f, 0.5f, -0.5f, 0.0f, 1.0f,
        -0.5f, -0.5f, -0.5f, 0.0f, 0.0f,
        -0.5f, -0.5f, 0.5f, 0.0f, 0.0f,
        0.5f, -0.5f, 0.5f, 1.0f, 0.0f,
        0.5f, 0.5f, 0.5f, 1.0f, 1.0f,
        0.5f, 0.5f, 0.5f, 1.0f, 1.0f,
        -0.5f, 0.5f, 0.5f, 0.0f, 1.0f,
        -0.5f, -0.5f, 0.5f, 0.0f, 0.0f,
        -0.5f, 0.5f, 0.5f, 1.0f, 0.0f,
        -0.5f, 0.5f, -0.5f, 1.0f, 1.0f,
        -0.5f, -0.5f, -0.5f, 0.0f, 1.0f,
        -0.5f, -0.5f, -0.5f, 0.0f, 1.0f,
        -0.5f, -0.5f, 0.5f, 0.0f, 0.0f,
        -0.5f, 0.5f, 0.5f, 1.0f, 0.0f,
        0.5f, 0.5f, 0.5f, 1.0f, 0.0f,
        0.5f, 0.5f, -0.5f, 1.0f, 1.0f,
        0.5f, -0.5f, -0.5f, 0.0f, 1.0f,
        0.5f, -0.5f, -0.5f, 0.0f, 1.0f,
        0.5f, -0.5f, 0.5f, 0.0f, 0.0f,
        0.5f, 0.5f, 0.5f, 1.0f, 0.0f,
        -0.5f, -0.5f, -0.5f, 0.0f, 1.0f,
        0.5f, -0.5f, -0.5f, 1.0f, 1.0f,
        0.5f, -0.5f, 0.5f, 1.0f, 0.0f,
        0.5f, -0.5f, 0.5f, 1.0f, 0.0f,
        -0.5f, -0.5f, 0.5f, 0.0f, 0.0f,
        -0.5f, -0.5f, -0.5f, 0.0f, 1.0f,
        -0.5f, 0.5f, -0.5f, 0.0f, 1.0f,
        0.5f, 0.5f, -0.5f, 1.0f, 1.0f,
        0.5f, 0.5f, 0.5f, 1.0f, 0.0f,
        0.5f, 0.5f, 0.5f, 1.0f, 0.0f,
        -0.5f, 0.5f, 0.5f, 0.0f, 0.0f,
        -0.5f, 0.5f, -0.5f, 0.0f, 1.0f
    };

    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);


    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);

    size_vertices = 36;

}

gf_render::Cube::~Cube() {
    glDeleteBuffers(1, &VAO);
    glDeleteBuffers(1, &VBO);
    glDeleteBuffers(1, &EBO);
}
