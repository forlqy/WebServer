#ifndef __SYLAR_HTTP_SESSION_H__
#define __SYLAR_HTTP_SESSION_H__

#include "sylar/socket_stream.h"
#include "http.h"

namespace sylar{
namespace http{


class HttpSession : public SocketStream{
public:
    using ptr = std::shared_ptr<HttpSession>;
    HttpSession(Socket::ptr sock, bool owner = true);
    HttpRequest::ptr recvRequest();
    int sendResponse(HttpResponse::ptr rsp);
};



}
}



#endif