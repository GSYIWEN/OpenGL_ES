#ifndef _VERTICEIF_H
#define _VERTICEIF_H
#include <boost/shared_ptr.hpp>
#include "include\DefinedTypes.h"

interface VerticeIF
{
public:
	virtual ~VerticeIF() {}

	virtual UInt8*
	createVertexData(UInt32 vertexSize, UInt32 vertexCount, enum RenderObjType type) = 0;

	virtual const UInt32&
	getVertexSize() const = 0;

	virtual const UInt32&
	getVertexBufferSize() const = 0;

	virtual void
	setPrimitiveType(PrimitiveType ePtype) = 0;

	virtual const PrimitiveType&
	getPrimitiveType() const = 0;

	virtual UInt8*
	createIndexData(VertexIndexType eVIT, UInt32 indexCount, enum RenderObjType type) = 0;

	virtual const UInt32&
	getIndexBufferSize() const = 0;

	virtual const UInt32&
	getIndexCount() const = 0;

	virtual const UInt8*
	getVertexData() const = 0;

	virtual const UInt8*
	getIndexData() const = 0;

	//virtual bool
	//loadVBO() = 0;

	//virtual bool
	//updateVBO() = 0;

	//virtual void
	//addAttribute(const VertexAttribute& va) = 0;

	//virtual void
	//clearAttributes() = 0;

};

typedef SmartPtr<VerticeIF> SpVerticeIF;


#endif
