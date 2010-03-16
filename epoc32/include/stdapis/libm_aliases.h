/*
* Copyright (c) 2006-2009 Nokia Corporation and/or its subsidiary(-ies).
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
* Name        : libm_aliases.h
* Part of     : libm
* This Header contains the macro declarations which serves the purposes of
* weak and strong aliases.
* Version     : 1.0
* Redistribution and use in source and binary forms, with or without 
* modification, are permitted provided that the following conditions are met:
* * Redistributions of source code must retain the above copyright notice, this 
* list of conditions and the following disclaimer. 
* * Redistributions in binary form must reproduce the above copyright notice, 
* this list of conditions and the following disclaimer in the documentation 
* and/or other materials provided with the distribution. 
* * Neither the name of the <ORGANIZATION> nor the names of its contributors 
* may be used to endorse or promote products derived from this software 
* without specific prior written permission. 
* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" 
* AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE 
* IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE 
* DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE
* FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL 
* DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR 
* SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER 
* CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
* OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE 
* OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*
*/



#ifndef __LIBM_ALIASES_H__
#define __LIBM_ALIASES_H__

#define frexpl 	frexp
#define nexttoward 	nextafter
#define nexttowardl	nextafter
#define nextafterl nextafter
#define ldexpl scalbn
#define	ldexpf scalbnf
#define scalbnl scalbn



/*
following are the aliases defined for the longdouble apis
*/
#define  	cbrtl  	cbrt
#define  	ceill  	ceil
#define  	erfl   	erf
#define 	erfcl  	erfc
#define 	expl   	exp
#define 	exp2l  	exp2
#define 	expm1l 	expm1
#define 	j0l  	j0
#define 	j1l  	j1
#define 	lrintl	lrint
#define 	lroundl	lround
#define 	roundl	round
#define 	logl	log
#define		log10l 	log10
#define		log1pl 	log1p
#define		logbl 	logb
#define		rintl 	rint
#define		sqrtl 	sqrt
#define		y0l 	y0
#define		y1l 	y1
#define		significandl 	significand
#define		nearbyintl 		nearbyint
#define 	finitel			finite
#define 	floorl			floor
#define 	fmal			fma
#define		fminl			fmin
#define 	gammal			gamma
#define 	lgammal			lgamma
#define		cosl			cos
#define		acosl			acos
#define		acoshl			acosh
#define		asinl			asin
#define		asinhl			asinh
#define		atanl			atan
#define		atanhl			atanh
#define		sinl			sin
#define		sinhl			sinh
#define		coshl			cosh
#define 	tanl			tan
#define 	tanhl			tanh
#define 	atan2l		atan2
#define		powl			pow
#define		dreml			drem
#define		fmodl			fmod
#define		hypotl			hypot
#define		remainderl		remainder
#define		jnl				jn
#define		ynl				yn
#define		scalbl			scalb
#define		modfl			modf
#define		remquol			remquo
#define		llrintl			llrint
#define		llroundl		llround

#endif /*__LIBM_ALIASES_H__*/
