/*
* Copyright (c) 2004-2007 Nokia Corporation and/or its subsidiary(-ies).
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
* Description:  A generic field type interface.
*
*/


#ifndef MVPBKFIELDTYPE_H
#define MVPBKFIELDTYPE_H


// INCLUDES
#include <e32std.h>
#include <vpbkfieldtype.hrh>

// FORWARD DECLARATIONS
class TVPbkFieldVersitProperty;
class TVPbkFieldTypeParameters;

// CLASS DECLARATIONS

/**
 * Virtual Phonebook field types. 
 *
 * The following structure documents the field types the Virtual Phonebook
 * supports. The structure describes each field type and the type information
 * which is associated to the field type. More information on the field type
 * model can be acquired from the vCard specification. For the field type
 * definitions @see VPbkFieldType.hrh. 
 *
 *
 * field type description: Last name
 * field type resource id: r_vpbk_field_type_lastname
 * associated versit properties:
 *     versit property name: EVPbkVersitNameN
 *     versit property subfield: EVPbkVersitSubFieldFamilyName
 *     versit property name: EVPbkVersitNameFN
 * 
 * field type description: Last name reading
 * field type resource id: r_vpbk_field_type_lastnamereading
 * associated versit properties:
 *     versit property name: EVPbkVersitNameSOUND
 *     versit property subfield: EVPbkVersitSubFieldFamilyNamePronunciation
 * 
 * field type description: First name
 * field type resource id: r_vpbk_field_type_firstname
 * associated versit properties:
 *     versit property name: EVPbkVersitNameN
 *     versit property subfield: EVPbkVersitSubFieldGivenName
 * 
 * field type description: First name reading
 * field type resource id: r_vpbk_field_type_firstnamereading
 * associated versit properties:
 *     versit property name: EVPbkVersitNameSOUND
 *     versit property subfield: EVPbkVersitSubFieldGivenNamePronunciation
 * 
 * field type description: Prefix
 * field type resource id: r_vpbk_field_type_prefix
 * associated versit properties:
 *     versit property name: EVPbkVersitNameN
 *     versit property subfield: EVPbkVersitSubFieldNamePrefix
 * 
 * field type description: Suffix            
 * field type resource id: r_vpbk_field_type_suffix
 * associated versit properties:
 *     versit property name: EVPbkVersitNameN
 *     versit property subfield: EVPbkVersitSubFieldNameSuffix
 * 
 * field type description: Nick name
 * field type resource id: r_vpbk_field_type_secondname
 * associated versit properties:
 *     versit property name: EVPbkVersitNameX
 *     versit property extension name: "X-NICKNAME"
 * 
 * field type description: Landline phone (home)
 * field type resource id: r_vpbk_field_type_landphonehome
 * associated versit properties:
 *     versit property name: EVPbkVersitNameTEL
 *     versit parameter: EVPbkVersitParamHOME 
 * associated exclude parameters: 
 *     exclude parameter: EVPbkVersitParamFAX
 *     exclude parameter: EVPbkVersitParamPAGER
 *     exclude parameter: EVPbkVersitParamCELL
 *     exclude parameter: EVPbkVersitParamVIDEO
 *     exclude parameter: EVPbkVersitParamCAR
 * 
 * field type description: Mobile phone (home)
 * field type resource id: r_vpbk_field_type_mobilephonehome
 * associated versit properties:
 *     versit property name: EVPbkVersitNameTEL
 *     versit parameter: EVPbkVersitParamCELL
 *     versit parameter: EVPbkVersitParamHOME 
 * 
 * field type description: Video number (home)
 * field type resource id: r_vpbk_field_type_videonumberhome
 * associated versit properties:
 *     versit property name: EVPbkVersitNameTEL
 *     versit parameter: EVPbkVersitParamVIDEO
 *     versit parameter: EVPbkVersitParamHOME
 * 
 * field type description: Fax number (home)
 * field type resource id: r_vpbk_field_type_faxnumberhome
 * associated versit properties:
 *     versit property name: EVPbkVersitNameTEL
 *     versit parameter: EVPbkVersitParamFAX
 *     versit parameter: EVPbkVersitParamHOME 
 * 
 * field type description: VoIP (home)
 * field type resource id: r_vpbk_field_type_voiphome
 * associated versit properties:
 *     versit property name: EVPbkVersitNameX
 *     versit parameter: EVPbkVersitParamVOIP
 *     versit parameter: EVPbkVersitParamHOME 
 *     versit property extension name: "X-SIP"
 * 
 * field type description: Email address (home)
 * field type resource id: r_vpbk_field_type_emailhome
 * associated versit properties:
 *     versit property name: EVPbkVersitNameEMAIL
 *     versit parameter: EVPbkVersitParamINTERNET
 *     versit parameter: EVPbkVersitParamHOME 
 * 
 * field type description: URL (home)
 * field type resource id: r_vpbk_field_type_urlhome
 * associated versit properties:
 *     versit property name: EVPbkVersitNameURL
 *     versit parameter: EVPbkVersitParamHOME 
 * 
 * field type description: Address label (home)
 * field type resource id: r_vpbk_field_type_addrlabelhome
 * associated versit properties:
 *     versit property name: EVPbkVersitNameLABEL
 *     versit parameter: EVPbkVersitParamHOME 
 * 
 * field type description: Address Postoffice (home)
 * field type resource id: r_vpbk_field_type_addrpohome
 * associated versit properties:
 *     versit property name: EVPbkVersitNameADR
 *     versit property subfield: EVPbkVersitSubFieldPostOfficeAddress
 *     versit parameter: EVPbkVersitParamHOME
 * 
 * field type description: Address Extension (home)
 * field type resource id: r_vpbk_field_type_addrexthome
 * associated versit properties:
 *     versit property name: EVPbkVersitNameADR
 *     versit property subfield: EVPbkVersitSubFieldExtendedAddress
 *     versit parameter: EVPbkVersitParamHOME 
 * 
 * field type description: Address Street (home)
 * field type resource id: r_vpbk_field_type_addrstreethome
 * associated versit properties:
 *     versit property name: EVPbkVersitNameADR
 *     versit property subfield: EVPbkVersitSubFieldStreet
 *     versit parameter: EVPbkVersitParamHOME 
 * 
 * field type description: Address Locality (home)
 * field type resource id: r_vpbk_field_type_addrlocalhome
 * associated versit properties:
 *     versit property name: EVPbkVersitNameADR
 *     versit property subfield: EVPbkVersitSubFieldLocality
 *     versit parameter: EVPbkVersitParamHOME 
 * 
 * field type description: Address Region (home)
 * field type resource id: r_vpbk_field_type_addrregionhome
 * associated versit properties:
 *     versit property name: EVPbkVersitNameADR
 *     versit property subfield: EVPbkVersitSubFieldRegion
 *     versit parameter: EVPbkVersitParamHOME 
 * 
 * field type description: Address Postal Code (home)
 * field type resource id: r_vpbk_field_type_addrpostcodehome
 * associated versit properties:
 *     versit property name: EVPbkVersitNameADR
 *     versit property subfield: EVPbkVersitSubFieldPostalCode
 *     versit parameter: EVPbkVersitParamHOME 
 * 
 * field type description: Address Country (home)
 * field type resource id: r_vpbk_field_type_addrcountryhome
 * associated versit properties:
 *     versit property name: EVPbkVersitNameADR
 *     versit property subfield: EVPbkVersitSubFieldCountry
 *     versit parameter: EVPbkVersitParamHOME 
 * 
 * field type description: Job title
 * field type resource id: r_vpbk_field_type_jobtitle
 * associated versit properties:
 *     versit property name: EVPbkVersitNameTITLE
 *     versit property name: EVPbkVersitNameROLE
 * 
 * field type description: Company name
 * field type resource id: r_vpbk_field_type_companyname
 * associated versit properties:
 *     versit property name: EVPbkVersitNameORG
 *     versit property subfield: EVPbkVersitSubFieldOrgName
 * 
 * field type description: Landline phone (work)
 * field type resource id: r_vpbk_field_type_landphonework
 * associated versit properties:
 *     versit property name: EVPbkVersitNameTEL
 *     versit parameter: EVPbkVersitParamWORK 
 * associated exclude parameters: 
 *     exclude parameter: EVPbkVersitParamFAX
 *     exclude parameter: EVPbkVersitParamPAGER
 *     exclude parameter: EVPbkVersitParamCELL
 *     exclude parameter: EVPbkVersitParamVIDEO
 *     exclude parameter: EVPbkVersitParamCAR 
 * 
 * field type description: Mobile phone (work)
 * field type resource id: r_vpbk_field_type_mobilephonework
 * associated versit properties:
 *     versit property name: EVPbkVersitNameTEL
 *     versit parameter: EVPbkVersitParamCELL
 *     versit parameter: EVPbkVersitParamWORK 
 * 
 * field type description: Video number (work)
 * field type resource id: r_vpbk_field_type_videonumberwork
 * associated versit properties:
 *     versit property name: EVPbkVersitNameTEL
 *     versit parameter: EVPbkVersitParamVIDEO
 *     versit parameter: EVPbkVersitParamWORK 
 * 
 * field type description: Fax number (work)
 * field type resource id: r_vpbk_field_type_faxnumberwork
 * associated versit properties:
 *     versit property name: EVPbkVersitNameTEL
 *     versit parameter: EVPbkVersitParamFAX
 *     versit parameter: EVPbkVersitParamWORK 
 * 
 * field type description: VoIP (work)
 * field type resource id: r_vpbk_field_type_voipwork
 * associated versit properties:
 *     versit property name: EVPbkVersitNameX
 *     versit parameter: EVPbkVersitParamVOIP
 *     versit parameter: EVPbkVersitParamWORK 
 *     versit property extension name: "X-SIP"
 * 
 * field type description: Email address (work)
 * field type resource id: r_vpbk_field_type_emailwork
 * associated versit properties:
 *     versit property name: EVPbkVersitNameEMAIL
 *     versit parameter: EVPbkVersitParamINTERNET
 *     versit parameter: EVPbkVersitParamWORK 
 * 
 * field type description: URL (work)
 * field type resource id: r_vpbk_field_type_urlwork
 * associated versit properties:
 *     versit property name: EVPbkVersitNameURL
 *     versit parameter: EVPbkVersitParamWORK 
 * 
 * field type description: Address label (work)
 * field type resource id: r_vpbk_field_type_addrlabelwork
 * associated versit properties:
 *     versit property name: EVPbkVersitNameLABEL
 *     versit parameter: EVPbkVersitParamWORK 
 * 
 * field type description: Address Postoffice (work)
 * field type resource id: r_vpbk_field_type_addrpowork
 * associated versit properties:
 *     versit property name: EVPbkVersitNameADR
 *     versit property subfield: EVPbkVersitSubFieldPostOfficeAddress
 *     versit parameter: EVPbkVersitParamWORK 
 * 
 * field type description: Address Extension (work)
 * field type resource id: r_vpbk_field_type_addrextwork
 * associated versit properties:
 *     versit property name: EVPbkVersitNameADR
 *     versit property subfield: EVPbkVersitSubFieldExtendedAddress
 *     versit parameter: EVPbkVersitParamWORK 
 * 
 * field type description: Address Street (work)
 * field type resource id: r_vpbk_field_type_addrstreetwork
 * associated versit properties:
 *     versit property name: EVPbkVersitNameADR
 *     versit property subfield: EVPbkVersitSubFieldStreet
 *     versit parameter: EVPbkVersitParamWORK 
 * 
 * field type description: Address Locality (work)
 * field type resource id: r_vpbk_field_type_addrlocalwork
 * associated versit properties:
 *     versit property name: EVPbkVersitNameADR
 *     versit property subfield: EVPbkVersitSubFieldLocality
 *     versit parameter: EVPbkVersitParamWORK 
 * 
 * field type description: Address Region (work)
 * field type resource id: r_vpbk_field_type_addrregionwork
 * associated versit properties:
 *     versit property name: EVPbkVersitNameADR
 *     versit property subfield: EVPbkVersitSubFieldRegion
 *     versit parameter: EVPbkVersitParamWORK 
 * 
 * field type description: Address Postal Code (work)
 * field type resource id: r_vpbk_field_type_addrpostcodework
 * associated versit properties:
 *     versit property name: EVPbkVersitNameADR
 *     versit property subfield: EVPbkVersitSubFieldPostalCode
 *     versit parameter: EVPbkVersitParamWORK 
 * 
 * field type description: Address Country (work)
 * field type resource id: r_vpbk_field_type_addrcountrywork
 * associated versit properties:
 *     versit property name: EVPbkVersitNameADR
 *     versit property subfield: EVPbkVersitSubFieldCountry
 *     versit parameter: EVPbkVersitParamWORK 
 * 
 * field type description: Landline phone (general)
 * field type resource id: r_vpbk_field_type_landphonegen
 * associated versit properties:
 *     versit property name: EVPbkVersitNameTEL
 * associated exclude parameters: 
 *     exclude parameter: EVPbkVersitParamWORK
 *     exclude parameter: EVPbkVersitParamHOME
 *     exclude parameter: EVPbkVersitParamFAX
 *     exclude parameter: EVPbkVersitParamPAGER
 *     exclude parameter: EVPbkVersitParamCELL
 *     exclude parameter: EVPbkVersitParamVIDEO
 *     exclude parameter: EVPbkVersitParamCAR 
 * 
 * field type description: Mobile phone (general)
 * field type resource id: r_vpbk_field_type_mobilephonegen
 * associated versit properties:
 *     versit property name: EVPbkVersitNameTEL
 *     versit parameter: EVPbkVersitParamCELL 
 * associated exclude parameters: 
 *     exclude parameter: EVPbkVersitParamWORK
 *     exclude parameter: EVPbkVersitParamHOME 
 * 
 * field type description: Video number (general)
 * field type resource id: r_vpbk_field_type_videonumbergen
 * associated versit properties:
 *     versit property name: EVPbkVersitNameTEL
 *     versit parameter: EVPbkVersitParamVIDEO 
 * associated exclude parameters: 
 *     exclude parameter: EVPbkVersitParamWORK
 *     exclude parameter: EVPbkVersitParamHOME 
 * 
 * field type description: Fax number (general)
 * field type resource id: r_vpbk_field_type_faxnumbergen
 * associated versit properties:
 *     versit property name: EVPbkVersitNameTEL
 *     versit parameter: EVPbkVersitParamFAX 
 * associated exclude parameters: 
 *     exclude parameter: EVPbkVersitParamWORK
 *     exclude parameter: EVPbkVersitParamHOME 
 * 
 * field type description: VoIP (general)
 * field type resource id: r_vpbk_field_type_voipgen
 * associated versit properties:
 *     versit property name: EVPbkVersitNameX
 *     versit parameter: EVPbkVersitParamVOIP 
 *     versit property extension name: "X-SIP"
 * associated exclude parameters: 
 *     exclude parameter: EVPbkVersitParamWORK
 *     exclude parameter: EVPbkVersitParamHOME 
 * 
 * field type description: PTT (POC)
 * field type resource id: r_vpbk_field_type_poc
 * associated versit properties:
 *     versit property name: EVPbkVersitNameX
 *     versit parameter: EVPbkVersitParamPOC 
 *     versit property extension name: "X-SIP"
 * 
 * field type description: SWIS
 * field type resource id: r_vpbk_field_type_swis
 * associated versit properties:
 *     versit property name: EVPbkVersitNameX
 *     versit parameter: EVPbkVersitParamSWIS 
 *     versit property extension name: "X-SIP"
 *     
 * field type description: SIP
 * field type resource id: r_vpbk_field_type_sip
 * associated versit properties:
 *     versit property name: EVPbkVersitNameX
 *     versit property extension name: "X-SIP"
 * 
 * field type description: Email address (general)
 * field type resource id: r_vpbk_field_type_emailgen
 * associated versit properties:
 *     versit property name: EVPbkVersitNameEMAIL
 *     versit parameter: EVPbkVersitParamINTERNET 
 * associated exclude parameters: 
 *     exclude parameter: EVPbkVersitParamWORK
 *     exclude parameter: EVPbkVersitParamHOME 
 * 
 * field type description: URL (general)
 * field type resource id: r_vpbk_field_type_urlgen
 * associated versit properties:
 *     versit property name: EVPbkVersitNameURL
 * associated exclude parameters: 
 *     exclude parameter: EVPbkVersitParamWORK
 *     exclude parameter: EVPbkVersitParamHOME 
 * 
 * field type description: Address label (general)
 * field type resource id: r_vpbk_field_type_addrlabelgen
 * associated versit properties:
 *     versit property name: EVPbkVersitNameLABEL
 * associated exclude parameters: 
 *     exclude parameter: EVPbkVersitParamWORK
 *     exclude parameter: EVPbkVersitParamHOME 
 * 
 * field type description: Address Postoffice (general)
 * field type resource id: r_vpbk_field_type_addrpogen
 * associated versit properties:
 *     versit property name: EVPbkVersitNameADR
 *     versit property subfield: EVPbkVersitSubFieldPostOfficeAddress
 * associated exclude parameters: 
 *     exclude parameter: EVPbkVersitParamWORK
 *     exclude parameter: EVPbkVersitParamHOME 
 * 
 * field type description: Address Extension (general)
 * field type resource id: r_vpbk_field_type_addrextgen
 * associated versit properties:
 *     versit property name: EVPbkVersitNameADR
 *     versit property subfield: EVPbkVersitSubFieldExtendedAddress
 * associated exclude parameters: 
 *     exclude parameter: EVPbkVersitParamWORK
 *     exclude parameter: EVPbkVersitParamHOME 
 * 
 * field type description: Address Street (general)
 * field type resource id: r_vpbk_field_type_addrstreetgen
 * associated versit properties:
 *     versit property name: EVPbkVersitNameADR
 *     versit property subfield: EVPbkVersitSubFieldStreet
 * associated exclude parameters: 
 *     exclude parameter: EVPbkVersitParamWORK
 *     exclude parameter: EVPbkVersitParamHOME 
 * 
 * field type description: Address Locality (general)
 * field type resource id: r_vpbk_field_type_addrlocalgen
 * associated versit properties:
 *     versit property name: EVPbkVersitNameADR
 *     versit property subfield: EVPbkVersitSubFieldLocality
 * associated exclude parameters: 
 *     exclude parameter: EVPbkVersitParamWORK
 *     exclude parameter: EVPbkVersitParamHOME 
 * 
 * field type description: Address Region (general)
 * field type resource id: r_vpbk_field_type_addrregiongen
 * associated versit properties:
 *     versit property name: EVPbkVersitNameADR
 *     versit property subfield: EVPbkVersitSubFieldRegion
 * associated exclude parameters: 
 *     exclude parameter: EVPbkVersitParamWORK
 *     exclude parameter: EVPbkVersitParamHOME 
 * 
 * field type description: Address Postal Code (general)
 * field type resource id: r_vpbk_field_type_addrpostcodegen
 * associated versit properties:
 *     versit property name: EVPbkVersitNameADR
 *     versit property subfield: EVPbkVersitSubFieldPostalCode
 * associated exclude parameters: 
 *     exclude parameter: EVPbkVersitParamWORK
 *     exclude parameter: EVPbkVersitParamHOME 
 * 
 * field type description: Address Country (general)
 * field type resource id: r_vpbk_field_type_addrcountrygen
 * associated versit properties:
 *     versit property name: EVPbkVersitNameADR
 *     versit property subfield: EVPbkVersitSubFieldCountry
 * associated exclude parameters: 
 *     exclude parameter: EVPbkVersitParamWORK
 *     exclude parameter: EVPbkVersitParamHOME 
 * 
 * field type description: Pager number
 * field type resource id: r_vpbk_field_type_pagernumber
 * associated versit properties:
 *     versit property name: EVPbkVersitNameTEL
 *     versit parameter: EVPbkVersitParamPAGER 
 * 
 * field type description: DTMF string
 * field type resource id: r_vpbk_field_type_dtmfstring
 * associated non-versit property: EVPbkNonVersitTypeDTMF
 * 
 * field type description: Wv(IM) address
 * field type resource id: r_vpbk_field_type_wvaddress
 * associated versit properties:
 *     versit property name: EVPbkVersitNameX
 *     versit property extension name: "X-WV-ID"
 * 
 * field type description: Date
 * field type resource id: r_vpbk_field_type_date
 * associated versit properties:
 *     versit property name: EVPbkVersitNameBDAY
 * 
 * field type description: Note
 * field type resource id: r_vpbk_field_type_note
 * associated versit properties:
 *     versit property name: EVPbkVersitNameNOTE
 * 
 * field type description: Thumbnail photo
 * field type resource id: r_vpbk_field_type_thumbnailpic
 * associated versit properties:
 *     versit property name: EVPbkVersitNamePHOTO
 *     versit property name: EVPbkVersitNameLOGO
 * 
 * field type description: Ring tone
 * field type resource id: r_vpbk_field_type_ringtone
 * associated non-versit property: EVPbkNonVersitTypeRingTone
 * 
 * field type description: Caller object image
 * field type resource id: r_vpbk_field_type_callerobjimg
 * associated non-versit property: EVPbkNonVersitTypeCodImage
 * 
 * field type description: Caller object text
 * field type resource id: r_vpbk_field_type_callerobjtext
 * associated non-versit property: EVPbkNonVersitTypeCodText
 * 
 * field type description: Middle name
 * field type resource id: r_vpbk_field_type_middlename
 * associated versit properties:
 *     versit property name: EVPbkVersitNameN
 *     versit property subfield: EVPbkVersitSubFieldAdditionalName
 * 
 * field type description: Department            
 * field type resource id: r_vpbk_field_type_department
 * associated versit properties:
 *     versit property name: EVPbkVersitNameORG
 *     versit property subfield: EVPbkVersitSubFieldOrgUnit
 * 
 * field type description: Assistant name
 * field type resource id: r_vpbk_field_type_asstname
 * associated versit properties:
 *     versit property name: EVPbkVersitNameX
 *     versit property extension name: "X-ASSISTANT"
 * 
 * field type description: Spouse
 * field type resource id: r_vpbk_field_type_spouse
 * associated versit properties:
 *     versit property name: EVPbkVersitNameX
 *     versit property extension name: "X-SPOUSE"
 * 
 * field type description: Children
 * field type resource id: r_vpbk_field_type_children
 * associated versit properties:
 *     versit property name: EVPbkVersitNameX
 *     versit property extension name: "X-CHILDREN"
 * 
 * field type description: Assistant phone
 * field type resource id: r_vpbk_field_type_asstphone
 * associated versit properties:
 *     versit property name: EVPbkVersitNameX
 *     versit property extension name: "X-ASSISTANT-TEL"
 * 
 * field type description: Car phone
 * field type resource id: r_vpbk_field_type_carphone
 * associated versit properties:
 *     versit property name: EVPbkVersitNameTEL
 *     versit parameter: EVPbkVersitParamCAR 
 * 
 * field type description: Anniversary
 * field type resource id: r_vpbk_field_type_anniversary
 * associated versit properties:
 *     versit property name: EVPbkVersitNameX
 *     versit property extension name: "X-ANNIVERSARY"
 * 
 * field type description: Class - Syncronization
 * field type resource id: r_vpbk_field_type_syncclass
 * associated versit properties:
 *     versit property name: EVPbkVersitNameX
 *     versit property extension name: "X-CLASS"
 * 
 * field type description: Location privacy indicator
 * field type resource id: r_vpbk_field_type_locprivacy
 * associated non-versit property: EVPbkNonVersitTypeLocationPrivacy
 * 
 * field type description: Generic label field type for folded view names and group labels
 * field type resource id: r_vpbk_field_type_genlabel
 * associated non-versit property: EVPbkNonVersitTypeGenericLabel
 */


