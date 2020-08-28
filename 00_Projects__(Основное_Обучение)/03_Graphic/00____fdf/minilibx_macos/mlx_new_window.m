//  mlx_new_window.m

#import <Cocoa/Cocoa.h>
#import <OpenGL/gl3.h>
#import <AppKit/NSOpenGLView.h>

#include <stdio.h>

#include "mlx_int.h"
#include "mlx_new_window.h"


NSOpenGLPixelFormatAttribute pfa_attrs[] =
  {
    NSOpenGLPFADepthSize, 32,
    NSOpenGLPFAOpenGLProfile, NSOpenGLProfileVersionLegacy,
    0
  };

static const GLfloat pixel_vertexes[8] =
  {
    -1.0 , -1.0,
    1.0, -1.0,
    1.0, 1.0,
    -1.0, 1.0
  };



int get_mouse_button(NSEventType eventtype)
{
  switch (eventtype) {
  case NSEventTypeLeftMouseDown:
  case NSEventTypeLeftMouseUp:
  case NSEventTypeLeftMouseDragged:
    return 1;
  case NSEventTypeRightMouseDown:
  case NSEventTypeRightMouseUp:
  case NSEventTypeRightMouseDragged:
    return 2;
  case NSEventTypeOtherMouseDown:
  case NSEventTypeOtherMouseUp:
  case NSEventTypeOtherMouseDragged:
    return 3;
  default:
    return 0;
  }
}


// classes for window & events




@implementation NSWindowEvent

- (NSWindowEvent *) initWithContentRect:(NSRect)rect styleMask:(NSUInteger)winstyle backing:(NSBackingStoreType)bck defer:(BOOL) dfr
{
  int i;

  if ((self = [super initWithContentRect:rect
		     styleMask:winstyle
		     backing:bck
		     defer:dfr]))
    {
      i = MAX_EVENT;
      while (i--)
	{
	  event_funct[i] = NULL;
	  event_param[i] = NULL;
	}
      keyrepeat = 0;
      keyflag = 0;
      size_x = rect.size.width;
      size_y = rect.size.height;
    }
  return (self);
}


- (void) setEvent:(int)event andFunc:(func_t)func andParam:(void *)param
{
  event_funct[event] = func;
  event_param[event] = param;
  if (event == 6) // motion notify
    {
      if (func == NULL)
	[self setAcceptsMouseMovedEvents:NO];
      else
	[self setAcceptsMouseMovedEvents:YES];
    }
}


- (void) setKeyRepeat:(int)mode
{
  keyrepeat = mode;
}

- (BOOL) acceptsFirstResponder
{
  return (YES);
}

