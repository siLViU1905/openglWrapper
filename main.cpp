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


    const auto &context = window.getContext();

    context.setClearColor(0.4f, 0.2f, 0.6f, 1.f);

    context.enable(GL::Capability::DEPTH_TEST);

    GL::Shader shader(logger);

    shader.compile(GL::ShaderType::VERTEX, "../sh.vert");
    shader.compile(GL::ShaderType::FRAGMENT, "../sh.frag");

    shader.link();

    float vertices[20] =
    {
        -0.5f, -0.5f, 0.f, 0.f, 0.f,
        0.5f, -0.5f, 0.f, 1.f, 0.f,
        0.5f, 0.5f, 0.f, 1.f, 1.f,
        -0.5f, 0.5f, 0.f, 0.f, 1.f
    };

    uint32_t indices[6] =
    {
        0, 1, 2,
        0, 2, 3
    };

    GL::Texture2D texture;

    texture.bind();

    auto fwhp = texture.load("../opengl_logo.png");

    if (!fwhp.pixels)
        logger.log("Texture failed loading");

    texture.parameter(GL::TextureParam::WRAP_S, GL::WrapMode::REPEAT);
    texture.parameter(GL::TextureParam::WRAP_T, GL::WrapMode::REPEAT);
    texture.parameter(GL::TextureParam::MIN_FILTER, GL::FilterMode::LINEAR_MIPMAP_LINEAR);
    texture.parameter(GL::TextureParam::MAG_FILTER, GL::FilterMode::LINEAR);

    context.texImage2D(GL::TextureType::T_2D, 0, fwhp, 0, GL::DataType::UNSIGNED_BYTE);

    context.generateMipMap(GL::TextureType::T_2D);

    texture.unbind();

    GL::VertexArray vao;

    GL::VBO vbo;

    GL::EBO ebo;

    vao.bind();

    vbo.bind();

    vbo.data(vertices, 20);

    ebo.bind();

    ebo.data(indices, 6);

    vao.attribPointer(0, 3, GL::DataType::FLOAT, false, 5 * sizeof(float), nullptr);

    vao.enableAttrib(0);

    vao.attribPointer(1, 2, GL::DataType::FLOAT, false, 5 * sizeof(float), reinterpret_cast<void *>(3 * sizeof(float)));

    vao.enableAttrib(1);

    vao.unbind();

    while (window.isOpen())
    {
        context.clear(GL::BufferBitMask::COLOR_DEPTH);

        shader.bind();

        context.activeTexture(0);

        texture.bind();

        shader.setUniformInt("aTex", 0);

        vao.bind();

        context.drawElements(GL::PrimitiveType::TRIANGLES, 6, GL::DataType::UNSIGNED_INT, nullptr);

        vao.unbind();

        texture.unbind();

        shader.unbind();

        window.swapBuffers();

        const auto &event = window.pollEvents();

        if (event.type == sgl::EventType::KEYBOARD && event.keyboard.key == sgl::Keyboard::Key::ESCAPE
            || event.windowState == sgl::WindowState::CLOSED)
            window.close();

        if (event.windowState == sgl::WindowState::RESIZED)
            context.setViewport(0, 0, window.getWidth(), window.getHeight());
    }

    std::cout << logger;
}
