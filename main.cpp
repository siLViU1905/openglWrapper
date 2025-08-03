#include <iostream>

#include "include/SGL/System/Window.h"
#include "include/SGL/Wrapper/Buffer.h"
#include "include/SGL/Wrapper/Shader.h"
#include "include/SGL/Wrapper/VertexArray.h"

int main()
{
    //sample code

    sgl::Logger logger;

    sgl::Window window(logger, 4, 6, 600, 600, "Sample");

    //callback per keys
    window.setKeyCallback(sgl::Keyboard::Key::B, sgl::Keyboard::Action::PRESS, []() { std::cout << "B pressed!\n"; });

    window.setButtonCallback(sgl::Mouse::Button::LEFT, sgl::Mouse::Action::RELEASE,
                             []() { std::cout << "Left click released\n"; });

    const auto &context = window.getContext();

    context.setClearColor(0.4f, 0.2f, 0.6f, 1.f);

    context.enable(GL::Capability::DEPTH_TEST);

    GL::Shader shader(logger);

    shader.compile(GL::ShaderType::VERTEX, "../sh.vert");
    shader.compile(GL::ShaderType::FRAGMENT, "../sh.frag");

    shader.link();

    float vertices[12] =
    {
        -0.5f, -0.5f, 0.f,
        0.5f, -0.5f, 0.f,
        0.5f, 0.5f, 0.f,
        -0.5f, 0.5f, 0.f,
    };

    uint32_t indices[6] =
    {
        0, 1, 2,
        0, 2, 3
    };

    GL::VertexArray vao;

    GL::VBO vbo;

    GL::EBO ebo;

    vao.bind();

    vbo.bind();

    vbo.data(vertices, 12);

    ebo.bind();

    ebo.data(indices, 6);

    vao.attribPointer(0, 3, GL::DataType::FLOAT, false, 3 * sizeof(float), nullptr);

    vao.enableAttrib(0);

    vao.unbind();

    while (window.isOpen())
    {
        context.clear(GL::BufferBitMask::COLOR_DEPTH);

        shader.bind();

        vao.bind();

        context.drawElements(GL::PrimitiveType::TRIANGLES, 6, GL::DataType::UNSIGNED_INT, nullptr);

        vao.unbind();

        shader.unbind();

        window.swapBuffers();

        const auto &event = window.pollEvents();

        if (event.type == sgl::EventType::KEYBOARD && event.keyboard.key == sgl::Keyboard::Key::ESCAPE
            || event.windowState == sgl::WindowState::CLOSED)
            window.close();

        if (event.windowState == sgl::WindowState::RESIZED)
            std::cout << "New window size! width: " << window.getWidth() << " height: " << window.getHeight() << '\n';
    }
}
