import { makeSetCookie } from "./util.ts.js";
import "cookie";
const post = async (event) => {
  console.log("\u25A0drogon start:", new Date());
  const body = await event.request.json();
  let reqPath = body["path"];
  let reqHeaders = event.request.headers;
  let reqBody = body;
  delete reqBody["path"];
  console.log("reqPath", reqPath);
  console.log("reqBody", reqBody);
  console.log("\u25A0drogon request");
  const response = await fetch("http://localhost:80/api/" + reqPath, {
    method: "POST",
    headers: reqHeaders,
    body: JSON.stringify(reqBody)
  });
  if (!response.ok) {
    console.log("\u25A0drogon faild end");
    return {
      status: response.status
    };
  }
  let resBody = await response.json();
  console.log("resBodyRow", resBody);
  let resCookie = makeSetCookie({
    authKey: resBody.authKey,
    authToken: resBody.authToken
  });
  delete resBody.authKey;
  delete resBody.authToken;
  console.log("resBody", resBody);
  console.log("resCookie", resCookie);
  console.log("\u25A0drogon success end:", new Date());
  return {
    status: response.status,
    body: resBody,
    headers: {
      ...resCookie
    }
  };
};
export { post };
