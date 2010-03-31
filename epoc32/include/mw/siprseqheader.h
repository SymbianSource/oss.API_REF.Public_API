/*
* Copyright (c) 2004-2009 Nokia Corporation and/or its subsidiary(-ies).
* All rights reserved.
* This component and the accompanying materials are made available
* under the terms of the License "Symbian Foundation License v1.0" to Symbian Foundation members and "Symbian Foundation End User License Agreement v1.0" to non-members
* which accompanies this distribution, and is available
* at the URL "http://www.symbianfoundation.org/legal/licencesv10.html".
*
* Initial Contributors:
* Nokia Corporation - initial contribution.
*
* Contributors:
*
* Description:
* Name        : siprseqheader.h
* Part of     : SIP Codec
* Interface   : SDK API, SIP Codec API
* Version     : SIP/4.0 
*
*/




#ifndef CSIPRSEQHEADER_H
#define CSIPRSEQHEADER_H

//  INCLUDES
#include "sipunsignedintheaderbase.h"
#include "_sipcodecdefs.h"

// CLASS DECLARATION
/**
* @publishedAll
* @released
*
* Class encapsulates a "RSeq"-header value.
*
*  @lib sipcodec.lib
*/
class CSIPRSeqHeader : public CSIPUnsignedIntHeaderBase
    {
    public: // Constructors and destructor

        /**
        * Constructs a CSIPRSeqHeader from textual representation 
        * of the header's value part.
        * @param aValue a value part of a "RSeq"-header (e.g. "123")
        * @return a new instance of CSIPRSeqHeader
        */
        IMPORT_C static CSIPRSeqHeader* DecodeL(const TDesC8& aValue);
    
        /**
        * Constructor
        * @param aValue the value to set
        */
        IMPORT_C CSIPRSeqHeader(TUint aValue);
    
        /**
        * Destructor, deletes the resources of CSIPRSeqHeader.
        */
        IMPORT_C ~CSIPRSeqHeader();


    public: // New functions

        /**
        * Constructs an instance of a CSIPRSeqHeader from a RReadStream
        * @param aReadStream a stream containing the value of the
        *        externalized header object (header name not included).
        * @return an instance of a CSIPRSeqHeader
        */
        IMPORT_C static CSIPHeaderBase* 
            InternalizeValueL(RReadStream& aReadStream);


    public: // From CSIPHeaderBase

        /**
        * From CSIPHeaderBase CloneL
        */
        IMPORT_C CSIPHeaderBase* CloneL() const;

        /**
        * From CSIPHeaderBase Name
        */
        IMPORT_C RStringF Name() const;


    public: // From CSIPHeaderBase, for internal use

        /**
        * @internalComponent
        */
        TPreferredPlace PreferredPlaceInMessage() const;

    public: // New functions, for internal use

        static RPointerArray<CSIPHeaderBase> BaseDecodeL(const TDesC8& aValue);

    private: // For testing purposes
    
        UNIT_TEST(CSIPRSeqHeaderTest)
    };

#endif // CSIPRSEQHEADER_H

// End of File
