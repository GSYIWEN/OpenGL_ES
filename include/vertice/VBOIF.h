#ifndef _VBOIF_H
#define _VBOIF_H
#include "include\DefinedTypes.h"


interface VBOIF
{
public: 
	virtual ~VBOIF() {}

	virtual bool
	bindData(BufferObjType eType, const void* pBuffer, UInt32 uSize, BufferUsageType eUsage = BUT_STATIC_DRAW) = 0;

	virtual bool
	updateData(UInt32 uOffset, UInt32 uSize, const void* pBuffer) = 0;

	virtual bool
	bind() = 0;

	virtual bool
	unbind() = 0;

	virtual void
	release() = 0;
};

typedef SmartPtr<VBOIF> SpVBOIF;
#endif // !_VBOIF_H
