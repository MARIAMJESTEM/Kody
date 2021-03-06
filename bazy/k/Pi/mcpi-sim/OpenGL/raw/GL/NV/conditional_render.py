'''Autogenerated by get_gl_extensions script, do not edit!'''
from OpenGL import platform as _p, constants as _cs, arrays
from OpenGL.GL import glget
import ctypes
EXTENSION_NAME = 'GL_NV_conditional_render'
def _f( function ):
    return _p.createFunction( function,_p.GL,'GL_NV_conditional_render',False)
_p.unpack_constants( """GL_QUERY_WAIT_NV 0x8E13
GL_QUERY_NO_WAIT_NV 0x8E14
GL_QUERY_BY_REGION_WAIT_NV 0x8E15
GL_QUERY_BY_REGION_NO_WAIT_NV 0x8E16""", globals())
@_f
@_p.types(None,_cs.GLuint,_cs.GLenum)
def glBeginConditionalRenderNV( id,mode ):pass
@_f
@_p.types(None,)
def glEndConditionalRenderNV(  ):pass


def glInitConditionalRenderNV():
    '''Return boolean indicating whether this extension is available'''
    from OpenGL import extensions
    return extensions.hasGLExtension( EXTENSION_NAME )
