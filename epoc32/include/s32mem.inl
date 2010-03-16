// Copyright (c) 1998-2009 Nokia Corporation and/or its subsidiary(-ies).
// All rights reserved.
// This component and the accompanying materials are made available
// under the terms of the License "Symbian Foundation License v1.0" to Symbian Foundation members and "Symbian Foundation End User License Agreement v1.0" to non-members
// which accompanies this distribution, and is available
// at the URL "http://www.symbianfoundation.org/legal/licencesv10.html".
//
// Initial Contributors:
// Nokia Corporation - initial contribution.
//
// Contributors:
//
// Description:
//

// Class RMemWriteStream
inline RMemWriteStream::RMemWriteStream(const MExternalizer<TStreamRef>& anExter)
	: RWriteStream(anExter)
/** 
Constructs a write stream with an externalizer.  For example, CStoreMap implements 
MExternalizer<TStreamRef>. 

@param anExter Specifies an externalizer. 
@see MExternalizer
@see CStoreMap  
*/
	{}

// Class RDesWriteStream
inline RDesWriteStream::RDesWriteStream(const MExternalizer<TStreamRef>& anExter)
	: RWriteStream(anExter)
/** 
Constructs a write stream with an externalizer.  For example, CStoreMap implements 
MExternalizer<TStreamRef>. 

@param anExter Specifies an externalizer. 
@see MExternalizer
@see CStoreMap  
*/
	{}

// Class RBufWriteStream
inline RBufWriteStream::RBufWriteStream(const MExternalizer<TStreamRef>& anExter)
	: RWriteStream(anExter)
/** 
Constructs a write stream with an externalizer.  For example, CStoreMap implements 
MExternalizer<TStreamRef>. 

@param anExter Specifies an externalizer. 
@see MExternalizer
@see CStoreMap  
*/
	{}
	
inline void RBufWriteStream::Append(CBufBase& aBuf)
/** 
Open a stream that writes to a dynamic buffer using insert mode.

@param aBuf The dynamic buffer that will be the sink of this stream.
@see RBufWriteStream::Insert
*/
	{Insert(aBuf,aBuf.Size());}
