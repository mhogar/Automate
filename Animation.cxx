#include "Animation.h"

Animation::Animation(int framerate) {
    _framerate = framerate;
    _currentFrame = 0;
}

Animation::~Animation() {
}

void Animation::Wait() {
    while (!_directives.empty()) {
        RenderFrame();
    }
}

void Animation::Delay(int duration) {
    int numFrames = duration * _framerate;
    for (int i = 0; i < numFrames; i++) {
        RenderFrame();
    }
}

void Animation::TranslateY(int duration) {
    _directives.push_back(new TranslateYDir(duration * _framerate));
}

void Animation::Opacity(int duration) {
    _directives.push_back(new OpacityDir(duration * _framerate));
}

void Animation::RenderFrame() {
    std::list<Directive*> completedDirectives;

    for (Directive* dir : _directives) {
        if (!dir->Execute()) {
            completedDirectives.push_back(dir);
        }
    }

    for (Directive* dir : completedDirectives) {
        _directives.remove(dir);
        delete dir;
    }

    _currentFrame++;
}
