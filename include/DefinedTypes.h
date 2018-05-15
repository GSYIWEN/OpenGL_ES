#ifndef _DEFINED_TYPES_H
#define _DEFINED_TYPES_H

//#ifdef WIN32
//#define ESUTIL_API  __cdecl
//#define ESCALLBACK  __cdecl
//#else
//#define ESUTIL_API
//#define ESCALLBACK
//#endif

//#ifdef __cplusplus
//
//extern "C" {
//#endif
#include <boost\shared_ptr.hpp>
#include <vector>
#include <list>
#include <map>


#define interface  class

#define DISALLOW_COPY_AND_ASSIGN(ClassName)		 \
	ClassName() {};								 \
	const ClassName& operator=(const ClassName&) {}

#define SmartPtr			boost::shared_ptr

#define DynamicPointCast	boost::dynamic_pointer_cast
//#define Vector				std::vector;
#define DELETEARRAY_ASSIGNNULL(ptr)	 \
	delete[] ptr;					\
	ptr = NULL;

#define DELETE_ASSIGNNULL(ptr)     \
	delete ptr;						\
	ptr = NULL;

#define NEWARRAY(className, count)	\
	new className[count]

//#define List                list
//
//#define Map					map

typedef unsigned char       UInt8;
typedef signed char         Int8;
typedef unsigned short      UInt16;
typedef signed short        Int16;
typedef unsigned int        UInt32;
typedef signed int          Int32;
typedef unsigned long long  UInt64;
typedef signed long long    Int64;

typedef float				Float32;
typedef double				Float64;

typedef std::string			P_ATTRIBUTEID;


enum VertexIndexType
{
	VIT_UINT16,
	VIT_UINT8,
	VIT_INVALID = -1
};

enum PrimitiveType {
	PRT_POINTS,
	PRT_LINE_LIST,
	PRT_LINE_STRIP,
	PRT_TRIANLE_LIST,
	PRT_TRIANLE_STRIP,
	PRT_TRIANLE_FAN,
	PRT_INVALID = -1
};

enum P_VDTYPE
{
	PVDT_BYTE = 0,
	PVDT_UNSIGNED_BYTE,
	PVDT_SHORT,
	PVDT_UNSIGNED_SHORT,
	PVDT_FIXED,
	PVDT_FLOAT,
};

enum RenderObjType
{
	ROT_INVALID = 0,
	ROT_BASED = 0x1000,

	ROT_BUILDING = ROT_BASED + 1,
	ROT_BUILDINGWALL,
	ROT_BUILDINGTOP,
	ROT_BUILDINGEDGE,
	ROT_TILEBG,
	ROT_TRIANGLE
};

enum BufferObjType
{
	BOT_ARRAY_BUFFER,
	BOT_ELEMENT_ARRAY_BUFFER,
};

enum BufferUsageType
{
	BUT_STREAM_DRAW,
	BUT_STATIC_DRAW,
	BUT_DYNAMIC_DRAW
};
#endif