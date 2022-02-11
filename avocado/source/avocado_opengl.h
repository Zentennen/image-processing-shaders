// avocado_opengl.h

#ifndef AVOCADO_OPENGL_H_INCLUDED
#define AVOCADO_OPENGL_H_INCLUDED

#ifdef __cplusplus
extern "C"
{;
#endif

#ifndef GL_VERSION_1_0
#define GL_VERSION_1_0 1
typedef void GLvoid;
typedef unsigned int GLenum;
typedef float GLfloat;
typedef int GLint;
typedef int GLsizei;
typedef unsigned int GLbitfield;
typedef double GLdouble;
typedef unsigned int GLuint;
typedef unsigned char GLboolean;
typedef unsigned char GLubyte;
#define GL_DEPTH_BUFFER_BIT               0x00000100
#define GL_STENCIL_BUFFER_BIT             0x00000400
#define GL_COLOR_BUFFER_BIT               0x00004000
#define GL_FALSE                          0
#define GL_TRUE                           1
#define GL_POINTS                         0x0000
#define GL_LINES                          0x0001
#define GL_LINE_LOOP                      0x0002
#define GL_LINE_STRIP                     0x0003
#define GL_TRIANGLES                      0x0004
#define GL_TRIANGLE_STRIP                 0x0005
#define GL_TRIANGLE_FAN                   0x0006
#define GL_QUADS                          0x0007
#define GL_NEVER                          0x0200
#define GL_LESS                           0x0201
#define GL_EQUAL                          0x0202
#define GL_LEQUAL                         0x0203
#define GL_GREATER                        0x0204
#define GL_NOTEQUAL                       0x0205
#define GL_GEQUAL                         0x0206
#define GL_ALWAYS                         0x0207
#define GL_ZERO                           0
#define GL_ONE                            1
#define GL_SRC_COLOR                      0x0300
#define GL_ONE_MINUS_SRC_COLOR            0x0301
#define GL_SRC_ALPHA                      0x0302
#define GL_ONE_MINUS_SRC_ALPHA            0x0303
#define GL_DST_ALPHA                      0x0304
#define GL_ONE_MINUS_DST_ALPHA            0x0305
#define GL_DST_COLOR                      0x0306
#define GL_ONE_MINUS_DST_COLOR            0x0307
#define GL_SRC_ALPHA_SATURATE             0x0308
#define GL_NONE                           0
#define GL_FRONT_LEFT                     0x0400
#define GL_FRONT_RIGHT                    0x0401
#define GL_BACK_LEFT                      0x0402
#define GL_BACK_RIGHT                     0x0403
#define GL_FRONT                          0x0404
#define GL_BACK                           0x0405
#define GL_LEFT                           0x0406
#define GL_RIGHT                          0x0407
#define GL_FRONT_AND_BACK                 0x0408
#define GL_NO_ERROR                       0
#define GL_INVALID_ENUM                   0x0500
#define GL_INVALID_VALUE                  0x0501
#define GL_INVALID_OPERATION              0x0502
#define GL_OUT_OF_MEMORY                  0x0505
#define GL_CW                             0x0900
#define GL_CCW                            0x0901
#define GL_POINT_SIZE                     0x0B11
#define GL_POINT_SIZE_RANGE               0x0B12
#define GL_POINT_SIZE_GRANULARITY         0x0B13
#define GL_LINE_SMOOTH                    0x0B20
#define GL_LINE_WIDTH                     0x0B21
#define GL_LINE_WIDTH_RANGE               0x0B22
#define GL_LINE_WIDTH_GRANULARITY         0x0B23
#define GL_POLYGON_MODE                   0x0B40
#define GL_POLYGON_SMOOTH                 0x0B41
#define GL_CULL_FACE                      0x0B44
#define GL_CULL_FACE_MODE                 0x0B45
#define GL_FRONT_FACE                     0x0B46
#define GL_DEPTH_RANGE                    0x0B70
#define GL_DEPTH_TEST                     0x0B71
#define GL_DEPTH_WRITEMASK                0x0B72
#define GL_DEPTH_CLEAR_VALUE              0x0B73
#define GL_DEPTH_FUNC                     0x0B74
#define GL_STENCIL_TEST                   0x0B90
#define GL_STENCIL_CLEAR_VALUE            0x0B91
#define GL_STENCIL_FUNC                   0x0B92
#define GL_STENCIL_VALUE_MASK             0x0B93
#define GL_STENCIL_FAIL                   0x0B94
#define GL_STENCIL_PASS_DEPTH_FAIL        0x0B95
#define GL_STENCIL_PASS_DEPTH_PASS        0x0B96
#define GL_STENCIL_REF                    0x0B97
#define GL_STENCIL_WRITEMASK              0x0B98
#define GL_VIEWPORT                       0x0BA2
#define GL_DITHER                         0x0BD0
#define GL_BLEND_DST                      0x0BE0
#define GL_BLEND_SRC                      0x0BE1
#define GL_BLEND                          0x0BE2
#define GL_LOGIC_OP_MODE                  0x0BF0
#define GL_DRAW_BUFFER                    0x0C01
#define GL_READ_BUFFER                    0x0C02
#define GL_SCISSOR_BOX                    0x0C10
#define GL_SCISSOR_TEST                   0x0C11
#define GL_COLOR_CLEAR_VALUE              0x0C22
#define GL_COLOR_WRITEMASK                0x0C23
#define GL_DOUBLEBUFFER                   0x0C32
#define GL_STEREO                         0x0C33
#define GL_LINE_SMOOTH_HINT               0x0C52
#define GL_POLYGON_SMOOTH_HINT            0x0C53
#define GL_UNPACK_SWAP_BYTES              0x0CF0
#define GL_UNPACK_LSB_FIRST               0x0CF1
#define GL_UNPACK_ROW_LENGTH              0x0CF2
#define GL_UNPACK_SKIP_ROWS               0x0CF3
#define GL_UNPACK_SKIP_PIXELS             0x0CF4
#define GL_UNPACK_ALIGNMENT               0x0CF5
#define GL_PACK_SWAP_BYTES                0x0D00
#define GL_PACK_LSB_FIRST                 0x0D01
#define GL_PACK_ROW_LENGTH                0x0D02
#define GL_PACK_SKIP_ROWS                 0x0D03
#define GL_PACK_SKIP_PIXELS               0x0D04
#define GL_PACK_ALIGNMENT                 0x0D05
#define GL_MAX_TEXTURE_SIZE               0x0D33
#define GL_MAX_VIEWPORT_DIMS              0x0D3A
#define GL_SUBPIXEL_BITS                  0x0D50
#define GL_TEXTURE_1D                     0x0DE0
#define GL_TEXTURE_2D                     0x0DE1
#define GL_TEXTURE_WIDTH                  0x1000
#define GL_TEXTURE_HEIGHT                 0x1001
#define GL_TEXTURE_BORDER_COLOR           0x1004
#define GL_DONT_CARE                      0x1100
#define GL_FASTEST                        0x1101
#define GL_NICEST                         0x1102
#define GL_BYTE                           0x1400
#define GL_UNSIGNED_BYTE                  0x1401
#define GL_SHORT                          0x1402
#define GL_UNSIGNED_SHORT                 0x1403
#define GL_INT                            0x1404
#define GL_UNSIGNED_INT                   0x1405
#define GL_FLOAT                          0x1406
#define GL_STACK_OVERFLOW                 0x0503
#define GL_STACK_UNDERFLOW                0x0504
#define GL_CLEAR                          0x1500
#define GL_AND                            0x1501
#define GL_AND_REVERSE                    0x1502
#define GL_COPY                           0x1503
#define GL_AND_INVERTED                   0x1504
#define GL_NOOP                           0x1505
#define GL_XOR                            0x1506
#define GL_OR                             0x1507
#define GL_NOR                            0x1508
#define GL_EQUIV                          0x1509
#define GL_INVERT                         0x150A
#define GL_OR_REVERSE                     0x150B
#define GL_COPY_INVERTED                  0x150C
#define GL_OR_INVERTED                    0x150D
#define GL_NAND                           0x150E
#define GL_SET                            0x150F
#define GL_TEXTURE                        0x1702
#define GL_COLOR                          0x1800
#define GL_DEPTH                          0x1801
#define GL_STENCIL                        0x1802
#define GL_STENCIL_INDEX                  0x1901
#define GL_DEPTH_COMPONENT                0x1902
#define GL_RED                            0x1903
#define GL_GREEN                          0x1904
#define GL_BLUE                           0x1905
#define GL_ALPHA                          0x1906
#define GL_RGB                            0x1907
#define GL_RGBA                           0x1908
#define GL_POINT                          0x1B00
#define GL_LINE                           0x1B01
#define GL_FILL                           0x1B02
#define GL_KEEP                           0x1E00
#define GL_REPLACE                        0x1E01
#define GL_INCR                           0x1E02
#define GL_DECR                           0x1E03
#define GL_VENDOR                         0x1F00
#define GL_RENDERER                       0x1F01
#define GL_VERSION                        0x1F02
#define GL_EXTENSIONS                     0x1F03
#define GL_NEAREST                        0x2600
#define GL_LINEAR                         0x2601
#define GL_NEAREST_MIPMAP_NEAREST         0x2700
#define GL_LINEAR_MIPMAP_NEAREST          0x2701
#define GL_NEAREST_MIPMAP_LINEAR          0x2702
#define GL_LINEAR_MIPMAP_LINEAR           0x2703
#define GL_TEXTURE_MAG_FILTER             0x2800
#define GL_TEXTURE_MIN_FILTER             0x2801
#define GL_TEXTURE_WRAP_S                 0x2802
#define GL_TEXTURE_WRAP_T                 0x2803
#define GL_REPEAT                         0x2901

#define OPENGL_FUNCTIONS_1_0 \
   GL_FUNC(void, glCullFace, GLenum mode) \
   GL_FUNC(void, glFrontFace, GLenum mode) \
   GL_FUNC(void, glHint, GLenum target, GLenum mode) \
   GL_FUNC(void, glLineWidth, GLfloat width) \
   GL_FUNC(void, glPointSize, GLfloat size) \
   GL_FUNC(void, glPolygonMode, GLenum face, GLenum mode) \
   GL_FUNC(void, glScissor, GLint x, GLint y, GLsizei width, GLsizei height) \
   GL_FUNC(void, glTexParameterf, GLenum target, GLenum pname, GLfloat param) \
   GL_FUNC(void, glTexParameterfv, GLenum target, GLenum pname, const GLfloat *params) \
   GL_FUNC(void, glTexParameteri, GLenum target, GLenum pname, GLint param) \
   GL_FUNC(void, glTexParameteriv, GLenum target, GLenum pname, const GLint *params) \
   GL_FUNC(void, glTexImage1D, GLenum target, GLint level, GLint internalformat, GLsizei width, GLint border, GLenum format, GLenum type, const void *pixels) \
   GL_FUNC(void, glTexImage2D, GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const void *pixels) \
   GL_FUNC(void, glDrawBuffer, GLenum buf) \
   GL_FUNC(void, glClear, GLbitfield mask) \
   GL_FUNC(void, glClearColor, GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha) \
   GL_FUNC(void, glClearStencil, GLint s) \
   GL_FUNC(void, glClearDepth, GLdouble depth) \
   GL_FUNC(void, glStencilMask, GLuint mask) \
   GL_FUNC(void, glColorMask, GLboolean red, GLboolean green, GLboolean blue, GLboolean alpha) \
   GL_FUNC(void, glDepthMask, GLboolean flag) \
   GL_FUNC(void, glDisable, GLenum cap) \
   GL_FUNC(void, glEnable, GLenum cap) \
   GL_FUNC(void, glFinish, void) \
   GL_FUNC(void, glFlush, void) \
   GL_FUNC(void, glBlendFunc, GLenum sfactor, GLenum dfactor) \
   GL_FUNC(void, glLogicOp, GLenum opcode) \
   GL_FUNC(void, glStencilFunc, GLenum func, GLint ref, GLuint mask) \
   GL_FUNC(void, glStencilOp, GLenum fail, GLenum zfail, GLenum zpass) \
   GL_FUNC(void, glDepthFunc, GLenum func) \
   GL_FUNC(void, glPixelStoref, GLenum pname, GLfloat param) \
   GL_FUNC(void, glPixelStorei, GLenum pname, GLint param) \
   GL_FUNC(void, glReadBuffer, GLenum src) \
   GL_FUNC(void, glReadPixels, GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, void *pixels) \
   GL_FUNC(void, glGetBooleanv, GLenum pname, GLboolean *data) \
   GL_FUNC(void, glGetDoublev, GLenum pname, GLdouble *data) \
   GL_FUNC(GLenum, glGetError, void) \
   GL_FUNC(void, glGetFloatv, GLenum pname, GLfloat *data) \
   GL_FUNC(void, glGetIntegerv, GLenum pname, GLint *data) \
   GL_FUNC(const GLubyte *, glGetString, GLenum name) \
   GL_FUNC(void, glGetTexImage, GLenum target, GLint level, GLenum format, GLenum type, void *pixels) \
   GL_FUNC(void, glGetTexParameterfv, GLenum target, GLenum pname, GLfloat *params) \
   GL_FUNC(void, glGetTexParameteriv, GLenum target, GLenum pname, GLint *params) \
   GL_FUNC(void, glGetTexLevelParameterfv, GLenum target, GLint level, GLenum pname, GLfloat *params) \
   GL_FUNC(void, glGetTexLevelParameteriv, GLenum target, GLint level, GLenum pname, GLint *params) \
   GL_FUNC(GLboolean, glIsEnabled, GLenum cap) \
   GL_FUNC(void, glDepthRange, GLdouble n, GLdouble f) \
   GL_FUNC(void, glViewport, GLint x, GLint y, GLsizei width, GLsizei height) 

#endif /* GL_VERSION_1_0 */

#ifndef GL_VERSION_1_1
#define GL_VERSION_1_1 1
typedef float GLclampf;
typedef double GLclampd;
#define GL_COLOR_LOGIC_OP                 0x0BF2
#define GL_POLYGON_OFFSET_UNITS           0x2A00
#define GL_POLYGON_OFFSET_POINT           0x2A01
#define GL_POLYGON_OFFSET_LINE            0x2A02
#define GL_POLYGON_OFFSET_FILL            0x8037
#define GL_POLYGON_OFFSET_FACTOR          0x8038
#define GL_TEXTURE_BINDING_1D             0x8068
#define GL_TEXTURE_BINDING_2D             0x8069
#define GL_TEXTURE_INTERNAL_FORMAT        0x1003
#define GL_TEXTURE_RED_SIZE               0x805C
#define GL_TEXTURE_GREEN_SIZE             0x805D
#define GL_TEXTURE_BLUE_SIZE              0x805E
#define GL_TEXTURE_ALPHA_SIZE             0x805F
#define GL_DOUBLE                         0x140A
#define GL_PROXY_TEXTURE_1D               0x8063
#define GL_PROXY_TEXTURE_2D               0x8064
#define GL_R3_G3_B2                       0x2A10
#define GL_RGB4                           0x804F
#define GL_RGB5                           0x8050
#define GL_RGB8                           0x8051
#define GL_RGB10                          0x8052
#define GL_RGB12                          0x8053
#define GL_RGB16                          0x8054
#define GL_RGBA2                          0x8055
#define GL_RGBA4                          0x8056
#define GL_RGB5_A1                        0x8057
#define GL_RGBA8                          0x8058
#define GL_RGB10_A2                       0x8059
#define GL_RGBA12                         0x805A
#define GL_RGBA16                         0x805B
#define GL_VERTEX_ARRAY                   0x8074

#define OPENGL_FUNCTIONS_1_1 \
   GL_FUNC(void, glDrawArrays, GLenum mode, GLint first, GLsizei count) \
   GL_FUNC(void, glDrawElements, GLenum mode, GLsizei count, GLenum type, const void *indices) \
   GL_FUNC(void, glGetPointerv, GLenum pname, void **params) \
   GL_FUNC(void, glPolygonOffset, GLfloat factor, GLfloat units) \
   GL_FUNC(void, glCopyTexImage1D, GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLint border) \
   GL_FUNC(void, glCopyTexImage2D, GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border) \
   GL_FUNC(void, glCopyTexSubImage1D, GLenum target, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width) \
   GL_FUNC(void, glCopyTexSubImage2D, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height) \
   GL_FUNC(void, glTexSubImage1D, GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, const void *pixels) \
   GL_FUNC(void, glTexSubImage2D, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const void *pixels) \
   GL_FUNC(void, glBindTexture, GLenum target, GLuint texture) \
   GL_FUNC(void, glDeleteTextures, GLsizei n, const GLuint *textures) \
   GL_FUNC(void, glGenTextures, GLsizei n, GLuint *textures) \
   GL_FUNC(GLboolean, glIsTexture, GLuint texture) 

#endif /* GL_VERSION_1_1 */

#ifndef GL_VERSION_1_2
#define GL_VERSION_1_2 1
#define GL_UNSIGNED_BYTE_3_3_2            0x8032
#define GL_UNSIGNED_SHORT_4_4_4_4         0x8033
#define GL_UNSIGNED_SHORT_5_5_5_1         0x8034
#define GL_UNSIGNED_INT_8_8_8_8           0x8035
#define GL_UNSIGNED_INT_10_10_10_2        0x8036
#define GL_TEXTURE_BINDING_3D             0x806A
#define GL_PACK_SKIP_IMAGES               0x806B
#define GL_PACK_IMAGE_HEIGHT              0x806C
#define GL_UNPACK_SKIP_IMAGES             0x806D
#define GL_UNPACK_IMAGE_HEIGHT            0x806E
#define GL_TEXTURE_3D                     0x806F
#define GL_PROXY_TEXTURE_3D               0x8070
#define GL_TEXTURE_DEPTH                  0x8071
#define GL_TEXTURE_WRAP_R                 0x8072
#define GL_MAX_3D_TEXTURE_SIZE            0x8073
#define GL_UNSIGNED_BYTE_2_3_3_REV        0x8362
#define GL_UNSIGNED_SHORT_5_6_5           0x8363
#define GL_UNSIGNED_SHORT_5_6_5_REV       0x8364
#define GL_UNSIGNED_SHORT_4_4_4_4_REV     0x8365
#define GL_UNSIGNED_SHORT_1_5_5_5_REV     0x8366
#define GL_UNSIGNED_INT_8_8_8_8_REV       0x8367
#define GL_UNSIGNED_INT_2_10_10_10_REV    0x8368
#define GL_BGR                            0x80E0
#define GL_BGRA                           0x80E1
#define GL_MAX_ELEMENTS_VERTICES          0x80E8
#define GL_MAX_ELEMENTS_INDICES           0x80E9
#define GL_CLAMP_TO_EDGE                  0x812F
#define GL_TEXTURE_MIN_LOD                0x813A
#define GL_TEXTURE_MAX_LOD                0x813B
#define GL_TEXTURE_BASE_LEVEL             0x813C
#define GL_TEXTURE_MAX_LEVEL              0x813D
#define GL_SMOOTH_POINT_SIZE_RANGE        0x0B12
#define GL_SMOOTH_POINT_SIZE_GRANULARITY  0x0B13
#define GL_SMOOTH_LINE_WIDTH_RANGE        0x0B22
#define GL_SMOOTH_LINE_WIDTH_GRANULARITY  0x0B23
#define GL_ALIASED_LINE_WIDTH_RANGE       0x846E

#define OPENGL_FUNCTIONS_1_2 \
   GL_FUNC(void, glDrawRangeElements, GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const void *indices) \
   GL_FUNC(void, glTexImage3D, GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLenum format, GLenum type, const void *pixels) \
   GL_FUNC(void, glTexSubImage3D, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void *pixels) \
   GL_FUNC(void, glCopyTexSubImage3D, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height) 

#endif /* GL_VERSION_1_2 */

#ifndef GL_VERSION_1_3
#define GL_VERSION_1_3 1
#define GL_TEXTURE0                       0x84C0
#define GL_TEXTURE1                       0x84C1
#define GL_TEXTURE2                       0x84C2
#define GL_TEXTURE3                       0x84C3
#define GL_TEXTURE4                       0x84C4
#define GL_TEXTURE5                       0x84C5
#define GL_TEXTURE6                       0x84C6
#define GL_TEXTURE7                       0x84C7
#define GL_TEXTURE8                       0x84C8
#define GL_TEXTURE9                       0x84C9
#define GL_TEXTURE10                      0x84CA
#define GL_TEXTURE11                      0x84CB
#define GL_TEXTURE12                      0x84CC
#define GL_TEXTURE13                      0x84CD
#define GL_TEXTURE14                      0x84CE
#define GL_TEXTURE15                      0x84CF
#define GL_TEXTURE16                      0x84D0
#define GL_TEXTURE17                      0x84D1
#define GL_TEXTURE18                      0x84D2
#define GL_TEXTURE19                      0x84D3
#define GL_TEXTURE20                      0x84D4
#define GL_TEXTURE21                      0x84D5
#define GL_TEXTURE22                      0x84D6
#define GL_TEXTURE23                      0x84D7
#define GL_TEXTURE24                      0x84D8
#define GL_TEXTURE25                      0x84D9
#define GL_TEXTURE26                      0x84DA
#define GL_TEXTURE27                      0x84DB
#define GL_TEXTURE28                      0x84DC
#define GL_TEXTURE29                      0x84DD
#define GL_TEXTURE30                      0x84DE
#define GL_TEXTURE31                      0x84DF
#define GL_ACTIVE_TEXTURE                 0x84E0
#define GL_MULTISAMPLE                    0x809D
#define GL_SAMPLE_ALPHA_TO_COVERAGE       0x809E
#define GL_SAMPLE_ALPHA_TO_ONE            0x809F
#define GL_SAMPLE_COVERAGE                0x80A0
#define GL_SAMPLE_BUFFERS                 0x80A8
#define GL_SAMPLES                        0x80A9
#define GL_SAMPLE_COVERAGE_VALUE          0x80AA
#define GL_SAMPLE_COVERAGE_INVERT         0x80AB
#define GL_TEXTURE_CUBE_MAP               0x8513
#define GL_TEXTURE_BINDING_CUBE_MAP       0x8514
#define GL_TEXTURE_CUBE_MAP_POSITIVE_X    0x8515
#define GL_TEXTURE_CUBE_MAP_NEGATIVE_X    0x8516
#define GL_TEXTURE_CUBE_MAP_POSITIVE_Y    0x8517
#define GL_TEXTURE_CUBE_MAP_NEGATIVE_Y    0x8518
#define GL_TEXTURE_CUBE_MAP_POSITIVE_Z    0x8519
#define GL_TEXTURE_CUBE_MAP_NEGATIVE_Z    0x851A
#define GL_PROXY_TEXTURE_CUBE_MAP         0x851B
#define GL_MAX_CUBE_MAP_TEXTURE_SIZE      0x851C
#define GL_COMPRESSED_RGB                 0x84ED
#define GL_COMPRESSED_RGBA                0x84EE
#define GL_TEXTURE_COMPRESSION_HINT       0x84EF
#define GL_TEXTURE_COMPRESSED_IMAGE_SIZE  0x86A0
#define GL_TEXTURE_COMPRESSED             0x86A1
#define GL_NUM_COMPRESSED_TEXTURE_FORMATS 0x86A2
#define GL_COMPRESSED_TEXTURE_FORMATS     0x86A3
#define GL_CLAMP_TO_BORDER                0x812D

#define OPENGL_FUNCTIONS_1_3 \
   GL_FUNC(void, glActiveTexture, GLenum texture) \
   GL_FUNC(void, glSampleCoverage, GLfloat value, GLboolean invert) \
   GL_FUNC(void, glCompressedTexImage3D, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLsizei imageSize, const void *data) \
   GL_FUNC(void, glCompressedTexImage2D, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const void *data) \
   GL_FUNC(void, glCompressedTexImage1D, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLint border, GLsizei imageSize, const void *data) \
   GL_FUNC(void, glCompressedTexSubImage3D, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const void *data) \
   GL_FUNC(void, glCompressedTexSubImage2D, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const void *data) \
   GL_FUNC(void, glCompressedTexSubImage1D, GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, const void *data) \
   GL_FUNC(void, glGetCompressedTexImage, GLenum target, GLint level, void *img) 

#endif /* GL_VERSION_1_3 */

#ifndef GL_VERSION_1_4
#define GL_VERSION_1_4 1
#define GL_BLEND_DST_RGB                  0x80C8
#define GL_BLEND_SRC_RGB                  0x80C9
#define GL_BLEND_DST_ALPHA                0x80CA
#define GL_BLEND_SRC_ALPHA                0x80CB
#define GL_POINT_FADE_THRESHOLD_SIZE      0x8128
#define GL_DEPTH_COMPONENT16              0x81A5
#define GL_DEPTH_COMPONENT24              0x81A6
#define GL_DEPTH_COMPONENT32              0x81A7
#define GL_MIRRORED_REPEAT                0x8370
#define GL_MAX_TEXTURE_LOD_BIAS           0x84FD
#define GL_TEXTURE_LOD_BIAS               0x8501
#define GL_INCR_WRAP                      0x8507
#define GL_DECR_WRAP                      0x8508
#define GL_TEXTURE_DEPTH_SIZE             0x884A
#define GL_TEXTURE_COMPARE_MODE           0x884C
#define GL_TEXTURE_COMPARE_FUNC           0x884D
#define GL_BLEND_COLOR                    0x8005
#define GL_BLEND_EQUATION                 0x8009
#define GL_CONSTANT_COLOR                 0x8001
#define GL_ONE_MINUS_CONSTANT_COLOR       0x8002
#define GL_CONSTANT_ALPHA                 0x8003
#define GL_ONE_MINUS_CONSTANT_ALPHA       0x8004
#define GL_FUNC_ADD                       0x8006
#define GL_FUNC_REVERSE_SUBTRACT          0x800B
#define GL_FUNC_SUBTRACT                  0x800A
#define GL_MIN                            0x8007
#define GL_MAX                            0x8008

#define OPENGL_FUNCTIONS_1_4 \
   GL_FUNC(void, glBlendFuncSeparate, GLenum sfactorRGB, GLenum dfactorRGB, GLenum sfactorAlpha, GLenum dfactorAlpha) \
   GL_FUNC(void, glMultiDrawArrays, GLenum mode, const GLint *first, const GLsizei *count, GLsizei drawcount) \
   GL_FUNC(void, glMultiDrawElements, GLenum mode, const GLsizei *count, GLenum type, const void *const*indices, GLsizei drawcount) \
   GL_FUNC(void, glPointParameterf, GLenum pname, GLfloat param) \
   GL_FUNC(void, glPointParameterfv, GLenum pname, const GLfloat *params) \
   GL_FUNC(void, glPointParameteri, GLenum pname, GLint param) \
   GL_FUNC(void, glPointParameteriv, GLenum pname, const GLint *params) \
   GL_FUNC(void, glBlendColor, GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha) \
   GL_FUNC(void, glBlendEquation, GLenum mode) 

#endif /* GL_VERSION_1_4 */

#ifndef GL_VERSION_1_5
#define GL_VERSION_1_5 1
typedef unsigned long long GLsizeiptr;
typedef long long GLintptr;
#define GL_BUFFER_SIZE                    0x8764
#define GL_BUFFER_USAGE                   0x8765
#define GL_QUERY_COUNTER_BITS             0x8864
#define GL_CURRENT_QUERY                  0x8865
#define GL_QUERY_RESULT                   0x8866
#define GL_QUERY_RESULT_AVAILABLE         0x8867
#define GL_ARRAY_BUFFER                   0x8892
#define GL_ELEMENT_ARRAY_BUFFER           0x8893
#define GL_ARRAY_BUFFER_BINDING           0x8894
#define GL_ELEMENT_ARRAY_BUFFER_BINDING   0x8895
#define GL_VERTEX_ATTRIB_ARRAY_BUFFER_BINDING 0x889F
#define GL_READ_ONLY                      0x88B8
#define GL_WRITE_ONLY                     0x88B9
#define GL_READ_WRITE                     0x88BA
#define GL_BUFFER_ACCESS                  0x88BB
#define GL_BUFFER_MAPPED                  0x88BC
#define GL_BUFFER_MAP_POINTER             0x88BD
#define GL_STREAM_DRAW                    0x88E0
#define GL_STREAM_READ                    0x88E1
#define GL_STREAM_COPY                    0x88E2
#define GL_STATIC_DRAW                    0x88E4
#define GL_STATIC_READ                    0x88E5
#define GL_STATIC_COPY                    0x88E6
#define GL_DYNAMIC_DRAW                   0x88E8
#define GL_DYNAMIC_READ                   0x88E9
#define GL_DYNAMIC_COPY                   0x88EA
#define GL_SAMPLES_PASSED                 0x8914
#define GL_SRC1_ALPHA                     0x8589

#define OPENGL_FUNCTIONS_1_5 \
   GL_FUNC(void, glGenQueries, GLsizei n, GLuint *ids) \
   GL_FUNC(void, glDeleteQueries, GLsizei n, const GLuint *ids) \
   GL_FUNC(GLboolean, glIsQuery, GLuint id) \
   GL_FUNC(void, glBeginQuery, GLenum target, GLuint id) \
   GL_FUNC(void, glEndQuery, GLenum target) \
   GL_FUNC(void, glGetQueryiv, GLenum target, GLenum pname, GLint *params) \
   GL_FUNC(void, glGetQueryObjectiv, GLuint id, GLenum pname, GLint *params) \
   GL_FUNC(void, glGetQueryObjectuiv, GLuint id, GLenum pname, GLuint *params) \
   GL_FUNC(void, glBindBuffer, GLenum target, GLuint buffer) \
   GL_FUNC(void, glDeleteBuffers, GLsizei n, const GLuint *buffers) \
   GL_FUNC(void, glGenBuffers, GLsizei n, GLuint *buffers) \
   GL_FUNC(GLboolean, glIsBuffer, GLuint buffer) \
   GL_FUNC(void, glBufferData, GLenum target, GLsizeiptr size, const void *data, GLenum usage) \
   GL_FUNC(void, glBufferSubData, GLenum target, GLintptr offset, GLsizeiptr size, const void *data) \
   GL_FUNC(void, glGetBufferSubData, GLenum target, GLintptr offset, GLsizeiptr size, void *data) \
   GL_FUNC(void *, glMapBuffer, GLenum target, GLenum access) \
   GL_FUNC(GLboolean, glUnmapBuffer, GLenum target) \
   GL_FUNC(void, glGetBufferParameteriv, GLenum target, GLenum pname, GLint *params) \
   GL_FUNC(void, glGetBufferPointerv, GLenum target, GLenum pname, void **params) 

#endif /* GL_VERSION_1_5 */

#ifndef GL_VERSION_2_0
#define GL_VERSION_2_0 1
typedef char GLchar;
typedef short GLshort;
typedef char GLbyte;
typedef unsigned short GLushort;
#define GL_BLEND_EQUATION_RGB             0x8009
#define GL_VERTEX_ATTRIB_ARRAY_ENABLED    0x8622
#define GL_VERTEX_ATTRIB_ARRAY_SIZE       0x8623
#define GL_VERTEX_ATTRIB_ARRAY_STRIDE     0x8624
#define GL_VERTEX_ATTRIB_ARRAY_TYPE       0x8625
#define GL_CURRENT_VERTEX_ATTRIB          0x8626
#define GL_VERTEX_PROGRAM_POINT_SIZE      0x8642
#define GL_VERTEX_ATTRIB_ARRAY_POINTER    0x8645
#define GL_STENCIL_BACK_FUNC              0x8800
#define GL_STENCIL_BACK_FAIL              0x8801
#define GL_STENCIL_BACK_PASS_DEPTH_FAIL   0x8802
#define GL_STENCIL_BACK_PASS_DEPTH_PASS   0x8803
#define GL_MAX_DRAW_BUFFERS               0x8824
#define GL_DRAW_BUFFER0                   0x8825
#define GL_DRAW_BUFFER1                   0x8826
#define GL_DRAW_BUFFER2                   0x8827
#define GL_DRAW_BUFFER3                   0x8828
#define GL_DRAW_BUFFER4                   0x8829
#define GL_DRAW_BUFFER5                   0x882A
#define GL_DRAW_BUFFER6                   0x882B
#define GL_DRAW_BUFFER7                   0x882C
#define GL_DRAW_BUFFER8                   0x882D
#define GL_DRAW_BUFFER9                   0x882E
#define GL_DRAW_BUFFER10                  0x882F
#define GL_DRAW_BUFFER11                  0x8830
#define GL_DRAW_BUFFER12                  0x8831
#define GL_DRAW_BUFFER13                  0x8832
#define GL_DRAW_BUFFER14                  0x8833
#define GL_DRAW_BUFFER15                  0x8834
#define GL_BLEND_EQUATION_ALPHA           0x883D
#define GL_MAX_VERTEX_ATTRIBS             0x8869
#define GL_VERTEX_ATTRIB_ARRAY_NORMALIZED 0x886A
#define GL_MAX_TEXTURE_IMAGE_UNITS        0x8872
#define GL_FRAGMENT_SHADER                0x8B30
#define GL_VERTEX_SHADER                  0x8B31
#define GL_MAX_FRAGMENT_UNIFORM_COMPONENTS 0x8B49
#define GL_MAX_VERTEX_UNIFORM_COMPONENTS  0x8B4A
#define GL_MAX_VARYING_FLOATS             0x8B4B
#define GL_MAX_VERTEX_TEXTURE_IMAGE_UNITS 0x8B4C
#define GL_MAX_COMBINED_TEXTURE_IMAGE_UNITS 0x8B4D
#define GL_SHADER_TYPE                    0x8B4F
#define GL_FLOAT_VEC2                     0x8B50
#define GL_FLOAT_VEC3                     0x8B51
#define GL_FLOAT_VEC4                     0x8B52
#define GL_INT_VEC2                       0x8B53
#define GL_INT_VEC3                       0x8B54
#define GL_INT_VEC4                       0x8B55
#define GL_BOOL                           0x8B56
#define GL_BOOL_VEC2                      0x8B57
#define GL_BOOL_VEC3                      0x8B58
#define GL_BOOL_VEC4                      0x8B59
#define GL_FLOAT_MAT2                     0x8B5A
#define GL_FLOAT_MAT3                     0x8B5B
#define GL_FLOAT_MAT4                     0x8B5C
#define GL_SAMPLER_1D                     0x8B5D
#define GL_SAMPLER_2D                     0x8B5E
#define GL_SAMPLER_3D                     0x8B5F
#define GL_SAMPLER_CUBE                   0x8B60
#define GL_SAMPLER_1D_SHADOW              0x8B61
#define GL_SAMPLER_2D_SHADOW              0x8B62
#define GL_DELETE_STATUS                  0x8B80
#define GL_COMPILE_STATUS                 0x8B81
#define GL_LINK_STATUS                    0x8B82
#define GL_VALIDATE_STATUS                0x8B83
#define GL_INFO_LOG_LENGTH                0x8B84
#define GL_ATTACHED_SHADERS               0x8B85
#define GL_ACTIVE_UNIFORMS                0x8B86
#define GL_ACTIVE_UNIFORM_MAX_LENGTH      0x8B87
#define GL_SHADER_SOURCE_LENGTH           0x8B88
#define GL_ACTIVE_ATTRIBUTES              0x8B89
#define GL_ACTIVE_ATTRIBUTE_MAX_LENGTH    0x8B8A
#define GL_FRAGMENT_SHADER_DERIVATIVE_HINT 0x8B8B
#define GL_SHADING_LANGUAGE_VERSION       0x8B8C
#define GL_CURRENT_PROGRAM                0x8B8D
#define GL_POINT_SPRITE_COORD_ORIGIN      0x8CA0
#define GL_LOWER_LEFT                     0x8CA1
#define GL_UPPER_LEFT                     0x8CA2
#define GL_STENCIL_BACK_REF               0x8CA3
#define GL_STENCIL_BACK_VALUE_MASK        0x8CA4
#define GL_STENCIL_BACK_WRITEMASK         0x8CA5

#define OPENGL_FUNCTIONS_2_0 \
   GL_FUNC(void, glBlendEquationSeparate, GLenum modeRGB, GLenum modeAlpha) \
   GL_FUNC(void, glDrawBuffers, GLsizei n, const GLenum *bufs) \
   GL_FUNC(void, glStencilOpSeparate, GLenum face, GLenum sfail, GLenum dpfail, GLenum dppass) \
   GL_FUNC(void, glStencilFuncSeparate, GLenum face, GLenum func, GLint ref, GLuint mask) \
   GL_FUNC(void, glStencilMaskSeparate, GLenum face, GLuint mask) \
   GL_FUNC(void, glAttachShader, GLuint program, GLuint shader) \
   GL_FUNC(void, glBindAttribLocation, GLuint program, GLuint index, const GLchar *name) \
   GL_FUNC(void, glCompileShader, GLuint shader) \
   GL_FUNC(GLuint, glCreateProgram, void) \
   GL_FUNC(GLuint, glCreateShader, GLenum type) \
   GL_FUNC(void, glDeleteProgram, GLuint program) \
   GL_FUNC(void, glDeleteShader, GLuint shader) \
   GL_FUNC(void, glDetachShader, GLuint program, GLuint shader) \
   GL_FUNC(void, glDisableVertexAttribArray, GLuint index) \
   GL_FUNC(void, glEnableVertexAttribArray, GLuint index) \
   GL_FUNC(void, glGetActiveAttrib, GLuint program, GLuint index, GLsizei bufSize, GLsizei *length, GLint *size, GLenum *type, GLchar *name) \
   GL_FUNC(void, glGetActiveUniform, GLuint program, GLuint index, GLsizei bufSize, GLsizei *length, GLint *size, GLenum *type, GLchar *name) \
   GL_FUNC(void, glGetAttachedShaders, GLuint program, GLsizei maxCount, GLsizei *count, GLuint *shaders) \
   GL_FUNC(GLint, glGetAttribLocation, GLuint program, const GLchar *name) \
   GL_FUNC(void, glGetProgramiv, GLuint program, GLenum pname, GLint *params) \
   GL_FUNC(void, glGetProgramInfoLog, GLuint program, GLsizei bufSize, GLsizei *length, GLchar *infoLog) \
   GL_FUNC(void, glGetShaderiv, GLuint shader, GLenum pname, GLint *params) \
   GL_FUNC(void, glGetShaderInfoLog, GLuint shader, GLsizei bufSize, GLsizei *length, GLchar *infoLog) \
   GL_FUNC(void, glGetShaderSource, GLuint shader, GLsizei bufSize, GLsizei *length, GLchar *source) \
   GL_FUNC(GLint, glGetUniformLocation, GLuint program, const GLchar *name) \
   GL_FUNC(void, glGetUniformfv, GLuint program, GLint location, GLfloat *params) \
   GL_FUNC(void, glGetUniformiv, GLuint program, GLint location, GLint *params) \
   GL_FUNC(void, glGetVertexAttribdv, GLuint index, GLenum pname, GLdouble *params) \
   GL_FUNC(void, glGetVertexAttribfv, GLuint index, GLenum pname, GLfloat *params) \
   GL_FUNC(void, glGetVertexAttribiv, GLuint index, GLenum pname, GLint *params) \
   GL_FUNC(void, glGetVertexAttribPointerv, GLuint index, GLenum pname, void **pointer) \
   GL_FUNC(GLboolean, glIsProgram, GLuint program) \
   GL_FUNC(GLboolean, glIsShader, GLuint shader) \
   GL_FUNC(void, glLinkProgram, GLuint program) \
   GL_FUNC(void, glShaderSource, GLuint shader, GLsizei count, const GLchar *const*string, const GLint *length) \
   GL_FUNC(void, glUseProgram, GLuint program) \
   GL_FUNC(void, glUniform1f, GLint location, GLfloat v0) \
   GL_FUNC(void, glUniform2f, GLint location, GLfloat v0, GLfloat v1) \
   GL_FUNC(void, glUniform3f, GLint location, GLfloat v0, GLfloat v1, GLfloat v2) \
   GL_FUNC(void, glUniform4f, GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3) \
   GL_FUNC(void, glUniform1i, GLint location, GLint v0) \
   GL_FUNC(void, glUniform2i, GLint location, GLint v0, GLint v1) \
   GL_FUNC(void, glUniform3i, GLint location, GLint v0, GLint v1, GLint v2) \
   GL_FUNC(void, glUniform4i, GLint location, GLint v0, GLint v1, GLint v2, GLint v3) \
   GL_FUNC(void, glUniform1fv, GLint location, GLsizei count, const GLfloat *value) \
   GL_FUNC(void, glUniform2fv, GLint location, GLsizei count, const GLfloat *value) \
   GL_FUNC(void, glUniform3fv, GLint location, GLsizei count, const GLfloat *value) \
   GL_FUNC(void, glUniform4fv, GLint location, GLsizei count, const GLfloat *value) \
   GL_FUNC(void, glUniform1iv, GLint location, GLsizei count, const GLint *value) \
   GL_FUNC(void, glUniform2iv, GLint location, GLsizei count, const GLint *value) \
   GL_FUNC(void, glUniform3iv, GLint location, GLsizei count, const GLint *value) \
   GL_FUNC(void, glUniform4iv, GLint location, GLsizei count, const GLint *value) \
   GL_FUNC(void, glUniformMatrix2fv, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) \
   GL_FUNC(void, glUniformMatrix3fv, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) \
   GL_FUNC(void, glUniformMatrix4fv, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) \
   GL_FUNC(void, glValidateProgram, GLuint program) \
   GL_FUNC(void, glVertexAttrib1d, GLuint index, GLdouble x) \
   GL_FUNC(void, glVertexAttrib1dv, GLuint index, const GLdouble *v) \
   GL_FUNC(void, glVertexAttrib1f, GLuint index, GLfloat x) \
   GL_FUNC(void, glVertexAttrib1fv, GLuint index, const GLfloat *v) \
   GL_FUNC(void, glVertexAttrib1s, GLuint index, GLshort x) \
   GL_FUNC(void, glVertexAttrib1sv, GLuint index, const GLshort *v) \
   GL_FUNC(void, glVertexAttrib2d, GLuint index, GLdouble x, GLdouble y) \
   GL_FUNC(void, glVertexAttrib2dv, GLuint index, const GLdouble *v) \
   GL_FUNC(void, glVertexAttrib2f, GLuint index, GLfloat x, GLfloat y) \
   GL_FUNC(void, glVertexAttrib2fv, GLuint index, const GLfloat *v) \
   GL_FUNC(void, glVertexAttrib2s, GLuint index, GLshort x, GLshort y) \
   GL_FUNC(void, glVertexAttrib2sv, GLuint index, const GLshort *v) \
   GL_FUNC(void, glVertexAttrib3d, GLuint index, GLdouble x, GLdouble y, GLdouble z) \
   GL_FUNC(void, glVertexAttrib3dv, GLuint index, const GLdouble *v) \
   GL_FUNC(void, glVertexAttrib3f, GLuint index, GLfloat x, GLfloat y, GLfloat z) \
   GL_FUNC(void, glVertexAttrib3fv, GLuint index, const GLfloat *v) \
   GL_FUNC(void, glVertexAttrib3s, GLuint index, GLshort x, GLshort y, GLshort z) \
   GL_FUNC(void, glVertexAttrib3sv, GLuint index, const GLshort *v) \
   GL_FUNC(void, glVertexAttrib4Nbv, GLuint index, const GLbyte *v) \
   GL_FUNC(void, glVertexAttrib4Niv, GLuint index, const GLint *v) \
   GL_FUNC(void, glVertexAttrib4Nsv, GLuint index, const GLshort *v) \
   GL_FUNC(void, glVertexAttrib4Nub, GLuint index, GLubyte x, GLubyte y, GLubyte z, GLubyte w) \
   GL_FUNC(void, glVertexAttrib4Nubv, GLuint index, const GLubyte *v) \
   GL_FUNC(void, glVertexAttrib4Nuiv, GLuint index, const GLuint *v) \
   GL_FUNC(void, glVertexAttrib4Nusv, GLuint index, const GLushort *v) \
   GL_FUNC(void, glVertexAttrib4bv, GLuint index, const GLbyte *v) \
   GL_FUNC(void, glVertexAttrib4d, GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w) \
   GL_FUNC(void, glVertexAttrib4dv, GLuint index, const GLdouble *v) \
   GL_FUNC(void, glVertexAttrib4f, GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w) \
   GL_FUNC(void, glVertexAttrib4fv, GLuint index, const GLfloat *v) \
   GL_FUNC(void, glVertexAttrib4iv, GLuint index, const GLint *v) \
   GL_FUNC(void, glVertexAttrib4s, GLuint index, GLshort x, GLshort y, GLshort z, GLshort w) \
   GL_FUNC(void, glVertexAttrib4sv, GLuint index, const GLshort *v) \
   GL_FUNC(void, glVertexAttrib4ubv, GLuint index, const GLubyte *v) \
   GL_FUNC(void, glVertexAttrib4uiv, GLuint index, const GLuint *v) \
   GL_FUNC(void, glVertexAttrib4usv, GLuint index, const GLushort *v) \
   GL_FUNC(void, glVertexAttribPointer, GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const void *pointer)

#endif /* GL_VERSION_2_0 */

#ifndef GL_VERSION_2_1
#define GL_VERSION_2_1 1
#define GL_PIXEL_PACK_BUFFER              0x88EB
#define GL_PIXEL_UNPACK_BUFFER            0x88EC
#define GL_PIXEL_PACK_BUFFER_BINDING      0x88ED
#define GL_PIXEL_UNPACK_BUFFER_BINDING    0x88EF
#define GL_FLOAT_MAT2x3                   0x8B65
#define GL_FLOAT_MAT2x4                   0x8B66
#define GL_FLOAT_MAT3x2                   0x8B67
#define GL_FLOAT_MAT3x4                   0x8B68
#define GL_FLOAT_MAT4x2                   0x8B69
#define GL_FLOAT_MAT4x3                   0x8B6A
#define GL_SRGB                           0x8C40
#define GL_SRGB8                          0x8C41
#define GL_SRGB_ALPHA                     0x8C42
#define GL_SRGB8_ALPHA8                   0x8C43
#define GL_COMPRESSED_SRGB                0x8C48
#define GL_COMPRESSED_SRGB_ALPHA          0x8C49

#define OPENGL_FUNCTIONS_2_1 \
   GL_FUNC(void, glUniformMatrix2x3fv, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) \
   GL_FUNC(void, glUniformMatrix3x2fv, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) \
   GL_FUNC(void, glUniformMatrix2x4fv, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) \
   GL_FUNC(void, glUniformMatrix4x2fv, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) \
   GL_FUNC(void, glUniformMatrix3x4fv, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) \
   GL_FUNC(void, glUniformMatrix4x3fv, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value)

#endif /* GL_VERSION_2_1 */

#ifndef GL_VERSION_3_0
#define GL_VERSION_3_0 1
typedef unsigned short GLhalf;
#define GL_COMPARE_REF_TO_TEXTURE         0x884E
#define GL_CLIP_DISTANCE0                 0x3000
#define GL_CLIP_DISTANCE1                 0x3001
#define GL_CLIP_DISTANCE2                 0x3002
#define GL_CLIP_DISTANCE3                 0x3003
#define GL_CLIP_DISTANCE4                 0x3004
#define GL_CLIP_DISTANCE5                 0x3005
#define GL_CLIP_DISTANCE6                 0x3006
#define GL_CLIP_DISTANCE7                 0x3007
#define GL_MAX_CLIP_DISTANCES             0x0D32
#define GL_MAJOR_VERSION                  0x821B
#define GL_MINOR_VERSION                  0x821C
#define GL_NUM_EXTENSIONS                 0x821D
#define GL_CONTEXT_FLAGS                  0x821E
#define GL_COMPRESSED_RED                 0x8225
#define GL_COMPRESSED_RG                  0x8226
#define GL_CONTEXT_FLAG_FORWARD_COMPATIBLE_BIT 0x00000001
#define GL_RGBA32F                        0x8814
#define GL_RGB32F                         0x8815
#define GL_RGBA16F                        0x881A
#define GL_RGB16F                         0x881B
#define GL_VERTEX_ATTRIB_ARRAY_INTEGER    0x88FD
#define GL_MAX_ARRAY_TEXTURE_LAYERS       0x88FF
#define GL_MIN_PROGRAM_TEXEL_OFFSET       0x8904
#define GL_MAX_PROGRAM_TEXEL_OFFSET       0x8905
#define GL_CLAMP_READ_COLOR               0x891C
#define GL_FIXED_ONLY                     0x891D
#define GL_MAX_VARYING_COMPONENTS         0x8B4B
#define GL_TEXTURE_1D_ARRAY               0x8C18
#define GL_PROXY_TEXTURE_1D_ARRAY         0x8C19
#define GL_TEXTURE_2D_ARRAY               0x8C1A
#define GL_PROXY_TEXTURE_2D_ARRAY         0x8C1B
#define GL_TEXTURE_BINDING_1D_ARRAY       0x8C1C
#define GL_TEXTURE_BINDING_2D_ARRAY       0x8C1D
#define GL_R11F_G11F_B10F                 0x8C3A
#define GL_UNSIGNED_INT_10F_11F_11F_REV   0x8C3B
#define GL_RGB9_E5                        0x8C3D
#define GL_UNSIGNED_INT_5_9_9_9_REV       0x8C3E
#define GL_TEXTURE_SHARED_SIZE            0x8C3F
#define GL_TRANSFORM_FEEDBACK_VARYING_MAX_LENGTH 0x8C76
#define GL_TRANSFORM_FEEDBACK_BUFFER_MODE 0x8C7F
#define GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_COMPONENTS 0x8C80
#define GL_TRANSFORM_FEEDBACK_VARYINGS    0x8C83
#define GL_TRANSFORM_FEEDBACK_BUFFER_START 0x8C84
#define GL_TRANSFORM_FEEDBACK_BUFFER_SIZE 0x8C85
#define GL_PRIMITIVES_GENERATED           0x8C87
#define GL_TRANSFORM_FEEDBACK_PRIMITIVES_WRITTEN 0x8C88
#define GL_RASTERIZER_DISCARD             0x8C89
#define GL_MAX_TRANSFORM_FEEDBACK_INTERLEAVED_COMPONENTS 0x8C8A
#define GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_ATTRIBS 0x8C8B
#define GL_INTERLEAVED_ATTRIBS            0x8C8C
#define GL_SEPARATE_ATTRIBS               0x8C8D
#define GL_TRANSFORM_FEEDBACK_BUFFER      0x8C8E
#define GL_TRANSFORM_FEEDBACK_BUFFER_BINDING 0x8C8F
#define GL_RGBA32UI                       0x8D70
#define GL_RGB32UI                        0x8D71
#define GL_RGBA16UI                       0x8D76
#define GL_RGB16UI                        0x8D77
#define GL_RGBA8UI                        0x8D7C
#define GL_RGB8UI                         0x8D7D
#define GL_RGBA32I                        0x8D82
#define GL_RGB32I                         0x8D83
#define GL_RGBA16I                        0x8D88
#define GL_RGB16I                         0x8D89
#define GL_RGBA8I                         0x8D8E
#define GL_RGB8I                          0x8D8F
#define GL_RED_INTEGER                    0x8D94
#define GL_GREEN_INTEGER                  0x8D95
#define GL_BLUE_INTEGER                   0x8D96
#define GL_RGB_INTEGER                    0x8D98
#define GL_RGBA_INTEGER                   0x8D99
#define GL_BGR_INTEGER                    0x8D9A
#define GL_BGRA_INTEGER                   0x8D9B
#define GL_SAMPLER_1D_ARRAY               0x8DC0
#define GL_SAMPLER_2D_ARRAY               0x8DC1
#define GL_SAMPLER_1D_ARRAY_SHADOW        0x8DC3
#define GL_SAMPLER_2D_ARRAY_SHADOW        0x8DC4
#define GL_SAMPLER_CUBE_SHADOW            0x8DC5
#define GL_UNSIGNED_INT_VEC2              0x8DC6
#define GL_UNSIGNED_INT_VEC3              0x8DC7
#define GL_UNSIGNED_INT_VEC4              0x8DC8
#define GL_INT_SAMPLER_1D                 0x8DC9
#define GL_INT_SAMPLER_2D                 0x8DCA
#define GL_INT_SAMPLER_3D                 0x8DCB
#define GL_INT_SAMPLER_CUBE               0x8DCC
#define GL_INT_SAMPLER_1D_ARRAY           0x8DCE
#define GL_INT_SAMPLER_2D_ARRAY           0x8DCF
#define GL_UNSIGNED_INT_SAMPLER_1D        0x8DD1
#define GL_UNSIGNED_INT_SAMPLER_2D        0x8DD2
#define GL_UNSIGNED_INT_SAMPLER_3D        0x8DD3
#define GL_UNSIGNED_INT_SAMPLER_CUBE      0x8DD4
#define GL_UNSIGNED_INT_SAMPLER_1D_ARRAY  0x8DD6
#define GL_UNSIGNED_INT_SAMPLER_2D_ARRAY  0x8DD7
#define GL_QUERY_WAIT                     0x8E13
#define GL_QUERY_NO_WAIT                  0x8E14
#define GL_QUERY_BY_REGION_WAIT           0x8E15
#define GL_QUERY_BY_REGION_NO_WAIT        0x8E16
#define GL_BUFFER_ACCESS_FLAGS            0x911F
#define GL_BUFFER_MAP_LENGTH              0x9120
#define GL_BUFFER_MAP_OFFSET              0x9121
#define GL_DEPTH_COMPONENT32F             0x8CAC
#define GL_DEPTH32F_STENCIL8              0x8CAD
#define GL_FLOAT_32_UNSIGNED_INT_24_8_REV 0x8DAD
#define GL_INVALID_FRAMEBUFFER_OPERATION  0x0506
#define GL_FRAMEBUFFER_ATTACHMENT_COLOR_ENCODING 0x8210
#define GL_FRAMEBUFFER_ATTACHMENT_COMPONENT_TYPE 0x8211
#define GL_FRAMEBUFFER_ATTACHMENT_RED_SIZE 0x8212
#define GL_FRAMEBUFFER_ATTACHMENT_GREEN_SIZE 0x8213
#define GL_FRAMEBUFFER_ATTACHMENT_BLUE_SIZE 0x8214
#define GL_FRAMEBUFFER_ATTACHMENT_ALPHA_SIZE 0x8215
#define GL_FRAMEBUFFER_ATTACHMENT_DEPTH_SIZE 0x8216
#define GL_FRAMEBUFFER_ATTACHMENT_STENCIL_SIZE 0x8217
#define GL_FRAMEBUFFER_DEFAULT            0x8218
#define GL_FRAMEBUFFER_UNDEFINED          0x8219
#define GL_DEPTH_STENCIL_ATTACHMENT       0x821A
#define GL_MAX_RENDERBUFFER_SIZE          0x84E8
#define GL_DEPTH_STENCIL                  0x84F9
#define GL_UNSIGNED_INT_24_8              0x84FA
#define GL_DEPTH24_STENCIL8               0x88F0
#define GL_TEXTURE_STENCIL_SIZE           0x88F1
#define GL_TEXTURE_RED_TYPE               0x8C10
#define GL_TEXTURE_GREEN_TYPE             0x8C11
#define GL_TEXTURE_BLUE_TYPE              0x8C12
#define GL_TEXTURE_ALPHA_TYPE             0x8C13
#define GL_TEXTURE_DEPTH_TYPE             0x8C16
#define GL_UNSIGNED_NORMALIZED            0x8C17
#define GL_FRAMEBUFFER_BINDING            0x8CA6
#define GL_DRAW_FRAMEBUFFER_BINDING       0x8CA6
#define GL_RENDERBUFFER_BINDING           0x8CA7
#define GL_READ_FRAMEBUFFER               0x8CA8
#define GL_DRAW_FRAMEBUFFER               0x8CA9
#define GL_READ_FRAMEBUFFER_BINDING       0x8CAA
#define GL_RENDERBUFFER_SAMPLES           0x8CAB
#define GL_FRAMEBUFFER_ATTACHMENT_OBJECT_TYPE 0x8CD0
#define GL_FRAMEBUFFER_ATTACHMENT_OBJECT_NAME 0x8CD1
#define GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_LEVEL 0x8CD2
#define GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_CUBE_MAP_FACE 0x8CD3
#define GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_LAYER 0x8CD4
#define GL_FRAMEBUFFER_COMPLETE           0x8CD5
#define GL_FRAMEBUFFER_INCOMPLETE_ATTACHMENT 0x8CD6
#define GL_FRAMEBUFFER_INCOMPLETE_MISSING_ATTACHMENT 0x8CD7
#define GL_FRAMEBUFFER_INCOMPLETE_DRAW_BUFFER 0x8CDB
#define GL_FRAMEBUFFER_INCOMPLETE_READ_BUFFER 0x8CDC
#define GL_FRAMEBUFFER_UNSUPPORTED        0x8CDD
#define GL_MAX_COLOR_ATTACHMENTS          0x8CDF
#define GL_COLOR_ATTACHMENT0              0x8CE0
#define GL_COLOR_ATTACHMENT1              0x8CE1
#define GL_COLOR_ATTACHMENT2              0x8CE2
#define GL_COLOR_ATTACHMENT3              0x8CE3
#define GL_COLOR_ATTACHMENT4              0x8CE4
#define GL_COLOR_ATTACHMENT5              0x8CE5
#define GL_COLOR_ATTACHMENT6              0x8CE6
#define GL_COLOR_ATTACHMENT7              0x8CE7
#define GL_COLOR_ATTACHMENT8              0x8CE8
#define GL_COLOR_ATTACHMENT9              0x8CE9
#define GL_COLOR_ATTACHMENT10             0x8CEA
#define GL_COLOR_ATTACHMENT11             0x8CEB
#define GL_COLOR_ATTACHMENT12             0x8CEC
#define GL_COLOR_ATTACHMENT13             0x8CED
#define GL_COLOR_ATTACHMENT14             0x8CEE
#define GL_COLOR_ATTACHMENT15             0x8CEF
#define GL_COLOR_ATTACHMENT16             0x8CF0
#define GL_COLOR_ATTACHMENT17             0x8CF1
#define GL_COLOR_ATTACHMENT18             0x8CF2
#define GL_COLOR_ATTACHMENT19             0x8CF3
#define GL_COLOR_ATTACHMENT20             0x8CF4
#define GL_COLOR_ATTACHMENT21             0x8CF5
#define GL_COLOR_ATTACHMENT22             0x8CF6
#define GL_COLOR_ATTACHMENT23             0x8CF7
#define GL_COLOR_ATTACHMENT24             0x8CF8
#define GL_COLOR_ATTACHMENT25             0x8CF9
#define GL_COLOR_ATTACHMENT26             0x8CFA
#define GL_COLOR_ATTACHMENT27             0x8CFB
#define GL_COLOR_ATTACHMENT28             0x8CFC
#define GL_COLOR_ATTACHMENT29             0x8CFD
#define GL_COLOR_ATTACHMENT30             0x8CFE
#define GL_COLOR_ATTACHMENT31             0x8CFF
#define GL_DEPTH_ATTACHMENT               0x8D00
#define GL_STENCIL_ATTACHMENT             0x8D20
#define GL_FRAMEBUFFER                    0x8D40
#define GL_RENDERBUFFER                   0x8D41
#define GL_RENDERBUFFER_WIDTH             0x8D42
#define GL_RENDERBUFFER_HEIGHT            0x8D43
#define GL_RENDERBUFFER_INTERNAL_FORMAT   0x8D44
#define GL_STENCIL_INDEX1                 0x8D46
#define GL_STENCIL_INDEX4                 0x8D47
#define GL_STENCIL_INDEX8                 0x8D48
#define GL_STENCIL_INDEX16                0x8D49
#define GL_RENDERBUFFER_RED_SIZE          0x8D50
#define GL_RENDERBUFFER_GREEN_SIZE        0x8D51
#define GL_RENDERBUFFER_BLUE_SIZE         0x8D52
#define GL_RENDERBUFFER_ALPHA_SIZE        0x8D53
#define GL_RENDERBUFFER_DEPTH_SIZE        0x8D54
#define GL_RENDERBUFFER_STENCIL_SIZE      0x8D55
#define GL_FRAMEBUFFER_INCOMPLETE_MULTISAMPLE 0x8D56
#define GL_MAX_SAMPLES                    0x8D57
#define GL_FRAMEBUFFER_SRGB               0x8DB9
#define GL_HALF_FLOAT                     0x140B
#define GL_MAP_READ_BIT                   0x0001
#define GL_MAP_WRITE_BIT                  0x0002
#define GL_MAP_INVALIDATE_RANGE_BIT       0x0004
#define GL_MAP_INVALIDATE_BUFFER_BIT      0x0008
#define GL_MAP_FLUSH_EXPLICIT_BIT         0x0010
#define GL_MAP_UNSYNCHRONIZED_BIT         0x0020
#define GL_COMPRESSED_RED_RGTC1           0x8DBB
#define GL_COMPRESSED_SIGNED_RED_RGTC1    0x8DBC
#define GL_COMPRESSED_RG_RGTC2            0x8DBD
#define GL_COMPRESSED_SIGNED_RG_RGTC2     0x8DBE
#define GL_RG                             0x8227
#define GL_RG_INTEGER                     0x8228
#define GL_R8                             0x8229
#define GL_R16                            0x822A
#define GL_RG8                            0x822B
#define GL_RG16                           0x822C
#define GL_R16F                           0x822D
#define GL_R32F                           0x822E
#define GL_RG16F                          0x822F
#define GL_RG32F                          0x8230
#define GL_R8I                            0x8231
#define GL_R8UI                           0x8232
#define GL_R16I                           0x8233
#define GL_R16UI                          0x8234
#define GL_R32I                           0x8235
#define GL_R32UI                          0x8236
#define GL_RG8I                           0x8237
#define GL_RG8UI                          0x8238
#define GL_RG16I                          0x8239
#define GL_RG16UI                         0x823A
#define GL_RG32I                          0x823B
#define GL_RG32UI                         0x823C
#define GL_VERTEX_ARRAY_BINDING           0x85B5

#define OPENGL_FUNCTIONS_3_0 \
   GL_FUNC(void, glColorMaski, GLuint index, GLboolean r, GLboolean g, GLboolean b, GLboolean a) \
   GL_FUNC(void, glGetBooleani_v, GLenum target, GLuint index, GLboolean *data) \
   GL_FUNC(void, glGetIntegeri_v, GLenum target, GLuint index, GLint *data) \
   GL_FUNC(void, glEnablei, GLenum target, GLuint index) \
   GL_FUNC(void, glDisablei, GLenum target, GLuint index) \
   GL_FUNC(GLboolean, glIsEnabledi, GLenum target, GLuint index) \
   GL_FUNC(void, glBeginTransformFeedback, GLenum primitiveMode) \
   GL_FUNC(void, glEndTransformFeedback, void) \
   GL_FUNC(void, glBindBufferRange, GLenum target, GLuint index, GLuint buffer, GLintptr offset, GLsizeiptr size) \
   GL_FUNC(void, glBindBufferBase, GLenum target, GLuint index, GLuint buffer) \
   GL_FUNC(void, glTransformFeedbackVaryings, GLuint program, GLsizei count, const GLchar *const*varyings, GLenum bufferMode) \
   GL_FUNC(void, glGetTransformFeedbackVarying, GLuint program, GLuint index, GLsizei bufSize, GLsizei *length, GLsizei *size, GLenum *type, GLchar *name) \
   GL_FUNC(void, glClampColor, GLenum target, GLenum clamp) \
   GL_FUNC(void, glBeginConditionalRender, GLuint id, GLenum mode) \
   GL_FUNC(void, glEndConditionalRender, void) \
   GL_FUNC(void, glVertexAttribIPointer, GLuint index, GLint size, GLenum type, GLsizei stride, const void *pointer) \
   GL_FUNC(void, glGetVertexAttribIiv, GLuint index, GLenum pname, GLint *params) \
   GL_FUNC(void, glGetVertexAttribIuiv, GLuint index, GLenum pname, GLuint *params) \
   GL_FUNC(void, glVertexAttribI1i, GLuint index, GLint x) \
   GL_FUNC(void, glVertexAttribI2i, GLuint index, GLint x, GLint y) \
   GL_FUNC(void, glVertexAttribI3i, GLuint index, GLint x, GLint y, GLint z) \
   GL_FUNC(void, glVertexAttribI4i, GLuint index, GLint x, GLint y, GLint z, GLint w) \
   GL_FUNC(void, glVertexAttribI1ui, GLuint index, GLuint x) \
   GL_FUNC(void, glVertexAttribI2ui, GLuint index, GLuint x, GLuint y) \
   GL_FUNC(void, glVertexAttribI3ui, GLuint index, GLuint x, GLuint y, GLuint z) \
   GL_FUNC(void, glVertexAttribI4ui, GLuint index, GLuint x, GLuint y, GLuint z, GLuint w) \
   GL_FUNC(void, glVertexAttribI1iv, GLuint index, const GLint *v) \
   GL_FUNC(void, glVertexAttribI2iv, GLuint index, const GLint *v) \
   GL_FUNC(void, glVertexAttribI3iv, GLuint index, const GLint *v) \
   GL_FUNC(void, glVertexAttribI4iv, GLuint index, const GLint *v) \
   GL_FUNC(void, glVertexAttribI1uiv, GLuint index, const GLuint *v) \
   GL_FUNC(void, glVertexAttribI2uiv, GLuint index, const GLuint *v) \
   GL_FUNC(void, glVertexAttribI3uiv, GLuint index, const GLuint *v) \
   GL_FUNC(void, glVertexAttribI4uiv, GLuint index, const GLuint *v) \
   GL_FUNC(void, glVertexAttribI4bv, GLuint index, const GLbyte *v) \
   GL_FUNC(void, glVertexAttribI4sv, GLuint index, const GLshort *v) \
   GL_FUNC(void, glVertexAttribI4ubv, GLuint index, const GLubyte *v) \
   GL_FUNC(void, glVertexAttribI4usv, GLuint index, const GLushort *v) \
   GL_FUNC(void, glGetUniformuiv, GLuint program, GLint location, GLuint *params) \
   GL_FUNC(void, glBindFragDataLocation, GLuint program, GLuint color, const GLchar *name) \
   GL_FUNC(GLint, glGetFragDataLocation, GLuint program, const GLchar *name) \
   GL_FUNC(void, glUniform1ui, GLint location, GLuint v0) \
   GL_FUNC(void, glUniform2ui, GLint location, GLuint v0, GLuint v1) \
   GL_FUNC(void, glUniform3ui, GLint location, GLuint v0, GLuint v1, GLuint v2) \
   GL_FUNC(void, glUniform4ui, GLint location, GLuint v0, GLuint v1, GLuint v2, GLuint v3) \
   GL_FUNC(void, glUniform1uiv, GLint location, GLsizei count, const GLuint *value) \
   GL_FUNC(void, glUniform2uiv, GLint location, GLsizei count, const GLuint *value) \
   GL_FUNC(void, glUniform3uiv, GLint location, GLsizei count, const GLuint *value) \
   GL_FUNC(void, glUniform4uiv, GLint location, GLsizei count, const GLuint *value) \
   GL_FUNC(void, glTexParameterIiv, GLenum target, GLenum pname, const GLint *params) \
   GL_FUNC(void, glTexParameterIuiv, GLenum target, GLenum pname, const GLuint *params) \
   GL_FUNC(void, glGetTexParameterIiv, GLenum target, GLenum pname, GLint *params) \
   GL_FUNC(void, glGetTexParameterIuiv, GLenum target, GLenum pname, GLuint *params) \
   GL_FUNC(void, glClearBufferiv, GLenum buffer, GLint drawbuffer, const GLint *value) \
   GL_FUNC(void, glClearBufferuiv, GLenum buffer, GLint drawbuffer, const GLuint *value) \
   GL_FUNC(void, glClearBufferfv, GLenum buffer, GLint drawbuffer, const GLfloat *value) \
   GL_FUNC(void, glClearBufferfi, GLenum buffer, GLint drawbuffer, GLfloat depth, GLint stencil) \
   GL_FUNC(const GLubyte *, glGetStringi, GLenum name, GLuint index) \
   GL_FUNC(GLboolean, glIsRenderbuffer, GLuint renderbuffer) \
   GL_FUNC(void, glBindRenderbuffer, GLenum target, GLuint renderbuffer) \
   GL_FUNC(void, glDeleteRenderbuffers, GLsizei n, const GLuint *renderbuffers) \
   GL_FUNC(void, glGenRenderbuffers, GLsizei n, GLuint *renderbuffers) \
   GL_FUNC(void, glRenderbufferStorage, GLenum target, GLenum internalformat, GLsizei width, GLsizei height) \
   GL_FUNC(void, glGetRenderbufferParameteriv, GLenum target, GLenum pname, GLint *params) \
   GL_FUNC(GLboolean, glIsFramebuffer, GLuint framebuffer) \
   GL_FUNC(void, glBindFramebuffer, GLenum target, GLuint framebuffer) \
   GL_FUNC(void, glDeleteFramebuffers, GLsizei n, const GLuint *framebuffers) \
   GL_FUNC(void, glGenFramebuffers, GLsizei n, GLuint *framebuffers) \
   GL_FUNC(GLenum, glCheckFramebufferStatus, GLenum target) \
   GL_FUNC(void, glFramebufferTexture1D, GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level) \
   GL_FUNC(void, glFramebufferTexture2D, GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level) \
   GL_FUNC(void, glFramebufferTexture3D, GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level, GLint zoffset) \
   GL_FUNC(void, glFramebufferRenderbuffer, GLenum target, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer) \
   GL_FUNC(void, glGetFramebufferAttachmentParameteriv, GLenum target, GLenum attachment, GLenum pname, GLint *params) \
   GL_FUNC(void, glGenerateMipmap, GLenum target) \
   GL_FUNC(void, glBlitFramebuffer, GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter) \
   GL_FUNC(void, glRenderbufferStorageMultisample, GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height) \
   GL_FUNC(void, glFramebufferTextureLayer, GLenum target, GLenum attachment, GLuint texture, GLint level, GLint layer) \
   GL_FUNC(void *, glMapBufferRange, GLenum target, GLintptr offset, GLsizeiptr length, GLbitfield access) \
   GL_FUNC(void, glFlushMappedBufferRange, GLenum target, GLintptr offset, GLsizeiptr length) \
   GL_FUNC(void, glBindVertexArray, GLuint array) \
   GL_FUNC(void, glDeleteVertexArrays, GLsizei n, const GLuint *arrays) \
   GL_FUNC(void, glGenVertexArrays, GLsizei n, GLuint *arrays) \
   GL_FUNC(GLboolean, glIsVertexArray, GLuint array)    

#endif /* GL_VERSION_3_0 */

#ifndef GL_VERSION_3_1
#define GL_VERSION_3_1 1
#define GL_SAMPLER_2D_RECT                0x8B63
#define GL_SAMPLER_2D_RECT_SHADOW         0x8B64
#define GL_SAMPLER_BUFFER                 0x8DC2
#define GL_INT_SAMPLER_2D_RECT            0x8DCD
#define GL_INT_SAMPLER_BUFFER             0x8DD0
#define GL_UNSIGNED_INT_SAMPLER_2D_RECT   0x8DD5
#define GL_UNSIGNED_INT_SAMPLER_BUFFER    0x8DD8
#define GL_TEXTURE_BUFFER                 0x8C2A
#define GL_MAX_TEXTURE_BUFFER_SIZE        0x8C2B
#define GL_TEXTURE_BINDING_BUFFER         0x8C2C
#define GL_TEXTURE_BUFFER_DATA_STORE_BINDING 0x8C2D
#define GL_TEXTURE_RECTANGLE              0x84F5
#define GL_TEXTURE_BINDING_RECTANGLE      0x84F6
#define GL_PROXY_TEXTURE_RECTANGLE        0x84F7
#define GL_MAX_RECTANGLE_TEXTURE_SIZE     0x84F8
#define GL_R8_SNORM                       0x8F94
#define GL_RG8_SNORM                      0x8F95
#define GL_RGB8_SNORM                     0x8F96
#define GL_RGBA8_SNORM                    0x8F97
#define GL_R16_SNORM                      0x8F98
#define GL_RG16_SNORM                     0x8F99
#define GL_RGB16_SNORM                    0x8F9A
#define GL_RGBA16_SNORM                   0x8F9B
#define GL_SIGNED_NORMALIZED              0x8F9C
#define GL_PRIMITIVE_RESTART              0x8F9D
#define GL_PRIMITIVE_RESTART_INDEX        0x8F9E
#define GL_COPY_READ_BUFFER               0x8F36
#define GL_COPY_WRITE_BUFFER              0x8F37
#define GL_UNIFORM_BUFFER                 0x8A11
#define GL_UNIFORM_BUFFER_BINDING         0x8A28
#define GL_UNIFORM_BUFFER_START           0x8A29
#define GL_UNIFORM_BUFFER_SIZE            0x8A2A
#define GL_MAX_VERTEX_UNIFORM_BLOCKS      0x8A2B
#define GL_MAX_GEOMETRY_UNIFORM_BLOCKS    0x8A2C
#define GL_MAX_FRAGMENT_UNIFORM_BLOCKS    0x8A2D
#define GL_MAX_COMBINED_UNIFORM_BLOCKS    0x8A2E
#define GL_MAX_UNIFORM_BUFFER_BINDINGS    0x8A2F
#define GL_MAX_UNIFORM_BLOCK_SIZE         0x8A30
#define GL_MAX_COMBINED_VERTEX_UNIFORM_COMPONENTS 0x8A31
#define GL_MAX_COMBINED_GEOMETRY_UNIFORM_COMPONENTS 0x8A32
#define GL_MAX_COMBINED_FRAGMENT_UNIFORM_COMPONENTS 0x8A33
#define GL_UNIFORM_BUFFER_OFFSET_ALIGNMENT 0x8A34
#define GL_ACTIVE_UNIFORM_BLOCK_MAX_NAME_LENGTH 0x8A35
#define GL_ACTIVE_UNIFORM_BLOCKS          0x8A36
#define GL_UNIFORM_TYPE                   0x8A37
#define GL_UNIFORM_SIZE                   0x8A38
#define GL_UNIFORM_NAME_LENGTH            0x8A39
#define GL_UNIFORM_BLOCK_INDEX            0x8A3A
#define GL_UNIFORM_OFFSET                 0x8A3B
#define GL_UNIFORM_ARRAY_STRIDE           0x8A3C
#define GL_UNIFORM_MATRIX_STRIDE          0x8A3D
#define GL_UNIFORM_IS_ROW_MAJOR           0x8A3E
#define GL_UNIFORM_BLOCK_BINDING          0x8A3F
#define GL_UNIFORM_BLOCK_DATA_SIZE        0x8A40
#define GL_UNIFORM_BLOCK_NAME_LENGTH      0x8A41
#define GL_UNIFORM_BLOCK_ACTIVE_UNIFORMS  0x8A42
#define GL_UNIFORM_BLOCK_ACTIVE_UNIFORM_INDICES 0x8A43
#define GL_UNIFORM_BLOCK_REFERENCED_BY_VERTEX_SHADER 0x8A44
#define GL_UNIFORM_BLOCK_REFERENCED_BY_GEOMETRY_SHADER 0x8A45
#define GL_UNIFORM_BLOCK_REFERENCED_BY_FRAGMENT_SHADER 0x8A46
#define GL_INVALID_INDEX                  0xFFFFFFFFu

#define OPENGL_FUNCTIONS_3_1 \
   GL_FUNC(void, glDrawArraysInstanced, GLenum mode, GLint first, GLsizei count, GLsizei instancecount) \
   GL_FUNC(void, glDrawElementsInstanced, GLenum mode, GLsizei count, GLenum type, const void *indices, GLsizei instancecount) \
   GL_FUNC(void, glTexBuffer, GLenum target, GLenum internalformat, GLuint buffer) \
   GL_FUNC(void, glPrimitiveRestartIndex, GLuint index) \
   GL_FUNC(void, glCopyBufferSubData, GLenum readTarget, GLenum writeTarget, GLintptr readOffset, GLintptr writeOffset, GLsizeiptr size) \
   GL_FUNC(void, glGetUniformIndices, GLuint program, GLsizei uniformCount, const GLchar *const*uniformNames, GLuint *uniformIndices) \
   GL_FUNC(void, glGetActiveUniformsiv, GLuint program, GLsizei uniformCount, const GLuint *uniformIndices, GLenum pname, GLint *params) \
   GL_FUNC(void, glGetActiveUniformName, GLuint program, GLuint uniformIndex, GLsizei bufSize, GLsizei *length, GLchar *uniformName) \
   GL_FUNC(GLuint, glGetUniformBlockIndex, GLuint program, const GLchar *uniformBlockName) \
   GL_FUNC(void, glGetActiveUniformBlockiv, GLuint program, GLuint uniformBlockIndex, GLenum pname, GLint *params) \
   GL_FUNC(void, glGetActiveUniformBlockName, GLuint program, GLuint uniformBlockIndex, GLsizei bufSize, GLsizei *length, GLchar *uniformBlockName) \
   GL_FUNC(void, glUniformBlockBinding, GLuint program, GLuint uniformBlockIndex, GLuint uniformBlockBinding)

#endif /* GL_VERSION_3_1 */

#ifndef GL_VERSION_3_2
#define GL_VERSION_3_2 1
typedef struct __GLsync *GLsync;
typedef unsigned long long GLuint64;
typedef long long GLint64;
#define GL_CONTEXT_CORE_PROFILE_BIT       0x00000001
#define GL_CONTEXT_COMPATIBILITY_PROFILE_BIT 0x00000002
#define GL_LINES_ADJACENCY                0x000A
#define GL_LINE_STRIP_ADJACENCY           0x000B
#define GL_TRIANGLES_ADJACENCY            0x000C
#define GL_TRIANGLE_STRIP_ADJACENCY       0x000D
#define GL_PROGRAM_POINT_SIZE             0x8642
#define GL_MAX_GEOMETRY_TEXTURE_IMAGE_UNITS 0x8C29
#define GL_FRAMEBUFFER_ATTACHMENT_LAYERED 0x8DA7
#define GL_FRAMEBUFFER_INCOMPLETE_LAYER_TARGETS 0x8DA8
#define GL_GEOMETRY_SHADER                0x8DD9
#define GL_GEOMETRY_VERTICES_OUT          0x8916
#define GL_GEOMETRY_INPUT_TYPE            0x8917
#define GL_GEOMETRY_OUTPUT_TYPE           0x8918
#define GL_MAX_GEOMETRY_UNIFORM_COMPONENTS 0x8DDF
#define GL_MAX_GEOMETRY_OUTPUT_VERTICES   0x8DE0
#define GL_MAX_GEOMETRY_TOTAL_OUTPUT_COMPONENTS 0x8DE1
#define GL_MAX_VERTEX_OUTPUT_COMPONENTS   0x9122
#define GL_MAX_GEOMETRY_INPUT_COMPONENTS  0x9123
#define GL_MAX_GEOMETRY_OUTPUT_COMPONENTS 0x9124
#define GL_MAX_FRAGMENT_INPUT_COMPONENTS  0x9125
#define GL_CONTEXT_PROFILE_MASK           0x9126
#define GL_DEPTH_CLAMP                    0x864F
#define GL_QUADS_FOLLOW_PROVOKING_VERTEX_CONVENTION 0x8E4C
#define GL_FIRST_VERTEX_CONVENTION        0x8E4D
#define GL_LAST_VERTEX_CONVENTION         0x8E4E
#define GL_PROVOKING_VERTEX               0x8E4F
#define GL_TEXTURE_CUBE_MAP_SEAMLESS      0x884F
#define GL_MAX_SERVER_WAIT_TIMEOUT        0x9111
#define GL_OBJECT_TYPE                    0x9112
#define GL_SYNC_CONDITION                 0x9113
#define GL_SYNC_STATUS                    0x9114
#define GL_SYNC_FLAGS                     0x9115
#define GL_SYNC_FENCE                     0x9116
#define GL_SYNC_GPU_COMMANDS_COMPLETE     0x9117
#define GL_UNSIGNALED                     0x9118
#define GL_SIGNALED                       0x9119
#define GL_ALREADY_SIGNALED               0x911A
#define GL_TIMEOUT_EXPIRED                0x911B
#define GL_CONDITION_SATISFIED            0x911C
#define GL_WAIT_FAILED                    0x911D
#define GL_TIMEOUT_IGNORED                0xFFFFFFFFFFFFFFFFull
#define GL_SYNC_FLUSH_COMMANDS_BIT        0x00000001
#define GL_SAMPLE_POSITION                0x8E50
#define GL_SAMPLE_MASK                    0x8E51
#define GL_SAMPLE_MASK_VALUE              0x8E52
#define GL_MAX_SAMPLE_MASK_WORDS          0x8E59
#define GL_TEXTURE_2D_MULTISAMPLE         0x9100
#define GL_PROXY_TEXTURE_2D_MULTISAMPLE   0x9101
#define GL_TEXTURE_2D_MULTISAMPLE_ARRAY   0x9102
#define GL_PROXY_TEXTURE_2D_MULTISAMPLE_ARRAY 0x9103
#define GL_TEXTURE_BINDING_2D_MULTISAMPLE 0x9104
#define GL_TEXTURE_BINDING_2D_MULTISAMPLE_ARRAY 0x9105
#define GL_TEXTURE_SAMPLES                0x9106
#define GL_TEXTURE_FIXED_SAMPLE_LOCATIONS 0x9107
#define GL_SAMPLER_2D_MULTISAMPLE         0x9108
#define GL_INT_SAMPLER_2D_MULTISAMPLE     0x9109
#define GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE 0x910A
#define GL_SAMPLER_2D_MULTISAMPLE_ARRAY   0x910B
#define GL_INT_SAMPLER_2D_MULTISAMPLE_ARRAY 0x910C
#define GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE_ARRAY 0x910D
#define GL_MAX_COLOR_TEXTURE_SAMPLES      0x910E
#define GL_MAX_DEPTH_TEXTURE_SAMPLES      0x910F
#define GL_MAX_INTEGER_SAMPLES            0x9110

#define OPENGL_FUNCTIONS_3_2 \
   GL_FUNC(void, glDrawElementsBaseVertex, GLenum mode, GLsizei count, GLenum type, const void *indices, GLint basevertex) \
   GL_FUNC(void, glDrawRangeElementsBaseVertex, GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const void *indices, GLint basevertex) \
   GL_FUNC(void, glDrawElementsInstancedBaseVertex, GLenum mode, GLsizei count, GLenum type, const void *indices, GLsizei instancecount, GLint basevertex) \
   GL_FUNC(void, glMultiDrawElementsBaseVertex, GLenum mode, const GLsizei *count, GLenum type, const void *const*indices, GLsizei drawcount, const GLint *basevertex) \
   GL_FUNC(void, glProvokingVertex, GLenum mode) \
   GL_FUNC(GLsync, glFenceSync, GLenum condition, GLbitfield flags) \
   GL_FUNC(GLboolean, glIsSync, GLsync sync) \
   GL_FUNC(void, glDeleteSync, GLsync sync) \
   GL_FUNC(GLenum, glClientWaitSync, GLsync sync, GLbitfield flags, GLuint64 timeout) \
   GL_FUNC(void, glWaitSync, GLsync sync, GLbitfield flags, GLuint64 timeout) \
   GL_FUNC(void, glGetInteger64v, GLenum pname, GLint64 *data) \
   GL_FUNC(void, glGetSynciv, GLsync sync, GLenum pname, GLsizei count, GLsizei *length, GLint *values) \
   GL_FUNC(void, glGetInteger64i_v, GLenum target, GLuint index, GLint64 *data) \
   GL_FUNC(void, glGetBufferParameteri64v, GLenum target, GLenum pname, GLint64 *params) \
   GL_FUNC(void, glFramebufferTexture, GLenum target, GLenum attachment, GLuint texture, GLint level) \
   GL_FUNC(void, glTexImage2DMultisample, GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations) \
   GL_FUNC(void, glTexImage3DMultisample, GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations) \
   GL_FUNC(void, glGetMultisamplefv, GLenum pname, GLuint index, GLfloat *val) \
   GL_FUNC(void, glSampleMaski, GLuint maskNumber, GLbitfield mask) 

#endif /* GL_VERSION_3_2 */

#ifndef GL_VERSION_3_3
#define GL_VERSION_3_3 1
#define GL_VERTEX_ATTRIB_ARRAY_DIVISOR    0x88FE
#define GL_SRC1_COLOR                     0x88F9
#define GL_ONE_MINUS_SRC1_COLOR           0x88FA
#define GL_ONE_MINUS_SRC1_ALPHA           0x88FB
#define GL_MAX_DUAL_SOURCE_DRAW_BUFFERS   0x88FC
#define GL_ANY_SAMPLES_PASSED             0x8C2F
#define GL_SAMPLER_BINDING                0x8919
#define GL_RGB10_A2UI                     0x906F
#define GL_TEXTURE_SWIZZLE_R              0x8E42
#define GL_TEXTURE_SWIZZLE_G              0x8E43
#define GL_TEXTURE_SWIZZLE_B              0x8E44
#define GL_TEXTURE_SWIZZLE_A              0x8E45
#define GL_TEXTURE_SWIZZLE_RGBA           0x8E46
#define GL_TIME_ELAPSED                   0x88BF
#define GL_TIMESTAMP                      0x8E28
#define GL_INT_2_10_10_10_REV             0x8D9F

#define OPENGL_FUNCTIONS_3_3 \
   GL_FUNC(void, glBindFragDataLocationIndexed, GLuint program, GLuint colorNumber, GLuint index, const GLchar *name) \
   GL_FUNC(GLint, glGetFragDataIndex, GLuint program, const GLchar *name) \
   GL_FUNC(void, glGenSamplers, GLsizei count, GLuint *samplers) \
   GL_FUNC(void, glDeleteSamplers, GLsizei count, const GLuint *samplers) \
   GL_FUNC(GLboolean, glIsSampler, GLuint sampler) \
   GL_FUNC(void, glBindSampler, GLuint unit, GLuint sampler) \
   GL_FUNC(void, glSamplerParameteri, GLuint sampler, GLenum pname, GLint param) \
   GL_FUNC(void, glSamplerParameteriv, GLuint sampler, GLenum pname, const GLint *param) \
   GL_FUNC(void, glSamplerParameterf, GLuint sampler, GLenum pname, GLfloat param) \
   GL_FUNC(void, glSamplerParameterfv, GLuint sampler, GLenum pname, const GLfloat *param) \
   GL_FUNC(void, glSamplerParameterIiv, GLuint sampler, GLenum pname, const GLint *param) \
   GL_FUNC(void, glSamplerParameterIuiv, GLuint sampler, GLenum pname, const GLuint *param) \
   GL_FUNC(void, glGetSamplerParameteriv, GLuint sampler, GLenum pname, GLint *params) \
   GL_FUNC(void, glGetSamplerParameterIiv, GLuint sampler, GLenum pname, GLint *params) \
   GL_FUNC(void, glGetSamplerParameterfv, GLuint sampler, GLenum pname, GLfloat *params) \
   GL_FUNC(void, glGetSamplerParameterIuiv, GLuint sampler, GLenum pname, GLuint *params) \
   GL_FUNC(void, glQueryCounter, GLuint id, GLenum target) \
   GL_FUNC(void, glGetQueryObjecti64v, GLuint id, GLenum pname, GLint64 *params) \
   GL_FUNC(void, glGetQueryObjectui64v, GLuint id, GLenum pname, GLuint64 *params) \
   GL_FUNC(void, glVertexAttribDivisor, GLuint index, GLuint divisor) \
   GL_FUNC(void, glVertexAttribP1ui, GLuint index, GLenum type, GLboolean normalized, GLuint value) \
   GL_FUNC(void, glVertexAttribP1uiv, GLuint index, GLenum type, GLboolean normalized, const GLuint *value) \
   GL_FUNC(void, glVertexAttribP2ui, GLuint index, GLenum type, GLboolean normalized, GLuint value) \
   GL_FUNC(void, glVertexAttribP2uiv, GLuint index, GLenum type, GLboolean normalized, const GLuint *value) \
   GL_FUNC(void, glVertexAttribP3ui, GLuint index, GLenum type, GLboolean normalized, GLuint value) \
   GL_FUNC(void, glVertexAttribP3uiv, GLuint index, GLenum type, GLboolean normalized, const GLuint *value) \
   GL_FUNC(void, glVertexAttribP4ui, GLuint index, GLenum type, GLboolean normalized, GLuint value) \
   GL_FUNC(void, glVertexAttribP4uiv, GLuint index, GLenum type, GLboolean normalized, const GLuint *value)

#endif /* GL_VERSION_3_3 */

#ifndef GL_ARB_debug_output
#define GL_ARB_debug_output 1
typedef void (cdecl *GLDEBUGPROCARB)(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar *message, const void *userParam);
#define GL_DEBUG_OUTPUT_SYNCHRONOUS_ARB   0x8242
#define GL_DEBUG_NEXT_LOGGED_MESSAGE_LENGTH_ARB 0x8243
#define GL_DEBUG_CALLBACK_FUNCTION_ARB    0x8244
#define GL_DEBUG_CALLBACK_USER_PARAM_ARB  0x8245
#define GL_DEBUG_SOURCE_API_ARB           0x8246
#define GL_DEBUG_SOURCE_WINDOW_SYSTEM_ARB 0x8247
#define GL_DEBUG_SOURCE_SHADER_COMPILER_ARB 0x8248
#define GL_DEBUG_SOURCE_THIRD_PARTY_ARB   0x8249
#define GL_DEBUG_SOURCE_APPLICATION_ARB   0x824A
#define GL_DEBUG_SOURCE_OTHER_ARB         0x824B
#define GL_DEBUG_TYPE_ERROR_ARB           0x824C
#define GL_DEBUG_TYPE_DEPRECATED_BEHAVIOR_ARB 0x824D
#define GL_DEBUG_TYPE_UNDEFINED_BEHAVIOR_ARB 0x824E
#define GL_DEBUG_TYPE_PORTABILITY_ARB     0x824F
#define GL_DEBUG_TYPE_PERFORMANCE_ARB     0x8250
#define GL_DEBUG_TYPE_OTHER_ARB           0x8251
#define GL_MAX_DEBUG_MESSAGE_LENGTH_ARB   0x9143
#define GL_MAX_DEBUG_LOGGED_MESSAGES_ARB  0x9144
#define GL_DEBUG_LOGGED_MESSAGES_ARB      0x9145
#define GL_DEBUG_SEVERITY_HIGH_ARB        0x9146
#define GL_DEBUG_SEVERITY_MEDIUM_ARB      0x9147
#define GL_DEBUG_SEVERITY_LOW_ARB         0x9148

static int GL_ARB_debug_output_available = 0;
#define OPENGL_DEBUG_OUTPUT_ARB_FUNCTIONS \
   GL_FUNC(void, glDebugMessageControlARB, GLenum source, GLenum type, GLenum severity, GLsizei count, const GLuint *ids, GLboolean enabled) \
   GL_FUNC(void, glDebugMessageInsertARB, GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar *buf) \
   GL_FUNC(void, glDebugMessageCallbackARB, GLDEBUGPROCARB callback, const void *userParam) \
   GL_FUNC(GLuint, glGetDebugMessageLogARB, GLuint count, GLsizei bufSize, GLenum *sources, GLenum *types, GLuint *ids, GLenum *severities, GLsizei *lengths, GLchar *messageLog)

#endif /* GL_ARB_debug_output */

#define OPENGL_BASE_FUNCTIONS \
   OPENGL_FUNCTIONS_1_0 \
   OPENGL_FUNCTIONS_1_1 

#define OPENGL_CORE_FUNCTIONS \
   OPENGL_FUNCTIONS_1_2 \
   OPENGL_FUNCTIONS_1_3 \
   OPENGL_FUNCTIONS_1_4 \
   OPENGL_FUNCTIONS_1_5 \
   OPENGL_FUNCTIONS_2_0 \
   OPENGL_FUNCTIONS_2_1 \
   OPENGL_FUNCTIONS_3_0 \
   OPENGL_FUNCTIONS_3_1 \
   OPENGL_FUNCTIONS_3_2 \
   OPENGL_FUNCTIONS_3_3 

#define GL_FUNC(ret, name, ...) \
   typedef ret cdecl type_##name (__VA_ARGS__); \
   extern type_##name *name; 

OPENGL_BASE_FUNCTIONS;
OPENGL_CORE_FUNCTIONS;
OPENGL_DEBUG_OUTPUT_ARB_FUNCTIONS;
#undef GL_FUNC

#ifdef __cplusplus
}
#endif

#endif // !AVOCADO_OPENGL_H_INCLUDED
