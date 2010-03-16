/*
* Copyright (c) 1997-2009 Nokia Corporation and/or its subsidiary(-ies).
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
*
*/






/**
 @file
 @publishedAll
 @released
*/

#ifndef	_MACHTYPES_H_
#define	_MACHTYPES_H_

#define	_CLOCK_T_   signed int	/* clock() - EPOC32 TInt */
#define	_TIME_T_    signed int	/* time()  - EPOC32 TInt */

#define CLOCKS_PER_SEC 1		/* machine dependent */
#define CLK_TCK CLOCKS_PER_SEC

#endif	/* _MACHTYPES_H_ */
