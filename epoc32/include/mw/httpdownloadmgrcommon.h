/*
* Copyright (c) 2002-2005 Nokia Corporation and/or its subsidiary(-ies).
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
* Description:  Common constants used in Download Manager Engine
*
*/



#ifndef HTTPDOWNLOADMGRCOMMON_H
#define HTTPDOWNLOADMGRCOMMON_H

//  INCLUDES
#include <e32base.h>

// CONSTANTS
const TInt KMaxUrlLength = 2048;
const TInt KMaxChunkSize = 4096;
const TUint KMaxDefAttrLength = 32;
const TUint KMaxRealmLength = 128;
const TUint KMaxContentTypeLength = 256;
const TUint KMaxDispositionTypeLength = 256;
const TInt32 KDefaultPort = 80;
const TInt32 KDefaultContentLength = -1;
const TUint KMaxGeneralHeaderFieldLength = 256;
/**  Length of a digest hash when represented in hex */
const TInt KHashLength = 32;
/**  Length of a digest hash before converting to hex. */
const TInt KRawHashLength = 16;
/**  Default FOTA package id. Default means no FOTA download! */
const TInt32 KDefaultFotaPckgId = -1;
/**  Non-MediaObject index */
const TInt32 KNonMoIndex = 0;
/**  Index of first media object */
const TInt32 KFirstMoIndex = 1;

const TInt KColon( ':' );
const TInt KSemiColon( ';' );
const TInt KQuote( '"' );
const TInt KEqual( '=' );

_LIT8( KHttpFieldSeparator, "\n");
_LIT8( KHttpDispositionTypeAttachment, "attachment");
_LIT8( KHttpDispositionTypeInline, "inline");
_LIT8( KHttpFileNameParm, "filename");

/**  OMA DD specific definition */
_LIT8( KCodMimeType, "text/x-co-desc" );
/**  OMA DD specific definition */
_LIT8( KDdMimeType, "application/vnd.oma.dd+xml" );
/**  OMA DD specific definition */
_LIT8( KDd2MimeType, "application/vnd.oma.dd2+xml" );
_LIT8( KRoapMimeType, "application/vnd.oma.drm.roap-trigger+xml" );

/// FOTA Update Package type.
_LIT8( KFotaPackageDataType, "application/vnd.nokia.swupd.dp2" );

/**  OMA DD specific definition */
_LIT8( KMultiPartMimeType, "multipart/related" );

/**  DRM specific MIME type */
_LIT8( KDrmMessageMimeType, "application/vnd.oma.drm.message" );
/**  DRM specific MIME type */
_LIT8( KDrmMessageMimeTypeDrmContent, "application/vnd.oma.drm.content" );
/**  DRM specific MIME type */
_LIT8( KDrmMessageMimeTypeDrmDcf, "application/vnd.oma.drm.dcf" );

/**  DRM specific MIME type */
_LIT8( KRoapPduMimeType, "application/vnd.oma.drm.roap-pdu+xml" );

/**  Enumeration indicating download state. 
 * The download states from EHttpDlMoved are temporary. E.g. download adopt 
 * EHttpDlMoved state, but right after that, it returns to the original 
 * EHttpDlCompleted state.
 */
enum THttpDownloadState
    {
    EHttpDlCreated = 1,
    EHttpDlInprogress,
    EHttpDlPaused,
    EHttpDlCompleted,
    EHttpDlFailed,

    /// download is moved from one client instance to another one.
    EHttpDlMoved,
    /// MMC card or other storage media is removed from the phone.
    EHttpDlMediaRemoved,
    /** MMC card or other storage media inserted and 
    * downloaded content file found on it. 
    * If MMC card inserted, but (partially) downloaded content file 
    * is not found on it, download is failed with error reason
    * EContentFileIntegrity. */
    EHttpDlMediaInserted,
    /** Download process can be paused again. This event only occurs after
    * EHttpDlNonPausable. */
    EHttpDlPausable,
    /// Download process cannot be paused, or the content will be lost.
    EHttpDlNonPausable,
    /// Download is deleted from another client instance.
    EHttpDlDeleted,
    /// Download is started when it's already progressing
    EHttpDlAlreadyRunning,
    /// Download is going to be deleted.
    EHttpDlDeleting,
    /// Out of network coverage, in case of non-pausable downloads
    EHttpDlNonPausableNetworkLoss,
    EHttpDlMultipleMOStarted,
    EHttpDlMultipleMOCompleted,
    EHttpDlMultipleMOFailed,
    /// Internally used download event. Do NOT deal with them
    EHttpDlCancelTransaction = 128
    };