/**
 * A generic field type interface. 
 *
 * Field types are based on the Versit 2.1 standard.
 */
class MVPbkFieldType
    {
    public: // Interface

        /**
         * Destructor. Clients must not destroy the field types they retrieve
         * from the Virtual Phonebook interfaces.
         */
        virtual ~MVPbkFieldType() { }

        /**
         * Returns the Versit properties mapped to this field type.
         *
         * @return Versit properties.
         */
        virtual TArray<TVPbkFieldVersitProperty> VersitProperties() const = 0;

        /**
         * Returns the Versit parameters fields of this type should not have.
         *
         * @return Excluded parameters.
         */
        virtual const TVPbkFieldTypeParameters& ExcludedParameters() const = 0;

        /**
         * Type name for field types not supported by the Versit 2.1 standard.
         *
         * @return A non-Versit type.
         */
        virtual TVPbkNonVersitFieldType NonVersitType() const = 0;

        /**
         * Returns true if this field type is the same as aOtherType.
         *
         * @param aOtherType The type to compare.
         * @return ETrue if the field types are the same.
         */
        virtual TBool IsSame(
                const MVPbkFieldType& aOtherType ) const = 0;

        /**
         * Returns true if this field type matches a Versit property.
         *
         * @param aMatchProperty A versit property to match against.
         * @param aMatchPriority A matching priority. Priorities start
         *                       from zero which is the highest priority.
         *                       Priority is also a direct index to
         *                       VersitProperties() array.
         * @return ETrue if this field type matches aMatchProperty at
         *         aMatchPriority. Returns always false if 
         *         aMatchPriority >= VersitProperties().Count().
         */
        virtual TBool Matches(
                const TVPbkFieldVersitProperty& aMatchProperty,
                TInt aMatchPriority ) const = 0;

        /**
         * Returns the field type resource id from VPbkEng.rsg
         * that be used to identify a type.
         *
         * @return A field type resource id.
         */
        virtual TInt FieldTypeResId() const = 0;

        /**
         * Returns an extension point for this interface or NULL.
         *
         * @param aExtensionUid no extensions defined currently.
         * @return an extension point for this interface or NULL.
         */
        virtual TAny* FieldTypeExtension(TUid /*aExtensionUid*/) 
                { return NULL; }
    };