- (void) flagsChanged:(NSEvent *)theEvent
{
  unsigned int flag;
  int the_key;
  unsigned int val;

  flag = [theEvent modifierFlags];
  //  printf("Key flag changed: %x => %x\n", keyflag, flag);
  //  printf("**mlx flag low part : %d  - %x\n", flag&0xFFFF, flag&0xFFFF);

  if (!(val = (keyflag|flag)&(~(keyflag&flag))))
    return ;   // no change - can happen when loosing focus on special key pressed, then re-pressed later
  the_key = 1;
  while (((val >> (the_key-1)) & 0x01)==0)
    the_key ++;
  if (flag > keyflag && event_funct[2] != NULL)
    event_funct[2](0xFF+the_key, event_param[2]);
  if (flag < keyflag && event_funct[3] != NULL)
    event_funct[3](0xFF+the_key, event_param[3]);
  /*
  if (event_funct[2] != NULL)
    {
      if (!(keyflag & NSAlphaShiftKeyMask) && (flag&NSAlphaShiftKeyMask)) event_funct[2](0xFF+1, event_param[2]);
      if (!(keyflag & NSShiftKeyMask) && (flag&NSShiftKeyMask)) event_funct[2](0xFF+2, event_param[2]);
      if (!(keyflag & NSControlKeyMask) && (flag&NSControlKeyMask)) event_funct[2](0xFF+3, event_param[2]);
      if (!(keyflag & NSAlternateKeyMask) && (flag&NSAlternateKeyMask)) event_funct[2](0xFF+4, event_param[2]);
      if (!(keyflag & NSCommandKeyMask) && (flag&NSCommandKeyMask)) event_funct[2](0xFF+5, event_param[2]);
      if (!(keyflag & NSNumericPadKeyMask) && (flag&NSNumericPadKeyMask)) event_funct[2](0xFF+6, event_param[2]);
      if (!(keyflag & NSHelpKeyMask) && (flag&NSHelpKeyMask)) event_funct[2](0xFF+7, event_param[2]);
      if (!(keyflag & NSFunctionKeyMask) && (flag&NSFunctionKeyMask)) event_funct[2](0xFF+8, event_param[2]);
    }
  if (event_funct[3] != NULL)
    {
      if ((keyflag & NSShiftKeyMask) && !(flag&NSShiftKeyMask)) event_funct[3](NSShiftKeyMask, event_param[3]);

      if ((keyflag & NSAlphaShiftKeyMask) && !(flag&NSAlphaShiftKeyMask)) event_funct[3](0xFF+1, event_param[3]);
      if ((keyflag & NSShiftKeyMask) && !(flag&NSShiftKeyMask)) event_funct[3](0xFF+2, event_param[3]);
      if ((keyflag & NSControlKeyMask) && !(flag&NSControlKeyMask)) event_funct[3](0xFF+3, event_param[3]);
      if ((keyflag & NSAlternateKeyMask) && !(flag&NSAlternateKeyMask)) event_funct[3](0xFF+4, event_param[3]);
      if ((keyflag & NSCommandKeyMask) && !(flag&NSCommandKeyMask)) event_funct[3](0xFF+5, event_param[3]);
      if ((keyflag & NSNumericPadKeyMask) && !(flag&NSNumericPadKeyMask)) event_funct[3](0xFF+6, event_param[3]);
      if ((keyflag & NSHelpKeyMask) && !(flag&NSHelpKeyMask)) event_funct[3](0xFF+7, event_param[3]);
      if ((keyflag & NSFunctionKeyMask) && !(flag&NSFunctionKeyMask)) event_funct[3](0xFF+8, event_param[3]);
    }
  */
  keyflag = flag;
}

- (void) keyDown:(NSEvent *)theEvent
{
  if (keyrepeat==0 && [theEvent isARepeat])
    return ;
  //  printf("Key Down: %d\n", [theEvent keyCode]);
  if (event_funct[2] != NULL)
    event_funct[2]([theEvent keyCode], event_param[2]);
  //  else [super keyDown: theEvent];
}

- (void) keyUp:(NSEvent *)theEvent
{
  //  printf("Key Up: %d\n", [theEvent keyCode]);
  if (event_funct[3] != NULL)
    event_funct[3]([theEvent keyCode], event_param[3]);
  //  else [super keyUp: theEvent];

}

- (void) mouseDown:(NSEvent *)theEvent
{
  NSPoint thepoint;
  int     button;

  thepoint = [theEvent locationInWindow];
  button = get_mouse_button([theEvent type]);
  //  printf("Mouse pressed bt %d  pos: %f, %f\n", button, thepoint.x, thepoint.y);
  if (event_funct[4] != NULL)
    event_funct[4](button, (int)(thepoint.x), size_y - 1 - (int)(thepoint.y), event_param[4]);
}

- (void) rightMouseDown:(NSEvent *)theEvent
{
  NSPoint thepoint;
  int     button;

  thepoint = [theEvent locationInWindow];
  button = get_mouse_button([theEvent type]);
  //  printf("Mouse pressed bt %d  pos: %f, %f\n", button, thepoint.x, thepoint.y);
  if (event_funct[4] != NULL)
    event_funct[4](button, (int)(thepoint.x), size_y - 1 - (int)(thepoint.y), event_param[4]);
}

- (void) otherMouseDown:(NSEvent *)theEvent
{
  NSPoint thepoint;
  int     button;

  thepoint = [theEvent locationInWindow];
  button = get_mouse_button([theEvent type]);
  //  printf("Mouse pressed bt %d  pos: %f, %f\n", button, thepoint.x, thepoint.y);
  if (event_funct[4] != NULL)
    event_funct[4](button, (int)(thepoint.x), size_y - 1 - (int)(thepoint.y), event_param[4]);
}

