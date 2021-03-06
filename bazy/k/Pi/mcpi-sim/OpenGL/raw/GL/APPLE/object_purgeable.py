'''Autogenerated by get_gl_extensions script, do not edit!'''
from OpenGL import platform as _p, constants as _cs, arrays
from OpenGL.GL import glget
import ctypes
EXTENSION_NAME = 'GL_APPLE_object_purgeable'
def _f( function ):
    return _p.createFunction( function,_p.GL,'GL_APPLE_object_purgeable',False)
_p.unpack_constants( """GL_BUFFER_OBJECT_APPLE 0x85B3
GL_RELEASED_APPLE 0x8A19
GL_VOLATILE_APPLE 0x8A1A
GL_RETAINED_APPLE 0x8A1B
GL_UNDEFINED_APPLE 0x8A1C
GL_PURGEABLE_APPLE 0x8A1D""", globals())
@_f
@_p.types(_cs.GLenum,_cs.GLenum,_cs.GLuint,_cs.GLenum)
def glObjectPurgeableAPPLE( objectType,name,option ):pass
@_f
@_p.types(_cs.GLenum,_cs.GLenum,_cs.GLuint,_cs.GLenum)
def glObjectUnpurgeableAPPLE( objectType,name,option ):pass
@_f
@_p.types(None,_cs.GLenum,_cs.GLuint,_cs.GLenum,arrays.GLintArray)
def glGetObjectParameterivAPPLE( objectType,name,pname,params ):pass


def glInitObjectPurgeableAPPLE():
    '''Return boolean indicating whether this extension is available'''
    from OpenGL import extensions
    return extensions.hasGLExtension( EXTENSION_NAME )