/**  Enumeration indicating download progress state. 
 * These enumarated values usually come with EHttpDlInprogress.
 * An exception is EHttpContentTypeReceived that pauses the download 
 * until client app accepts and resumes, or deletes/resets it.
 */
enum THttpProgressState
    {
    EHttpProgNone = 0,

    EHttpStarted = 500,

    EHttpProgCreatingConnection = 1000,
    EHttpProgConnectionNeeded = 1010,
    EHttpProgConnected = 1020,

    EHttpProgConnectionSuspended = 1022,

    EHttpProgDisconnected = 1030,

    EHttpProgDownloadStarted = 2000,
    EHttpContentTypeRequested = EHttpProgDownloadStarted + 20,

    /**  Download status is EHttpDlPaused!
    * Application can check the received content type here and decide whether 
    * to accept it or not. Call Start again to carry on download, or Delete to 
    * delete this download. */
    EHttpContentTypeReceived,

    EHttpProgSubmitIssued = EHttpProgDownloadStarted + 30,

    EHttpProgResponseHeaderReceived = 2050,
    EHttpProgResponseBodyReceived,
    EHttpProgRedirectedPermanently,
    EHttpProgRedirectedTemporarily,
    EHttpProgDlNameChanged,
    EHttpProgContentTypeChanged,

    /// OMA DD specific progress
    EHttpProgCodDescriptorDownloaded = 2500,
    /// OMA DD specific progress
    EHttpProgCodDownloadStarted,
    /// Cod is accepted
    EHttpProgCodDescriptorAccepted,
    /**  Cod Handler downloaded the content, but still needs to continue some 
    * operation. Call Start again to carry on! Download status is 
    * EHttpDlInprogress! */
    EHttpProgCodLoadEnd,
    EHttpProgSupportedMultiPart,
    
    EHttpProgCodPdAvailable,
    EHttpProgCodDownloadShouldResume,
    EHttpProgCodDownloadPause,

    EHttpProgMovingContentFile = 3000,
    EHttpProgContentFileMoved,

    // We have received sufficient HTTP response body to allow us to recognize 
    // content-type from data rather than trust content-type header
    EHttpContTypeRecognitionAvail,
    
    //The state is used for duplicate files .The duplicate file is renamed
 	//and move happens simultaneously
 	EHttpProgContentFileMovedAndDestFNChanged,
 	
 	// Progress event to indicate download is progressively played
    EHttpDlProgProgressive,
    
    // Progress event to indicate download is not progressively played
    EHttpDlProgNonProgressive
    };