- (void) mouseUp:(NSEvent *)theEvent
{
  NSPoint thepoint;
  int     button;

  thepoint = [theEvent locationInWindow];
  button = get_mouse_button([theEvent type]);
  //  printf("Mouse release bt %d  pos: %f, %f\n", button, thepoint.x, thepoint.y);
  if (event_funct[5] != NULL)
    event_funct[5](button, (int)(thepoint.x), size_y - 1 - (int)(thepoint.y), event_param[5]);
}

- (void) rightMouseUp:(NSEvent *)theEvent
{
  NSPoint thepoint;
  int     button;

  thepoint = [theEvent locationInWindow];
  button = get_mouse_button([theEvent type]);
  //  printf("Mouse release bt %d  pos: %f, %f\n", button, thepoint.x, thepoint.y);
  if (event_funct[5] != NULL)
    event_funct[5](button, (int)(thepoint.x), size_y - 1 - (int)(thepoint.y), event_param[5]);
}

- (void) otherMouseUp:(NSEvent *)theEvent
{
  NSPoint thepoint;
  int     button;

  thepoint = [theEvent locationInWindow];
  button = get_mouse_button([theEvent type]);
  //  printf("Mouse release bt %d  pos: %f, %f\n", button, thepoint.x, thepoint.y);
  if (event_funct[5] != NULL)
    event_funct[5](button, (int)(thepoint.x), size_y - 1 - (int)(thepoint.y), event_param[5]);
}

- (void) mouseMoved:(NSEvent *)theEvent
{
  NSPoint thepoint;

  thepoint = [theEvent locationInWindow];
  //  printf("Mouse moved  pos: %f, %f\n", thepoint.x, thepoint.y);
  if (event_funct[6] != NULL)
    event_funct[6]((int)(thepoint.x), size_y - 1 - (int)(thepoint.y), event_param[6]);
}


- (void) mouseDragged:(NSEvent *)theEvent
{
  NSPoint thepoint;

  thepoint = [theEvent locationInWindow];
  //  printf("Mouse moved  pos: %f, %f\n", thepoint.x, thepoint.y);
  if (event_funct[6] != NULL)
    event_funct[6]((int)(thepoint.x), size_y - 1 - (int)(thepoint.y), event_param[6]);
}


- (void) rightMouseDragged:(NSEvent *)theEvent
{
  NSPoint thepoint;

  thepoint = [theEvent locationInWindow];
  //  printf("Mouse moved  pos: %f, %f\n", thepoint.x, thepoint.y);
  if (event_funct[6] != NULL)
    event_funct[6]((int)(thepoint.x), size_y - 1 - (int)(thepoint.y), event_param[6]);
}


- (void) otherMouseDragged:(NSEvent *)theEvent
{
  NSPoint thepoint;

  thepoint = [theEvent locationInWindow];
  //  printf("Mouse moved  pos: %f, %f\n", thepoint.x, thepoint.y);
  if (event_funct[6] != NULL)
    event_funct[6]((int)(thepoint.x), size_y - 1 - (int)(thepoint.y), event_param[6]);
}


- (void) scrollWheel:(NSEvent *)theEvent
{
  NSPoint thepoint;
  int     button;
  float	  sens;

  if (event_funct[4] == NULL)
    return ;

  button = 0;
  thepoint = [theEvent locationInWindow];
  sens = [theEvent deltaY];
  if (sens > 0.2)
    button = 4;
  if (sens < -0.2)
    button = 5;
  sens = [theEvent deltaX];
  if (sens > 0.2)
    button = 6;
  if (sens < -0.2)
    button = 7;
  if (button != 0)
    event_funct[4](button, (int)(thepoint.x), size_y - 1 - (int)(thepoint.y), event_param[4]);
}


- (void) exposeNotification:(NSNotification *)note
{
  //    printf("Expose...\n");
    if (event_funct[12] != NULL)
      event_funct[12](event_param[12]);
    //    printf("Expose done.\n");
}

- (void) closeNotification:(NSNotification *)note
{
  if (event_funct[17] != NULL)
    event_funct[17](event_param[17]);
}

- (void) deminiaturizeNotification:(NSNotification *)note
{
  //  if (event_funct[??] != NULL)
  //    event_funct[??](event_param[??]);
  [self exposeNotification:note];
}
@end


@implementation MlxWin

