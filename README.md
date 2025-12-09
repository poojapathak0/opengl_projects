# OpenGL Projects

A collection of OpenGL learning projects and demonstrations.

## Projects

### 1. Polygon Name Display
A simple OpenGL program that displays the name "POOJA" using polygons (rectangles).

**Location**: `polygon_name/`

**Features**:
- Simple polygon-based text rendering
- Each letter drawn using basic rectangles
- Great for learning OpenGL fundamentals
- Detailed tutorial included

**How to build**:
```bash
cd polygon_name
g++ -g name_display.c ../src/glad.c -I../include -L../lib -lglfw3 -lopengl32 -lgdi32 -o name_display.exe
```

**How to run**:
```bash
./name_display.exe
```

## Prerequisites

- MinGW-w64 (GCC compiler)
- GLFW library
- GLAD OpenGL loader
- Windows OS (or modify build commands for Linux/Mac)

## Learning Resources

Each project includes:
- Source code with comments
- Detailed README with explanations
- Build instructions
- Learning exercises

## Getting Started

1. Clone this repository
2. Install MinGW-w64 from [mingw-w64.org](https://www.mingw-w64.org/)
3. Navigate to any project folder
4. Follow the build instructions in that project's README

## Contributing

Feel free to fork and add your own OpenGL learning projects!

## License

Free to use for educational purposes.
