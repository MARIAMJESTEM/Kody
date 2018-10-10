'''Autogenerated by get_gl_extensions script, do not edit!'''
from OpenGL import platform as _p, constants as _cs, arrays
from OpenGL.GL import glget
import ctypes
EXTENSION_NAME = 'GL_EXT_secondary_color'
def _f( function ):
    return _p.createFunction( function,_p.GL,'GL_EXT_secondary_color',False)
_p.unpack_constants( """GL_COLOR_SUM_EXT 0x8458
GL_CURRENT_SECONDARY_COLOR_EXT 0x8459
GL_SECONDARY_COLOR_ARRAY_SIZE_EXT 0x845A
GL_SECONDARY_COLOR_ARRAY_TYPE_EXT 0x845B
GL_SECONDARY_COLOR_ARRAY_STRIDE_EXT 0x845C
GL_SECONDARY_COLOR_ARRAY_POINTER_EXT 0x845D
GL_SECONDARY_COLOR_ARRAY_EXT 0x845E""", globals())
glget.addGLGetConstant( GL_COLOR_SUM_EXT, (1,) )
glget.addGLGetConstant( GL_CURRENT_SECONDARY_COLOR_EXT, (1,) )
glget.addGLGetConstant( GL_SECONDARY_COLOR_ARRAY_SIZE_EXT, (1,) )
glget.addGLGetConstant( GL_SECONDARY_COLOR_ARRAY_TYPE_EXT, (1,) )
glget.addGLGetConstant( GL_SECONDARY_COLOR_ARRAY_STRIDE_EXT, (1,) )
@_f
@_p.types(None,_cs.GLbyte,_cs.GLbyte,_cs.GLbyte)
def glSecondaryColor3bEXT( red,green,blue ):pass
@_f
@_p.types(None,arrays.GLbyteArray)
def glSecondaryColor3bvEXT( v ):pass
@_f
@_p.types(None,_cs.GLdouble,_cs.GLdouble,_cs.GLdouble)
def glSecondaryColor3dEXT( red,green,blue ):pass
@_f
@_p.types(None,arrays.GLdoubleArray)
def glSecondaryColor3dvEXT( v ):pass
@_f
@_p.types(None,_cs.GLfloat,_cs.GLfloat,_cs.GLfloat)
def glSecondaryColor3fEXT( red,green,blue ):pass
@_f
@_p.types(None,arrays.GLfloatArray)
def glSecondaryColor3fvEXT( v ):pass
@_f
@_p.types(None,_cs.GLint,_cs.GLint,_cs.GLint)
def glSecondaryColor3iEXT( red,green,blue ):pass
@_f
@_p.types(None,arrays.GLintArray)
def glSecondaryColor3ivEXT( v ):pass
@_f
@_p.types(None,_cs.GLshort,_cs.GLshort,_cs.GLshort)
def glSecondaryColor3sEXT( red,green,blue ):pass
@_f
@_p.types(None,arrays.GLshortArray)
def glSecondaryColor3svEXT( v ):pass
@_f
@_p.types(None,_cs.GLubyte,_cs.GLubyte,_cs.GLubyte)
def glSecondaryColor3ubEXT( red,green,blue ):pass
@_f
@_p.types(None,arrays.GLubyteArray)
def glSecondaryColor3ubvEXT( v ):pass
@_f
@_p.types(None,_cs.GLuint,_cs.GLuint,_cs.GLuint)
def glSecondaryColor3uiEXT( red,green,blue ):pass
@_f
@_p.types(None,arrays.GLuintArray)
def glSecondaryColor3uivEXT( v ):pass
@_f
@_p.types(None,_cs.GLushort,_cs.GLushort,_cs.GLushort)
def glSecondaryColor3usEXT( red,green,blue ):pass
@_f
@_p.types(None,arrays.GLushortArray)
def glSecondaryColor3usvEXT( v ):pass
@_f
@_p.types(None,_cs.GLint,_cs.GLenum,_cs.GLsizei,ctypes.c_void_p)
def glSecondaryColorPointerEXT( size,type,stride,pointer ):pass


def glInitSecondaryColorEXT():
    '''Return boolean indicating whether this extension is available'''
    from OpenGL import extensions
    return extensions.hasGLExtension( EXTENSION_NAME )