/**  Enums to access session level attributes.
* Attribute types: string(8/16), TInt32, TBool.
* Some of them indicated as read-only. In debug mode if the client 
* application tries to write such attribute server panics. 
* In release mode it only returns with KErrArgument.
* If not specified other, buffer size is KMaxDefAttrLength.
*
* Every 8bits string attribute can be queried into 16bits descriptor.
* In this case the 8bits buffer is converted into a 16bits one.
*/
enum THttpDownloadMgrAttrib
    {
    EDlMgrAppUid,    /**<  Unique id of the application
                            * passed in Connect.
                            * (TInt32 - read only) */

    EDlMgrIap,          /**<  Internet Access Point
                            * (TInt32 - read/write)
                            * (default: default AP used from CommsDb) */

    EDlMgrExitAction,  /**<  See THttpDownloadMgrExitAction
                            * (TInt32 - read/write)
                            * (default: EExitNothing) */

    EDlMgrSilentMode,       /**<  No UI interaction in download process
                            * (TBool - read/write)
                            * (default: EFalse)
                            * It is supported only in case of FOTA!!! */

    EDlMgrMaster,           /**<  Used if application can be executed in multiple
                            * instances (stand-alone and embedded).
                            * This flag indicates that this instance, while running, 
                            * will inherit downloads of all other instances's 
                            * when they closed.
                            * Two masters are forbidden in the same time.
                            * (TBool - read/write)
                            * (default: EFalse) */

    EDlMgrAllDlsInMaster,   /**<  Returns the number of downloads of the Master
                            * instance of the application
                            * (TInt32 - read-only) */

    EDlMgrNoMediaDlsInMaster, /**<  Returns the number of downloads of the 
                            * Master instance, those downloads were stored on a 
                            * media, that media is not present in the phone.
                            * (TInt32 - read-only) */

    EDlMgrConnectionName,   /**<  Name of the connection to be used to create 
                            * connection.
                            * Or on return it is name of connection used by this instance of
                            * download manager. Connection has to be established before this
                            * attribute could be returned. Same as RConnection::Name().
                            * Download Manager automatically connects to network with the 
                            * given name.
                            * (String16<KMaxName> - read/write) */

    EDlMgrAPName,   /**<  Name of the access point used. Valid only if the IAP id
                            * is known by download manager
                            * (String16 - read-only)
                            * (Not supported on yet!) */

    EDlMgrNumInprogressDownloads,  
                                /**<  Number of in-progress downloads of the client.
                                * (TInt32 - read-only) */

    EDlMgrConnected,  /**<  Returns ETrue if the session have active connection.
                            * (TBool - read-only) */

    EDlMgrNoMediaDls, /**<  Returns the number of downloads that are 
                            * stored on a media that is not present in the phone. 
                            * (e.g. MMC that is unplugged) */

    EDlMgrEnableCookies,  /**<  Client can specify cookie usage in downloads 
                            * via this attribute.
                            * (TBool - read/write)
                            * (default: ETrue) */

    EDlAutoConnect,    /**<  Connection is automatically created if not 
                            * exists and this attribute is ETrue. If it's EFalse and no 
                            * connection, EHttpProgConnectionNeeded is sent to 
                            * the client.
                            * (TBool - read/write)
                            * (default: ETrue) */
    EDlMgrAutoConnect = EDlAutoConnect,

    EDlMgrFotaDownload,   /**<  Deprecated! Do not use!!!
                            * Indicates that it is a FOTA download
                            * (TBool - read/write)
                            * (default: EFalse) */

    EDlMgrCodFolder,    /**<  Folder to store COD contents
                            * (String16<KMaxPath> - read-only)
                            * (Not supported on yet!) */
    EDlMgrNumOfClientSideDownload,    
                            /**<  Number of client side download
                            * (TInt32 - read-only) */
    EDlMgrHasActiveDownloads,
                            /**< Indicates there are unfinished downloads, particularly
                              * important during re-start of DownloadMgr after failure
                              * of DownloadManager or device */
    EDlMgrAutoAcceptCod,     /**< Tells CODHandler to suppress download confirmation
                              * dialog for user acceptance of COD/OMA downloads */
                              
    EDlMgrProgressiveDownload /**<  Used to control progressiveness
    							 * of all downoads in a session
                            	 * (TBool - read/write)*/                              

    };

