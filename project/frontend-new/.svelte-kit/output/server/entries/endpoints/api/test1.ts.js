import "cookie";
async function post(event) {
  console.log("test2");
  console.log("event", event);
  return {
    status: 201,
    body: {
      testParam: "AAA",
      testParam2: 234
    }
  };
}
export { post };
