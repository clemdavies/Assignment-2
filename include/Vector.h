#ifndef VECTOR_H
#define VECTOR_H

#include <math.h>
#include <vector>

const unsigned MINIMUM_SIZE = 10;

  /**
   * @class Vector
   * @brief Encapsulated array. Dynamically increases the size when needed.
   *
   * @author Clem Davies
   * @version 01
   * @date 27/04/2016
   *
   */
template <class T>
class Vector
{
  public:

      /**
       * @brief Creates a Vector with size starting at minimum_size of 10.
       */
    Vector();

      /**
       * @brief Creates a Vector with starting maxSize as passed value.
       * @param The maximum size of the array.
       */
    Vector(unsigned size);

      /**
       * @brief Constructs a copy of Vector.
       * @param The Vector object to copy from.
       * @return The newly created Vector object.
       */
    Vector( const Vector &srcVector);

      /**
       * @brief Constructs a copy of Vector using assignment operator.
       * @param The Vector object to copy from.
       * @return The newly created Vector object.
       */
    Vector& operator=(const Vector &srcVector);

      /**
       * @brief Destroys the stored arrays.
       */
    virtual ~Vector();

      /**
       * @brief Returns the element at passed index in array.
       * @param The index.
       * @return The element.
       */
    const T& get(unsigned index) const;

      /**
       * @brief Inserts passed element at passed index in array. Resizes if neccessary.
       * @param Index to insert at.
       * @param Element to insert.
       */
    void insert(unsigned index, const T &element);

      /**
       * @brief Empties the arrays and resets member variables to initial state.
       */
    void clear();

      /**
       * @brief Checks to see if the array has any elements.
       * @return True if there are no elements in the array.
       */
    bool empty() const;

      /**
       * @brief Returns the current number of elements in the array.
       * @return The size.
       */
    unsigned getSize() const;

      /**
       * @brief Returns the current maximum size of the array.
       * @return The maximum size.
       */
    unsigned getMaxSize() const;

  private:
      /**
       * @brief Increases maxSize of elements array by 1.5 until passed index fits and copies all values into larger array.
       * @param The index value that needs to fit into the new array.
       */
    void increaseMaxSize(unsigned toFitIndex);

      /**
       * @brief The current number of elements in the elements array.
       */
    unsigned currentSize;

      /**
       * @brief The maximum size of elements array.
       */
    unsigned maxSize;

      /**
       * @brief The encapsulated vector.
       */
    std::vector<T> *elements;
};

/* -------------------------------------------------------------------------------- */
  template<class T>
  Vector<T>::Vector()
  {
    maxSize = MINIMUM_SIZE;
    elements = new std::vector<T>(maxSize);
    currentSize = 0;
  }

/* -------------------------------------------------------------------------------- */
  template<class T>
  Vector<T>::Vector(unsigned size)
  {
    maxSize = (size > MINIMUM_SIZE)? size : MINIMUM_SIZE;
    elements = new std::vector<T>(maxSize);
    currentSize = 0;
  }

/* -------------------------------------------------------------------------------- */
  template<class T>
  Vector<T>::Vector( const Vector &srcVector)
  {
    maxSize = srcVector.maxSize;
    elements = new std::vector<T>(maxSize);
    for(unsigned i = 0; i < maxSize; i++)
    {
      (*elements)[i] = (*srcVector.elements)[i];
    }
    currentSize = srcVector.currentSize;
  }

/* -------------------------------------------------------------------------------- */
  template<class T>
  Vector<T>& Vector<T>::operator=(const Vector &srcVector)
  {
    // check for self-assignment
    if (this == &srcVector)
      return *this;

    maxSize = srcVector.maxSize;
    elements = new std::vector<T>(maxSize);
    for(unsigned i = 0; i < maxSize; i++)
    {
      (*elements)[i] = (*srcVector.elements)[i];
    }
    currentSize = srcVector.currentSize;

    return *this;
  }

/* -------------------------------------------------------------------------------- */
  template<class T>
  Vector<T>::~Vector()
  {
    delete elements;
  }

/* -------------------------------------------------------------------------------- */
  template<class T>
  const T& Vector<T>::get(unsigned index) const
  {
    return (*elements)[index];
  }

/* -------------------------------------------------------------------------------- */
  template<class T>
  void Vector<T>::insert(unsigned index, const T &element)
  {
    if(index >= maxSize)
    {
      increaseMaxSize(index);
    }
    (*elements)[index] = element;
    currentSize++;
  }

/* -------------------------------------------------------------------------------- */
  template<class T>
  void Vector<T>::clear()
  {
    elements->clear();
    currentSize = 0;
  }

/* -------------------------------------------------------------------------------- */
  template<class T>
  bool Vector<T>::empty() const
  {
    return currentSize == 0;
  }

/* -------------------------------------------------------------------------------- */
  template<class T>
  unsigned Vector<T>::getSize() const
  {
    return currentSize;
  }

/* -------------------------------------------------------------------------------- */
  template<class T>
  unsigned Vector<T>::getMaxSize() const
  {
    return static_cast<unsigned>(elements->capacity());
  }

/* -------------------------------------------------------------------------------- */
  template<class T>
  void Vector<T>::increaseMaxSize(unsigned toFitIndex)
  {
    if(toFitIndex < maxSize)return;
    while(toFitIndex >= maxSize) maxSize = ceil( maxSize * 1.5 );
    elements->resize(maxSize);
  }


#endif // VECTOR_H
