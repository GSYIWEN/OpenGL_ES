#ifndef  _VERTEXATTRIBUTE_H
#define  _VERTEXATTRIBUTE_H
//#include "../../include/DefinedTypes.h"
#include "include\DefinedTypes.h"

//namespace OpenGL_ES {

	class VertexAttribute
	{
	public:
		VertexAttribute(const P_ATTRIBUTEID& vaName,
			Int32 vaSize,
			P_VDTYPE vaType,
			bool vaNormalized,
			UInt32 vaStride,
			UInt32 vaPointer,
			UInt32 vaIndex)
			: name(vaName)
			, size(vaSize)
			, type(vaType)
			, normalized(vaNormalized)
			, stride(vaStride)
			, pointer(vaPointer)
			, index(vaIndex)
		{
		}

		~VertexAttribute() {};

	public:
		P_ATTRIBUTEID name;
		int			  size;
		P_VDTYPE      type;
		bool		  normalized;
		UInt32		  stride;
		UInt32	      pointer;
		UInt32		  index;
	};
//}
#endif // ! VERTEXATTRIBUTE_H

