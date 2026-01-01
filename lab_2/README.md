# Lab 2 - DDA Line Drawing Algorithm

## Question 1: Digital Differential Analyzer (DDA) Line Drawing Algorithm

### What is DDA Algorithm?

The Digital Differential Analyzer (DDA) algorithm is a simple line drawing algorithm that uses floating-point arithmetic to generate points between two endpoints.

### Algorithm Steps:

1. Calculate dx = x2 - x1 and dy = y2 - y1
2. Calculate steps = max(|dx|, |dy|)
3. Calculate x_increment = dx / steps and y_increment = dy / steps
4. Start from (x1, y1)
5. For each step:
   - Plot the point at (round(x), round(y))
   - x = x + x_increment
   - y = y + y_increment

### How to Build and Run:

```bash
# Build the program
g++ -g lab_2/dda_line.c src/glad.c -Iinclude -Llib -lglfw3 -lopengl32 -lgdi32 -o lab_2/dda_line.exe

# Run the program
./lab_2/dda_line.exe
```

### What the Program Does:

- Implements the DDA line drawing algorithm
- Draws 5 different lines:
  - Horizontal line
  - Vertical line
  - Diagonal lines (positive and negative slopes)
- Displays the lines in a window
- Press ESC to close

### Example Output:

The program draws white lines on a black background demonstrating various line orientations.
