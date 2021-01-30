#include "Directive.h"
#include <iostream>

TimedDir::TimedDir(int numFrames) {
    _currentFrame = 0;
    _numFrames = numFrames;
}

bool TimedDir::Execute() {
    _currentFrame++;
    return _currentFrame < _numFrames;
}

TranslateYDir::TranslateYDir(int numFrames) : TimedDir(numFrames) {   
}

bool TranslateYDir::Execute() {
    std::cout << "TranslateY " << _currentFrame << std::endl;
    return TimedDir::Execute();
}

OpacityDir::OpacityDir(int numFrames) : TimedDir(numFrames) {
}

bool OpacityDir::Execute() {
    std::cout << "Opacity " << _currentFrame << std::endl;
    return TimedDir::Execute();
}
