/*
* Copyright (c) 2005-2009 Nokia Corporation and/or its subsidiary(-ies).
* All rights reserved.
* This component and the accompanying materials are made available
* under the terms of the License "Eclipse Public License v1.0"
* which accompanies this distribution, and is available
* at the URL "http://www.eclipse.org/legal/epl-v10.html".
*
* Initial Contributors:
* Nokia Corporation - initial contribution.
*
* Contributors:
*
* Description: 
* @publishedAll
* @released
*
*/


#ifndef AUTHEXPRESSION_INL
#define AUTHEXPRESSION_INL

#include "authserver/authexpression.h"

namespace AuthServer
{


// -------- TAuthExpressionWrapper --------


inline TAuthExpressionWrapper::operator CAuthExpression*()
/**
	Conversion operator recasts this object as a
	pointer to the contained authorisation expression.
 */
	{
	return iPtr;
	}


#ifdef AUTH_EXPR_BINARY_OPS


inline TAuthExpressionWrapper operator&(TAuthExpressionWrapper aLeft, TAuthExpressionWrapper aRight)
/**
	This overloaded operator is a wrapper around a call to AuthAnd.
	See AuthAnd for a full description.	
	
	@param	aLeft			Left subexpression.
	@param	aRight			Right subexpression.
	@return					Wrapper around new complex AND expression,
							which is NULL if could not allocate.
	@see AuthAnd
 */
	{
	return AuthAnd(aLeft, aRight);
	}


inline TAuthExpressionWrapper operator|(TAuthExpressionWrapper aLeft, TAuthExpressionWrapper aRight)
/**
	This overloaded operator is a wrapper around a call to AuthOr
	See AuthOr for a full description.	
	
	@param	aLeft			Left subexpression.
	@param	aRight			Right subexpression.
	@return					Wrapper around new complex OR expression,
							which is NULL if could not allocate.
	@see AuthOr
 */
	{
	return AuthOr(aLeft, aRight);
	}


#endif	// #ifdef AUTH_EXPR_BINARY_OPS


}	// namespace AuthServer


#endif	// AUTHEXPRESSION_INL

