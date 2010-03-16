/*
* Copyright (c) 2004-2005 Nokia Corporation and/or its subsidiary(-ies). 
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
* Description:       Interface class describing class that may be used as
*                 output stream for dom tree
*
*/







#ifndef XMLENGINE_MOUTPUTSTREAM_H_INCLUDED
#define XMLENGINE_MOUTPUTSTREAM_H_INCLUDED

#include <e32base.h>



/**
 * MXmlEngOutputStream is used by XML Engine to write serialized XML data
 * to stream. This interface should be implemented by client application
 * when RXmlEngDocument::SaveL() method is used to serialize xml data to stream.
 *
 * @lib XmlEngineDOM.lib
 * @since S60 v3.1
 */
class MXmlEngOutputStream
    {
public:
    /**
     * Callback for writing a buffer with data to output stream
     *
     * @since S60 v3.1
     * @return number of bytes written or -1 in case of error
     */
    virtual TInt Write(const TDesC8& aBuffer) = 0;

    /**
     * Callback for closing output stream
     *
     * @since S60 v3.1
     * @return 
     *       0 is succeeded, 
     *      -1 in case of error
     */
    virtual TInt Close() = 0;
    };



#endif /* XMLENGINE_MOUTPUTSTREAM_H_INCLUDED */  