- (id) initWithRect: (NSRect)rect andTitle: (NSString *)title pfaAttrs: (NSOpenGLPixelFormatAttribute *)attrs
{
  NSOpenGLPixelFormat* pixFmt = [[NSOpenGLPixelFormat alloc] initWithAttributes:attrs];

  if ((self = [super initWithFrame:rect pixelFormat:pixFmt]) != nil)
    {
      NSUInteger windowStyle = NSWindowStyleMaskTitled | NSWindowStyleMaskClosable | NSWindowStyleMaskMiniaturizable;

      win = [[NSWindowEvent alloc] initWithContentRect:rect
				   styleMask:windowStyle
				   backing:NSBackingStoreBuffered   // NSBackingStoreNonretained
				   defer:NO];
      [win setContentView:self];
      [win setTitle:title];
      [win setKeyRepeat:1];
      [win makeKeyAndOrderFront:self];

      //      printf("init ctx: current %p ", [NSOpenGLContext currentContext]);

      //      ctx = [[NSOpenGLContext alloc] initWithFormat:pixFmt shareContext:[NSOpenGLContext currentContext]]; //other_context];
      //      [ctx setView:self];
      //      [ctx makeCurrentContext];

      [[self openGLContext] makeCurrentContext];
      [[self openGLContext] setView:self];
      [self prepareOpenGL];

      [self setNextKeyView:self];

      //      [[NSNotificationCenter defaultCenter] addObserver:win selector:@selector(exposeNotification:) name:@"NSWindowDidExposeNotification" object:nil];
      [[NSNotificationCenter defaultCenter] addObserver:win selector:@selector(exposeNotification:) name:@"NSWindowDidBecomeKeyNotification" object:win];
      [[NSNotificationCenter defaultCenter] addObserver:win selector:@selector(deminiaturizeNotification:) name:@"NSWindowDidDeminiaturizeNotification" object:win];
      [[NSNotificationCenter defaultCenter] addObserver:win selector:@selector(closeNotification:) name:@"NSWindowWillCloseNotification" object:win];
      // [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(ctxNeedsUpdate:)
      //				    name:NSViewGlobalFrameDidChangeNotification
      //				    object:nil];

      size_x = rect.size.width;
      size_y = rect.size.height;

      glClearColor(0, 0, 0, 0);
      glClear(GL_COLOR_BUFFER_BIT);
      glFlush();

      //[win makeKeyAndOrderFront:nil];
      // BOOL r = [win isKeyWindow];
      //  if (r==YES) printf("keywindow ok\n"); else printf("keywindow KO\n");

      // Window controller subclass to set title
      // NSWindowController* windowController = [[NSWindowController alloc] initWithWindow:win];
      // [windowController windowTitleForDocumentDisplayName:title];
      // [windowController showWindow:nil];
      // MlxWinController *mlxWinCont = [[MlxWinController alloc] initWin:win andTitle:title];

      // after nswindowcontroller who will retake first responder
      //      BOOL r = [win makeFirstResponder:nil];
      //      if (r==YES) printf("responder ok\n"); else printf("responder KO\n");

      [pixFmt release];
    }
  return (self);
}

