#ifndef _VERTICE_H
#define _VERTICE_H
#include "include\vertice\VertexAttribute.h"
#include "include\DefinedTypes.h"
#include "include\vertice\VerticeIF.h"

class Vertice : public VerticeIF
{
public:
	static SpVerticeIF
	create(bool bUpdate = true);

protected:
	Vertice(bool bUpdate);

	virtual ~Vertice();

	virtual UInt8*
	createVertexData(UInt32 vertexSize, UInt32 vertexCount, enum RenderObjType type);

	virtual const UInt32&
	getVertexSize() const;

	virtual const UInt32&
	getVertexBufferSize() const;

	virtual void
	setPrimitiveType(PrimitiveType ePtype);

	virtual const PrimitiveType&
	getPrimitiveType() const;

	virtual UInt8*
	createIndexData(VertexIndexType eVIT, UInt32 indexCount, enum RenderObjType type);

	virtual const UInt32&
	getIndexBufferSize() const;

	virtual const UInt32&
	getIndexCount() const;

	virtual const UInt8*
	getVertexData() const;

	virtual const UInt8*
	getIndexData() const;

	//virtual bool
	//loadVBO();

	//virtual bool
	//updateVBO();

	//virtual void
	//addAttribute(const VertexAttribute& va);

	//virtual void
	//clearAttributes();

protected:
	/*bool loadVAO();

	bool loadWithVAOSupport();

	bool loadWithOutVAOSupport();

	bool bindAttribute(UInt32 index,
						Int32 size,
						P_VDTYPE type,
						bool normalized,
						UInt32 stride,
						UInt32 pointer);*/

private:
	DISALLOW_COPY_AND_ASSIGN(Vertice);

private: 
	PrimitiveType m_ePriType;
	UInt32 m_uPriCount;
	UInt8* m_pVertexBuffer;
	UInt32 m_uVertexSize;
	UInt32 m_uVertexCount;
	UInt32 m_uVertexBufferSize;

	UInt8* m_pIndexBuffer;
	UInt32 m_uIndexCount;
	UInt32 m_uIndexBufferSize;
	std::vector<VertexAttribute> m_vertexAttribute;

};
#endif // !VERTICE_H