/**  Enums to access download specific attributes.
* Attribute types: string(8/16), TInt32, TBool.
* Some of them indicated as read-only. In debug mode
* if the client application tries to write such attribute
* server panics. In release mode it only returns with
* KErrArgument.
* If not specified anyway buffer size is KMaxDefAttrLength.
*/
enum THttpDownloadAttrib
    {
    // Download progress attributes
    EDlAttrState,           /**<  See THttpDownloadState 
                            * (TInt32 - read-only) */

    EDlAttrProgressState,   /**<  See THttpProgressState 
                            * (TInt32 - read-only) */

    EDlAttrUserData,    /**<  Any user defined data that can fit into 32bits
                            * (TInt32 - read/write) */

    EDlAttrId,         /**<  Unique id of the download.
                            * (TInt32 - read-only) */

    //
    // Attributes mandatory to issue the request
    //
    EDlAttrReqUrl = 100,    /**<  Requested URL of the content.
                            * (String8<KMaxUrlLength> - read/write */

    EDlAttrRedirUlr,        /**<  URL after the last permanent redirection.
                            * When download is created or reseted it's the same
                            * as EDlAttrReqUrl.
                            * (String8<KMaxUrlLength> - read-only) */
    EDlAttrRedirUrl = EDlAttrRedirUlr,

    EDlAttrCurrentUrl,      /**<  Current URL of the content. It's always updated if
                            * transaction redirected (permanently/temporary).
                            * (String8<KMaxUrlLength> - read-only) */

    EDlAttrName,   /**<  Name of the download. Generated from URL path.
                            * If URL doesn't contain filename in the path 
                            * this name is 'index.html' as per default. 
                            * (String16<KMaxPath> - read-only) */

    EDlAttrPort,      /**<  Port address of the host 
                            * (TInt32 - read/write)
                            * (default: KDefaultPort) */

    EDlAttrMethod,          /**<  Do not use it. For internal usage only!!!
                            * (TInt32 - read/write) */

    EDlAttrRequestHeaderAddon,  /**<  Client application can specify addition request
                            * header field with this attribute.
                            * Additional header fields cannot override the ones
                            * set by Download Manager!
                            * Format is:
        * fieldname KColon fieldrawdata [KHttpFieldSeparator fieldname KColon fieldrawdata]
        * Do not insert whitespaces between fieldname and ":" and fieldrawdata!
                            * Sample format string: "%S%c%S".
                            * (String8 - read/write) */

    EDlAttrNextBodyData,    /**<  Returns the next body chunk.
                            * (String8<KMaxChunkSize> - read-only)
                            * (Not supported on v2.8!) */

    EDlAttrReleaseBodyData, /**<  Retrieving attribute releases memory allocated 
                            * for body chunk returned in a previous 
                            * EDlAttrNextBodyData call.
                            * On return it indicates that that chunk was the last one.
                            * (TBool - read-only)
                            * (Not supported on v2.8!) */

    EDlAttrRedirected,      /**<  Indicates that temporary redirection occured. 
                            * Pausing this download is dangerous, because on 
                            * restart only the original URL, or the last 
                            * permenently redirected URL is used. It's not 
                            * guaranteed that HTTP server will provide the same 
                            * content on restart after a temporary redirection.
                            * (TBool - read-only) */

    EDlAttrResponseHeader,  /**<  In continue download, client application can 
                            * pass the received response header via this 
                            * attribute.
                            * Format is the same as in case of EDlAttrRequestHeaderAddon.
                            * (String8 - write-only. Accepted only if EDlAttrContinue is ETrue) */

    EDlAttrRequestHeaderAddonLength, /**<  Length of the request header add-on, 
                            * set by client application.
                            * (TInt - read-only) */

    //
    // HTTP/Proxy authentication attributes.
    // Have to be set when state is EHttpDlPaused/EHttpContentTypeReceived
    //
    EDlAttrAuthScheme = 200,  /**<  Scheme of authentication. 
                            * See THttpAuthenticationScheme!
                            * (TInt - read/write. Write is accepted only if EDlAttrContinue is ETrue) */

    EDlAttrRealm,           /**<  Realm of the HTTP authentication
                            * (String8<KMaxRealmLength> - read/write. 
                            * Write is accepted only if EDlAttrContinue is ETrue) */

    EDlAttrUsername,        /**<  User name.
                            * (String8 - read/write) */

    EDlAttrPassword,        /**<  Password.
                            * (String8 - write-only) */

    EDlAttrProxyRealm,      /**<  Realm of the proxy authentication.
                            * (String8<KMaxRealmLength> - read/write. 
                            * Write is accepted only if EDlAttrContinue is ETrue) */

    EDlAttrProxyUsername,   /**<  User name for proxy authentication.
                            * (String8 - read/write) */

    EDlAttrProxyPassword,   /**<  Password for proxy authentication.
                            * (String8 - write-only) */

    //
    // Miscellaneous download attributes
    //
    EDlAttrDestFilename,    /**<  Destination filename. Content will be 
                            * moved/renamed here after download completed.
                            * Can be set only before Start and after
                            * download successfully completed.
                            * (String16<KMaxPath> - read/write) */

    EDlAttrLength,          /**<  Full size of the content.
                            * (TInt32 - read/write. 
                            * Write is accepted only if EDlAttrContinue is ETrue)
                            * (default: KDefaultContentLength - until content size is known) */

    EDlAttrDownloadedSize,  /**<  Downloaded size of the content.
                            * (TInt32 - read-only) */
    
    EDlAttrNoContentTypeCheck,  /**<  Content is downloaded w/o content type validation.
                            * (TBool - read/write)
                            * (default: EFalse) */

    EDlAttrContinueBody,    /**<  In case of continue download, the client application
                            * can pass already received body data to download manager 
                            * via this attribute. Note that if the download is not started this
                            * data is lost, because download manager doesn't persist it until that.
                            * It is because it's actually not surely known what the destination file 
                            * size&name until that.
                            * (String8 - write only. Accepted only if EDlAttrContinue is ETrue)
                            * (String16 - write only. Accepted only if EDlAttrContinue is ETrue. 
                            * 8bits data stream stored in 16bits descriptor.) */

	EDlAttrDestRemovable,	/**<  Indicates that the content file is stored on 
	                    * a removable media.
	                    * (TBool - read-only) */

    //
    // Attributes to indicate error occured during download
    //
    EDlAttrStatusCode = 500, /**<  Status code from response header
                            * (TInt32 - read-only) */

    EDlAttrErrorId, /**<  See THttpDownloadMgrError
                            * (TInt32 - read-only) */

    EDlAttrGlobalErrorId,   /**<  Global error id
                            * (TInt32 - read-only) */

    EDlAttrContentType,     /**<  Content type from response header
                            * (String8<KMaxContentTypeLength> - read/write. 
                            * Write is accepted only if EDlAttrCodDownload is ETrue) */

    EDlAttrTargetApp,       /**<  Target app that can open the content
                            * (TInt32 - read/write. 
                            * Write is accepted only if EDlAttrContinue is ETrue) */

    EDlAttrMediaType,       /**<  Media type from response header. See RFC2616.
                            * (String8<KMaxContentTypeLength> - read-only) */
    EDlAttrMediaTypeBoundary, /**<  Boundary attribute from media type.
                            * (String8<KMaxContentTypeLength> - read-only) */

	EDlAttrAttachmentFileName,

    //
    // Other 
    //
    EDlAttrDisconnectOnReset = 1000, /**<  Automatic disconnection when Reset called.
                            * (TBool - read/write)
                            * (default: ETrue) */

    EDlAttrDisconnectOnPause,   /**<  Automatic disconnection when Pause called.
                            * In progress state EHttpContentTypeReceived
                            * download is in paused state but connection is
                            * not closed.
                            * (TBool - read/write)
                            * (default: ETrue) */

    EDlAttrUnused1, 

    EDlAttrAction,   /**<  See THttpDownloadMgrAction
                            * (TInt32 - read/write)
                            * (default: ELaunch ) */

    EDlAttrRestartAction,   /**<  See THttpRestartActions
                            * (TInt32 - read/write)
                            * (default: ERestartIfExpired ) */

    EDlAttrNoMedia,   /**<  ETrue if the media, on which the download is stored, is removed.
                            * A Reset clears this flag.
                            * (TBool - read only) */

    EDlAttrContinue,  /**<  Indicates that download was started in 
                            * client app but that doesn't handle it. 
                            * Download is created with RHttpDownloadMgr::CreateClientSideDownloadL().
                            * (TBool - read-only)
                            * (default: EFalse) */

    EDlAttrPausable,  /**<  If EFalse, download cannot be paused, or the 
                            * content will be lost.
                            * (TBool - read-only)
                            * (default: ETrue) */

    EDlAttrHidden,      /**<  If true download is NOT shows in the download 
                            * list or in any way to the user.
                            * (TBool - read/write)
                            * (default: EFalse) */

    EDlAttrSilent,    /**<  No progress events sent to the client application. 
                            * Only exceptions are:
                            * EHttpDlInprogress - EHttpStarted
                            * EHttpDlCompleted
                            * EHttpDlFailed
                            * (TBool - read/write)
                            * (default: EFalse) */

    EDlAttrProgressive,     /**<  Indicates that this is a progressive download.
                            * (TBool - read/write)
                            * (default: EFalse) */
                            
    EDlAttrFotaPckgId,      /**<  Fota package ID.
                            * (TInt32 - read/write)
                            * (default: KDefaultFotaPckgId. Default means no FOTA download! ) */
                            
    EDlAttrDownloadNextUrl, /**<  This attribute is not supported from 3.0!
                            * Beginning from 3.0, Download Manager never 
                            * downloads the next-uri of OMA/COD downloads 
                            * automatically, but forwards the next-uri to the 
                            * client via MHttpDownloadMgrNextUriObserver, 
                            * then the client can create a new download with 
                            * the next-uri it has got, if it wants so. */
                            
    EDlAttrDownloadUpdatedDDUri,/**<  If ETrue, updated DD URI is present in download descriptor.
                                * Start download with updatd DD URI.
                                * (TBool - read/write) 
                                * (default: EFalse)
                                */
    
    EDlAttrUpdatedDDUri,    /**<  Updated DD URI.
                            * (String8<KMaxUrlLength> - read/write
                            */                           
                            
    EDlAttrDDType,          /**<  Content type of the descriptor for OMA downloads. 
                            * For HTTP this will be content type of the MO
                            * (String8<KMaxContentTypeLength> - read only. 
                            */                            

   /**  Application can set and query raw header 
    * fields and values via these attributes.
    * (String<KMaxGeneralHeaderFieldLength> - read/write) */
    EDlAttrHeaderFields     = 1500,
    EDlAttrCharSet          = EDlAttrHeaderFields, // Character Set
    EDlAttrResponseCharSet  = EDlAttrCharSet,
    EDlAttrResponseAge,
    EDlAttrResponseETag,
    EDlAttrResponseLocation,
    EDlAttrResponseRetryAfter,
    EDlAttrResponseServer,
    EDlAttrResponseVary,

    /**  Request headers */
    EDlAttrRequestAccept = 2000,
    EDlAttrRequestAcceptCharSet,
    EDlAttrRequestAcceptLanguage,
    EDlAttrRequestExpect,
    EDlAttrRequestFrom,
    EDlAttrRequestHost,
    EDlAttrRequestMaxForwards,
    EDlAttrRequestPragma,
    EDlAttrRequestReferer,
    EDlAttrRequestUserAgent,
    EDlAttrRequestVary,

    /**  Entity header fields */
    EDlAttrEntityAllow = 2500,
    EDlAttrEntityContentEncoding,
    EDlAttrEntityContentLanguage,
    EDlAttrEntityContentLocation,
    EDlAttrEntityExpires,
    EDlAttrEntityLastModified,

    /**  General header fields */
    EDlAttrGeneralCacheControl = 3000,
    EDlAttrGeneralDate,
    EDlAttrGeneralPragma,
    EDlAttrGeneralVia,
    EDlAttrGeneralWarning,

    /**  Internally used attribute! Do NOT use! */
    EDlAttrSucceeded = 8192,
    /**  Internally used attribute! Do NOT use! */
    EDlAttUnused2,
    /**  Internally used attribute! Do NOT use! */
    EDlAttrFailed,
    
    EDlAttrCodDownload,    /**<  Indicates that it is an OMA DD downlad, 
                            * and the content is downloaded by COD Handler. 
                            * (TBool - read-only)
                            * (default: EFalse) */

    /**  Internally used attribute! Do NOT use! */
    EDlAttrHashedMsgBody, 
    /**  Internally used attribute! Do NOT use! */
    EDlAttrDefaultEvent,
    /**  Internally used attribute! Do NOT use! */
    EDlAttrRedirectedTemporary,
    /**  Internally used attribute! Do NOT use! */
    EDlAttrRedirectedPermanently,
    /**  Internally used attribute! Do NOT use! */
    EDlAttrCodDescriptorAccepted,
    /**  Internally used attribute! Do NOT use! */
    EDlAttrCodLoadEnd,

    EDlAttrDiskBufferingSize,
                               /**< Indicates how large a buffer (in bytes) to
                                 * use when writing this download to disk.  A
                                 * value of 0 indicates no buffering. */

    /**  Internally used attribute! Do NOT use! */                                 
	EDlAttrCodPdAvailable,  /* This is introduced for OMA 2 (DD2). Indicates that progressive download is available 
							* in case if license element exists in the DD2 this attribute is set when the right obj
							* is available and the Progressive download element is true.
							* In case when the license element in not represented this attribute is set if
							* the Progressive download element is true.
							*/

	EDlAttrLocalFileName,   /* This is introduced for OMA 2 (DD2).
                            * Local filename. Content will be 
                            * moved from this location.
                            * This attribute should be set before the client sends the Move command
                            * (String16<KMaxPath> - read/write) */		

    /**  Internally used attribute! Do NOT use! */                                 

    EDlAttrCodPausable,     /**<  Would update the server about Pausability of COD Download. 
                            * This attribute is only used for COD downloads to update pause attibure in server
                            * (TBool - write only) 
                            */                               				   
	
	EDlAttrDdFileName,		/** For storing DD File name. */
    EDlAttrActiveDownload,
	EDlAttrActivePlayedDownload,
	EDlAttrNumMediaObjects,
    EDlAttrMultipleMOLength,/**<  specifies total length of all MOs for the download.
                            * (TInt32 - read/write. */

    EDlAttrMultipleMODownloadedSize, /**<  current downloaded size (the sum of downloaded size of all completed MOs. Completed MOs can be successful/failed/paused MOs). .
                            * (TInt32 - read-only) */
    EDlAttrAlbumName        /**<  Name of the album. In case of non-album download, this is the download name.
                            * (String16<KMaxPath> - read-only) */
    };

