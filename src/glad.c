/*
 * GLAD - OpenGL Loader Implementation
 */

#include <glad/glad.h>
#include <string.h>

PFNGLCLEARPROC glad_glClear = NULL;
PFNGLCLEARCOLORPROC glad_glClearColor = NULL;
PFNGLVIEWPORTPROC glad_glViewport = NULL;
PFNGLCREATESHADERPROC glad_glCreateShader = NULL;
PFNGLSHADERSOURCEPROC glad_glShaderSource = NULL;
PFNGLCOMPILESHADERPROC glad_glCompileShader = NULL;
PFNGLGETSHADERIVPROC glad_glGetShaderiv = NULL;
PFNGLGETSHADERINFOLOGPROC glad_glGetShaderInfoLog = NULL;
PFNGLCREATEPROGRAMPROC glad_glCreateProgram = NULL;
PFNGLATTACHSHADERPROC glad_glAttachShader = NULL;
PFNGLLINKPROGRAMPROC glad_glLinkProgram = NULL;
PFNGLGETPROGRAMIVPROC glad_glGetProgramiv = NULL;
PFNGLGETPROGRAMINFOLOGPROC glad_glGetProgramInfoLog = NULL;
PFNGLDELETESHADERPROC glad_glDeleteShader = NULL;
PFNGLUSEPROGRAMPROC glad_glUseProgram = NULL;
PFNGLGENBUFFERSPROC glad_glGenBuffers = NULL;
PFNGLBINDBUFFERPROC glad_glBindBuffer = NULL;
PFNGLBUFFERDATAPROC glad_glBufferData = NULL;
PFNGLGENVERTEXARRAYSPROC glad_glGenVertexArrays = NULL;
PFNGLBINDVERTEXARRAYPROC glad_glBindVertexArray = NULL;
PFNGLVERTEXATTRIBPOINTERPROC glad_glVertexAttribPointer = NULL;
PFNGLENABLEVERTEXATTRIBARRAYPROC glad_glEnableVertexAttribArray = NULL;
PFNGLDRAWARRAYSPROC glad_glDrawArrays = NULL;
PFNGLBEGINPROC glad_glBegin = NULL;
PFNGLENDPROC glad_glEnd = NULL;
PFNGLVERTEX2FPROC glad_glVertex2f = NULL;
PFNGLCOLOR3FPROC glad_glColor3f = NULL;

static void* glad_get_proc(void* (*load)(const char *name), const char* name) {
    void* result = load(name);
    return result;
}

int gladLoadGLLoader(void* (*load)(const char *name)) {
    if (load == NULL) {
        return 0;
    }

    glad_glClear = (PFNGLCLEARPROC)glad_get_proc(load, "glClear");
    glad_glClearColor = (PFNGLCLEARCOLORPROC)glad_get_proc(load, "glClearColor");
    glad_glViewport = (PFNGLVIEWPORTPROC)glad_get_proc(load, "glViewport");
    glad_glCreateShader = (PFNGLCREATESHADERPROC)glad_get_proc(load, "glCreateShader");
    glad_glShaderSource = (PFNGLSHADERSOURCEPROC)glad_get_proc(load, "glShaderSource");
    glad_glCompileShader = (PFNGLCOMPILESHADERPROC)glad_get_proc(load, "glCompileShader");
    glad_glGetShaderiv = (PFNGLGETSHADERIVPROC)glad_get_proc(load, "glGetShaderiv");
    glad_glGetShaderInfoLog = (PFNGLGETSHADERINFOLOGPROC)glad_get_proc(load, "glGetShaderInfoLog");
    glad_glCreateProgram = (PFNGLCREATEPROGRAMPROC)glad_get_proc(load, "glCreateProgram");
    glad_glAttachShader = (PFNGLATTACHSHADERPROC)glad_get_proc(load, "glAttachShader");
    glad_glLinkProgram = (PFNGLLINKPROGRAMPROC)glad_get_proc(load, "glLinkProgram");
    glad_glGetProgramiv = (PFNGLGETPROGRAMIVPROC)glad_get_proc(load, "glGetProgramiv");
    glad_glGetProgramInfoLog = (PFNGLGETPROGRAMINFOLOGPROC)glad_get_proc(load, "glGetProgramInfoLog");
    glad_glDeleteShader = (PFNGLDELETESHADERPROC)glad_get_proc(load, "glDeleteShader");
    glad_glUseProgram = (PFNGLUSEPROGRAMPROC)glad_get_proc(load, "glUseProgram");
    glad_glGenBuffers = (PFNGLGENBUFFERSPROC)glad_get_proc(load, "glGenBuffers");
    glad_glBindBuffer = (PFNGLBINDBUFFERPROC)glad_get_proc(load, "glBindBuffer");
    glad_glBufferData = (PFNGLBUFFERDATAPROC)glad_get_proc(load, "glBufferData");
    glad_glGenVertexArrays = (PFNGLGENVERTEXARRAYSPROC)glad_get_proc(load, "glGenVertexArrays");
    glad_glBindVertexArray = (PFNGLBINDVERTEXARRAYPROC)glad_get_proc(load, "glBindVertexArray");
    glad_glVertexAttribPointer = (PFNGLVERTEXATTRIBPOINTERPROC)glad_get_proc(load, "glVertexAttribPointer");
    glad_glEnableVertexAttribArray = (PFNGLENABLEVERTEXATTRIBARRAYPROC)glad_get_proc(load, "glEnableVertexAttribArray");
    glad_glDrawArrays = (PFNGLDRAWARRAYSPROC)glad_get_proc(load, "glDrawArrays");
    glad_glBegin = (PFNGLBEGINPROC)glad_get_proc(load, "glBegin");
    glad_glEnd = (PFNGLENDPROC)glad_get_proc(load, "glEnd");
    glad_glVertex2f = (PFNGLVERTEX2FPROC)glad_get_proc(load, "glVertex2f");
    glad_glColor3f = (PFNGLCOLOR3FPROC)glad_get_proc(load, "glColor3f");

    return 1;
}
