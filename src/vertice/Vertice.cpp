#include "include\vertice\Vertice.h"
#include "include\vertice\VerticeIF.h"

Vertice::Vertice(bool bUpdate)
: m_ePriType(PRT_INVALID)
, m_uPriCount(0)
, m_pVertexBuffer(NULL)
, m_uVertexSize(0)
, m_uVertexCount(0)
, m_uVertexBufferSize(0)
, m_pIndexBuffer(NULL)
, m_uIndexCount(0)
, m_uIndexBufferSize(0)
{

}

SpVerticeIF
Vertice::create(bool bUpdate) 
{
	SpVerticeIF sp(reinterpret_cast<VerticeIF*>(new Vertice(bUpdate)));
	return sp;
}

Vertice::~Vertice()
{
	if (NULL != m_pVertexBuffer) {
		DELETEARRAY_ASSIGNNULL(m_pVertexBuffer);
	}

	if (NULL != m_pIndexBuffer) {
		DELETEARRAY_ASSIGNNULL(m_pIndexBuffer);
	}
}

UInt8*
Vertice::createVertexData(UInt32 vertexSize, UInt32 vertexCount, enum RenderObjType type)
{
	if (NULL != m_pVertexBuffer) {
		m_pVertexBuffer = NULL;
		m_uVertexSize = 0;
		m_uVertexBufferSize = 0;
		m_uVertexCount = 0;
	}

	UInt32 uBufferSize = vertexSize * vertexCount;
	if (0 == uBufferSize) {
		return NULL;
	}

	m_pVertexBuffer = new UInt8[uBufferSize];
	if (NULL != m_pVertexBuffer) {
		memset(m_pVertexBuffer, 0, uBufferSize);
		m_uVertexBufferSize = uBufferSize;
		m_uVertexCount = vertexCount;
		m_uVertexSize = vertexSize;
	}

	return m_pVertexBuffer;
}

const UInt32&
Vertice::getVertexSize() const
{
	return m_uVertexSize;
}

const UInt32& 
Vertice::getVertexBufferSize() const
{
	return m_uVertexBufferSize;
}

void 
Vertice::setPrimitiveType(PrimitiveType ePt)
{
	m_ePriType = ePt;	
}

const PrimitiveType& 
Vertice::getPrimitiveType() const
{
	return m_ePriType;
}

UInt8* 
Vertice::createIndexData(VertexIndexType eVIT, UInt32 uIndexCount, enum RenderObjType type)
{
	if (NULL != m_pIndexBuffer) {
		DELETEARRAY_ASSIGNNULL(m_pIndexBuffer);
		m_uIndexBufferSize = 0;
		m_uIndexCount = 0;
	}

	UInt32 uBufferSize = 0;
	switch (eVIT)
	{
	case VIT_UINT16:
		uBufferSize = sizeof(UInt16);
		break;
	case VIT_UINT8:
		uBufferSize = sizeof(UInt8);
		break;
	default:
		uBufferSize = 0;
		break;
	}

	uBufferSize *= uIndexCount;
	if (0 == uBufferSize) {
		return NULL;
	}

	m_pIndexBuffer = new UInt8[uBufferSize];
	if (NULL != m_pIndexBuffer) {
		m_uIndexBufferSize = uBufferSize;
		m_uIndexCount = uIndexCount;
	}

	return m_pIndexBuffer;
}

const UInt32& 
Vertice::getIndexBufferSize() const
{
	return m_uIndexBufferSize;
}

const UInt32& 
Vertice::getIndexCount() const
{
	return m_uIndexCount;
}

const UInt8* 
Vertice::getIndexData() const
{
	return m_pIndexBuffer;
}

const UInt8* 
Vertice::getVertexData() const
{
	return m_pVertexBuffer;
}