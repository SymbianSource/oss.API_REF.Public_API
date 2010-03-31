/*
* Copyright (c) 2004-2006 Nokia Corporation and/or its subsidiary(-ies). 
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
* Description:       Processing instruction node functions
*
*/







#ifndef XMLENGINE_PROCESSINGINSTRUCTION_H_INCLUDED
#define XMLENGINE_PROCESSINGINSTRUCTION_H_INCLUDED

#include "xmlengnode.h"



/**
 * Instance of TXmlEngProcessingInstruction class represents an XML processing 
 * instruction in the DOM tree.
 * 
 * @lib XmlEngineDOM.lib
 * @since S60 v3.1
 */
class TXmlEngProcessingInstruction : public TXmlEngNode
{
  public:
    /**
     * Default constructor
     *
     * @since S60 v3.1
     */
	inline TXmlEngProcessingInstruction();
    
    /**
     * Get target of processing instruction.
     *
     * @since S60 v3.1
     * @return "Target" part of a processing instruction
     *
     * @code
     *    <?target data?>
     * @endcode
     * @see http://www.w3.org/TR/2004/REC-xml-20040204/#sec-pi
     */
    IMPORT_C TPtrC8 Target() const;

    /**
     * Get data of processing instruction.
     *
     * @since S60 v3.1
     * @return "Data" part of a processing instruction
     *
     * @code
     *    <?target data?>
     * @endcode
     * @see http://www.w3.org/TR/2004/REC-xml-20040204/#sec-pi
     */
    IMPORT_C TPtrC8 Data() const;

    /**
     * Sets data part of processing instruction
     *
     * @since S60 v3.1
     * @param aData New data part of processing instruction
     * @note PI contents should not contain "?>" sequence
     */
    IMPORT_C void SetDataL(const TDesC8& aData);

protected:
    /**
     * Constructor
     *
     * @since S60 v3.1
     * @param aInternal processing instruction pointer
     */
	inline TXmlEngProcessingInstruction(void* aInternal);
};



#include "xmlengprocessinginstruction.inl"
#endif /* XMLENGINE_PROCESSINGINSTRUCTION_H_INCLUDED */
