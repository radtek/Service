/* soapserviceService.cpp
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

#include "soapserviceService.h"

serviceService::serviceService() : soap(SOAP_IO_DEFAULT)
{	serviceService_init(SOAP_IO_DEFAULT, SOAP_IO_DEFAULT);
}

serviceService::serviceService(const serviceService& rhs)
{	soap_copy_context(this, &rhs);
}

serviceService::serviceService(const struct soap &_soap) : soap(_soap)
{ }

serviceService::serviceService(soap_mode iomode) : soap(iomode)
{	serviceService_init(iomode, iomode);
}

serviceService::serviceService(soap_mode imode, soap_mode omode) : soap(imode, omode)
{	serviceService_init(imode, omode);
}

serviceService::~serviceService()
{
	this->destroy();
}

void serviceService::serviceService_init(soap_mode imode, soap_mode omode)
{	soap_imode(this, imode);
	soap_omode(this, omode);
	static const struct Namespace namespaces[] = {
        {"SOAP-ENV", "http://www.w3.org/2003/05/soap-envelope", "http://schemas.xmlsoap.org/soap/envelope/", NULL},
        {"SOAP-ENC", "http://www.w3.org/2003/05/soap-encoding", "http://schemas.xmlsoap.org/soap/encoding/", NULL},
        {"xsi", "http://www.w3.org/2001/XMLSchema-instance", "http://www.w3.org/*/XMLSchema-instance", NULL},
        {"xsd", "http://www.w3.org/2001/XMLSchema", "http://www.w3.org/*/XMLSchema", NULL},
        {"ns", "http://localhost:8089/service.wsdl", NULL, NULL},
        {NULL, NULL, NULL, NULL}
    };
	soap_set_namespaces(this, namespaces);
}

void serviceService::destroy()
{	soap_destroy(this);
	soap_end(this);
}

void serviceService::reset()
{	this->destroy();
	soap_done(this);
	soap_initialize(this);
	serviceService_init(SOAP_IO_DEFAULT, SOAP_IO_DEFAULT);
}

#ifndef WITH_PURE_VIRTUAL
serviceService *serviceService::copy()
{	serviceService *dup = SOAP_NEW_COPY(serviceService(*(struct soap*)this));
	return dup;
}
#endif

serviceService& serviceService::operator=(const serviceService& rhs)
{	soap_copy_context(this, &rhs);
	return *this;
}

int serviceService::soap_close_socket()
{	return soap_closesock(this);
}

int serviceService::soap_force_close_socket()
{	return soap_force_closesock(this);
}

int serviceService::soap_senderfault(const char *string, const char *detailXML)
{	return ::soap_sender_fault(this, string, detailXML);
}

int serviceService::soap_senderfault(const char *subcodeQName, const char *string, const char *detailXML)
{	return ::soap_sender_fault_subcode(this, subcodeQName, string, detailXML);
}

int serviceService::soap_receiverfault(const char *string, const char *detailXML)
{	return ::soap_receiver_fault(this, string, detailXML);
}

int serviceService::soap_receiverfault(const char *subcodeQName, const char *string, const char *detailXML)
{	return ::soap_receiver_fault_subcode(this, subcodeQName, string, detailXML);
}

void serviceService::soap_print_fault(FILE *fd)
{	::soap_print_fault(this, fd);
}

#ifndef WITH_LEAN
#ifndef WITH_COMPAT
void serviceService::soap_stream_fault(std::ostream& os)
{	::soap_stream_fault(this, os);
}
#endif

char *serviceService::soap_sprint_fault(char *buf, size_t len)
{	return ::soap_sprint_fault(this, buf, len);
}
#endif

void serviceService::soap_noheader()
{	this->header = NULL;
}

::SOAP_ENV__Header *serviceService::soap_header()
{	return this->header;
}

int serviceService::run(int port)
{	if (!soap_valid_socket(this->master) && !soap_valid_socket(this->bind(NULL, port, 100)))
		return this->error;
	for (;;)
	{	if (!soap_valid_socket(this->accept()))
		{	if (this->errnum == 0) // timeout?
				this->error = SOAP_OK;
			break;
		}
		if (this->serve())
			break;
		this->destroy();
	}
	return this->error;
}