/**  
*  See RFC2616.
*/
enum THttpMethod
    {
    EMethodGET,     
    EMethodPOST,
    EMethodHEAD
    };

/**  
*  Authentication scheme
*/
enum THttpAuthenticationScheme
    {
    EAuthBasic,                 ///< Basic authentication scheme
    EAuthDigest                ///< Digest authentication scheme
    };

/**
*  This attribute specifies what Download Manager do
*  with the downloads on exit.
*/
enum THttpDownloadMgrExitAction
    {
    EExitNothing,              ///< Downloads remain intacted on exit (default).
    EExitPause,                ///< All downloads paused on exit.
    EExitDelete                 ///< All downloads deleted on exit.
    };

/**
*  The action to do when a download completes.
*/
enum THttpDownloadMgrAction
    {
    /**
     * Do nothing when download completed.
     */
    EDoNothing  = 0,
    /**
     * Automatically move content to the location pointed by EDlAttrDestFilename 
     */
    EMove           = 0x0001,
    /**
     * Automatically lauch target application when download
     * completed. This is the default if not set (default).
     */
    ELaunch         = 0x0002,
    /**
     * Automatically lauch progressive download 
     */
    EPdLaunch         = 0x0004  
    };

/**
*  Restart actions.
*/
enum THttpRestartActions
    {
    ERestartIfExpired,    /**< Download content again if content is expired (default). */
    ERestartNoIfCompleted,  /**< (Re)Start completes with EHttpDlCompleted at 
                                    * once if already completed. 
                                    * Anyway starts to download the content only if it's 
                                    * not modified since last partial download.
                                    * Restarted anyway. No content update/expiry check. */
    ERestartForced         /**< Forced download. Don't matter if content is 
                                    * expired, or not. */
    };

