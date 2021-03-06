#ifndef HTTPHANDLERPROXYTEST_H
#define HTTPHANDLERPROXYTEST_H

#include "HttpHandlerTest.h"
#include <QObject>
#include <QUrl>

namespace Pillow { class HttpServer; class HttpHandlerSimpleRouter; }
class CapturingHandler;
class HoldingHandler;

class HttpHandlerProxyTest : public HttpHandlerTestBase
{
	Q_OBJECT
	Pillow::HttpServer* server;
	Pillow::HttpHandlerSimpleRouter* router;
	CapturingHandler* capturingHandler;
	HoldingHandler* holdingHandler;
	
public:
	HttpHandlerProxyTest();
	
protected:
	QUrl serverUrl() const;

private slots:
	void init();
	void cleanup();

private slots:
	void testSuccessfulResponse();
	void testClosingResponse();
	void testPrematureClosingResponse();
	void testInvalidResponse();
	void testContentLengthMismatchedResponse();
	void testProxyChain();
	void testNonGetRequest();
	void testHandlesMultipleConcurrentRequests();
	void testCustomProxyPipe();
};

#endif // HTTPHANDLERPROXYTEST_H
