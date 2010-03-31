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
* Description:       DOM errors codes
*
*/








/**
 * NOTE1: All errors returned by DOM parser (positive values) are propagated from open-source library.
 * They can be found in documentation to Libxml2 (version 2.6.10). See http://xmlsoft.org, and find enum xmlParserErrors.
 *
 * NOTE2: This errors CANNOT be propagated to other applications. 
 *        It should be handled by user application.
 */

#ifndef XMLENGINE_DOM_ERRORS_H__
#define XMLENGINE_DOM_ERRORS_H__

#include <e32def.h> 

/** DOM parsing error */
const TInt KXmlEngErrParsing = -32397;
/** DOM save errors */
const TInt KXmlEngErrNegativeOutputSize = -32383;
const TInt KXmlEngErrWrongEncoding = -32382;

/** KXmlEngErrNullNode error */
const TInt KXmlEngErrNullNode = -32380;
/** KXmlEngErrWrongUseOfAPI error */
const TInt KXmlEngErrWrongUseOfAPI = -32381;

#endif // XMLENGINE_DOM_ERRORS_H__

/*
* PARSING ERRORS:
*
*     XML_ERR_OK = 0 
*    XML_ERR_INTERNAL_ERROR 				 1  
*    XML_ERR_NO_MEMORY 						 2  
*    XML_ERR_DOCUMENT_START 				 3  
*    XML_ERR_DOCUMENT_EMPTY 				 4  
*    XML_ERR_DOCUMENT_END 					 5  
*    XML_ERR_INVALID_HEX_CHARREF 			 6  
*    XML_ERR_INVALID_DEC_CHARREF 			 7  
*    XML_ERR_INVALID_CHARREF 				 8  
*    XML_ERR_INVALID_CHAR 					 9  
*    XML_ERR_CHARREF_AT_EOF 				 10 
*    XML_ERR_CHARREF_IN_PROLOG 				 11 
*    XML_ERR_CHARREF_IN_EPILOG 				 12 
*    XML_ERR_CHARREF_IN_DTD 				 13 
*    XML_ERR_ENTITYREF_AT_EOF 				 14 
*    XML_ERR_ENTITYREF_IN_PROLOG 			 15 
*    XML_ERR_ENTITYREF_IN_EPILOG 			 16 
*    XML_ERR_ENTITYREF_IN_DTD 				 17 
*    XML_ERR_PEREF_AT_EOF 					 18 
*    XML_ERR_PEREF_IN_PROLOG 				 19 
*    XML_ERR_PEREF_IN_EPILOG 				 20 
*    XML_ERR_PEREF_IN_INT_SUBSET 			 21 
*    XML_ERR_ENTITYREF_NO_NAME 				 22 
*    XML_ERR_ENTITYREF_SEMICOL_MISSING	 	 23 
*    XML_ERR_PEREF_NO_NAME 					 24 
*    XML_ERR_PEREF_SEMICOL_MISSING 			 25 
*    XML_ERR_UNDECLARED_ENTITY 				 26 
*    XML_WAR_UNDECLARED_ENTITY 				 27 
*    XML_ERR_UNPARSED_ENTITY 				 28 
*    XML_ERR_ENTITY_IS_EXTERNAL 			 29 
*    XML_ERR_ENTITY_IS_PARAMETER 			 30 
*    XML_ERR_UNKNOWN_ENCODING 				 31 
*    XML_ERR_UNSUPPORTED_ENCODING 			 32 
*    XML_ERR_STRING_NOT_STARTED 			 33 
*    XML_ERR_STRING_NOT_CLOSED 				 34 
*    XML_ERR_NS_DECL_ERROR 					 35 
*    XML_ERR_ENTITY_NOT_STARTED 			 36 
*    XML_ERR_ENTITY_NOT_FINISHED 			 37 
*    XML_ERR_LT_IN_ATTRIBUTE 				 38 
*    XML_ERR_ATTRIBUTE_NOT_STARTED 			 39 
*    XML_ERR_ATTRIBUTE_NOT_FINISHED 		 40 
*    XML_ERR_ATTRIBUTE_WITHOUT_VALUE		 41 
*    XML_ERR_ATTRIBUTE_REDEFINED 			 42 
*    XML_ERR_LITERAL_NOT_STARTED 			 43 
*    XML_ERR_LITERAL_NOT_FINISHED 			 44 
*    XML_ERR_COMMENT_NOT_FINISHED 			 45 
*    XML_ERR_PI_NOT_STARTED 				 46 
*    XML_ERR_PI_NOT_FINISHED 				 47 
*    XML_ERR_NOTATION_NOT_STARTED 			 48 
*    XML_ERR_NOTATION_NOT_FINISHED 			 49 
*    XML_ERR_ATTLIST_NOT_STARTED 			 50 
*    XML_ERR_ATTLIST_NOT_FINISHED 			 51 
*    XML_ERR_MIXED_NOT_STARTED 				 52 
*    XML_ERR_MIXED_NOT_FINISHED 			 53 
*    XML_ERR_ELEMCONTENT_NOT_STARTED 		 54 
*    XML_ERR_ELEMCONTENT_NOT_FINISHED		 55 
*    XML_ERR_XMLDECL_NOT_STARTED 			 56 
*    XML_ERR_XMLDECL_NOT_FINISHED 			 57 
*    XML_ERR_CONDSEC_NOT_STARTED 			 58 
*    XML_ERR_CONDSEC_NOT_FINISHED 			 59 
*    XML_ERR_EXT_SUBSET_NOT_FINISHED		 60 
*    XML_ERR_DOCTYPE_NOT_FINISHED 			 61 
*    XML_ERR_MISPLACED_CDATA_END 			 62 
*    XML_ERR_CDATA_NOT_FINISHED 			 63 
*    XML_ERR_RESERVED_XML_NAME 				 64 
*    XML_ERR_SPACE_REQUIRED 				 65 
*    XML_ERR_SEPARATOR_REQUIRED 			 66 
*    XML_ERR_NMTOKEN_REQUIRED 				 67 
*    XML_ERR_NAME_REQUIRED 					 68 
*    XML_ERR_PCDATA_REQUIRED 				 69 
*    XML_ERR_URI_REQUIRED 					 70 
*    XML_ERR_PUBID_REQUIRED 				 71 
*    XML_ERR_LT_REQUIRED 					 72 
*    XML_ERR_GT_REQUIRED 					 73 
*    XML_ERR_LTSLASH_REQUIRED 				 74 
*    XML_ERR_EQUAL_REQUIRED 				 75 
*    XML_ERR_TAG_NAME_MISMATCH 				 76 
*    XML_ERR_TAG_NOT_FINISHED 				 77 
*    XML_ERR_STANDALONE_VALUE 				 78 
*    XML_ERR_ENCODING_NAME 					 79 
*    XML_ERR_HYPHEN_IN_COMMENT 				 80 
*    XML_ERR_INVALID_ENCODING 				 81 
*    XML_ERR_EXT_ENTITY_STANDALONE 			 82 
*    XML_ERR_CONDSEC_INVALID 				 83 
*    XML_ERR_VALUE_REQUIRED 				 84 
*    XML_ERR_NOT_WELL_BALANCED 				 85 
*    XML_ERR_EXTRA_CONTENT 					 86 
*    XML_ERR_ENTITY_CHAR_ERROR 				 87 
*    XML_ERR_ENTITY_PE_INTERNAL 			 88 
*    XML_ERR_ENTITY_LOOP 					 89 
*    XML_ERR_ENTITY_BOUNDARY 				 90 
*    XML_ERR_INVALID_URI 					 91 
*    XML_ERR_URI_FRAGMENT 					 92 
*    XML_WAR_CATALOG_PI 					 93 
*    XML_ERR_NO_DTD 						 94 
*    XML_ERR_CONDSEC_INVALID_KEYWORD 		 95 
*    XML_ERR_VERSION_MISSING 				 96 
*    XML_WAR_UNKNOWN_VERSION 				 97 
*    XML_WAR_LANG_VALUE 					 98 
*    XML_WAR_NS_URI 						 99 
*    XML_WAR_NS_URI_RELATIVE 				 100 
*    XML_ERR_MISSING_ENCODING 				 101 
*    XML_NS_ERR_XML_NAMESPACE			     200
*    XML_NS_ERR_UNDEFINED_NAMESPACE 		 201 
*    XML_NS_ERR_QNAME 						 202 
*    XML_NS_ERR_ATTRIBUTE_REDEFINED 		 203 
*/    