/**
*  Allocated usable error range: -30421 -> -30470 (includes the 1st and last numbers).
*/
enum THttpDownloadMgrError
    {
    ENoError = 0,
    EGeneral = -30421,  ///< Non-download specific error. See global error code.
    EInternal = -30422,  /**< Internal error occured. Most probably a programming error.
                                    * (e.g. download that is stored on a media, that is not present
                                    * in the phone, cannot be started) */
    EContentFileIntegrity = -30423, /**< Content file is missing or has different size then 
                                    * it should be. EDlAttrNoMedia is ETrue if the media, on which
                                    * content file was (partially) stored, removed. */
    EDiskFull = -30424,  ///< Not enough disk space for the content
    EConnectionFailed = -30425,    /**< Most probably IAP id was wrong or no network coverage.
                                    * For more specific info about the error see EDlAttrGlobalErrorId. */
    ETransactionFailed = -30426,    /**< Error occured in the transaction. 
                                    * For more specific info about the error see EDlAttrGlobalErrorId. */
    EMoveFailed = -30427,  /**< Moving content file failed. 
                                    * See EDlAttrGlobalErrorId for specific reason. */
    EDestFileWriteFailed = -30428,  ///< Destination file write failed.
    EMMCRemoved = -30429,  ///< MMC card, where th download is being persisted, removed.
    EBadUrl = -30430,   /**<  Download Manager cannot handle this URL:
                                    * - it's too long
                                    * - malformed. */

    // Download attributes related error

    EWrongDestFilename = -30431,    
                                    ///< Error in destination filename. Most probably not a real filename.
    EDestFileInUse = -30432,        
                                    /**< Destination file cannot be opened/created. It's most probably
                                    * in use by other app. or download. */

    //HTTP error case

    EHttpUnhandled = -30433,   
                                    /**< Unhandled HTTP error code. See it in 
                                    * EDlAttrGlobalErrorId. */
    EHttpAuthenticationFailed = -30434,  
                                    /**< 401 - Client has to set username/password 
                                    * and Start download again. */
    EProxyAuthenticationFailed = -30435, 
                                    /**< 407 - Client has to set proxy 
                                    * username/password and Start download again. */
    EObjectNotFound = -30436,    
                                    /**< 404 - Object not found. */
    EPartialContentModified = -30437,    
                                    /**< 412: partial content cannot be downloaded because
                                    * it's already modified. 
                                    * Call Reset or set THttpRestartActions::ERestartForced */

    EContentExpired = -30438,       
                                    /**< Paused content is expired, or content 
                                    * is modified between two requests.
                                    * Call Reset() or see THttpRestartActions. */
                                    
    // miscellaneous errors
    EHttpRestartFailed  = -30450    /**<  Resuming progressive download failed. */
    };

#endif      // HTTPDOWNLOADMGRCOMMON_H   

// End of File
