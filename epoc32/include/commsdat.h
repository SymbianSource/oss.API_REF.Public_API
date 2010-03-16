// Copyright (c) 2004-2009 Nokia Corporation and/or its subsidiary(-ies).
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
// Constants for use in storing comms data via CommsDat
// 
//



/**
 @file
 @publishedAll
 @released
*/


#if (!defined COMMSDAT_H)
#define       COMMSDAT_H

#include <comms-infras/metatype.h>
#include <e32property.h>


namespace Meta
    {

	/**
	Visitor factory functions
	@internalComponent
	*/
    MMetaType* TMDBNumBaseVisitorFactoryL(const TAny* mem, const TAny* data);
   	/**     
   	@internalComponent
   	*/
    MMetaType* TMDBTextBaseVisitorFactoryL(const TAny* mem, const TAny* data);
    /**     
   	@internalComponent
   	*/
    MMetaType* TMDBBinBaseVisitorFactoryL(const TAny* mem, const TAny* data);
    /**     
   	@internalComponent
   	*/
    MMetaType* TMDBDeprecatedVisitorFactoryL(const TAny* mem, const TAny* data);
	/**
    @publishedPartner
    @released
    */
    IMPORT_C MMetaType* TMDBNumVisitorFactoryL(const TAny* mem, const TAny* data);
    /**
    @publishedPartner
    @released
    */
    IMPORT_C MMetaType* TMDBLinkNumVisitorFactoryL(const TAny* mem, const TAny* data);
    /**
    @publishedPartner
    @released
    */
    IMPORT_C MMetaType* TMDBTextVisitorFactoryL(const TAny* mem, const TAny* data);
    /**
    @publishedPartner
    @released
    */
    IMPORT_C MMetaType* TMDBMedTextVisitorFactoryL(const TAny* mem, const TAny* data);
    /**
    @publishedPartner
    @released
    */
    IMPORT_C MMetaType* TMDBLongTextVisitorFactoryL(const TAny* mem, const TAny* data);
    /**
    @publishedPartner
    @released
    */
    IMPORT_C MMetaType* TMDBBinVisitorFactoryL(const TAny* mem, const TAny* data);
    /**
    @publishedPartner
    @released
    */
    IMPORT_C MMetaType* TMDBLinkVisitorFactoryL(const TAny* mem, const TAny* data);
    /**
    @publishedPartner
    @released
    */
    IMPORT_C MMetaType* TMDBRecordSetVisitorFactoryL(const TAny* mem, const TAny* data);
    /**
    @publishedPartner
    @released
    */
    IMPORT_C MMetaType* TMDBGenericRecordVisitorFactoryL(const TAny* mem, const TAny* data);

    }


