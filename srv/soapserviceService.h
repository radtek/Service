/* soapserviceService.h
   Generated by gSOAP 2.8.34 for service.h

gSOAP XML Web services tools
Copyright (C) 2000-2016, Robert van Engelen, Genivia Inc. All Rights Reserved.
The soapcpp2 tool and its generated software are released under the GPL.
This program is released under the GPL with the additional exemption that
compiling, linking, and/or using OpenSSL is allowed.
--------------------------------------------------------------------------------
A commercial use license is available from Genivia Inc., contact@genivia.com
--------------------------------------------------------------------------------
*/

#ifndef soapserviceService_H
#define soapserviceService_H
#include "soapH.h"

    class SOAP_CMAC serviceService : public soap {
      public:
        /// Variables globally declared in service.h, if any
        /// Construct a service with new managing context
        serviceService();
        /// Copy constructor
        serviceService(const serviceService&);
        /// Construct service given a managing context
        serviceService(const struct soap&);
        /// Constructor taking input+output mode flags for the new managing context
        serviceService(soap_mode iomode);
        /// Constructor taking input and output mode flags for the new managing context
        serviceService(soap_mode imode, soap_mode omode);
        /// Destructor deletes deserialized data and managing context
        virtual ~serviceService();
        /// Delete all deserialized data (with soap_destroy() and soap_end())
        virtual void destroy();
        /// Delete all deserialized data and reset to defaults
        virtual void reset();
        /// Initializer used by constructors
        virtual void serviceService_init(soap_mode imode, soap_mode omode);
        /// Return a copy that has a new managing context with the same engine state
        virtual serviceService *copy() SOAP_PURE_VIRTUAL;
        /// Copy assignment
        serviceService& operator=(const serviceService&);
        /// Close connection (normally automatic)
        virtual int soap_close_socket();
        /// Force close connection (can kill a thread blocked on IO)
        virtual int soap_force_close_socket();
        /// Return sender-related fault to sender
        virtual int soap_senderfault(const char *string, const char *detailXML);
        /// Return sender-related fault with SOAP 1.2 subcode to sender
        virtual int soap_senderfault(const char *subcodeQName, const char *string, const char *detailXML);
        /// Return receiver-related fault to sender
        virtual int soap_receiverfault(const char *string, const char *detailXML);
        /// Return receiver-related fault with SOAP 1.2 subcode to sender
        virtual int soap_receiverfault(const char *subcodeQName, const char *string, const char *detailXML);
        /// Print fault
        virtual void soap_print_fault(FILE*);
    #ifndef WITH_LEAN
    #ifndef WITH_COMPAT
        /// Print fault to stream
        virtual void soap_stream_fault(std::ostream&);
    #endif
        /// Write fault to buffer
        virtual char *soap_sprint_fault(char *buf, size_t len);
    #endif
        /// Disables and removes SOAP Header from message by setting soap->header = NULL
        virtual void soap_noheader();
        /// Get SOAP Header structure (i.e. soap->header, which is NULL when absent)
        virtual ::SOAP_ENV__Header *soap_header();
        /// Run simple single-thread (iterative, non-SSL) service on port until a connection error occurs (returns SOAP_OK or error code), use this->bind_flag = SO_REUSEADDR to rebind for immediate rerun
        virtual int run(int port);
    #if defined(WITH_OPENSSL) || defined(WITH_GNUTLS)
        /// Run simple single-thread SSL service on port until a connection error occurs (returns SOAP_OK or error code), use this->bind_flag = SO_REUSEADDR to rebind for immediate rerun
        virtual int ssl_run(int port);
    #endif
        /// Bind service to port (returns master socket or SOAP_INVALID_SOCKET)
        virtual SOAP_SOCKET bind(const char *host, int port, int backlog);
        /// Accept next request (returns socket or SOAP_INVALID_SOCKET)
        virtual SOAP_SOCKET accept();
    #if defined(WITH_OPENSSL) || defined(WITH_GNUTLS)
        /// When SSL is used, after accept() should perform and accept SSL handshake
        virtual int ssl_accept();
    #endif
        /// After accept() serve this request (returns SOAP_OK or error code)
        virtual int serve();
        /// Used by serve() to dispatch a request (returns SOAP_OK or error code)
        virtual int dispatch();
        ///
        /// Service operations are listed below (you should define these)
        /// Note: compile with -DWITH_PURE_VIRTUAL for pure virtual methods
        ///
        /// Web service operation 'getFileService' (returns SOAP_OK or error code)
        virtual int getFileService(struct ns__TempleFiles in, int &result) SOAP_PURE_VIRTUAL;
        /// Web service operation 'TempleMatchService' (returns SOAP_OK or error code)
        virtual int TempleMatchService(struct ns__TempleMatchPARA inPara, struct ns__TempleMatchOUT &outPara) SOAP_PURE_VIRTUAL;
        /// Web service operation 'getCCalibrationXYZFile' (returns SOAP_OK or error code)
        virtual int getCCalibrationXYZFile(struct SOAP_ENC__base64 inFile, int &result) SOAP_PURE_VIRTUAL;
        /// Web service operation 'CCalibrationXYZNewService' (returns SOAP_OK or error code)
        virtual int CCalibrationXYZNewService(struct ns__CCalibrationXYZNewPARA inPara, struct ns__CCalibrationXYZNewOUT &outPara) SOAP_PURE_VIRTUAL;
    };
#endif
