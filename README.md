# OpenGL Projects

A collection of OpenGL learning projects and demonstrations configured for VS Code with GLFW and GLAD.

## Prerequisites

- MinGW-w64 (GCC compiler): Download from [mingw-w64.org](https://www.mingw-w64.org/) or use [MSYS2](https://www.msys2.org/)
- GLFW library
- GLAD OpenGL loader
- Windows OS (or modify build commands for Linux/Mac)

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
├── lab_2/              # Lab 2 assignments (DDA, Bresenham, etc.)
├── opengl_projects/    # Additional projects
└── .vscode/            # VS Code configuration
```

## Projects

### 1. Polygon Name Display
A simple OpenGL program that displays the name "POOJA" using polygons (rectangles).

**Location**: `opengl_projects/polygon_name/`

**Features**:
- Simple polygon-based text rendering
- Each letter drawn using basic rectangles
- Great for learning OpenGL fundamentals
- Detailed tutorial included

**How to build**:
```bash
cd opengl_projects/polygon_name
g++ -g name_display.c ../../src/glad.c -I../../include -L../../lib -lglfw3 -lopengl32 -lgdi32 -o name_display.exe
```

### 2. Lab 2 - Line and Shape Algorithms
Various implementations of computer graphics algorithms.

**Location**: `lab_2/`

**Programs**:
- DDA Line Algorithm
- Bresenham Line Algorithm
- Midpoint Circle Algorithm
- Midpoint Ellipse Algorithm
- Line Graph
- Pie Chart

## Building and Running

### Using VS Code Tasks

1. **Build**: Press `Ctrl+Shift+B` or run "Build OpenGL Project" task
2. **Run**: Press `Ctrl+Shift+P` → "Tasks: Run Test Task" → "Build and Run"
3. **Debug**: Press `F5` to build and debug

### Using Terminal

```bash
# Build the main project
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

## Learning Resources

Each project includes:
- Source code with comments
- Detailed README with explanations
- Build instructions
- Learning exercises

## Next Steps

- Modify `src/main.c` to add more complex graphics
- Add more shaders
- Implement camera controls
- Load textures and 3D models

## Resources

- [Learn OpenGL](https://learnopengl.com/)
- [GLFW Documentation](https://www.glfw.org/documentation.html)
- [OpenGL Reference](https://www.khronos.org/opengl/)

## Contributing

Feel free to fork and add your own OpenGL learning projects!

## License

Free to use for educational purposes.