namespace CommsDat
{

/**
Use this constant for Debug panic calls

@publishedAll
*/
_LIT(KCommsDatName,"CommsDat");

/**
Use this constant for Debug panic calls

@publishedAll
*/
enum
	{
	ECommitBeforeOpenTransaction = 1,
	ERollBackBeforeOpenTransaction = 2,
	ESessionClosed = 3,
    EWrongAPPrioritySelPolRecord = 4,
    EWrongIAPServiceType = 5
	};
	
using namespace Meta;

//////////////////////////////////////////////////
// VERSION INFO
//

/**
Use this constant when starting a session to ask to use the latest version of the data set
Do not use this constant if want option to keep using particular version after update
Using this constant will require the client to keep up to date with any changes in the current dataset
Use specific version constants to avoid changing until a deprecated version is no longer supported.

@publishedAll
*/
#define KCDLatestVersion            TVersion(0,0,0)


/**
Versions of the dataset in use
NB These versions will change as data set is updated
All versions apart from the one defined as KCDCurrentVersion are deprecated
*/

/*
Initial Version 
@publishedAll
*/

#define KCDVersion1_1               TVersion(1,1,1)

#ifdef SYMBIAN_NON_SEAMLESS_NETWORK_BEARER_MOBILITY
/**
Some elements in Version KCDVersion1_1 now deprecated
These elements will be mapped if the client starts a session with KCDVersion1_1
They will be ignored or rejected as not supported if client starts a session with 
KCDVersion1_2 or KCDLatestVersion

@publishedAll
*/
#define KCDVersion1_2               TVersion(1,2,1)
#endif
/**
The version of the dataset supported by default
NB This version will change as data set is updated

@publishedAll
*/
#ifdef SYMBIAN_NON_SEAMLESS_NETWORK_BEARER_MOBILITY

#define KCDCurrentVersion           KCDVersion1_2

#else

#define KCDCurrentVersion           KCDVersion1_1

#endif




////////////////////////////////////////////////////
//  Attribute Flags
//

/**
Access control attribute flags.
When these are SET in the mask the attribute is obeyed
When they are CLEARED from the mask, the attribute is ignored
By default attributes are obeyed.

@publishedAll
*/
typedef enum
{
  ECDNoWriteButDelete = 0x0000010,     // R/W Read Only but deleteable      Caller should explicitly choose to modify
                                       //                                   Enforced by convention only, not with Platform Security
  ECDHidden           = 0x0000020,     // R/W Read-Write Hidden data        Not policed - hides public utility info such as default values
                                       //                                   Enforced by convention only, not with Platform Security  
  ECDPrivate          = 0x0000040,     // R/W Read-Write Private data       For sensitive user data such as passwords
                                       //                                   Policed at storage server API with platsec capability
  ECDProtectedWrite   = 0x0000080,     // W   Write-Protected data          To allow data to be read only to most clients but modifiable by a few privileged clients
                                       //                                   Policed at storage server API with platsec capability
} TCDAttributeFlags;


/////////////////////////////////////////////////////
// Field types
//
/**
@publishedPartner
@released
*/
typedef enum
{
	EText,          ///< Text field - descriptor with a maximum length of 50 unicode characters.
 	EDesC8,         ///< Buffer of TUInt8. Maximum length is 1024 * 8. 
 	EUint32,		///< Unsigned 32 bit integer field.
 	EInt,			///< Signed integer field
 	EBool,			///< Boolean field
 	EMedText,       ///< Text field - descriptor with a maximum length of 256 unicode characters.
 	ELongText, 		///< Text field - descriptor with a maximum length of 1024 unicode characters.
    ELink			///< This field is an integer that identifies a record in another table.

} TCDFieldValueTypes;

/**
@publishedPartner
@released
*/
const TInt KMaxTextLength		= 50; 		///< Specifies the max length (characters) for short text.
/**
@publishedPartner
@released
*/
const TInt KMaxMedTextLength	= 255; 		///< Specifies the max length (characters) for medium text.
/**
@publishedPartner
@released
*/
const TInt KMaxLongTextLength	= 1024;		///< Specifies the max length (characters) for long text.
/**
@publishedPartner
@released
*/
const TInt KMaxNumLength		= 1;		///< Specifies the max length for an integer and a boolean.

// Length override on a normal text field
/**
@publishedPartner
@released
*/
const TInt KShortTextLength		= 32;

////////////////////////////////////////////////////
// Masks for Element Type info
//


/**
Mask to use to hide attribute reserved bits

@publishedAll
*/
#define KCDMaskHideAttrAndRes       0xffffff00


/**
Mask to use to show reserved bits

@publishedAll
*/
#define KCDMaskShowRes              0x8000000f


/**
Mask to use to hide reserved bits

@publishedAll
*/
#define KCDMaskHideRes              0x7ffffff0


/**
T x x   Mask to show Table Type info

@publishedAll
*/
#define KCDMaskShowRecordType       0x7f800000


/**
x C x   Mask to show Column Type 

@publishedAll
*/
#define KCDMaskShowFieldType        0x007f0000


/**
T C x   Mask to show Table and Column Type 

@publishedAll
*/
#define KCDMaskShowType             0x7fff0000


/**
T x R   Mask to show Record id

@publishedAll - don't use this.  Replace with KCDMaskShowRecordId
*/
#define KCDMaskShowInstance         0x0000ff00


/**
T x R   Mask to show Record id
Use in place of KCDMaskShowInstance
@publishedAll
*/
#define KCDMaskShowRecordId         0x0000ff00


/**
T C R   Mask to show Field instance without attributes or reserved bits

@publishedAll
*/
#define KCDMaskShowField            0x7fffff00


/**
T C R   Mask for Central Repository to find a single field

@internalComponent
*/
#define KCDMaskFindSingleField		0x7FFFFFFE

/**
T x R   Mask to show Record Type and Record Id without column type, attributes or reserved bits

@publishedAll
*/
#define KCDMaskShowRecordTypeAndId  (KCDMaskShowRecordType | KCDMaskShowRecordId)

/**
x C R   Mask to show Column Type and Record Id without Record type, attributes or reserved bits

@publishedAll
*/
#define KCDMaskShowColumnTypeAndRecordId  (KCDMaskShowFieldType |  KCDMaskShowRecordId)


/**
Mask to show Attributes

@publishedAll
*/
#define KCDMaskShowAttributes       0x000000f0


/**
Mask for all attribute settings that apply to read and write operations
see TCDAttributeFlags

  ECDNoWriteButDelete = 0x0000010                             
  ECDHidden           = 0x0000020
  ECDPrivate          = 0x0000040
  ECDProtectedWrite   = 0x0000080

@publishedPartner
@released
*/
#define KCDMaskShowReadWriteAttributes  (ECDNoWriteButDelete |ECDHidden | ECDPrivate | ECDProtectedWrite)

/**
Mask for all attribute settings that apply to read operations
see TCDAttributeFlags
                          
  ECDHidden           = 0x0000020
  ECDPrivate          = 0x0000040
  
@publishedPartner
@released  
*/
#define KCDMaskShowReadAttributes       (ECDHidden| ECDPrivate)     

/**
Mask to use to show attributes and reserved bits

@publishedAll
*/
#define KCDMaskShowAttrAndRes       0x000000ff


/**
Id for the Initial record in a record set

@publishedAll
*/
#define KCDInitialRecordId			0x00000100


/**
Id for the Initial table in the database

@publishedAll
*/
#define KCDInitialTableId			0x00800000


/**
Id for the Initial User defined table in the database
clients have 64 table ids available to them

@publishedAll
*/
#define KCDInitialUDefRecordType   0x5F800000


/**
Id for the Last User defined table in the database.

@publishedAll
*/
#define KCDLastUDefRecordType      0x7F800000


/**
Id for the Initial column in a record set

@publishedAll
*/
#define KCDInitialColumnId			0x00010000


/**
T C 0   location for default field values

@publishedAll
*/
#define KCDDefaultRecord            0x00000000


/**
Combine with table id and Column id to give the location of column type info

@publishedAll
*/
#define KCDColumnTypeInfo           0x0000ff00

/**
Combine with table id to give the location of table type info

@publishedPartner
@released
*/
#define KCDTableTypeInfo            0x007fff00

/*
Combine with table id to give location of record type info
*/
//#define KCDRecordTypeInfo			0x007f0000


/**
Use to request allocation of a new table id.
Should only be called when creating a new user-defined table

@publishedPartner
@released
*/
#define KCDNewTableRequest          0x007fff00


/**
Combine with table id to give request for a new column in a table.
The table must already exist.  New columns should only normally be 
requested when creating a new user-defined table

@publishedPartner
@released
*/
#define KCDNewColumnRequest			0x0000ff01



/**
Combine with table id to give request for a new record in a table.
The table must already exist.

@publishedAll
*/
#define KCDNewRecordRequest			0x807f0001


/**
Combined with CMDBField, it finds the TableId given the table name

@publishedAll
*/
#define KCDMaskGenericTableName			KCDNewTableRequest



/**
Maximum number of tables that can be created in one repository

@publishedAll
*/
#define KCDMaxTables                254


/**
Maximum number of User defined tables that can be created in one repository

@publishedAll
*/
#define KCDMaxUserDefTables         64


/**
Maximum number of columns that can be created in one table

@publishedAll
*/
#define KCDMaxColumns               126  


/**
Maximum number of records that can be stored in one table

@publishedAll
*/
#define KCDMaxRecords               254


/**
Maximum number of characters in a field name

@publishedAll
*/
#define KCDMaxFieldNameLength        64



/**
Flag to indicate change in field
Not for use in database.  Just with fields

@internalComponent
*/
#define KCDChangedFlag      0x00000001

/**
@publishedPartner
@released
*/
#define KCDMaxRecordId     0x0000ff00
/**
@publishedPartner
@released
*/
#define KCDMaxColumnId     0x007f0000
/**
@publishedPartner
@released
*/
#define KCDMaxTableId      0x7f800000



/*
Mask to show only basic type info, 
Masks out all info on links
@internalComponent
*/
#define KCDShowBasicTypeInfo  0x000000ff
/**
Typedefs for convenience in meta data definitions
@internalComponent
*/
using namespace Meta;

template <class TYPE> class TMDBVisitor;
class TMDBRecordLinkVisitor;
class TMDBRecordSetVisitor;
class TMDBGenericRecordVisitor;
class CMDBElement;

/*
Visitors for field values
*/

/**
Typedefs for convenience in meta data definitions
@internalComponent
*/
 typedef TMDBVisitor<TInt>                           TMDBNum;

/**
Typedefs for convenience in meta data definitions
@internalComponent
*/	
 typedef TMDBVisitor<TInt>                           TMDBBool;
 
/**
Typedefs for convenience in meta data definitions
@internalComponent
*/	
 typedef TMDBVisitor<TDesC>                          TMDBDes;	
 
/**
Typedefs for convenience in meta data definitions
@internalComponent
*/
 typedef TMDBVisitor<TDesC8>                         TMDBDes8;	

/*
Visitors for containers
*/

/**
Typedefs for convenience in meta data definitions
@internalComponent
*/
typedef TMDBRecordLinkVisitor						TMDBLink;	

/**
Typedefs for convenience in meta data definitions
@internalComponent
*/		
typedef TMDBRecordSetVisitor                        TMDBRecordSet;

/**
Typedefs for convenience in meta data definitions
@internalComponent
*/		
typedef TMDBGenericRecordVisitor                    TMDBGenRecord;		

/** UIDs for CommDB event notification */
/**
@publishedPartner
@released
*/
const TUid KUidCommDbNotificationEvent = {0x1020762E};
/**
@publishedPartner
@released
*/
const TUid KUidCommsDatStatusEvent = {KUidSystemCategoryValue};
/**
@publishedPartner
@released
*/
const TInt KCommsDatStatusEventCommitSeq = 0x1020762F;

/**
Metadatabase container type ids

@internalComponent
*/
#define KCDTIdMDBElement            123

/**
Metadatabase container type ids

@internalComponent
*/
#define KCDTIdMDBNumFieldBase       223

/**
Metadatabase container type ids

@internalComponent
*/
#define KCDTIdMDBTextFieldBase      224

/**
Metadatabase container type ids

@internalComponent
*/
#define KCDTIdMDBBinFieldBase       225

/**
Metadatabase container type ids

@internalComponent
*/
#define KCDTIdMDBRecordLinkBase     323

/**
Metadatabase container type ids

@internalComponent
*/
#define KCDTIdMDBRecordSetBase      523

/**
Metadatabase container type ids

@internalComponent
*/
#define KCDTIdMDBGenericRecord      585


/**
Macro for interaction with netmeta
@publishedAll
*/
#define X_REGISTER_ATTRIBUTE( thisMetaClass, var, metaType ) \
 { _FOFF( thisMetaClass, var ), Meta::metaType##VisitorFactoryL },


#define EXP_DATA_VTABLE \
 IMPORT_C virtual Meta::SVDataTableEntry const* GetVDataTable() const;	\
 IMPORT_C virtual TUint8* GetAttribPtr(const TInt aOffset) const;	\
 IMPORT_C static Meta::SVDataTableEntry const* GetVDataTableStatic(); \
 static const Meta::SVDataTableEntry iVDataTable[];


/**
Macros used to implement virtual functions from MMetaData interface and construct the v data table
@publishedAll
*/
#define EXP_START_ATTRIBUTE_TABLE( thisMetaClass, uid, typeId ) \
 EXPORT_C Meta::SVDataTableEntry const* thisMetaClass::GetVDataTable() const { return &iVDataTable[0]; };	\
 EXPORT_C TUint8* thisMetaClass::GetAttribPtr(const TInt aOffset) const { return (TUint8*)this + aOffset; };	\
 EXPORT_C Meta::SVDataTableEntry const* thisMetaClass::GetVDataTableStatic() { return &iVDataTable[0]; }; \
 const Meta::SVDataTableEntry thisMetaClass::iVDataTable[] = { \
 { uid, reinterpret_cast<Meta::TMetaTypeNewL>(typeId) },


#define END_ATTRIBUTE_TABLE_BASE_N( baseMetaClass, baseId, entry ) \
 { (TInt)((TAny*)(baseMetaClass::GetVDataTableStatic() + entry)), NULL }};


} //end namespace CommsDat
#endif