- (int)	pixel_management
{
  bzero(&glsl, sizeof(glsl));   // so gldelete[shader/program] go silent on error.

  glDisable(GL_DEPTH_TEST);
  glGenBuffers(1, &pixel_vbuffer);
  glBindBuffer(GL_ARRAY_BUFFER, pixel_vbuffer);
  glBufferData(GL_ARRAY_BUFFER, sizeof(pixel_vertexes), pixel_vertexes, GL_DYNAMIC_DRAW); // 4 points buff
  // pixel_ptr = glMapBuffer(GL_ARRAY_BUFFER, GL_WRITE_ONLY);

  glGenTextures(1, &pixel_texture);
  glBindTexture(GL_TEXTURE_2D, pixel_texture);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S,     GL_CLAMP_TO_EDGE);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T,     GL_CLAMP_TO_EDGE);
  pixtexbuff = malloc(sizeof(unsigned int)*size_x*size_y);
  pixel_nb = size_x*size_y;
  while (pixel_nb--) pixtexbuff[pixel_nb] = 0xFF000000;
  pixel_nb = 0;
  glTexImage2D(
	       GL_TEXTURE_2D, 0,           /* target, level of detail */
	       GL_RGBA8,                    /* internal format */
	       size_x, size_y, 0,           /* width, height, border */
	       GL_BGRA, GL_UNSIGNED_BYTE,   /* external format, type */
	       pixtexbuff                   /* pixels */
	       );
  //      printf("pix tex err? 0x%x\n", glGetError());

  if (mlx_shaders(&glsl))
    return (0);

  glUseProgram(glsl.pixel_program);
  glsl.loc_pixel_texture = glGetUniformLocation(glsl.pixel_program, "texture");
  //glsl.loc_pixel_winhalfsize = glGetUniformLocation(glsl.pixel_program, "winhalfsize");
  glsl.loc_pixel_position = glGetAttribLocation(glsl.pixel_program, "position");
  //      printf("err? 0x%x\n", glGetError());

  glUseProgram(glsl.image_program);
  glsl.loc_image_texture = glGetUniformLocation(glsl.image_program, "texture");
  glsl.loc_image_pos = glGetUniformLocation(glsl.image_program, "imagepos");
  glsl.loc_image_size = glGetUniformLocation(glsl.image_program, "imagesize");
  glsl.loc_image_winhalfsize = glGetUniformLocation(glsl.image_program, "winhalfsize");
  glsl.loc_image_position = glGetAttribLocation(glsl.image_program, "position");
  //      printf("err? 0x%x\n", glGetError());

  glUseProgram(glsl.font_program);
  glsl.loc_font_texture = glGetUniformLocation(glsl.font_program, "texture");
  glsl.loc_font_color = glGetUniformLocation(glsl.font_program, "color");
  glsl.loc_font_posinwin = glGetUniformLocation(glsl.font_program, "fontposinwin");
  glsl.loc_font_posinatlas = glGetUniformLocation(glsl.font_program, "fontposinatlas");
  glsl.loc_font_atlassize = glGetUniformLocation(glsl.font_program, "fontatlassize");
  glsl.loc_font_winhalfsize = glGetUniformLocation(glsl.font_program, "winhalfsize");
  glsl.loc_font_position = glGetAttribLocation(glsl.font_program, "position");
  //      printf("err? 0x%x\n", glGetError());

  glFlush();
  return (1);
}

- (void) ctxNeedsUpdate
{
  // printf("Context update\n");
  [ctx update];
}

- (void) selectGLContext
{
  if ([NSOpenGLContext currentContext] != [self openGLContext])
    {
      //      printf("ctx: %p => %p\n", [NSOpenGLContext currentContext], [self openGLContext]);
      [[self openGLContext] makeCurrentContext];
    }
}

- (void) flushGLContext
{
  [[self openGLContext] flushBuffer];
}

- (NSOpenGLContext *) ctx
{
  return (ctx);
}


- (void) pixelPutColor: (int)color X:(int)x Y:(int)y
{
  pixel_nb ++;

  glBindTexture(GL_TEXTURE_2D, pixel_vbuffer);
  glTexSubImage2D(GL_TEXTURE_2D, 0, x, y, 1, 1, GL_BGRA, GL_UNSIGNED_BYTE, (GLvoid *)(&color));

  if (pixel_nb >= MAX_PIXEL_NB)
    [self mlx_gl_draw];
}

- (void) destroyPixelManagement
{
  free(pixtexbuff);
  [self selectGLContext];
  glDeleteBuffers(1, &pixel_vbuffer);
  glDeleteTextures(1, &pixel_texture);
  glDeleteProgram(glsl.pixel_program);
  glDeleteProgram(glsl.image_program);
  glDeleteShader(glsl.pixel_vshader);
  glDeleteShader(glsl.pixel_fshader);
  glDeleteShader(glsl.image_vshader);
  glDeleteShader(glsl.image_fshader);
}


- (void) destroyMe
{
  [[NSNotificationCenter defaultCenter] removeObserver:win];
  [[NSNotificationCenter defaultCenter] removeObserver:self];
  // [ctx release];
  [win close];
  [self release];
}

- (void) setEvent:(int)event andFunc:(func_t)func andParam:(void *)param
{
  [win setEvent:event andFunc:func andParam:param];
}

- (void) setKeyRepeat:(int)mode
{
  [win setKeyRepeat:mode];
}

