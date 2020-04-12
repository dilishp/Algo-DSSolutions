#include "pch.h"
#include <iostream>

using namespace std;

class NullPtrException : public exception
{
	virtual const char* what() const throw()
	{
		return "Null Ptr Exception";
	}
};

template <typename T>
class smart_ptr {
public:
	// Create a smart_ptr that is initialized to nullptr. The reference count
	// should be initialized to nullptr.
	smart_ptr()
	{
		ref_ = nullptr;
		ptr_ = nullptr;
	}
	
	// Create a smart_ptr that is initialized to raw_ptr. The reference count
	// should be one. No change is made to raw_ptr.
	explicit smart_ptr(T* &raw_ptr) noexcept
	{
		ptr_ = raw_ptr;
		ref_ = new int(1);
	}

	// Create a smart_ptr that is initialized to raw_ptr. The reference count
	// should be one. If the constructor fails raw_ptr is deleted.    
	explicit smart_ptr(T* &&raw_ptr)
	{
		ptr_ = std::move(raw_ptr);
		ref_ = new int(1);

	}

	// Copy construct a pointer from rhs. The reference count should be 
// incremented by one.
	smart_ptr(const smart_ptr& rhs)
	{
		ptr_ = rhs.ptr_;
		ref_ = new int;
		(*ref_) = (rhs.ref_) + 1;
	}

	// Move construct a pointer from rhs.
	smart_ptr(smart_ptr&& rhs)
	{
		ptr_ = std::move(rhs.ptr_);
		ref_ = new int;
		ref_ = rhs.ref_;
	}

	// This assignment should make a shallow copy of the right-hand side's
	// pointer data. The reference count should be incremented as appropriate.
	smart_ptr& operator=(const smart_ptr& rhs)
	{
		ptr_ = rhs.ptr_;
		(*ref_) = (rhs.ref_) + 1;
	}
	
	// This move assignment should steal the right-hand side's pointer data.

	smart_ptr& operator=(smart_ptr&& rhs)
	{
		ptr_ = std::move(rhs.ptr_);
		(*ref_) = rhs.ref_;
	}

	// If the smart_ptr is either nullptr or has a reference count of one, this
	// function will do nothing and return false. Otherwise, the referred to
	// object's reference count will be decreased and a new deep copy of the
	// object will be created. This new copy will be the object that this
	// smart_ptr points and its reference count will be one. 
	bool clone()
	{
		if ((ptr_ == nullptr) || (*ref_ == 1))
		{
			return false;
		}
		else
		{
			(*ref_)--;
			this = new smart_ptr(this->ptr_);
			(*this->ref_) = 1;
			return true;
		}
	}
	
	// Returns the reference count of the pointed to data.

	int ref_count() const
	{
		if(nullptr != ref_)
			return *ref_;
	}
	// The dereference operator shall return a reference to the referred object.
	// Throws null_ptr_exception on invalid access. 
	T& operator*() throw()
	{
		if (ptr_)
		{
			return *ptr_;
		}
		throw NullPtrException();
	}
	
	// The arrow operator shall return the pointer ptr_. Throws null_ptr_exception
	// on invalid access.
	T* operator->() throw()
	{
		if (ptr_)
			return ptr_;
		throw NullPtrException();
	}


	~smart_ptr()
	{
		delete ref_;
		ref_ = nullptr;
		ptr_ = nullptr;
	}

private:
	T* ptr_;               // pointer to the referred object
	int* ref_;             // pointer to a reference count
};