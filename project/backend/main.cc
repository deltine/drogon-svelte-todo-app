#include <drogon/drogon.h>
#include <chrono>

using namespace drogon;
using namespace std::chrono_literals;

int main()
{
    // Set HTTP listener address and port
    app().addListener("0.0.0.0", 80);
    // Load config file
    app().loadConfigFile("../config.json");
    // Run HTTP framework,the method will block in the internal event loop
    app().registerPostHandlingAdvice(
        [](const HttpRequestPtr &req, const HttpResponsePtr &res)
        {
            res->addHeader("Access-Control-Allow-Origin", "http://localhost:3000");
            // res->addHeader("Access-Control-Allow-Methods", "GET, POST, PUT, PATCH, DELETE, HEAD, OPTIONS");
            // res->addHeader("Access-Control-Allow-Headers", "content-type, Accept, X-Custom-Header, credentials"); // x-requested-with
            res->addHeader("Access-Control-Allow-Credentials", "true");
            res->addHeader("Access-Control-Max-Age", "600");
        });
    drogon::app().run();
    return 0;
}
