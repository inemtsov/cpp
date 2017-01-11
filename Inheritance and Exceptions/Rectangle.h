#pragma once

#include "Point2D.h"
#include "CustomException.h"

template<class T>
class Rectangle : public Point2D<T> {

 protected:
    T width, height;
 public:

  Rectangle();
  Rectangle(T x, T y, T width, T height);
  T getWidth() const;
  T getHeight() const;
  void setWidth(T newWidth);
  void setHeight(T newHeight);
  float area() const;
  float circumference() const;

};
template <class T>
Rectangle<T>::Rectangle() {

}
template <class T>
Rectangle<T>::Rectangle(T x, T y, T width, T height){
  if (width<=0 || height<=0) {
    throw (CustomException(33));
  }
      Point2D<T>::x=x;
      Point2D<T>::y=y;
      this->width=width;
      this->height=height;
}
template <class T>
T Rectangle<T>::getWidth() const {
  return width;
}

template <class T>
T Rectangle<T>::getHeight() const {
  return height;
}
template <class T>
void Rectangle<T>::setHeight(T newHeight) {
  if (newHeight<=0) {
    throw (CustomException(33));
  }
  this->height=newHeight;
}
template <class T>
void Rectangle<T>::setWidth(T newWidth) {
  if (newWidth<=0 ) {
    throw (CustomException(33));
  }
  this->width=newWidth;
}

template <class T>
float Rectangle<T>::area() const {
  return (float)width*height;
}

template <class T>
float Rectangle<T>::circumference() const {
  return (float)(2*(width+height));
}