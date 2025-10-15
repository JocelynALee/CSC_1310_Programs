/********************************************************************************
	Title: 	  SmartPointer.h
	Authors:  Jocelyn Lee & Kylie Truong
	Date:  	  11/01/2024
	Purpose:  Contains everything needed for the SmartPointer
*********************************************************************************/
#ifndef SMARTPOINTER_H
#define SMARTPOINTER_H

/*********************************************/
/*            SmartPointer Class             */
/*********************************************/
template<typename T>
class SmartPointer 
{
    private:
        T* ptr;

    public:
        /* Constructor */
        SmartPointer(T* p);
        
        /* Copy Constructor */
        SmartPointer(const SmartPointer& sp);
        
        /* Move Constructor */
        SmartPointer(SmartPointer&& sp) noexcept;

        /* Destructor */
        ~SmartPointer();

        /* Assignment Operators */
        SmartPointer& operator=(const SmartPointer& sp);
        SmartPointer& operator=(SmartPointer&& sp) noexcept;

        /* Dereference Operators */
        T& operator*() const;
        T* operator->() const;

        /* Comparison Operators */
        bool operator==(const SmartPointer& sp) const;
        bool operator!=(const SmartPointer& sp) const;
    };

    /* Implementation */
    template<typename T>
    SmartPointer<T>::SmartPointer(T* p) : ptr(p) {}

    template<typename T>
    SmartPointer<T>::SmartPointer(const SmartPointer& sp) 
    {
        if (sp.ptr) {
            ptr = new T(*(sp.ptr)); 
        } else {
            ptr = nullptr;
        }
    }

    template<typename T>
    SmartPointer<T>::SmartPointer(SmartPointer&& sp) noexcept : ptr(sp.ptr) 
    {
        sp.ptr = nullptr;
    }

    template<typename T>
    SmartPointer<T>::~SmartPointer() 
    {
        delete ptr;
    }

    template<typename T>
    SmartPointer<T>& SmartPointer<T>::operator=(const SmartPointer& sp) 
    {
        if (this != &sp) {
            delete ptr; 
            if (sp.ptr) {
                ptr = new T(*(sp.ptr));
            } else {
                ptr = nullptr; 
            }
        }
        return *this;
    }

    template<typename T>
    SmartPointer<T>& SmartPointer<T>::operator=(SmartPointer&& sp) noexcept 
    {
        if (this != &sp) {
            delete ptr; 
            ptr = sp.ptr; 
            sp.ptr = nullptr;
        }
        return *this;
    }

    template<typename T>
    T& SmartPointer<T>::operator*() const 
    {
        return *ptr;
    }

    template<typename T>
    T* SmartPointer<T>::operator->() const 
    {
        return ptr;
    }

    template<typename T>
    bool SmartPointer<T>::operator==(const SmartPointer& sp) const 
    {
        return ptr == sp.ptr;
    }

    template<typename T>
    bool SmartPointer<T>::operator!=(const SmartPointer& sp) const 
    {
        return ptr != sp.ptr;
    }

#endif