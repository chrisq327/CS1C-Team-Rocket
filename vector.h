#ifndef VECTOR_H_
#define VECTOR_H_

#include "iostream"
#include <algorithm> // std::copy


using std::copy;
using namespace std;
namespace myStd
{

template<typename T>
class vector
{
    /*
    vector of doubles much like stl vector container

    NOTE: elem[n] is vector component n for all n >= 0 AND n < size_v
          size_v = the number of items stored in the vector
          space = the available storage capacity of the vector where size_v <= space
          if size_v < space there is space for (space - size_v) doubles after elem[size_v-1]
    */

    int size_v;   // the size
    T *elem; // pointer to the elements (or 0)
    int space;    // number of elements plus number of free slots
public:
    /* constructors */
    /**
     * @brief vector default constructor.  Sets size and space to 0, and elem to nullptr
     */
    vector() : size_v{0}, elem{nullptr}, space{0} {} // default constructor

    /**
     * @brief vector alternative constructor.  Need to pass in an int for the space
     * @param s the space the vector will hold
     */
    explicit vector(int s) : size_v{0}, elem{new T[s]}, space{s} // alternate constructor
    {
       for (int i = 0; i < size_v; ++i)
           elem[i] = T(); // elements are initialized
    }

    /**
     * @brief vector copy constructor
     * @param src  the vector that is being copied from
     */
    vector(const vector &src) : size_v{src.size_v}, elem{new T[src.size_v]}, space{src.space} // copy constructor
    {
        copy(src.elem, src.elem + size_v, elem); // copy elements - std::copy() algorithm
    }

    /**
     * @brief operator = copy assignment overload
     * @param src the vector that is being copied from
     * @return the vector that is being coppied into
     */
    vector &operator=(const vector &src) // copy assignment
    {
        T *p = new T[src.size_v];       // allocate new space
        copy(src.elem, src.elem + src.size_v, p); // copy elements - std::copy() algorithm
        delete[] elem;                            // deallocate old space
        elem = p;                                 // now we can reset elem
        size_v = src.size_v;
        return *this;  // return a self-reference
    }

    ~vector() {
        for(int i = 0; i < size_v; i++)
        {
            delete elem[i];
        }
        delete[] elem; // destructor
    }

    /* functions */
    /**
     * @brief operator [] overloaded [] operator to return the data at that particular index
     * @param n index spot of the vector that is being accessed
     * @return data stored in that index
     */
    T &operator[](int n) {
        return elem[n]; // access: return reference
    }

    /**
     * @brief operator [] const overloaded [] operator to return data at the particular index
     * @param n index of the vector that is being access
     * @return data stored at index passed
     */
    const T &operator[](int n) const {
        return elem[n];
    }

    /**
     * @brief size returns the amount of items stored inside of the vector
     * @return amount stored inside of the vector
     */
    int size() const {
        return size_v;
    }

    /**
     * @brief capacity returns the capacity of the vector in total, not just what is being sued
     * @return total size of the vector
     */
    int capacity() const {
        return space;
    }

    /**
     * @brief resize expands the vector to the increased size
     * @param newsize the new size of the vector
     */
    void resize(int newsize) // growth
    // make the vector have newsize elements
    // initialize each new element with the default value 0.0
    {
        reserve(newsize);
        for (int i = size_v; i < newsize; ++i)
           elem[i] =  T(); // initialize new elements
        space = newsize;
    }

    /**
     * @brief push_back adds the element to the back of the vector (after the last item)
     * @param d the element to be added to the vector
     */
    void push_back(T d)
    // increase vector size by one; initialize the new element with d
    {
        if (space == 0)
            reserve(8);         // start with space for 8 elements
        else if (size_v == space)
            reserve(2 * space); // get more space
        elem[size_v] = d;       // add d at end
        ++size_v;               // increase the size (size_v is the number of elements)
    }

    /**
     * @brief reserve creates a new vector to reserve the amount of space specified
     * @param newalloc amount of space for the new vector
     */
    void reserve(int newalloc)
    {
        // never decrease allocation
        if(!(newalloc<size_v))
        {
        // allocate new space
            T *temp = new T[newalloc];
            for(int i = 0; i < size_v; i++)
            {
                temp[i] = elem[i];
            }
            delete [] elem;
            elem = temp;
            space = newalloc;
        }
        // copy old elements
        // deallocate old space
    }

    using iterator = T *;
    using const_iterator = const T *;

    /**
     * @brief begin returns the first element of the vector
     * @return first element of the vector
     */
    iterator begin() // points to first element
    {
        if (size_v == 0)
            return nullptr;
        return &elem[0];
    }

    /**
     * @brief begin returns the first element of the vector
     * @return first element of the vector
     */
    const_iterator begin() const
    {
        if (size_v == 0)
            return nullptr;
        return &elem[0];
    }

    /**
     * @brief end returns the last element of the vector
     * @return last element of the vector
     */
    iterator end() // points to one beyond the last element
    {
        if (size_v == 0)
            return nullptr;
        return &elem[size_v];
    }

    /**
     * @brief end returns the last element of the vector
     * @return last element of the vector
     */
    const_iterator end() const
    {
        if (size_v == 0)
            return nullptr;
        return &elem[size_v];
    }

    /**
     * @brief insert inserts the value at the position, pushing everything after it back 1 space
     * @param p position to insert the value
     * @param val value to be insert in the slot
     * @return iterator used to traverse the vector
     */
    iterator insert(iterator p, const T &val) // insert a new element val before p
    {
        // make sure we have space
        int index = p - begin();
        if(!(size_v == space))
        {
            reserve(size() == 0 ? 8 : 2* size());
        }

        iterator pp = begin() + index;
        for (iterator pos = end()-1; pos != pp-1; --pos)
                *(pos + 1) = *pos;

        *(begin()+index) = val;
        size_v++;

        // the place to put value

        // copy element one position to the right
        // insert value
        return pp;
    }

    /**
     * @brief erase removes the point at the index passed, moving everything down (forward) one
     * @param p position to be deleted
     * @return iterator used to traverse the array
     */
    iterator erase(iterator p) // remove element pointed to by p
    {
        if (p == end())
            return p;
        for (iterator pos = p + 1; pos != end(); ++pos)
            *(pos - 1) = *pos; // copy element one position to the left
       // delete (end() - 1);
        --size_v;
        return p;
    }
};
}

#endif /* VECTOR_H_ */
