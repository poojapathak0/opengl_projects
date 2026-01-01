# OpenGL Project Setup

This project is configured for OpenGL development in VS Code with GLFW and GLAD.

## Prerequisites

Make sure you have MinGW-w64 (GCC) installed on your system:
- Download from: https://www.mingw-w64.org/
- Or use MSYS2: https://www.msys2.org/

## Project Structure

```
opengl/
├── src/
│   ├── main.c          # Main OpenGL application
│   └── glad.c          # GLAD OpenGL loader implementation
├── include/
│   ├── glad/
│   │   └── glad.h      # GLAD header
│   └── GLFW/           # GLFW headers
├── lib/                # GLFW libraries
└── .vscode/            # VS Code configuration
```

## Building and Running

### Using VS Code Tasks

1. **Build**: Press `Ctrl+Shift+B` or run "Build OpenGL Project" task
2. **Run**: Press `Ctrl+Shift+P` → "Tasks: Run Test Task" → "Build and Run"
3. **Debug**: Press `F5` to build and debug

### Using Terminal

```bash
# Build the project
g++ -g src/main.c src/glad.c -Iinclude -Llib -lglfw3 -lopengl32 -lgdi32 -o main.exe

# Run the executable
./main.exe
```

## What the Sample Does

The sample program creates a window and renders an orange triangle using:
- OpenGL 3.3 Core Profile
- Vertex and Fragment Shaders
- Vertex Buffer Objects (VBO)
- Vertex Array Objects (VAO)

**Controls**: Press `ESC` to close the window

## Troubleshooting

If you get compilation errors:
1. Ensure MinGW is in your PATH
2. Verify g++ is accessible: `g++ --version`
3. Check that all library files are in the `lib/` directory

## Next Steps

- Modify `src/main.c` to add more complex graphics
- Add more shaders
- Implement camera controls
- Load textures and 3D models

## Resources

- [Learn OpenGL](https://learnopengl.com/)
- [GLFW Documentation](https://www.glfw.org/documentation.html)
- [OpenGL Reference](https://www.khronos.org/opengl/)