- (void) clearWin
{
  glClearColor(0, 0, 0, 0);
  glClear(GL_COLOR_BUFFER_BIT);
}

- (void) mlx_gl_draw_img:(mlx_img_list_t *)img andCtx:(mlx_img_ctx_t *)imgctx andX:(int)x andY:(int)y
{

  if (pixel_nb >0)
    [self mlx_gl_draw];

  glUseProgram(glsl.image_program);

  glActiveTexture(GL_TEXTURE0);
  glBindTexture(GL_TEXTURE_2D, imgctx->texture);
  glUniform1i(glsl.loc_image_texture, 0);

  glUniform2f(glsl.loc_image_winhalfsize, size_x/2, size_y/2);
  glUniform2f(glsl.loc_image_pos, x, size_y - y);
  glUniform2f(glsl.loc_image_size, img->width, -img->height);

  glBindBuffer(GL_ARRAY_BUFFER, imgctx->vbuffer);
  glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2*sizeof(GLfloat), (void*)0);
  glEnableVertexAttribArray(0);

  glEnable(GL_BLEND);
  glBlendFunc(GL_ONE_MINUS_SRC_ALPHA, GL_SRC_ALPHA);  // src alpha 0xFF : keep dst
  glBlendEquation(GL_FUNC_ADD);

  glDrawArrays(GL_TRIANGLE_FAN, 0, 4);
  glDisableVertexAttribArray(0);

}


- (void) mlx_gl_draw_font:(mlx_img_list_t *)img andCtx:(mlx_img_ctx_t *)imgctx andX:(int)x andY:(int)y andColor:(int)color glyphX:(int)gx glyphY:(int)gy
{
  GLfloat color_tab[4];

  if (pixel_nb >0)
    [self mlx_gl_draw];

  color_tab[0] = ((float)((color&0xFF0000)>>16))/255.0;
  color_tab[1] = ((float)((color&0xFF00)>>8))/255.0;
  color_tab[2] = ((float)((color&0xFF)>>0))/255.0;
  color_tab[3] = 1.0;
  glUseProgram(glsl.font_program);

  glActiveTexture(GL_TEXTURE0);
  glBindTexture(GL_TEXTURE_2D, imgctx->texture);
  glUniform1i(glsl.loc_font_texture, 0);
  glUniform4fv(glsl.loc_font_color, 1, color_tab);

  glUniform2f(glsl.loc_font_winhalfsize, size_x/2, size_y/2);
  glUniform2f(glsl.loc_font_posinwin, x, size_y - 1 - y);
  glUniform2f(glsl.loc_font_posinatlas, gx, gy);
  glUniform2f(glsl.loc_font_atlassize, img->width, img->height);

  glBindBuffer(GL_ARRAY_BUFFER, imgctx->vbuffer);
  glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2*sizeof(GLfloat), (void*)0);
  glEnableVertexAttribArray(0);

  glEnable(GL_BLEND);
  glBlendFunc(GL_ONE_MINUS_SRC_ALPHA, GL_SRC_ALPHA);  // src alpha 0xFF : keep dst
  glBlendEquation(GL_FUNC_ADD);

  glDrawArrays(GL_TRIANGLE_FAN, 0, 4);
  glDisableVertexAttribArray(0);

}


- (void) mlx_gl_draw
{
  if (pixel_nb <= 0)
    return ;

  glUseProgram(glsl.pixel_program);

  glActiveTexture(GL_TEXTURE0);
  glBindTexture(GL_TEXTURE_2D, pixel_vbuffer);
  glUniform1i(glsl.loc_pixel_texture, 0);
  
  glBindBuffer(GL_ARRAY_BUFFER, pixel_vbuffer);
  glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2*sizeof(GLfloat), (void*)0);
  glEnableVertexAttribArray(0);

  glEnable(GL_BLEND);
  glBlendFunc(GL_ONE_MINUS_SRC_ALPHA, GL_SRC_ALPHA);  // src alpha 0xFF : keep dst
  glBlendEquation(GL_FUNC_ADD);

  glDrawArrays(GL_TRIANGLE_FAN, 0, 4);
  glDisableVertexAttribArray(0);

  pixel_nb = size_x*size_y;
  while (pixel_nb--) pixtexbuff[pixel_nb] = 0xFF000000;
  glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, size_x, size_y, 0, GL_BGRA, GL_UNSIGNED_BYTE, pixtexbuff);
  pixel_nb = 0;
  
}

