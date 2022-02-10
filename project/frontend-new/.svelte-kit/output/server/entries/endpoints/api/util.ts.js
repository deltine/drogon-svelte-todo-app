import { serialize } from "cookie";
function makeSetCookie(params) {
  let serializes = [];
  for (const property in params) {
    if (params[property] == void 0)
      continue;
    serializes.push(serialize(property, params[property], {
      path: "/",
      httpOnly: true,
      sameSite: "strict",
      secure: true,
      maxAge: 60 * 60 * 24 * 7
    }));
  }
  return {
    "Set-Cookie": serializes
  };
}
function makeResetCoolie(params) {
  let serializes = [];
  console.log("params", params);
  for (const property in params) {
    console.log("params[property]", params[property]);
    serializes.push(serialize(params[property], "", {
      path: "/",
      expires: new Date(0),
      maxAge: 0
    }));
  }
  return {
    "Set-Cookie": serializes
  };
}
export { makeResetCoolie, makeSetCookie };