/**
 * An interface for a list of field types.
 *
 */
class MVPbkFieldTypeList
    {
    public: // Interface
        /**
         * Destructor.
         */
        virtual ~MVPbkFieldTypeList() { }

        /**
         * Returns the number of field type objects in this list.
         *
         * @return A number of field types.
         */
        virtual TInt FieldTypeCount() const = 0;

        /**
         * Returns the field type object at aIndex. 
         *
         * The objects are not in any specific order.
         *
         * @precond aIndex >= 0 && aIndex < FieldTypeCount()
         * @param aIndex An index of a field type.
         * @return A reference to Virtual Phonebook field type.
         *         The reference is valid for the lifetime of this object.
         */
        virtual const MVPbkFieldType& FieldTypeAt(
                TInt aIndex ) const = 0;

        /**
         * Returns true if this list contains aFieldType.
         *
         * @param aFieldType The field type to look for.
         * @return ETrue if the list contains the field type.
         */
        virtual TBool ContainsSame(
                const MVPbkFieldType& aFieldType ) const = 0;

        /**
         * Returns the maximum matching priority held by this field type list.
         *
         * @return A maximum match priority.
         */
        virtual TInt MaxMatchPriority() const = 0;

        /**
         * Returns a matching field type in this list or NULL if no match is
         * found.
         *
         * @param aMatchProperty A Versit property to match.
         * @param aMatchPriority A match priority.
         * @return A matching field type.
         */
        virtual const MVPbkFieldType* FindMatch(
                const TVPbkFieldVersitProperty& aMatchProperty,
                TInt aMatchPriority ) const = 0;

        /**
         * Returns a matching field type in this list or NULL if no match is 
         * found.
         *
         * @param aNonVersitType A non Versit field type to match.
         * @return A matching field type.
         */
        virtual const MVPbkFieldType* FindMatch(
                TVPbkNonVersitFieldType aNonVersitType ) const = 0;

        /**
         * Returns the field type corresponding to field type resource id.
         *
         * If no match is found returns NULL. The resource id aFieldTypeResId
         * corresponds to the VPBK_FIELD_TYPE types in VPbkEng.rsg.
         *
         * @param aFieldTypeResId The field type resource id.
         * @return The corresponding field type.
         */
        virtual const MVPbkFieldType* Find( TInt /*aFieldTypeResId*/ ) const
            { return NULL; }

        /**
         * Returns an extension point for this interface or NULL.
         *
         * @param aExtensionUid no extensions defined currently.
         * @return an extension point for this interface or NULL.
         */
        virtual TAny* FieldTypeListExtension(TUid /*aExtensionUid*/) 
                { return NULL; }
    };

