Window::Window()
}

SDL_Renderer *Window::getRendererContext() const { return this->renderer; }

bool Window::isQuitRequested() {}

void Window::clear() {}

void Window::update() { SDL_RenderPresent(this->renderer); }

void Window::destroy() {}
