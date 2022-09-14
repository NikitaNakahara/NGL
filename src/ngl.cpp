#include "../include/NGL/ngl.hpp"

#include <iostream>

#ifdef __linux__

#include <X11/Xlib.h>

struct NGLWindow {
    int width;
    int height;
    const char* title;
    Display* display;
    Window window;
    XEvent event;
};

NGLWindow* nglCreateWindow(int width, int height, const char* title) {
    NGLWindow* window;
    window->width = width;
    window->height = height;
    window->title = title;

    window->display = XOpenDisplay(NULL);
    if (window->display == NULL) {
        return nullptr;
    }

    int screen = XDefaultScreen(window->display);
    Window rootWindow = XRootWindow(window->display, screen);
    int bgColor = XBlackPixel(window->display, screen);

    window->window = XCreateSimpleWindow(
        window->display, rootWindow,
        0, 0,
        window->width, window->height,
        0, 0,
        bgColor
    );

    // Activate keyboard event
    XSelectInput(window->display, window->window, KeyPressMask);

    // Show window
    XMapWindow(window->display, window->window);

    // Flush data to X-server
    XFlush(window->display);

    return window;
}

void nglCloseWindow(NGLWindow* window) {
    XDestroyWindow(window->display, window->window);
    XCloseDisplay(window->display);
}

void nglPoolEvents(NGLWindow* window) {
    XNextEvent(window->display, &window->event);
}

bool nglWindowShouldClose(NGLWindow* window) {
    if (window->event.type == Expose) {
        return true;
    }
    
    return false;
}

#endif // __linux__
