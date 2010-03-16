/*
* Copyright (c) 2006-2006 Nokia Corporation and/or its subsidiary(-ies). 
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
* Description: Crypto graphy utils api declaration
*
*/

#ifndef C_SEN_CRYPTO_UTILS_H
#define C_SEN_CRYPTO_UTILS_H

#include <hash.h>


/**
 * Set of static convenience methods to help in cryptography
 */
class SenCryptoUtils
    {
    public:
        /**
        * Algorithm taken from of TLS specification RFC 2246 - 5.HMAC and the pseudorandom function  
        *           
        *           P_hash(secret, seed) = HMAC_hash(secret, A(1) + seed) +
        *                              HMAC_hash(secret, A(2) + seed) +
        *                              HMAC_hash(secret, A(3) + seed) + ...
        *
        *               Where + indicates concatenation.
        *
        *               A() is defined as:
        *                   A(0) = seed
        *                   A(i) = HMAC_hash(secret, A(i-1))
        *
        *       P_hash can be iterated as many times as is necessary to produce the
        *       required quantity of data. For example, if P_SHA-1 was being used to
        *       create 64 bytes of data, it would have to be iterated 4 times
        *       (through A(4)), creating 80 bytes of output data; the last 16 bytes
        *       of the final iteration would then be discarded, leaving 64 bytes of
        *       output data.
        * @param aSecret - secret
        * @param aSeed - seed
        * @param aLength - length of new secret
        * @since Series60 4.0
        */
        IMPORT_C static HBufC8* GetPSHA1HashL( const TDesC8& aSecret, 
                                               const TDesC8& aSeed, 
                                               const TInt aLength );
    
        /*
        * Encode data into Base64 format
        * @param aData - source data
        * @return encoded data, if some problem occurs, NULL is returned
        * @since Series60 4.0
        */
        IMPORT_C static HBufC8* EncodeBase64L(const TDesC8& aData);
    
        /*
        * Decode data from Base64 format
        * @param aData - source data
        * @return decoded data, if some problem occurs, NULL is returned
        * @since Series60 4.0
        */
        IMPORT_C static HBufC8* DecodeBase64L(const TDesC8& aData);
    
        /*
        * Randomize some data and hash it using MD5 digest algorithm.
        * @return hashed randomized data (constant length of hash according to MD5 specification)
        * @since Series60 4.0
        */
        IMPORT_C static HBufC8* RandomAndHashMd5LC();
        
        /*
        * Create <BinarySecret> tag from security token.
        * @param aSecret security context token.
        * @param aValueType Indicates what the security token is
        * @return <BinarySecret> tag with encoded (base64) token.
        */
        IMPORT_C static HBufC8* CreateEncodedBinarySecretL( const TDesC8& aSecret, 
                                                            const TDesC8& aValueType );
        
        /*
        * Timestamp as number of seconds since 1 january 1970 
        *   Calculated for present phone time.
        * @return timestamp value
        * @since Series60 5.0
        */
        IMPORT_C static HBufC8* GetTimestampL();


        /*
        * Timestamp as number of seconds since 1 january 1970.
        *   Calculated for provided time.
        * @param aTime base for generated timestamp
        * @return timestamp value
        * @since Series60 5.0
        */
        IMPORT_C static HBufC8* GetTimestampL(TTime aTime);
        
        /*
        * Randomize some data (based on time) and hash it using MD5 digest algorithm, 
        * convert each byte to hex nember representation
        * @return hashed randomized data (constant length of hash according to MD5 specification
        * doubled during hex conversion)
        * @since Series60 5.0
        */
        IMPORT_C static HBufC8* GetRandomNonceL();
        
    private:
        /**
        * Hide default C++ constructor.
        */
        SenCryptoUtils();
    };

#endif // C_SEN_CRYPTO_UTILS_H

