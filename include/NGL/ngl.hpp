#pragma once

/* Main window struct */
struct NGLWindow;

/** 
* @brief Create window
*
* @param width window width 
* @param height window height
* @param title window title
*
* @return window struct ptr 
*/
NGLWindow* nglCreateWindow(int width, int height, const char* title);

/**
 * @brief For linux - close connection with X-server
 * 
 * @param window window struct ptr 
 */
void nglCloseWindow(NGLWindow* window);

/**
 * @brief Pool events for active window
 * 
 * @param window window struct ptr
 */
void nglPoolEvents(NGLWindow* window);

/**
 * @brief Check close window event
 * 
 * @param window window struct ptr
 * 
 * @return true if window should close
 * @return false if window souldn't close
 */
bool nglWindowShouldClose(NGLWindow* window);
