#pragma once

#include "Point2D.h"
#include "CustomException.h"

template<class T>
class Circle : public Point2D<T>{
 protected:
  T radius;
 public:
  Circle();
  Circle(T x, T y, T radius);
  T getRadius() const;
  void setRadius(T newRadius);
  float area() const ;
  float circumference() const;
};
template <class T>
Circle<T>::Circle() {

}
template <class T>
Circle<T>::Circle(T x, T y, T radius){
      if (radius<=0) {
        throw (CustomException(22));
      }
    Point2D<T>::x=x;
    Point2D<T>::y=y;
    setRadius(radius);
}
template <class T>
T Circle<T>::getRadius() const {
  return radius;
}

template <class T>
void Circle<T>::setRadius(T newRadius)  {
  if (newRadius<=0) {
    throw (CustomException(22));
  }
  this->radius=newRadius;
}

template <class T>
float Circle<T>::area() const  {
  return ((float)(3.14*radius*radius));
}

template <class T>
float Circle<T>::circumference() const {
  return ((float)(2*3.14*radius));
}
