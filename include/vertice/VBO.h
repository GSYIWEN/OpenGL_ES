#ifndef  _VBO_H
#define  _VBO_H
//#include "GLES2\gl2.h"
//#include "GLES2\gl2ext.h"
#include "include\vertice\VBOIF.h"
#include "include\DefinedTypes.h"
#include "include\vertice\VBOSystem.h"
class VBO : public VBOIF
{
public:
	static SpVBOIF
	create(RenderObjType rType);

	virtual ~VBO();
protected:

	VBO(RenderObjType rType);

	virtual bool
	bindData(BufferObjType eType, const void* pBuffer, UInt32 uSize, BufferUsageType eUsage = BUT_STATIC_DRAW);

	virtual bool
	updateData(UInt32 uOffset, UInt32 uSize, const void* pBuffer);

	virtual bool
	bind();

	virtual bool
	unbind();

	virtual void
	release();

	bool
	isValid();

private:
	VBO(const VBO& vbo);
	VBO& operator=(const VBO& vbo) {}

private:
	GLenum m_eTarget; //vbo type
	GLenum m_eUsage;  //vbo usage type
	GLuint m_iHandle; //vbo handle
	UInt32 m_iSize;
	RenderObjType m_eType;
	VBOSystem* m_pVBOSystem;


};

#endif // ! _VBO_H