@end


// mlx API
 

void *mlx_new_window(mlx_ptr_t *mlx_ptr, int size_x, int size_y, char *title)
{
  mlx_win_list_t	*newwin;
  NSString		*str;

  if ((newwin = malloc(sizeof(*newwin))) == NULL)
    return ((void *)0);
  newwin->img_list = NULL;
  newwin->next = mlx_ptr->win_list;
  newwin->nb_flush = 0;
  newwin->pixmgt = 1;
  mlx_ptr->win_list = newwin;

  NSRect windowRect = NSMakeRect(100, 100, size_x, size_y);
  str = [NSString stringWithCString:title encoding:NSASCIIStringEncoding];
  newwin->winid = [[MlxWin alloc] initWithRect:windowRect andTitle:str pfaAttrs:pfa_attrs];
  if (newwin->winid)
    if (![(id)(newwin->winid) pixel_management])
      {
	[(id)(newwin->winid) destroyPixelManagement];
	[(id)(newwin->winid) destroyMe];
      }
  return ((void *)newwin);
}


void mlx_clear_window(mlx_ptr_t *mlx_ptr, mlx_win_list_t *win_ptr)
{
  [(id)(win_ptr->winid) selectGLContext];
  [(id)(win_ptr->winid) clearWin];
  win_ptr->nb_flush ++;
}


void mlx_expose_hook(mlx_win_list_t *win_ptr, int (*funct_ptr)(), void *param)
{
  [(id)(win_ptr->winid) setEvent:12 andFunc:funct_ptr andParam:param];
}

void mlx_key_hook(mlx_win_list_t *win_ptr, int (*funct_ptr)(), void *param)
{
  [(id)(win_ptr->winid) setEvent:3 andFunc:funct_ptr andParam:param];
}

void mlx_mouse_hook(mlx_win_list_t *win_ptr, int (*funct_ptr)(), void *param)
{
  [(id)(win_ptr->winid) setEvent:4 andFunc:funct_ptr andParam:param];
}

void mlx_hook(mlx_win_list_t *win_ptr, int x_event, int x_mask, int (*funct_ptr)(), void *param)
{
  [(id)(win_ptr->winid) setEvent:x_event andFunc:funct_ptr andParam:param];
}

int     mlx_do_key_autorepeatoff(mlx_ptr_t *mlx_ptr)
{
  mlx_win_list_t *win;

  win = mlx_ptr->win_list;
  while (win)
    {
      [(id)(win->winid) setKeyRepeat:0];
      win = win->next;
    }
  return (0);
}

int     mlx_do_key_autorepeaton(mlx_ptr_t *mlx_ptr)
{
  mlx_win_list_t *win;

  win = mlx_ptr->win_list;
  while (win)
    {
      [(id)(win->winid) setKeyRepeat:1];
      win = win->next;
    }
  return (0);
}


int     mlx_destroy_window(mlx_ptr_t *mlx_ptr, mlx_win_list_t *win_to_del)
{
  mlx_win_list_t    first;
  mlx_win_list_t    *win;
  mlx_img_ctx_t	    *ctx;
  mlx_img_ctx_t	    *ctx2;

  first.next = mlx_ptr->win_list;
  win = &first;
  while (win && win->next)
    {
      if (win->next == win_to_del)
	win->next = win->next->next;
      win = win->next;
    }
  mlx_ptr->win_list = first.next;

  if (win_to_del->pixmgt)
    {
      [(id)(win_to_del->winid) selectGLContext];
      ctx = win_to_del->img_list;   // should be null anyway if no pixel management
      while (ctx)
	{
	  glDeleteBuffers(1, &(ctx->vbuffer));
	  glDeleteTextures(1, &(ctx->texture));
	  ctx2 = ctx;
	  ctx = ctx->next;
	  free(ctx2);
	}
      [(id)(win_to_del->winid) destroyPixelManagement];
    }
  [(id)(win_to_del->winid) destroyMe];
  free(win_to_del);

  //  printf("destroy window done.\n");
  mlx_do_sync(mlx_ptr);
  return (0);
}