#if defined(WITH_OPENSSL) || defined(WITH_GNUTLS)
int serviceService::ssl_run(int port)
{	if (!soap_valid_socket(this->master) && !soap_valid_socket(this->bind(NULL, port, 100)))
		return this->error;
	for (;;)
	{	if (!soap_valid_socket(this->accept()))
		{	if (this->errnum == 0) // timeout?
				this->error = SOAP_OK;
			break;
		}
		if (this->ssl_accept() || this->serve())
			break;
		this->destroy();
	}
	return this->error;
}
#endif

SOAP_SOCKET serviceService::bind(const char *host, int port, int backlog)
{	return soap_bind(this, host, port, backlog);
}

SOAP_SOCKET serviceService::accept()
{	return soap_accept(this);
}

#if defined(WITH_OPENSSL) || defined(WITH_GNUTLS)
int serviceService::ssl_accept()
{	return soap_ssl_accept(this);
}
#endif

int serviceService::serve()
{
#ifndef WITH_FASTCGI
	unsigned int k = this->max_keep_alive;
#endif
	do
	{
#ifndef WITH_FASTCGI
		if (this->max_keep_alive > 0 && !--k)
			this->keep_alive = 0;
#endif
		if (soap_begin_serve(this))
		{	if (this->error >= SOAP_STOP)
				continue;
			return this->error;
		}
		if ((dispatch() || (this->fserveloop && this->fserveloop(this))) && this->error && this->error < SOAP_STOP)
		{
#ifdef WITH_FASTCGI
			soap_send_fault(this);
#else
			return soap_send_fault(this);
#endif
		}
#ifdef WITH_FASTCGI
		soap_destroy(this);
		soap_end(this);
	} while (1);
#else
	} while (this->keep_alive);
#endif
	return SOAP_OK;
}

static int serve_ns__getFileService(serviceService*);
static int serve_ns__TempleMatchService(serviceService*);
static int serve_ns__getCCalibrationXYZFile(serviceService*);
static int serve_ns__CCalibrationXYZNewService(serviceService*);

int serviceService::dispatch()
{
	soap_peek_element(this);
	if (!soap_match_tag(this, this->tag, "ns:getFileService"))
		return serve_ns__getFileService(this);
	if (!soap_match_tag(this, this->tag, "ns:TempleMatchService"))
		return serve_ns__TempleMatchService(this);
	if (!soap_match_tag(this, this->tag, "ns:getCCalibrationXYZFile"))
		return serve_ns__getCCalibrationXYZFile(this);
	if (!soap_match_tag(this, this->tag, "ns:CCalibrationXYZNewService"))
		return serve_ns__CCalibrationXYZNewService(this);
	return this->error = SOAP_NO_METHOD;
}

static int serve_ns__getFileService(serviceService *soap)
{	struct ns__getFileService soap_tmp_ns__getFileService;
	struct ns__getFileServiceResponse soap_tmp_ns__getFileServiceResponse;
	soap_default_ns__getFileServiceResponse(soap, &soap_tmp_ns__getFileServiceResponse);
	soap_default_ns__getFileService(soap, &soap_tmp_ns__getFileService);
	if (!soap_get_ns__getFileService(soap, &soap_tmp_ns__getFileService, "ns:getFileService", NULL))
		return soap->error;
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap->error;
	soap->error = soap->getFileService(soap_tmp_ns__getFileService.in, soap_tmp_ns__getFileServiceResponse.result);
	if (soap->error)
		return soap->error;
	soap->encodingStyle = "";
	soap_serializeheader(soap);
	soap_serialize_ns__getFileServiceResponse(soap, &soap_tmp_ns__getFileServiceResponse);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put_ns__getFileServiceResponse(soap, &soap_tmp_ns__getFileServiceResponse, "ns:getFileServiceResponse", "")
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	};
	if (soap_end_count(soap)
	 || soap_response(soap, SOAP_OK)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put_ns__getFileServiceResponse(soap, &soap_tmp_ns__getFileServiceResponse, "ns:getFileServiceResponse", "")
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap->error;
	return soap_closesock(soap);
}

