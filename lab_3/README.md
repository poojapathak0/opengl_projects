# Lab 3: 2D Transformations using Homogeneous Coordinates

This lab contains implementations of various 2D transformations using OpenGL and homogeneous coordinate systems.

## Files

1. **translation.c** - 2D Translation
2. **rotation.c** - 2D Rotation
3. **scaling.c** - 2D Scaling
4. **reflection.c** - 2D Reflection
5. **shearing.c** - 2D Shearing
6. **composite.c** - Composite Transformations (4 transformations combined)

## Compilation

Each file can be compiled using:
```bash
gcc -o <output_name> <source_file.c> -I../include -L../lib -lglut32 -lopengl32 -lgdi32
```

## Examples

```bash
# Translation
gcc -o translation translation.c -I../include -L../lib -lglut32 -lopengl32 -lgdi32

# Rotation
gcc -o rotation rotation.c -I../include -L../lib -lglut32 -lopengl32 -lgdi32

# Scaling
gcc -o scaling scaling.c -I../include -L../lib -lglut32 -lopengl32 -lgdi32

# Reflection
gcc -o reflection reflection.c -I../include -L../lib -lglut32 -lopengl32 -lgdi32

# Shearing
gcc -o shearing shearing.c -I../include -L../lib -lglut32 -lopengl32 -lgdi32

# Composite
gcc -o composite composite.c -I../include -L../lib -lglut32 -lopengl32 -lgdi32
```

## Features

- All transformations use homogeneous coordinate systems (3x3 matrices)
- Visual representation with original shape in blue and transformed shape in red/other colors
- Interactive controls where applicable
- Clear console output explaining the transformation parameters

## Controls

- **Q or ESC**: Exit the program
- **Reflection**: Press 1, 2, or 3 to switch between X-axis, Y-axis, and origin reflection
- **Shearing**: Press 1 or 2 to switch between X-shearing and Y-shearing