/**
 * An interface for composites of MVPbkFieldTypeList objects.
 */
class MVPbkMultiFieldTypeList : public MVPbkFieldTypeList
    {
    public: // Interface

        /**
         * Destructor.
         */
        virtual ~MVPbkMultiFieldTypeList() { }

        /**
         * Adds aTypeList to this composite by reference. New lists are 
         * appended to the end of current lists, starting from index
         * FieldTypeCount().
         *
         * @param aTypelist A field type list to append.
         */
        virtual void AppendL( const MVPbkFieldTypeList& aTypeList ) = 0;

        /**
         * Removes aTypeList from this composite.
         *
         * @param aTypelist A field type list to remove.
         */
        virtual void Remove( const MVPbkFieldTypeList& aTypeList ) = 0;

        /**
         * Returns an extension point for this interface or NULL.
         *
         * @param aExtensionUid no extensions defined currently.
         * @return an extension point for this interface or NULL.
         */
        virtual TAny* MultiFieldTypeListExtension(TUid /*aExtensionUid*/) 
                { return NULL; }
    };


namespace VPbkFieldTypeList {

// --------------------------------------------------------------------------
// IsSame
// Compares two field type lists. Fieldtypes must be from same 
// contact manager. Uses MVPbkFieldType::IsSame. 
// --------------------------------------------------------------------------
//
IMPORT_C TBool IsSame( const MVPbkFieldTypeList& aLeft, 
        const MVPbkFieldTypeList& aRight );

}
#endif // MVPBKFIELDTYPE_H

//End of file
