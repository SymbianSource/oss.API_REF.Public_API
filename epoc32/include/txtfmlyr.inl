// Copyright (c) 1997-2009 Nokia Corporation and/or its subsidiary(-ies).
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




inline CParaFormatLayer* CParaFormatLayer::CloneL()const
/** Constructs and returns a new CParaFormatLayer with identical formatting to 
the current layer. Note that the function does not copy the original layer's 
based-on link - the new layer's based-on link is set to NULL, so that the 
two layers may not have the same effective formatting.

@return A new paragraph format layer cloned from the current layer. */
	{return STATIC_CAST(CParaFormatLayer*,DoCloneL());}




inline CCharFormatLayer* CCharFormatLayer::CloneL()const
/** Constructs and returns a new CCharFormatLayer with identical formatting to 
the current layer. Note that the function does not copy the original layer's 
based-on link - the new layer's based-on link is set to NULL, so that the 
two layers may not have the same effective formatting.

@return A new character format layer cloned from the current layer. */
	{return STATIC_CAST(CCharFormatLayer*,DoCloneL());}
