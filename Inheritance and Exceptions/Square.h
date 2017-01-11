#pragma once

#include "Point2D.h"
#include "Rectangle.h"

template<class T>
class Square : public Rectangle<T>{
 public:
  Square(T x, T y, T side);
};

template <class T>
Square<T>::Square(T x, T y, T side){
  if (side<=0) {
    throw (CustomException(33));
  }
Point2D<T>::x=x;
Point2D<T>::y=y;
Rectangle<T>::height=side;
Rectangle<T>::width=side;
}