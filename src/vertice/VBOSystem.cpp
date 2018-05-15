#include "include\vertice\VBOSystem.h"

VBOSystem* VBOSystem::s_pInstance = NULL;

VBOSystem*
VBOSystem::instance() {
	if (NULL == s_pInstance) {
		s_pInstance = new VBOSystem;
	}
	return s_pInstance;
}

void 
VBOSystem::destroy()
{
	if (NULL != s_pInstance) {
		s_pInstance->stop();
		DELETE_ASSIGNNULL(s_pInstance);
	}
}

VBOSystem::VBOSystem()
: m_cUsedQueue()
, m_iUsedSize(0)
, m_curHandle(0)
, m_iUpdateID(0)
{

}

VBOSystem::~VBOSystem()
{

}

bool 
VBOSystem::genBuffers(GLenum target, GLsizei n, GLuint* buffers, RenderObjType eType)
{
	if (eType == ROT_INVALID || (target == GL_INVALID_ENUM)) {
		return false;
	}

	GLuint* uHandle = NEWARRAY(GLuint, n);
	glGenBuffers(n, uHandle);

	if (GL_NO_ERROR != glGetError()) {
		DELETEARRAY_ASSIGNNULL(uHandle);
		return false;
	}

	for (UInt8 i = 0; i < n; ++i) {
		buffers[i] = uHandle[i];
		m_cUsedQueue.insert(std::make_pair(buffers[i], VBOAttribute(0, target, eType)));
	}

	DELETEARRAY_ASSIGNNULL(uHandle);
	return true;
}

bool
VBOSystem::bindBuffer(GLenum target, GLuint buffer)
{
	if (GL_INVALID_ENUM == target) {
		return false;
	}

	glBindBuffer(target, buffer);

	if (GL_NO_ERROR != glGetError()) {
		m_curHandle = 0;
		return false;
	}

	m_curHandle = buffer;

	if (0!= m_curHandle) {
		vbo_map::iterator itFind = m_cUsedQueue.find(m_curHandle);
		if (itFind != m_cUsedQueue.end()) {
			(itFind->second).mUpdateID = m_iUpdateID;
		}
	}

	return true;
}

bool
VBOSystem::bufferData(GLenum target, GLsizeiptr size, const GLvoid* data, GLenum usage, RenderObjType eType)
{
	if (m_curHandle == 0
		|| eType == ROT_INVALID
		|| target == GL_INVALID_ENUM) {
		return false;
	}

	glBufferData(target, size, data, usage);

	if (GL_NO_ERROR != glGetError()) {
		return false;
	}

	m_cUsedQueue[m_curHandle].mType = eType;
	m_cUsedQueue[m_curHandle].mTarget = target;
	m_cUsedQueue[m_curHandle].mSize = size;

	return true;
}

bool 
VBOSystem::bufferSubData(GLenum target, GLintptr offset, GLsizeiptr size, const GLvoid* data)
{
	if (m_curHandle == 0 || target == GL_INVALID_ENUM) {
		return false;
	}

	glBufferSubData(target, offset, size, data);
	if (GL_NO_ERROR != glGetError()) {
		return false;
	}

	return true;
}

bool 
VBOSystem::deleteBuffers(GLenum target, GLsizei n, GLuint* buffers) {
	if (NULL == buffers || target == GL_INVALID_ENUM) {
		return false;
	}

	for (UInt32 i = 0; i < n; ++i) {
		vbo_map::iterator itFind = m_cUsedQueue.find(buffers[i]);
		if (itFind != m_cUsedQueue.end()) {
			m_cUsedQueue.erase(itFind);
		}
	}

	return true;
}

void 
VBOSystem::updateID(UInt32 iID) {
	m_iUpdateID = iID;
}

void 
VBOSystem::stop()
{
	UInt32 iSize = m_cUsedQueue.size();

	GLuint* uHandles = NEWARRAY(GLuint, iSize);
	UInt32 iNum = 0;
	for (vbo_map::const_iterator it = m_cUsedQueue.begin(); it != m_cUsedQueue.end(); ++it) {
		if (it->first != 0) {
			uHandles[iNum++] = it->first;
		}
	}

	if (iNum > 0)
	{
		glDeleteBuffers(iNum, uHandles);
	}

	m_iUsedSize = 0;
	m_curHandle = 0;
	m_iUpdateID = 0;

	DELETEARRAY_ASSIGNNULL(uHandles);
}