/*
* Copyright (c) 2006-2007 Nokia Corporation and/or its subsidiary(-ies).
* All rights reserved.
* This component and the accompanying materials are made available
* under the terms of "Eclipse Public License v1.0"
* which accompanies this distribution, and is available
* at the URL "http://www.eclipse.org/legal/epl-v10.html".
*
* Initial Contributors:
* Nokia Corporation - initial contribution.
*
* Contributors:
*
* Description:  A parameter class for a find operation.
*
*/


#ifndef T_TVPBKWORDPARSERCALLBACKPARAM_H
#define T_TVPBKWORDPARSERCALLBACKPARAM_H

#include <e32def.h>

/**
 * A parameter class for a find operation.
 *
 * The parameter is used in TCallBack parameter to the client when it uses
 * the find operation of the contact manager. The find operations will
 * then leave the parsing of words to clients responsibility.
 * The Virtual Phonebook store implementation will set the iStringToParse
 * and client then fills the iWordArray.
 *
 * @see CVPbkContactManager::FindL
 */
struct TVPbkWordParserCallbackParam
    {
    /**
     * Constructor.
     *
     * @param aStringToParse a string that must be parsed to iWordArray
     * @param aWordArray an array for parsed words
     */
    inline TVPbkWordParserCallbackParam( const TDesC* aStringToParse, 
        CDesCArray* aWordArray ) 
        :   iStringToParse( aStringToParse ), 
            iWordArray( aWordArray ) {}

    /**
     * Not Own: a string that client must parse.
     */
    const TDesC* iStringToParse;

    /**
     * Not Own: an array for parsed words.
     */
    CDesCArray* iWordArray;
    };

#endif // T_TVPBKWORDPARSERCALLBACKPARAM_H
