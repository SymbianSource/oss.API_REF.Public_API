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
* CAuthExpression declaration
*
*/


/**
 @file 
 @publishedAll
 @released
*/

#ifndef AUTHEXPRESSION_H
#define AUTHEXPRESSION_H

#include <s32strm.h>
#include "authserver/authtypes.h"


namespace AuthServer
{


class CAuthExpression : public CBase
/**
	Describes an authentication expression.

	AuthServer clients construct expressions using
	AuthExpr, combined with AuthAnd and AuthOr, or
	the equivalent overloaded & and | operators.

	@see AuthExpr
	@see AuthAnd
	@see AuthOr
 */
	{
public:
	/**
		Externalize this object to the supplied stream.

		@param	aWriteStream Stream to write persistent state to.
	 */
	virtual void ExternalizeL(RWriteStream& aWriteStream) const = 0;
	};


class TAuthExpressionWrapper
/**
	Simple wrapper around a pointer to an authentication
	expression.  It is defined so the binary & and | operators
	can be overloaded to generate concise expressions.
	
	Like CAuthExpression, this class should not be
	used directly by clients, but via the AuthExpr,
	AuthAnd, and AuthOr functions, or via the overloaded
	& and | operators.  For this reason, the constructors
	are not exported.
	
	@see AuthExpr
	@see AuthAnd
	@see AuthOr
 */
	{
public:
	/* @internalComponent*/
	TAuthExpressionWrapper(CAuthExpression* aExpression);
	/* @internalComponent */
	TAuthExpressionWrapper(TAuthPluginType aType);
	/* @internalComponent */
	TAuthExpressionWrapper(TPluginId aPluginId);
	/* @internalComponent */
	TAuthExpressionWrapper();
	
	inline operator CAuthExpression*();
	
private:
	/**
		Pointer to the referenced authentication expression.
		This is NULL in OOM.
	 */
	CAuthExpression*const iPtr;
	};


IMPORT_C TAuthExpressionWrapper AuthExpr(TAuthPluginType aType);
IMPORT_C TAuthExpressionWrapper AuthExpr(TPluginId aPluginId);
IMPORT_C TAuthExpressionWrapper AuthExpr();

IMPORT_C TAuthExpressionWrapper AuthOr(CAuthExpression* aLeft, CAuthExpression* aRight);
IMPORT_C TAuthExpressionWrapper AuthAnd(CAuthExpression* aLeft, CAuthExpression* aRight);


#define AUTH_EXPR_BINARY_OPS
#ifdef AUTH_EXPR_BINARY_OPS

// These binary operators provide a more concise way to write
// authentication expressions than AuthOr and AuthAnd.  However,
// their behaviour - dynamically allocating from the heap - is
// non-obvious to a reader, so they are left as a build-time
// option.

inline TAuthExpressionWrapper operator&(TAuthExpressionWrapper aLeft, TAuthExpressionWrapper aRight);
inline TAuthExpressionWrapper operator|(TAuthExpressionWrapper aLeft, TAuthExpressionWrapper aRight);

#endif


}	// namespace AuthServer

#include "authserver/authexpression.inl"

#endif // EXPRESSION_H
