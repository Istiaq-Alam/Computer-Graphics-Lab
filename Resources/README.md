# FreeGLUT Installation & Setup on Windows11 (Code::Blocks)
[Tutorial](https://www.youtube.com/watch?v=7rLo69vCooU)


# FreeGLUT Installation & Setup on Kali Linux (Code::Blocks)

**Step-by-Step with Error Fixes**

---

## STEP 1: Update the System

```bash
sudo apt update
sudo apt upgrade -y
```

---

## STEP 2: Install ALL Required OpenGL & FreeGLUT Packages

This is the **most important step**. Install both **runtime** and **development** libraries.

```bash
sudo apt install -y &&
freeglut3 freeglut3-dev &&
libglu1-mesa libglu1-mesa-dev &&
libgl1-mesa-dev &&
libxxf86vm1 libxxf86vm-dev &&
mesa-utils
```

### Why this matters

| Package          | Purpose                 |
| ---------------- | ----------------------- |
| `freeglut3`      | Runtime                 |
| `freeglut3-dev`  | Headers + linker        |
| `libxxf86vm1`    | Runtime dependency      |
| `libxxf86vm-dev` | Fixes `-lXxf86vm` error |
| `mesa-utils`     | OpenGL tools            |

---

## STEP 3: Verify Installation (Very Important)

```bash
ls /usr/include/GL/freeglut.h
ls /usr/lib/x86_64-linux-gnu/libXxf86vm.so
```

If both exist → system is correct.

---

## STEP 4: Create a New Project in Code::Blocks

1. Open **Code::Blocks**
2. **File → New → Project**
3. Select **Console application**
4. Choose **C** or **C++**
5. Finish

---

## STEP 5: Configure Linker Settings (CRITICAL)

### Open:

```
Right-click project → Build options
```

Make sure **project name (top)** is selected.

---

### Linker settings → Link libraries

Add **only these**, in this exact order:

```
glut
GLU
GL
Xxf86vm
```

❌ DO NOT add:

* `-LxXf86vm`
* full paths
* duplicates

---

## STEP 6: Do NOT Use Global Variables (Recommended)

On Linux, **global variables are unnecessary**.

If your project complains about `$(#glut)` or `$(#freeglut)`:

* Remove them from **Search directories**
* Remove them from **Linker settings**

Linux uses `/usr` automatically.

---

## STEP 7: Correct Header File

Use **only** this:

```c
#include <GL/freeglut.h>
```

❌ Do NOT use:

```c
#include <GL/glut.h>
```

---

## STEP 8: Correct Minimal FreeGLUT Program

This prevents the **glutInit error**.

```c
#include <GL/freeglut.h>

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glFlush();
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);                 // MUST be first
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600, 600);
    glutCreateWindow("FreeGLUT Test");
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
```

---

## STEP 9: Clean & Build (Always Do This)

```
Build → Clean
Build → Build
Build → Run
```

---

# Common Errors & Their FIXES (From Your Experience)

---

### ❌ Error:

`Code::Blocks does not know global compiler variable "glut"`

✅ Fix:

* Remove global variables OR
* Use system install (`/usr`)
* Prefer **no global variables on Linux**

---

### ❌ Error:

`ld: cannot find -LxXf86vm`

✅ Fix:

* You used `-L` instead of `-l`
* Correct library name is:

```
Xxf86vm
```

---

### ❌ Error:

`error while loading shared libraries: libXxf86vm.so.1`

✅ Fix:

```bash
sudo apt install libxxf86vm1
```

---

### ❌ Error:

`ld: cannot find -lXxf86vm`

✅ Fix:

```bash
sudo apt install libxxf86vm-dev
```

---

### ❌ Error:

`glutCreateWindow called without glutInit`

✅ Fix:

* Ensure:

```c
int main(int argc, char **argv)
glutInit(&argc, argv);
```

* Must be before **any GLUT call**

---

## FINAL VERIFIED LINKER CONFIGURATION (Linux)

```
glut
GLU
GL
Xxf86vm
```

No paths
No `-L` flags
No global variables

---

## FINAL CHECK

Run:

```bash
glxgears
```

If gears spin → OpenGL is working perfectly.

---


