

https://github.com/user-attachments/assets/def06b3d-0858-4963-a935-724c39f1fe89



# POOJA - Name Display using OpenGL Polygons

## 📚 Complete Tutorial: How This Works

### 🎯 What Does This Program Do?

This program creates a window and draws your name "POOJA" (my case) using simple shapes (polygons). Think of it like building letters with LEGO blocks - each letter is made from smaller rectangles!

---

## 🧱 The Building Blocks

### 1. **Understanding OpenGL Coordinate System**

OpenGL uses a coordinate system where:
- The **center** of the screen is `(0, 0)`
- **Left edge** is `-1.0`, **Right edge** is `+1.0`
- **Bottom edge** is `-1.0`, **Top edge** is `+1.0`

```
        (+1.0)
          |
(-1.0) ---0--- (+1.0)
          |
        (-1.0)
```

### 2. **What Are Polygons?**

A polygon is a closed shape made by connecting points (vertices). In our code:
```c
glBegin(GL_POLYGON);        // Start drawing a shape
glVertex2f(x1, y1);         // Point 1
glVertex2f(x2, y2);         // Point 2
glVertex2f(x3, y3);         // Point 3
glVertex2f(x4, y4);         // Point 4
glEnd();                    // Finish the shape
```

This creates a 4-sided shape (rectangle). OpenGL automatically fills it with color!

---

## 🔤 How Each Letter is Built

### **Letter P - Example Breakdown**

The letter "P" is made from **3 rectangles**:

```
###             Rectangle 1: Vertical line (left side)
###  ####       Rectangle 2: Top horizontal bar
###  ####       Rectangle 3: Right vertical part of the loop
###             
###             
```

**Code explanation:**
```c
void drawP(float x, float y, float size) {
    // Rectangle 1: The vertical left bar of P
    glBegin(GL_POLYGON);
    glVertex2f(x, y);                    // Bottom-left corner
    glVertex2f(x + size * 0.1f, y);      // Bottom-right corner (thin width)
    glVertex2f(x + size * 0.1f, y + size); // Top-right corner (full height)
    glVertex2f(x, y + size);             // Top-left corner
    glEnd();
    
    // Rectangle 2: The top horizontal bar
    glBegin(GL_POLYGON);
    glVertex2f(x, y + size * 0.5f);        // Starts at middle height
    glVertex2f(x + size * 0.4f, y + size * 0.5f); // Extends right
    glVertex2f(x + size * 0.4f, y + size);        // Goes to top
    glVertex2f(x, y + size);
    glEnd();
    
    // Rectangle 3: The right edge of P's loop
    glBegin(GL_POLYGON);
    glVertex2f(x + size * 0.4f, y + size * 0.9f);  // Small vertical line
    glVertex2f(x + size * 0.5f, y + size * 0.9f);
    glVertex2f(x + size * 0.5f, y + size * 0.6f);
    glVertex2f(x + size * 0.4f, y + size * 0.6f);
    glEnd();
}
```

**Why multiply by size?**
- `size * 0.1f` = 10% of letter size (thin line)
- `size * 0.5f` = 50% of letter size (halfway)
- This makes letters scalable - change `size` and everything adjusts!

### **Letter O - The Circle Effect**

O is made from **4 rectangles** creating a square frame:
```
#######    Top bar
##   ##    Left & right bars
##   ##    
#######    Bottom bar
```

Each rectangle forms one side of the "O".

### **Letter J - The Hook**

J needs **3 rectangles**:
1. Vertical line (the main part)
2. Bottom horizontal (the hook)
3. Left vertical (completing the hook)

### **Letter A - The Triangle Top**

A is built from **4 rectangles**:
1. Left vertical line
2. Right vertical line  
3. Top horizontal bar (connecting them)
4. Middle horizontal bar (the crossbar)

---