static int serve_ns__TempleMatchService(serviceService *soap)
{	struct ns__TempleMatchService soap_tmp_ns__TempleMatchService;
	struct ns__TempleMatchOUT outPara;
	soap_default_ns__TempleMatchOUT(soap, &outPara);
	soap_default_ns__TempleMatchService(soap, &soap_tmp_ns__TempleMatchService);
	if (!soap_get_ns__TempleMatchService(soap, &soap_tmp_ns__TempleMatchService, "ns:TempleMatchService", NULL))
		return soap->error;
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap->error;
	soap->error = soap->TempleMatchService(soap_tmp_ns__TempleMatchService.inPara, outPara);
	if (soap->error)
		return soap->error;
	soap->encodingStyle = "";
	soap_serializeheader(soap);
	soap_serialize_ns__TempleMatchOUT(soap, &outPara);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put_ns__TempleMatchOUT(soap, &outPara, "ns:TempleMatchOUT", "")
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	};
	if (soap_end_count(soap)
	 || soap_response(soap, SOAP_OK)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put_ns__TempleMatchOUT(soap, &outPara, "ns:TempleMatchOUT", "")
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap->error;
	return soap_closesock(soap);
}

static int serve_ns__getCCalibrationXYZFile(serviceService *soap)
{	struct ns__getCCalibrationXYZFile soap_tmp_ns__getCCalibrationXYZFile;
	struct ns__getCCalibrationXYZFileResponse soap_tmp_ns__getCCalibrationXYZFileResponse;
	soap_default_ns__getCCalibrationXYZFileResponse(soap, &soap_tmp_ns__getCCalibrationXYZFileResponse);
	soap_default_ns__getCCalibrationXYZFile(soap, &soap_tmp_ns__getCCalibrationXYZFile);
	if (!soap_get_ns__getCCalibrationXYZFile(soap, &soap_tmp_ns__getCCalibrationXYZFile, "ns:getCCalibrationXYZFile", NULL))
		return soap->error;
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap->error;
	soap->error = soap->getCCalibrationXYZFile(soap_tmp_ns__getCCalibrationXYZFile.inFile, soap_tmp_ns__getCCalibrationXYZFileResponse.result);
	if (soap->error)
		return soap->error;
	soap->encodingStyle = "";
	soap_serializeheader(soap);
	soap_serialize_ns__getCCalibrationXYZFileResponse(soap, &soap_tmp_ns__getCCalibrationXYZFileResponse);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put_ns__getCCalibrationXYZFileResponse(soap, &soap_tmp_ns__getCCalibrationXYZFileResponse, "ns:getCCalibrationXYZFileResponse", "")
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	};
	if (soap_end_count(soap)
	 || soap_response(soap, SOAP_OK)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put_ns__getCCalibrationXYZFileResponse(soap, &soap_tmp_ns__getCCalibrationXYZFileResponse, "ns:getCCalibrationXYZFileResponse", "")
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap->error;
	return soap_closesock(soap);
}

static int serve_ns__CCalibrationXYZNewService(serviceService *soap)
{	struct ns__CCalibrationXYZNewService soap_tmp_ns__CCalibrationXYZNewService;
	struct ns__CCalibrationXYZNewOUT outPara;
	soap_default_ns__CCalibrationXYZNewOUT(soap, &outPara);
	soap_default_ns__CCalibrationXYZNewService(soap, &soap_tmp_ns__CCalibrationXYZNewService);
	if (!soap_get_ns__CCalibrationXYZNewService(soap, &soap_tmp_ns__CCalibrationXYZNewService, "ns:CCalibrationXYZNewService", NULL))
		return soap->error;
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap->error;
	soap->error = soap->CCalibrationXYZNewService(soap_tmp_ns__CCalibrationXYZNewService.inPara, outPara);
	if (soap->error)
		return soap->error;
	soap->encodingStyle = "";
	soap_serializeheader(soap);
	soap_serialize_ns__CCalibrationXYZNewOUT(soap, &outPara);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put_ns__CCalibrationXYZNewOUT(soap, &outPara, "ns:CCalibrationXYZNewOUT", "")
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	};
	if (soap_end_count(soap)
	 || soap_response(soap, SOAP_OK)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put_ns__CCalibrationXYZNewOUT(soap, &outPara, "ns:CCalibrationXYZNewOUT", "")
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap->error;
	return soap_closesock(soap);
}
/* End of server object code */
