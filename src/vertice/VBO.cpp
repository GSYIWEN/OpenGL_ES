#include "include\vertice\VBO.h"

//namespace OpenGL_ES
//{
	VBO::VBO(RenderObjType rType)
		: m_eTarget(GL_ARRAY_BUFFER)
		, m_eUsage(GL_STATIC_DRAW)
		, m_iHandle(0)
		, m_iSize(0)
		, m_eType(rType)
		, m_pVBOSystem(NULL)
	{
		m_pVBOSystem = VBOSystem::instance();
	}

	VBO::~VBO()
	{
	}

	SpVBOIF
		VBO::create(RenderObjType rType)
	{
		SpVBOIF vbo(new VBO(rType));
		return vbo;
	}

	bool
	VBO::bindData(BufferObjType eType, const void* pBuffer, UInt32 uSize, BufferUsageType eUsage)
	{
		if ((NULL == pBuffer) || !uSize)
		{
			return false;
		}

		if (NULL == m_pVBOSystem) {
			return false;
		}

		GLenum eTarget = GL_ARRAY_BUFFER;
		if (eUsage == BOT_ARRAY_BUFFER)
		{
			eTarget = GL_ARRAY_BUFFER;
		}
		else {
			eTarget = GL_ELEMENT_ARRAY_BUFFER;
		}
		
		if (!m_pVBOSystem->genBuffers(eTarget, 1, &m_iHandle, m_eType)) {
			m_iHandle = 0;
			return false;
		}

		if (!m_pVBOSystem->bindBuffer(eTarget, m_iHandle)) {
			release();
			return false;
		}

		GLenum eGLUsage = GL_STATIC_DRAW;
		switch (eUsage)
		{
		case BUT_STREAM_DRAW:
			eGLUsage = GL_STREAM_DRAW;
			break;
		case BUT_STATIC_DRAW:
			eGLUsage = GL_STATIC_DRAW;
			break;
		case BUT_DYNAMIC_DRAW:
			eGLUsage = GL_DYNAMIC_DRAW;
			break;
		default:
			eGLUsage = GL_STATIC_DRAW;
			break;
		}
		
		if (!m_pVBOSystem->bufferData(eTarget, uSize, pBuffer, eGLUsage, m_eType)) {
			release();
			return false;
		}

		m_eTarget = eTarget;
		m_eUsage = eGLUsage;
		m_iSize = uSize;

		return true;
	}

	bool
	VBO::updateData(UInt32 uOffset, UInt32 uSize, const void* pBuffer)
	{
		if ((NULL == pBuffer) || (uSize == 0)) {
			return false;
		}

		if (uOffset + uSize > m_iSize) {
			return false;
		}

		if (NULL == m_pVBOSystem) {
			return false;
		}

		if (!m_pVBOSystem->bindBuffer(m_eTarget, m_iHandle)) {
			return false;
		}

		return true;
	}

	bool
	VBO::bind()
	{
		if (0 == m_iHandle) {
			return false;
		}
		if (NULL == m_pVBOSystem) {
			return false;
		}

		if (!m_pVBOSystem->bindBuffer(m_eTarget, m_iHandle)) {
			return false;
		}

		return true;
	}

	bool
	VBO::unbind()
	{
		if (NULL == m_pVBOSystem) {
			return false;
		}

		if (!m_pVBOSystem->bindBuffer(m_eTarget, 0)) {
			return false;
		}
		return true;
	}

	void 
	VBO::release()
	{
		if (NULL == m_pVBOSystem) {
			return;
		}

		if (!m_pVBOSystem->deleteBuffers(m_eTarget, 1, &m_iHandle)) {
			m_iHandle = 0;
			return;
		}

		m_iHandle = 0;
	}

	bool
	VBO::isValid() {
		return m_iHandle;
	}
//}