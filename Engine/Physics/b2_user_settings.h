#ifndef B2_USER_SETTINGS
#define B2_USER_SETTINGS

#include <cstdarg>
#include <cstdint>
#include "ContactHandler.hpp"
#include "PhysicsEngineAdapter.hpp"

#define b2_lengthUnitsPerMeter 1.0f

#define b2_maxPolygonVertices	8

struct b2BodyUserData
{
	b2BodyUserData()
	{
		pointer = 0;
	}

	ContactHandler* contactHandler = nullptr;

	/// For legacy compatibility
	uintptr_t pointer;
};

/// You can define this to inject whatever data you want in b2Fixture
struct b2FixtureUserData
{
	b2FixtureUserData()
	{
		pointer = 0;
	}

	/// For legacy compatibility
	uintptr_t pointer;
};

/// You can define this to inject whatever data you want in b2Joint
struct b2JointUserData
{
	b2JointUserData()
	{
		pointer = 0;
	}

	/// For legacy compatibility
	uintptr_t pointer;
};

// Memory Allocation

/// Default allocation functions
void* b2Alloc_Default(int32 size);
void b2Free_Default(void* mem);

/// Implement this function to use your own memory allocator.
inline void* b2Alloc(int32 size)
{
	return b2Alloc_Default(size);
}

/// If you implement b2Alloc, you should also implement this function.
inline void b2Free(void* mem)
{
	b2Free_Default(mem);
}

/// Default logging function
void b2Log_Default(const char* string, va_list args);

/// Implement this to use your own logging.
inline void b2Log(const char* string, ...)
{
	va_list args;
	va_start(args, string);
	b2Log_Default(string, args);
	va_end(args);
}


#endif
