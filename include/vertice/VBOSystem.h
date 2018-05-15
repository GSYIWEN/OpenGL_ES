#ifndef _VBOSYSTEM_H
#define _VBOSYSTEM_H
#include "include\DefinedTypes.h"
#include <GLES3\gl3.h>
#include <map>

	struct VBOAttribute
	{
		UInt32 mSize;
		GLenum mTarget;
		UInt32 mUpdateID;
		RenderObjType mType;

		VBOAttribute()
		: mSize(0)
		, mTarget(GL_INVALID_ENUM)
		, mUpdateID(0)
		, mType(ROT_INVALID)
		{
		}

		VBOAttribute(UInt32 iSize, GLenum eTarget, RenderObjType eType)
		: mSize(iSize)
		, mTarget(eTarget)
		, mUpdateID(0)
		, mType(eType)
		{

		}

		VBOAttribute& operator=(const VBOAttribute& rhs)
		{
			if (this != &rhs) {
				mSize = rhs.mSize;
				mTarget = rhs.mTarget;
				mUpdateID = rhs.mUpdateID;
				mType = rhs.mType;
			}
			return(*this);
		}

		VBOAttribute(const VBOAttribute& rhs)
		: mSize(rhs.mSize)
		, mTarget(rhs.mTarget)
		, mUpdateID(rhs.mUpdateID)
		, mType(rhs.mType)
		{

		}

		bool
		operator>(const VBOAttribute& rhs) const
		{
			return(mSize > rhs.mSize);
		}

		bool
		operator<(const VBOAttribute& rhs) const
		{
			return(mSize < rhs.mSize);
		}
	};


	struct VBONode
	{
		GLuint mHandle;
		VBOAttribute mAttri;

		VBONode()
		: mHandle(0)
		, mAttri()
		{

		}

		VBONode(GLuint buffer, GLenum eTarget, UInt32 iSize, RenderObjType eType)
		: mHandle(buffer)
		, mAttri(iSize, eTarget, eType) 
		{

		}

		VBONode(GLuint buffer, const VBOAttribute& rhs)
		: mHandle(buffer)
		, mAttri(rhs)
		{

		}

		VBONode& operator=(const VBONode& rhs) {
			if (this != &rhs) {
				mHandle = rhs.mHandle;
				mAttri = rhs.mAttri;
			}
			return *this;
		}

		VBONode(const VBONode& rhs)
		: mHandle(rhs.mHandle)
		, mAttri(rhs.mAttri)
		{

		}

		bool operator==(const VBONode& rhs) const
		{
			return (mHandle == rhs.mHandle);
		}

		bool operator>(const VBONode& rhs) const
		{
			return (mAttri > rhs.mAttri);
		}

		bool operator<(const VBONode& rhs) const
		{
			return (mAttri < rhs.mAttri);
		}
	};

	class VBOSystem
	{
	public:
		static VBOSystem* instance();

		static void destroy();

		bool genBuffers(GLenum target, GLsizei n, GLuint* buffers, RenderObjType eType);

		bool bindBuffer(GLenum target, GLuint buffer);

		bool bufferData(GLenum target, GLsizeiptr size, const GLvoid* data, GLenum usage, RenderObjType BufferUsageType);

		bool bufferSubData(GLenum target, GLintptr offset, GLsizeiptr size, const GLvoid* data);

		bool deleteBuffers(GLenum target, GLsizei n, GLuint* buffers);

		void updateID(UInt32 iID);

		//void optmize(bool bEnable);

	protected:
		VBOSystem();

		virtual ~VBOSystem();

		//void start();

		void stop();

	private:
		//typedef List<VBONode> vbo_queue;
		typedef std::map<GLenum, VBOAttribute> vbo_map;
		vbo_map m_cUsedQueue;
		UInt32 m_iUsedSize;
		GLuint m_curHandle;
		UInt32 m_iUpdateID;

		static VBOSystem* s_pInstance;

	};
#endif // !_VBOSYSTEM_H
