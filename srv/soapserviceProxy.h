/* soapserviceProxy.h
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

#ifndef soapserviceProxy_H
#define soapserviceProxy_H
#include "soapH.h"

    class SOAP_CMAC serviceProxy : public soap {
      public:
        /// Endpoint URL of service 'serviceProxy' (change as needed)
        const char *soap_endpoint;
        /// Variables globally declared in service.h, if any
        /// Construct a proxy with new managing context
        serviceProxy();
        /// Copy constructor
        serviceProxy(const serviceProxy& rhs);
        /// Construct proxy given a managing context
        serviceProxy(const struct soap&);
        /// Constructor taking an endpoint URL
        serviceProxy(const char *endpoint);
        /// Constructor taking input and output mode flags for the new managing context
        serviceProxy(soap_mode iomode);
        /// Constructor taking endpoint URL and input and output mode flags for the new managing context
        serviceProxy(const char *endpoint, soap_mode iomode);
        /// Constructor taking input and output mode flags for the new managing context
        serviceProxy(soap_mode imode, soap_mode omode);
        /// Destructor deletes deserialized data and managing context
        virtual ~serviceProxy();
        /// Initializer used by constructors
        virtual void serviceProxy_init(soap_mode imode, soap_mode omode);
        /// Return a copy that has a new managing context with the same engine state
        virtual serviceProxy *copy() SOAP_PURE_VIRTUAL;
        /// Copy assignment
        serviceProxy& operator=(const serviceProxy&);
        /// Delete all deserialized data (uses soap_destroy() and soap_end())
        virtual void destroy();
        /// Delete all deserialized data and reset to default
        virtual void reset();
        /// Disables and removes SOAP Header from message by setting soap->header = NULL
        virtual void soap_noheader();
        /// Get SOAP Header structure (i.e. soap->header, which is NULL when absent)
        virtual ::SOAP_ENV__Header *soap_header();
        /// Get SOAP Fault structure (i.e. soap->fault, which is NULL when absent)
        virtual ::SOAP_ENV__Fault *soap_fault();
        /// Get SOAP Fault string (NULL when absent)
        virtual const char *soap_fault_string();
        /// Get SOAP Fault detail as string (NULL when absent)
        virtual const char *soap_fault_detail();
        /// Close connection (normally automatic, except for send_X ops)
        virtual int soap_close_socket();
        /// Force close connection (can kill a thread blocked on IO)
        virtual int soap_force_close_socket();
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
        /// Web service operation 'getFileService' (returns SOAP_OK or error code)
        virtual int getFileService(struct ns__TempleFiles in, int &result)
        { return this->getFileService(NULL, NULL, in, result); }
        virtual int getFileService(const char *soap_endpoint, const char *soap_action, struct ns__TempleFiles in, int &result);
        /// Web service operation 'TempleMatchService' (returns SOAP_OK or error code)
        virtual int TempleMatchService(struct ns__TempleMatchPARA inPara, struct ns__TempleMatchOUT &outPara)
        { return this->TempleMatchService(NULL, NULL, inPara, outPara); }
        virtual int TempleMatchService(const char *soap_endpoint, const char *soap_action, struct ns__TempleMatchPARA inPara, struct ns__TempleMatchOUT &outPara);
        /// Web service operation 'getCCalibrationXYZFile' (returns SOAP_OK or error code)
        virtual int getCCalibrationXYZFile(struct SOAP_ENC__base64 inFile, int &result)
        { return this->getCCalibrationXYZFile(NULL, NULL, inFile, result); }
        virtual int getCCalibrationXYZFile(const char *soap_endpoint, const char *soap_action, struct SOAP_ENC__base64 inFile, int &result);
        /// Web service operation 'CCalibrationXYZNewService' (returns SOAP_OK or error code)
        virtual int CCalibrationXYZNewService(struct ns__CCalibrationXYZNewPARA inPara, struct ns__CCalibrationXYZNewOUT &outPara)
        { return this->CCalibrationXYZNewService(NULL, NULL, inPara, outPara); }
        virtual int CCalibrationXYZNewService(const char *soap_endpoint, const char *soap_action, struct ns__CCalibrationXYZNewPARA inPara, struct ns__CCalibrationXYZNewOUT &outPara);
    };
#endif